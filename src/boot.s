;
; boot.s -- Start of kernel.
;

global boot
extern kmain

; 3GB offest for translating physical => virtual
KERNEL_VIRTUAL_BASE equ 0xC0000000
; Page directory index of kernels 4MB PTE
KERNEL_PAGE_NUM     equ (KERNEL_VIRTUAL_BASE >> 22)

section .data
align 0x1000
; PDE identity-maps first 4MB of 32-bit physical address space
; Sets bit 7 (PS), bit 1 (RW), bit 0 (P)
boot_page_directory:
  dd 0x00000083                           ; First 4MB
  times (KERNEL_PAGE_NUM - 1) dd 0        ; Pages before kernel
  dd 0x00000083                           ; Kernel 4MB at 3GB offset
  times (1024 - KERNEL_PAGE_NUM - 1) dd 0 ; Pagest after kernel

section .text
bits 32
boot:
  ; Load page directory
  mov ecx, (boot_page_directory - KERNEL_VIRTUAL_BASE)
  mov cr3, ecx

  ; Set PSE bit in CR4 to enable 4MB pages
  mov ecx, cr4
  or ecx, 0x0000010
  mov cr4, ecx

  ; Set PG bit in CR0 to enable paging
  mov ecx, cr0
  or ecx, 0x80000000
  mov cr0, ecx

  ; Long jump to higher half
  lea ecx, [start_higher_half]
  jmp ecx

start_higher_half:
  ; Unmap identiy-mapped first 4MB of physical address space
  mov dword [boot_page_directory], 0
  invlpg [0]

  mov esp, stack_top    ; Setup stack
  
  add ebx, KERNEL_VIRTUAL_BASE
  push ebx              ; Load multiboot info
  push eax              ; Load multiboot magic

  cli                   ; Disable interrupts

  call kmain            ; Start Kernel
  ; mov dword [0xC00B8000], 0x2f4b2f4f

  cli
.hang
  hlt
  jmp .hang



KERNEL_STACK_SIZE equ 0x4000

section .bss
align 32
stack_bottom:
  resb KERNEL_STACK_SIZE
stack_top:

