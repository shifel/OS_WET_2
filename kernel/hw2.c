#include <linux/kernel.h>
#include <linux/sched.h>

asmlinkage long sys_hello(void) {
    printk("Hello, World!\n");
    return 0;
}
asmlinkage long sys_set_status(int status){
    if(status != 0 && status != 1){
        return -EINVAL;
    }
    current->facultie = status;
    return 0;
}

asmlinkage long sys_get_status(void){
    return current->facultie;
}

asmlinkage long sys_register_process(void){
    printk("sys_register_process:: Started\n");
//    struct list_head* head = &current->important_list;
//    struct list_head* iter;
    int FUCK_THIS = 0;
    struct task_struct* entry;
    struct task_struct* init = find_task_by_vpid(1);
    printk("sys_register_process::init_pid == %d\n", init->pid);
    /*
    if(init->important_list == NULL){
        
        //init->important_list = &(init->this_head);
    }*/
    //printk("init->important_list: %p, init->important_list.next: %p, init->important_list.prev: %p", &init->important_list, init->important_list.next, init->important_list.prev);
    list_for_each_entry(entry, &(init->this_head), this_head){
        if (FUCK_THIS > 10){
            printk("sys_register_process:: FUCK\n");
            return -1;
        }
        
        if (entry->pid == current->pid){
            return 0;
        }
        printk("sys_register_process:: iteration %d\n", FUCK_THIS);
        FUCK_THIS++;
    }
    
    INIT_LIST_HEAD(&(current->this_head));
    list_add(&(current->this_head), &(init->this_head));
    printk("sys_register_process::pid == %d\n", current->pid);
//
    return 0;
}
asmlinkage long sys_get_all_cs(void){
    long sum = 0;
    struct list_head* iter;
    struct task_struct* entry;
    list_for_each_entry(entry, &(current->this_head), this_head){
        if (entry->facultie == 1){
            sum += entry->pid;
            printk("get_all_cs::CS_entry->pid == %d\n", entry->pid);
        }else{
            printk("get_all_cs::EE_entry->pid == %d\n", entry->pid);
        }
        
    }
    return sum;
}

