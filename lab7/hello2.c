// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause

#include <linux/init.h>
#include <linux/module.h>
#include <hello1.h>
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Hello2 Lab5");
MODULE_AUTHOR("Pavlovets");

static uint iterations = 1;
module_param(iterations, uint, 0444);

static int hello_init(void)
{
	return print_hello(iterations);
}

static void hello_exit(void)
{
	pr_alert("Kern_alert HELLO_EXIT,\n");
}

module_init(hello_init);
module_exit(hello_exit);
