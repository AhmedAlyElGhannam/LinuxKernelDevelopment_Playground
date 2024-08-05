#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL"); // has to be specified to allow using GPL-licensed code in kernel
MODULE_AUTHOR("Nemesis"); // this is my gaming alias
MODULE_DESCRIPTION("A Module That Prints Hello"); // module description has to be clear and meme-free
MODULE_VERSION("1.0.0"); // module version based on development

// this function is executed upon module insertion into the kernel
static int __init hello_init(void)
{
    // printk not printf since this is executing in kernel space *PANIIIIK!*
    printk(KERN_INFO "Hello From The Kernel's Siiiiiiide!\n");
    return 0;
}

// this function is executed upon module removal from the kernel
static void __exit hello_exit(void)
{
    printk(KERN_INFO "A D I O S\n");
}

module_init(hello_init); // tells the kernel that this is the init function for this module
module_exit(hello_exit); // tells the kernel that this is the exit function for this module

