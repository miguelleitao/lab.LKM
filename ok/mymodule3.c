#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/fs.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ARCOM teacher");
MODULE_DESCRIPTION("A Simple char device driver. No reads, no writes.");

static long int naluno = 0;
static char *disc = "ISEP";

module_param(naluno, long, 0);
module_param(disc, charp, 0);

MODULE_PARM_DESC(naluno, "O numero do aluno");
MODULE_PARM_DESC(disc, "A disciplina do aluno");

int Major;

static int device_open(struct inode *inode, struct file *file)
{
  static int c = 0;
  printk( " counter=%d\n", c++ );
  return 0;
}
static int device_close(struct inode *inode, struct file *file)
{
 printk( "device closed.\n");
 return 0;
}

static ssize_t device_read(struct file *f, char*buf, size_t len, loff_t *off) { return 0;}

static ssize_t device_write(struct file *f, const char*buf, size_t len, loff_t *off) {return 0;}


static struct file_operations fops = {
	.open = device_open,
	.read = device_read,
	.write = device_write,
	.release = device_close
};


static int __init hello_init(void)
{
    printk(KERN_INFO "mymodule version 3 loaded!\n");
    printk(KERN_INFO "Modulo carregado pelo aluno %ld de %s\n",naluno,disc);

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

