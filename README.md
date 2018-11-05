# mangOS

> A simple hobby OS targeting x86

#### How To Run
```bash
# clang, nasm, qemu, grub are required
# Compile:
make # -j4 for multithreded compile (4 cores)

# Run in qemu
make run

# Debug
make debug
# In a seperate terminal in the same directory (.gdbinit):
gdb
break kmain
continue
```

#### TODO
- [x] Create starting point in 32 bit
- [x] Basic segmentation
- [x] Create GDT
- [x] Create basic IDT/IQR's
- [x] Keyboard/timer support
- [x] Multiboot info
- [ ] Add basic paging
    - [ ] Map kernel at higher half
- [ ] Heap support
- [ ] VFS/initrd
- [ ] Multitasking
- [ ] Userland



#### Resources
* [https://wiki.osdev.org/Main_Page](https://wiki.osdev.org/Main_Page)
* [http://www.jamesmolloy.co.uk/tutorial_html/](http://www.jamesmolloy.co.uk/tutorial_html/)
* [http://www.osdever.net/bkerndev/Docs/title.htm](http://www.osdever.net/bkerndev/Docs/title.htm)
* [https://littleosbook.github.io](https://littleosbook.github.io)
* [http://www.brokenthorn.com/Resources/](http://www.brokenthorn.com/Resources/)
* [http://www.osdever.net/tutorials/](http://www.osdever.net/tutorials/)
