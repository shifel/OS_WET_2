#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>


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
    //printk("sys_register_process:: =============== Started ===============\n");
//    struct list_head* head = &current->important_list;
//    struct list_head* iter;
    //int FUCK_THIS = 0;
    struct task_struct* entry = NULL;
    struct task_struct* init = find_task_by_vpid(1);
    
    
    if(init->important_list.next == NULL || init->important_list.prev == NULL){
        //printk("sys_register_process:: important_list == NULL\n");
        //init->important_list = (struct list_head*) kmalloc(sizeof(struct list_head), GFP_NOWAIT);
        INIT_LIST_HEAD(&init->important_list);
        
        INIT_LIST_HEAD(&(init->this_head));
        list_add(&(init->this_head), &(init->important_list));
        //init->important_list = &(init->this_head);
    }
    
    //printk("sys_register_process:: ========== INIT_INFO ==========\n");
    //printk("sys_register_process::init_pid == %d\n", init->pid);
    //printk("init->important_list: %p, init->important_list.next: %p, init->important_list.prev: %p\n", &(init->important_list), init->important_list.next, init->important_list.prev);
    //printk("init->this_head: %p, init->this_head.next: %p, init->this_head.prev: %p\n", &init->this_head, init->this_head.next, init->this_head.prev);
    //printk("sys_register_process:: ========== List_INFO ==========\n");
    list_for_each_entry(entry, &(init->important_list), this_head){
        //if (FUCK_THIS > 10){
            //printk("sys_register_process:: FUCK\n");
            //return 0;
        //}
        if (entry->pid == current->pid){
            return 0;
        }
        
        
        //printk("sys_register_process::entry_pid == %d\n", entry->pid);
        //printk("entry->important_list: %p, entry->important_list.next: %p, entry->important_list.prev: %p\n", &(entry->important_list), entry->important_list.next, entry->important_list.prev);
        //printk("entry(%d):: entry->this_head: %p, entry->this_head.next: %p, entry->this_head.prev: %p\n", entry->pid, &entry->this_head, entry->this_head.next, entry->this_head.prev);
        
        //printk("sys_register_process:: iteration %d\n", FUCK_THIS);
        //FUCK_THIS++;
    }
    
    INIT_LIST_HEAD(&(current->this_head));
    list_add(&(current->this_head), &(init->important_list));
    //printk("sys_register_process:: ========== current_INFO ==========\n");
    //printk("sys_register_process::pid == %d\n", current->pid);
    //printk("init->important_list: %p, init->important_list.next: %p, init->important_list.prev: %p\n", &(init->important_list), init->important_list.next, init->important_list.prev);
    //printk("current->this_head: %p, current->this_head.next: %p, current->this_head.prev: %p\n", &(current->this_head), current->this_head.next, current->this_head.prev);
    //printk("current->important_list: %p, current->important_list.next: %p, current->important_list.prev: %p\n", &(current->important_list), current->important_list.next, current->important_list.prev);

//
    //printk("sys_register_process:: =============== Ended ===============\n");
    return 0;
}
asmlinkage long sys_get_all_cs(void){
    //printk("sys_get_all_cs:: =============== Started ===============\n");
    int size = 0;
    long sum = 0;
    struct task_struct* init = find_task_by_vpid(1);
    struct task_struct* entry = NULL;
    
    list_for_each_entry(entry, &(init->important_list), this_head){
        //printk("entry(%d):: entry->this_head: %p, entry->this_head.next: %p, entry->this_head.prev: %p\n", entry->pid, &entry->this_head, entry->this_head.next, entry->this_head.prev);
        if (entry->pid != 1){
            size++;
        }
    }
    
    if (size < 1){
        return -ENODATA;
    }
    
    list_for_each_entry(entry, &(init->important_list), this_head){
        //printk("entry(%d):: entry->this_head: %p, entry->this_head.next: %p, entry->this_head.prev: %p\n", entry->pid, &entry->this_head, entry->this_head.next, entry->this_head.prev);
        
        if (entry->facultie == 1){
            sum += entry->pid;
            //printk("get_all_cs::CS_entry->pid == %d\n", entry->pid);
        }
        
    }
    //printk("sys_get_all_cs:: =============== Ended ===============\n");
    
    return sum;
}


