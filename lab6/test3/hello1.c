#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

#include <linux/slab.h>

#include <hello1.h>


MODULE_AUTHOR("Pavlovets");
MODULE_DESCRIPTION("Hello1 component");
MODULE_LICENSE("Dual BSD/GPL");

static struct my_list_head *head;

int print_hello(uint n){
	
    uint i = 0;
    struct my_list_head *temp1;
    struct my_list_head *temp2;
    head = kmalloc(sizeof(struct my_list_head*), GFP_KERNEL);
    temp1 = head;

    for(i=0;i<n;i++){
        temp1->next = kmalloc(sizeof(struct my_list_head*), GFP_KERNEL);
        temp1->time_pre = ktime_get();
		pr_info("Hello world\n");
        temp1->time_post = ktime_get();
        temp2 = temp1;
        temp1 = temp1->next;
	}
    kfree(temp2->next);
    temp2->next = NULL;
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
    pr_info("Hello1_init started");
    return 0;
}

static void __exit hello1_exit(void)
{
    struct my_list_head* temp1 = head;
    struct my_list_head* temp2 = temp1;
    while(temp1 != NULL){
        pr_info("Printing time: %lld", temp1->time_post - temp1->time_pre);
        temp2 = temp1;
        temp1 = temp2->next;
        kfree(temp2);
    }
}

module_init(hello1_init);
module_exit(hello1_exit);
