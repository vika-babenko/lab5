#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include <linux/errno.h>

MODULE_AUTHOR("Dmytro Tymochko <dima.tymochko@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint howmany = 1;
module_param(howmany, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(howmany, "A parameter that determines how many times the message will be displayed. Accepts values from 0-10.");

static int __init hello_init(void)
{
	int i;

	if (howmany == 0) {
		printk(KERN_WARNING "Be careful, the value is so small!!!\n");
	}
	else if (howmany > 5 && howmany <= 10) {
		printk(KERN_WARNING "Be careful, the value is midle!\n");
	} 
	else if (howmany > 10) {
		printk(KERN_ERR "Value is not correct!\n");
		return -EINVAL;
	} 
	for (i = 0; i < howmany; i++) {
		printk(KERN_EMERG "Hello, world!\n");
	}
	
	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
