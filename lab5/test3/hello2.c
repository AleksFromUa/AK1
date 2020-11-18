#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>

MODULE_AUTHOR("Pavlovets");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint iterations = 1;
module_param(iterations, uint, S_IRUGO);
MODULE_PARM_DESC(iterations, "Number of iterations of printing hello world");

static int __init initter(void)
{
	uint i = 0;

	printk(KERN_INFO "iterations: %d\n", iterations);

	if(iterations == 0) {
		pr_warning(KERN_WARNING "WARNING, iterations is 0");
	}else if(iterations >=5 && iterations <= 10) {
		pr_warning(KERN_WARNING "WARNING, iterations is >=5 and <=10");
	} else if(iterations > 10) {
		pr_err(KERN_ERR "ERROR, iterations is >10");
		return -EINVAL;
	}
		print_hello(iterations);
		return 0;
}

static void __exit exitter(void)
{
/* Do nothing here right now */
}


module_init(initter);
module_exit(exitter);
