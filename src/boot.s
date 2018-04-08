;
; boot.s -- Start of kernel.
;

global _start
extern kmain

section .text
bits 32
_start:
  mov esp, stack_top    ; Setup stack
  push ebx              ; Load multiboot info

  cli                   ; Disable interrupts

  call check_multiboot  ; Check multiboot
  call check_cpuid      ; Check cpuid
  call check_long_mode  ; Check long mode (x86_64)

  call kmain            ; Start Kernel
  jmp $

check_multiboot:
  cmp eax, 0x36D76289
  jne .no_multiboot
  ret
.no_multiboot:
  mov al, "0"
  jmp error

check_cpuid:
  ; Check if CPUID is supported by attempting to flip the ID bit (bit 21) in
  ; the FLAGS register. If we can flip it, CPUID is available
  ; Copy FLAGS in to EAX via stack
  pushfd
  pop eax
  ; Copy to ECX as well for comparing later on
  mov ecx, eax
  ; Flip the ID bit
  xor eax, 1 << 21
  ; Copy EAX to FLAGS via the stack
  push eax
  popfd
  ; Copy FLAGS back to EAX (with the flipped bit if CPUID is supported)
  pushfd
  pop eax
  ; Restore FLAGS from the old version stored in ECX (i.e. flipping the ID bit
  ; back if it was ever flipped).
  push ecx
  popfd
  ; Compare EAX and ECX. If they are equal then that means the bit wasn't
  ; flipped, and CPUID isn't supported.
  xor eax, ecx
  je .no_cpuid
  ret
.no_cpuid:
  mov al, "1"
  jmp error

check_long_mode:
  mov eax, 0x80000000   ; Set the A-register to 0x80000000
  cpuid                 ; CPU identification
  cmp eax, 0x80000001   ; Compare the A-register with 0x80000001
  jb .no_long_mode      ; It is less, there is no long mode

  mov eax, 0x80000001   ; Set the A-register to 0x80000001
  cpuid                 ; CPU identification
  test edx, 1 << 29     ; Test if the LM-bit, which is bit 29,
                        ; is set in the D-register
  jz .no_long_mode      ; They aren't, there is no long-mode
  ret
.no_long_mode:
  mov al, "2"
  jmp error

error:
  mov dword [0xb8000], 0x4f524f45
  mov dword [0xb8004], 0x4f3a4f52
  mov dword [0xb8008], 0x4f204f20
  mov byte  [0xb800a], al
  hlt

.end:


KERNEL_STACK_SIZE equ 16384

section .bss
align 4
stack_bottom:
  resb KERNEL_STACK_SIZE
stack_top:

