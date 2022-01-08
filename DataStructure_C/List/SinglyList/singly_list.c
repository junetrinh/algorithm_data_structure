#include "singly_list.h"

/*HELPER FUNCTION*********************************************************/
/* Allocate the node as well as referene the data inside the node
 */
singly_node_t* allocate_node(void* data){
    singly_node_t* node = (singly_node_t*) calloc(1, sizeof(*node));
    assert(node);

    return node;
}


singly_list_t* create_singly_list(){
    singly_list_t* list = (singly_list_t*) malloc(sizeof(*list));
    assert(list);

    list->head = list -> tail = NULL;
    list -> size = 0;

    return list;
}

void push_to_singly_list(void* data, singly_list_t* list){
    assert(list && data);

    // create a node to hold the data
    singly_node_t* node = allocate_node(data);

    // add the node to the list->

    // case first node in the list
    if(list -> size == 0 && list -> tail != NULL){
        list -> head = list -> tail = node;
        list -> size ++;
    }

    else {
       (list -> tail) -> next = node;
        list -> tail = node;
        list -> size ++;
    }
}

void add_by_index_singly_list(void* data, int index, singly_list_t* list){
    assert(data && index > 0);

    // if the index in larger than the current size, simply add to the tail of the list
    if(index >= list->size){
        push_to_singly_list(data, list);
    }

    else{
        // add the node
        singly_node_t* node = allocate_node(data);
        // loop til the index
        singly_node_t* precedesor = NULL;
        singly_node_t* cur = list->head;

        for(int i=0; i != index; i++ ){
            precedesor = cur;
            cur = cur -> next;
        }

        // perform add an insertion
        precedesor -> next = node;
        node-> next = cur;
        list -> size ++;
    }
};

void* pop_from_singly_list(singly_list_t* list){
    assert(list && list -> size > 0);

    singly_node_t* data = list -> head;

    //case where there are only 1 node in list
    if(list -> size == 1){
        list -> head = list -> tail = NULL;
    }
    else{
        list -> head = list -> head -> next;
    }

    list -> size --;

    return data;
}


void* remove_by_index_singly_list(int index, singly_list_t* list){
    assert(list && index > -2);

    // if index == -1 then remove the last item
    if(index == -1){
        index = list -> size;
    }

    // loop till reach the desired index;
    singly_node_t* precedesor = NULL;
    singly_node_t* cur = list-> head;

    for(int i = 0; i != index; i++){
        precedesor = cur;
        cur = cur -> next;
    }

    // perform extract the node
    void* data = cur -> data;
    precedesor -> next = cur -> next;
    list -> size --;

    // de-allocate the node;
    free(cur);
    cur = NULL;

    return data;
}

void clear_singly_list(singly_list_t* list){
    assert(list);
    
    list -> size = 0;

    singly_node_t* cur = list -> head;
    singly_node_t* delete;

    while(cur != NULL){
        delete = cur;
        cur = cur -> next;

        // de-allocate the delete node
        free(delete);    
    }

    list -> head = list -> tail = NULL;
}

void destroy_singly_list(singly_list_t** list){
    // clear the list
    clear_singly_list(*list);

    // de-allocate the list
    free(*list);
    *list = NULL;
}