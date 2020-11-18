#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>

MODULE_AUTHOR("Pavlovets");
MODULE_DESCRIPTION("Hello1 component");
MODULE_LICENSE("Dual BSD/GPL");


static void print_hello(uint n){
	uint i = 0;
    for(i=0;i<n;i++){
		pr_info("Hello world\n");
	}
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
    pr_info("Hello1_init started");
    return 0;
}

static void __exit hello1_exit(void)
{
    
}

module_init(hello1_init);
module_exit(hello1_exit);
