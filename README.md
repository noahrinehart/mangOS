# mangOS

> A simple hobby OS targeting x86

## Dependencies
* `nasm`
* `clang`
    * with linker (`lld.ld`)
* `grub`
* `mkisofs`
* `qemu`
* `gdb` (for debugging)
* stage2_eldorito
    * Download from [here](https://osdn.net/projects/sfnet_joesbootdisk/downloads/development/boots/iso/stage2_eltorito/) to `src/iso/stage2_eltorito`

### Arch Linux
`$ sudo pacman -S nasm clang lld grub cdrkit qemu gdb`

## How To Run
```bash
# clang, nasm, qemu, grub are required
# Compile:
make # -j4 for multithreded compile (4 cores)

# Run in qemu
make run

# Debug
make debug
# In a seperate terminal...
gdb
break kmain
continue
```

### Note for gdb:
> Note for `gdb`: you may get "...auto-loading has been decline", to fix this, follow the instructions to enable executation below for that directory

## TODO
- [x] Create starting point in 32 bit
- [x] Create GDT
- [x] Create basic IDT/IQR's
- [x] Keyboard/timer support
- [ ] Multiboot info
- [ ] Add basic paging
    - [x] Map kernel at higher half
    - [ ] Create page frame allocator
    - [ ] Crate frames on demand
    - [ ] Swap frames on demand
- [ ] Heap support
- [ ] VFS/initrd
- [ ] Multitasking
- [ ] Userland



## Resources
* [https://wiki.osdev.org/Main_Page](https://wiki.osdev.org/Main_Page)
* [http://www.jamesmolloy.co.uk/tutorial_html/](http://www.jamesmolloy.co.uk/tutorial_html/)
* [http://www.osdever.net/bkerndev/Docs/title.htm](http://www.osdever.net/bkerndev/Docs/title.htm)
* [https://littleosbook.github.io](https://littleosbook.github.io)
* [http://www.brokenthorn.com/Resources/](http://www.brokenthorn.com/Resources/)
* [http://www.osdever.net/tutorials/](http://www.osdever.net/tutorials/)

