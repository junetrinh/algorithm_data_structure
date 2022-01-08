#include "singly_list.h"

int main(int argc, char** argv){
    printf("++++++Testing the singly list ____++++++++++++");
    // create a singly_list
    singly_list_t* list = create_singly_list();

    // add 10 number to list
    for(int i = 0; i < 10; i ++){
        // allocate the data for i
        int* num = (int*) malloc(sizeof(int));
        assert(num);

        *num = i;

        push_to_singly_list(num, list);
    }

    // test 1: check the data in the list
    if(list -> size != 10){
        printf("a");
    }
}