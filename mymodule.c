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
int init_module(void);
void cleanup_module(void);

#define SUCCESS 0


/* 
 * Global variables are declared as static, so are global within the file. 
 */
static struct timer_list my_timer;


void my_timer_func(struct timer_list * ptr)
{
	static int counter;
	printk(KERN_INFO "Timer func: %d\n", counter++);
	mod_timer(&my_timer, jiffies + SCAN_DELAY);
}



/*
 * This function is called when the module is loaded
 */
int __init init_module(void)
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
void __exit cleanup_module(void)
{
	/* 
	 * Unregister the timer 
	 */
	del_timer(&my_timer);
	printk(KERN_INFO "Timer Module unloaded.\n");
}

