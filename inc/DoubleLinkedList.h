/*
 * DoubleLinkedList.h
 *
 *  Created on: Oct 11, 2019
 *      Author: HGB5KOR
 */

#ifndef SRC_DOUBLELINKEDLIST_H_
#define SRC_DOUBLELINKEDLIST_H_

#include "Deftypes.h"

/**
 * Structure for a Node ins Dingle linked list.
 */
struct Dll_Node_st
{
    sint32 NodeData_s32;
    struct Dll_Node_st * PrevNode_pst;
    struct Dll_Node_st * NextNode_pst;
};

typedef struct Dll_Node_st Dll_Node_tst;
typedef Dll_Node_tst * Dll_Node_tpst;

/**
 * Structure that holds the List parameters.
 */
typedef struct
{
    /* Pointer to the Head Node structure */
    Dll_Node_tpst Dll_HeadNode_pst;

    /* Pointer to the Tail Node structure */
    Dll_Node_tpst Dll_TailNode_pst;

    /* Holds the number of nodes in the doubly-linked list. */
    uint32 Dll_ListCurrSize_u32;

} Dll_ListParams_tst;

#define LIST_OPS_SUCCESS        (1)
#define LIST_OPS_FAILURE        (0)
#define MEMORY_ALLOC_FAILED     (-1)

#endif /* SRC_DOUBLELINKEDLIST_H_ */
