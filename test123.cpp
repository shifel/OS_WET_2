#include<linux/list.h>
#include "stdio.h"

int main(){
    struct list_head important = LIST_HEAD_INIT(important);
    struct abc {
        struct list_head node;
        int num;
    };
    struct abc A;
    A.num = 1;
    struct abc B;
    B.num = 1;
    struct abc C;
    C.num = 1;
    
    list_add(&(A.node), &(important.node));
    list_add(&(B.node), &(important.node));
    list_add(&(C.node), &(important.node));
    
    struct abc* entry;
    printf("iteration:: &important == %p\n", important);
    list_for_each_entry(entry, &(important), node){
//        if (entry->pid == current->pid){
//            return 0;
//        }
        printf("iteration:: node->num == %d\n", entry->num);
        printf("iteration:: node->prev == %p\n", entry->node->prev);
        printf("iteration:: node->next == %p\n", entry->node->next);
    }
////
    return 0;
}