#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/fs.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ARCOM teacher");
MODULE_DESCRIPTION("A Simple device driver");

static char msg[120];
static char* msgp;


int Major;

static int device_open(struct inode *inode, struct file *file)
{
    static int c = 0;
    printk( " Device opened %d times\n", c++ );
    return 0;
}
static int device_close(struct inode *inode, struct file *file)
{
     printk( " device closed.\n");
     return 0;
}

static ssize_t device_read(struct file *f, char *buf, size_t len, loff_t *off) 
{ 
    int bytes_read = 0;
    while ( len && *msgp ) {
	char c = *(msgp++);
	if ( c >= 'a' ) c -= 0x20;
	put_user( c, buf++);
	len--;
	bytes_read++;
    }

    return bytes_read;
}

static ssize_t device_write(struct file *f, const char*buf, size_t len, loff_t *off) {

    int bytes = 0;
    char *dest = msg;
    int max_size = 80;
    printk("    writing %ld bytes to position %lld\n", len, *off);
    while( len>0 && max_size>0 ) {
	get_user( *(dest++), buf++);
	len--;
	max_size--;
	bytes++;
    }
    *dest = 0;
    msgp = msg;
    return bytes;
}


static struct file_operations fops = {
	.open = device_open,
	.read = device_read,
	.write = device_write,
	.release = device_close
};

static int __init hello_init(void)
{
    printk(KERN_INFO "mymodule version 5 loaded!\n");

    Major = register_chrdev(0, "ARCOMdev", &fops);
    printk(KERN_INFO " My Major: %d\n", Major);
    sprintf(msg, "Original message.\n" );
    msgp = msg;
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
    unregister_chrdev(Major, "ARCOMdev");

}

module_init(hello_init);
module_exit(hello_cleanup);

