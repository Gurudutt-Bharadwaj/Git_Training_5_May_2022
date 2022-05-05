#ifndef __SINGLE_LINKED_LIST__
#define __SINGLE_LINKED_LIST__

#include "Deftypes.h"

/**
 * Structure for a single linked list.
 */
struct Sll_Node_st
{
	sint32 NodeData_s32;
	struct Sll_Node_st * NextNode_pst;
};

typedef struct Sll_Node_st Sll_Node_tst;
typedef Sll_Node_tst * Sll_Node_tpst; 

/**
 * Structure that holds the List parameters.
 */
typedef struct
{
	/* Pointer to the Head Node structure */
	Sll_Node_tpst Sll_HeadNode_pst;
	
	/* Holds the number of nodes in the singly-linked list. */
	uint32 Sll_ListCurrSize_u32;
	
} Sll_ListParams_tst;

#define LIST_OPS_SUCCESS		(1)
#define LIST_OPS_FAILURE		(0)
#define MEMORY_ALLOC_FAILED		(-1)

Std_ReturnType Sll_InsertFront(Sll_ListParams_tst * ListParams_pst, sint32 Data_s32);
Std_ReturnType Sll_InsertRear(Sll_ListParams_tst * ListParams_pst, sint32 Data_s32);
Std_ReturnType Sll_DeleteFront(Sll_ListParams_tst * ListParams_pst);
Std_ReturnType Sll_DeleteRear(Sll_ListParams_tst * ListParams_pst);
Std_ReturnType Sll_InsertSpecPos(Sll_ListParams_tst * ListParams_pst, uint32 Position_u32, sint32 Data_s32);
Std_ReturnType Sll_DeleteSpecPos(Sll_ListParams_tst * ListParams_pst, uint32 Position_u32);
Std_ReturnType Sll_DisplayListData(Sll_ListParams_tst * ListParams_pst);

#endif
