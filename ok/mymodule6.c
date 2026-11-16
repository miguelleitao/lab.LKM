/*
 *  mymodule6.c: Creates a kernel module with a timer 
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/timer.h>

#define SCAN_DELAY   		HZ/2

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Malta de ARCOM");
MODULE_DESCRIPTION("Timer in kernel module example");
MODULE_VERSION("v6.2.1");

/*  
 *  Prototypes
 */
//static int __init init_module(void);
//static void __exit cleanup_module(void);

#define SUCCESS 0


/* 
 * Global variables are declared as static, so are global within the file. 
 */
static struct timer_list my_timer;


static void my_timer_func(struct timer_list * ptr)
{
	static int counter;
	printk(KERN_INFO "Timer func: %d\n", counter++);
	mod_timer(&my_timer, jiffies + SCAN_DELAY);
}



/*
 * This function is called when the module is loaded
 */
static int __init my_init(void)
{
 	printk(KERN_INFO "Loading Timer module\n");

	/*
	 * Set up the timer for the first time
	 */
        timer_setup(&my_timer, my_timer_func, 0);
        mod_timer(&my_timer, jiffies + SCAN_DELAY);

	return SUCCESS;
}

/*
 * This function is called when the module is unloaded
 */
static void __exit my_exit(void)
{
	/* 
	 * Unregister the timer 
	 */
	//del_timer(&my_timer);
	timer_shutdown_sync(&my_timer);
	printk(KERN_INFO "Timer Module unloaded.\n");
}

module_init(my_init);
module_exit(my_exit);
