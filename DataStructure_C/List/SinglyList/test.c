#include "singly_list.h"

int main(int argc, char** argv){
    printf("++++++Testing the singly list ____++++++++++++\n");
    // create a singly_list
    singly_list_t* list = create_singly_list();

    // add 10 number to list
    for(int i = 0; i < 10; i ++){
        // allocate the data for i
        int* num = (int*) malloc(sizeof(*num));
        assert(num);

        *num = i;
        printf("Number added to list is : %d  [size: %d]\n", i, list -> size );
        push_to_singly_list(num, list);
    }

    // test 1: check the data in the list
    while(list->size != 0){
        int* val = pop_from_singly_list(list);

        if(val){
            printf("The value just pop is : %d   [size: %d]\n", *((int*) val), list -> size );
            free(val);
        }else{
            printf("Got a invalid pop");
        }
    }

    destroy_singly_list(&list);
}