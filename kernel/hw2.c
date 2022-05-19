#include <linux/kernel.h>
#include <linux/sched.h>

asmlinkage long sys_hello(void) {
 printk("Hello, World!\n");
 return 0;
}
asmlinkage int sys_set_status(int status){
    if(status != 0 && status != 1){
        return -EINVAL;
    }
    current->facultie = status;
    return 0;
}

asmlinkage int sys_get_status(void){
    return current->facultie;
}