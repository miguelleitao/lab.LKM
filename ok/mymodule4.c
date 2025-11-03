#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/fs.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ARCOM teacher");
MODULE_DESCRIPTION("A Simple char device driver");

static char msg[120];
static char* msgp;

int Major;

static int device_open(struct inode *inode, struct file *file)
{
  static int c = 0;
  printk( " counter=%d\n", c++ );
  sprintf(msg, "mensagem %d criada pelo modulo.\n", c);
  msgp = msg;
  return 0;
}
static int device_close(struct inode *inode, struct file *file)
{
 printk( "device closed.\n");
 return 0;
}

static ssize_t device_read(struct file *f, char *buf, size_t len, loff_t *off) 
{ 
    int bytes_read = 0;
    
    //if ( !msgp ) return 0;

    while ( len && *msgp ) {
	put_user( *(msgp++), buf++);
	len--;
	bytes_read++;
    }

    return bytes_read;
}


static struct file_operations fops = {
	.open = device_open,
	.read = device_read,
	.release = device_close
};


static int __init hello_init(void)
{
    printk(KERN_INFO "mymodule version 4 loaded!\n");

    Major = register_chrdev(0, "ARCOMdev", &fops);
    printk(KERN_INFO " O meu Major: %d\n", Major);

    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
    unregister_chrdev(Major, "ARCOMdev");

}

module_init(hello_init);
module_exit(hello_cleanup);

