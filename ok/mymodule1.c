#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ARCOM teacher");
MODULE_DESCRIPTION("A Simple Hello World module");

static long int num_aluno = 0;
static char *disc = "ISEP";

module_param(num_aluno, long, S_IRUSR);
MODULE_PARM_DESC(num_aluno, "o numero do aluno");
module_param(disc, charp, 0);
MODULE_PARM_DESC(disc, "O nome da disciplina");


static int __init hello_init(void)
{
    printk(KERN_INFO "Hello world!\n");
    printk(KERN_INFO "Modulo compilado pelo aluno %ld de %s\n", num_aluno, disc);
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

