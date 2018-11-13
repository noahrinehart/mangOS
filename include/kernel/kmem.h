extern char base[];    /* Start of memory         */
extern char text[];    /* Start of text segment   */
extern char etext[];   /* End of text segment     */
extern char rodata[];  /* Start of rodata segment */
extern char erodata[]; /* End of rodata segment   */
extern char data[];    /* Start of data segment   */
extern char edata[];   /* End of data segment     */
extern char bss[];     /* Start of bss segment    */
extern char ebss[];    /* End of bss segment      */

extern char kernel_virtual_start[];  /* Start of virtual memory          */
extern char kernel_physical_start[]; /* Start of physical memory         */
extern char kernel_virtual_end[];    /* End of virtual memory of kernel  */
extern char kernel_physical_end[];   /* End of physical memory of kernel */
