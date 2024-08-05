

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL"); // has to be specified to allow using GPL-licensed code in kernel
MODULE_AUTHOR("Nemesis"); // this is my gaming alias
MODULE_DESCRIPTION("A Simple Character Device Driver For Educational Purposes With No Memes!"); // module/driver description has to be clear and meme-free
MODULE_VERSION("1.0.0"); // module version based on development

static char ker_buf[100]; 

static int dev_open(struct inode* inode, struct file* file);
static ssize_t dev_read(struct file* file, char* buf, size_t len, loff_t* off);
static ssize_t dev_write(struct file* file, const char* buf, size_t len, loff_t* off);
static int dev_release(struct inode* inode, struct file* file);
static struct file_operations fops =
{
    .read = dev_read,
    .write = dev_write,
    .open = dev_open,
    .release = dev_release
};
 
// this function is executed upon module insertion into the kernel
static int __init rickroll_init(void)
{
    // the 90 here represents the major id that will be used later to link calls to this driver (I do not understand this well yet)
    int t = register_chrdev(90, "mydev", &fops); // registers this module as a char dev driver with major id 90
    if (t < 0)
    {
        printk(KERN_ERR "Character Device Did Not Register Successfully\n");
        return -EIO;
    }

    printk(KERN_INFO "Never gonna give you up\n");
    printk(KERN_INFO "Never gonna let you down\n");
    printk(KERN_INFO "Never gonna run around and desert you\n");
    printk(KERN_INFO "Never gonna make you cry\n");
    printk(KERN_INFO "Never gonna say goodbye\n");
    printk(KERN_INFO "Never gonna tell a lie and hurt you\n");

    return 0;
}

static int dev_open(struct inode* inode, struct file* file)
{
    printk(KERN_INFO "Device Opened\n");
    return 0;
}

static ssize_t dev_read(struct file* file, char* buf, size_t len, loff_t* off)
{
    if (*off >= sizeof(ker_buf))
        return 0;
    
    if (len > sizeof(ker_buf))
        len = sizeof(ker_buf);

    copy_to_user(buf, ker_buf, len);

    return len;
}
static ssize_t dev_write(struct file* file, const char* buf, size_t len, loff_t* off)
{
    if (len >= sizeof(ker_buf))
        return -EIO;

    memset(ker_buf, 0, sizeof(ker_buf));

    copy_from_user(ker_buf, buf, len);
    ker_buf[len] = 0;

    return len;
}

static int dev_release(struct inode* inode, struct file* file)
{
    printk(KERN_INFO "Device Closed\n");
    return 0;
}

// this function is executed upon module removal from the kernel
static void __exit rickroll_exit(void)
{
    unregister_chrdev(90, "mydev"); // unregisters this module and frees the major number

    printk(KERN_INFO "Bro you just posted cringe\n");
    printk(KERN_INFO "I am gonna make you die\n");
    printk(KERN_INFO "Say goodbye\n");
    printk(KERN_INFO "*CLICK*\n");
}

module_init(rickroll_init); // tells the kernel that this is the init function for this module
module_exit(rickroll_exit); // tells the kernel that this is the exit function for this module

