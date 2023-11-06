
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#define PROCFS_NAME "arcom"

static int hello_proc_show(struct seq_file *m, void *v) {
  seq_printf(m, "Hello proc from arcom!\n");
  return 0;
}

static int hello_proc_open(struct inode *inode, struct  file *file) {
  return single_open(file, hello_proc_show, NULL);
}

static const struct file_operations hello_proc_fops = {
  .owner = THIS_MODULE,
  .open = hello_proc_open,
  .read = seq_read,
  .llseek = seq_lseek,
  .release = single_release,
};

static int __init hello_proc_init(void) {
  struct proc_dir_entry *myproc = proc_create(PROCFS_NAME, 0, NULL, &hello_proc_fops);
  if ( myproc==NULL ) {
    printk(KERN_ERR "Could not create proc entry '%s'\n", PROCFS_NAME);
    return -ENOMEM;
  }
  printk(KERN_INFO "Proc entry '%s' created\n", PROCFS_NAME);
  return 0;
}

static void __exit hello_proc_exit(void) {
  remove_proc_entry(PROCFS_NAME, NULL);
  printk(KERN_INFO "Proc entry '%s' removed\n", PROCFS_NAME);
}

MODULE_LICENSE("GPL");
module_init(hello_proc_init);
module_exit(hello_proc_exit);

