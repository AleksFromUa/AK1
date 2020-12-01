#include <linux/ktime.h>


struct my_list_head{
    struct my_list_head *next;
    ktime_t time_pre;
    ktime_t time_post;
};

int print_hello(uint n);