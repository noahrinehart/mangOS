;
; boot.s -- Start of kernel.
;

global start
global KERNEL_VIRTUAL_BASE
global PageDirectoryVirtualAddress
global stack_bottom


extern kmain

; Virtual base address of kernel space. Used to convert virtual address into physical
; addresses until paging is enabled.
KERNEL_VIRTUAL_BASE equ 0xC0000000								 ; 3GB
KERNEL_PAGE_NUMBER equ (KERNEL_VIRTUAL_BASE >> 22) ; Page directory index of kernal's 4MB PTE


section .data
align 0x1000
PageDirectoryVirtualAddress:
	; Identity maps first 4MB of 32-bit physical address space
	; Sets Huge Page, R/W, Present bits
	dd 0x00000083
	times (KERNEL_PAGE_NUMBER - 1) dd 0
	dd 0x00000083
	times (1024 - KERNEL_PAGE_NUMBER - 1) dd 0

section .text
align 4
_start:
start equ (_start - KERNEL_VIRTUAL_BASE)
	; Must be PIC and use phsycial addresss until paging setup
	global PageDirectoryPhysicalAddress
	; 0x1004000
	PageDirectoryPhysicalAddress equ (PageDirectoryVirtualAddress - KERNEL_VIRTUAL_BASE)
	mov ecx, PageDirectoryPhysicalAddress
	mov cr3, ecx	; Load page directory base register

	mov ecx, cr4
	or ecx, 0x00000010 ; Set PSE for huge pages
	mov cr4, ecx

	mov ecx, cr0
	or ecx, 0x80000000 ; Enable paging
	mov cr0, ecx

	; Far jump to correct code since paging is enabled
	lea ecx, [higher_half_loader]
	jmp ecx

higher_half_loader:
	; Unmap identity-mapped first 4MB of physical address space
	mov dword [PageDirectoryVirtualAddress], 0
	invlpg [0]

	mov esp, stack_top
	
	; add ebx, KERNEL_VIRTUAL_BASE
	; push ebx

  ; push ebx              ; Load multiboot info
  ; push eax              ; Load multiboot magic
  
  ; call kmain            ; Start Kernel

  mov word [0xC00B8000], 0x2848               ; H
  mov word [0xC00B8002], 0x2845               ; E
  mov word [0xC00B8004], 0x284C               ; L
  mov word [0xC00B8006], 0x284C               ; L
  mov word [0xC00B8008], 0x284F               ; O
  mov word [0xC00B800A], 0x2821               ; !

.halt:
  hlt
  jmp .halt
.end:


KERNEL_STACK_SIZE equ 0x4000

section .bss
align 4
stack_bottom:
  resb KERNEL_STACK_SIZE
stack_top:
