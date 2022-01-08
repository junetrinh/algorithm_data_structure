/* Singly list:
    -> List that is made up of node that only has preference of its precedesor.
    -> The List structure have head and an optional tail.

    Performence:
        -> search: O(n)
        -> Add: O(n) -> search for position to add + O(1) -> adding.
        -> remove: O(n) -> search for position to remove + O(1) -> to remove
        -> sort: depend on the algorithm
*/

/* Author: Xuan (June) 29-Dec-2021
*/

#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


struct singly_node{
    void* data;
    struct singly_node* next;
} ;
typedef struct singly_node singly_node_t;

typedef struct {
    singly_node_t* head;
    singly_node_t* tail;
    int size;
} singly_list_t;

/* Allocate a singly_list and return to user
*/
singly_list_t* create_singly_list();

/* Add to the end of singly list
 */
void push_to_singly_list(void* data, singly_list_t* list);

/* Add to the list at indicated index
 */
void add_by_index_singly_list(void* data, int index, singly_list_t* list);

/* remove the first item from the singly_list and return that value
 */
void* pop_from_singly_list(singly_list_t* list);

/* Remove the data store at the index from the singly list and return that value
 */
void* remove_by_index_singly_list(int index, singly_list_t* list);


/* Remove and deallocate each node in the list
 */
void clear_singly_list(singly_list_t* list);

/* Clear and deallocate the singly list
 */ 
void destroy_singly_list(singly_list_t** list);


#endif