/* Author: Gurudutt S Bharadwaj */
/* DoubleLinkedListLib.c */
/* Library file where there are functions regarding Double Linked Lists. */

#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

/**
 * Function to insert a node in the beginning of the double linked list.
 *
 * /param   ListParams_pst  Pointer to the structure containing the parameters
 *                          related to the Double Linked list.
 *
 * /param   Data_s32        Data of the new node
 *
 * /return  LIST_OPS_SUCCESS - If adding a node in the beginning was successful.
 *          LIST_OPS_FAILURE - If adding a node in the beginning was a failure.
 *          MEMORY_ALLOC_FAILED  - If dynamic memory allocation failed.
 */

Std_ReturnType Dll_InsertFront(Dll_ListParams_tst * ListParams_pst, sint32 Data_s32)
{
    Dll_Node_tpst NewNode_pst = NULL;
    Std_ReturnType RetVal_s8 = LIST_OPS_FAILURE;

    /* Allocate memory for the node to be inserted. */
    NewNode_pst = (Dll_Node_tpst) malloc(sizeof(Dll_Node_tst));

    /* Check if memory allocation was successful. */
    if(NewNode_pst == NULL)
    {
        printf("Dynamic memory allocation failed.\n");
        RetVal_s8 = MEMORY_ALLOC_FAILED;
    }

    else
    {
        NewNode_pst->NodeData_s32 = Data_s32;
        NewNode_pst->PrevNode_pst = NULL;
        NewNode_pst->NextNode_pst = ListParams_pst->Dll_HeadNode_pst;

        /* Update the head node of the list. */
        ListParams_pst->Dll_HeadNode_pst = NewNode_pst;

        /* If the tail node is NULL, then it also means that the head node is NULL and the list is empty. */
        if(ListParams_pst->Dll_TailNode_pst == NULL)
        {
            /* Update the tail node of the list. */
            ListParams_pst->Dll_TailNode_pst = NewNode_pst;
        }

        /* Increment the node counter. */
        ListParams_pst->Dll_ListCurrSize_u32++;

        RetVal_s8 = LIST_OPS_SUCCESS;
    }

    return RetVal_s8;
}

/**
 * Function to insert a node at the rear end of the single linked list.
 *
 * /param   ListParams_pst    Pointer to the structure containing the parameters
 *                            related to the Double Linked list.
 *
 * /param   Data_s32          Data of the new node
 *
 * /return  LIST_OPS_SUCCESS - If adding a node in the beginning was successful.
 *          LIST_OPS_FAILURE - If adding a node in the beginning was a failure.
 *          MEMORY_ALLOC_FAILED  - If dynamic memory allocation failed.
 */

Std_ReturnType Dll_InsertRear(Dll_ListParams_tst * ListParams_pst, sint32 Data_s32)
{
    Dll_Node_tpst NewNode_pst = NULL;
    Dll_Node_tpst RearNode_pst = NULL;

    Std_ReturnType RetVal_s8 = LIST_OPS_FAILURE;

    NewNode_pst = (Dll_Node_tpst) malloc(sizeof(Dll_Node_tst));
    if(NewNode_pst == NULL)
    {
        printf("Dynamic memory allocation failed.\n");
        RetVal_s8 = MEMORY_ALLOC_FAILED;
    }

    else
    {
        RearNode_pst = ListParams_pst->Dll_TailNode_pst;

        /* Copy the data onto the new node. */
        NewNode_pst->NodeData_s32 = Data_s32;

        /* Update the previous and next node links. */
        NewNode_pst->PrevNode_pst = RearNode_pst;
        NewNode_pst->NextNode_pst = NULL;

        if(ListParams_pst->Dll_TailNode_pst != NULL)
        {
            /* Update the next node link of the tail node only if the tail node is present (not NULL) */
            RearNode_pst->NextNode_pst = NewNode_pst;
        }

        else
        {
            /* The tail node is NULL which means the head node is also NULL and the list is empty. */
            ListParams_pst->Dll_HeadNode_pst = NewNode_pst;
        }

        /* Updating the tail node is a mandatory step irrespective whether the list is empty or not. */
        ListParams_pst->Dll_TailNode_pst = NewNode_pst;

        /* Increment the node counter. */
        ListParams_pst->Dll_ListCurrSize_u32++;

        RetVal_s8 = LIST_OPS_SUCCESS;
    }

    return RetVal_s8;
}
