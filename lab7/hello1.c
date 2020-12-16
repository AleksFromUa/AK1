// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>
#include <linux/slab.h>
#define DEBUG

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Hello1 Lab5");
MODULE_AUTHOR("Pavlovets");

static struct my_list_head *head;

void clear_my_list(void)
{
	struct my_list_head *temp_first;
	struct my_list_head *temp_second;

	temp_first = head;

	while (temp_first != NULL) {
		temp_second = temp_first->next;
		kfree(temp_first);
		temp_first = temp_second;
	}
}

int print_hello(uint iterations)
{
	int i;
	struct my_list_head *temp_head1;
	struct my_list_head *temp_head2;

	BUG_ON(iterations > 10);

	head = kmalloc(sizeof(struct my_list_head *), GFP_KERNEL);

	temp_head1 = head;

	if (iterations == 0) {
		pr_warn("WARNING\nvalue = 0\n");
		return 0;
	} else if (iterations >= 5) {
		pr_warn("WARNING\nvalue is in betwen 5 and 10\n");
	}

	for (i = 0; i < iterations; i++) {
		temp_head1->next = kmalloc(sizeof(struct my_list_head *)
		, GFP_KERNEL);
		if (i == 9)
			temp_head1 = NULL;

		temp_head1->time = ktime_get();
		pr_info("Hello, world\n");
		temp_head1->post_time = ktime_get();
		temp_head2 = temp_head1;
		temp_head1 = temp_head1->next;
	}
	kfree(temp_head2->next);
	temp_head2->next = NULL;

	return 0;
}
EXPORT_SYMBOL(print_hello);


static int __init hello1_init(void)
{
	pr_info("hello1 init");
	return 0;
}

static void __exit hello1_exit(void)
{
	struct my_list_head *temp_first = head;
	struct my_list_head *temp_second = temp_first;

	pr_debug("Print list start");
	while (temp_first != NULL) {
		pr_debug("Time spent %lld",
		temp_first->post_time - temp_first->time);

		temp_second = temp_first;
		temp_first = temp_second->next;
		kfree(temp_second);
	}
	pr_debug("Print list end");
	pr_info("hello1 exit");
}

module_init(hello1_init);
module_exit(hello1_exit);
