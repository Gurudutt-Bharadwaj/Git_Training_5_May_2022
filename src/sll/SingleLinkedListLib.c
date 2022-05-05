/* Author: Gurudutt S Bharadwaj */
/* LibSingleLinkedList.c */
/* Library file where there are functions regarding Single Linked List. */

#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"


/**
 * Function to insert a node in the beginning of the linked list.
 *
 * /param	HeadNode_ppst	Address of the pointer holding the first node
 *							of the list. In case this function updates the
 *							list such that the first element is altered, then
 *							this parameter shall be updated with the new node
 *							address.
 *
 * /param	Data_s32		Data of the new node
 *
 * /return 	LIST_OPS_SUCCESS - If adding a node in the beginning was successful.
 * 			LIST_OPS_FAILURE - If adding a node in the beginning was a failure.
 * 			MEMORY_ALLOC_FAILED	 - If dynamic memory allocation failed.	
 */

Std_ReturnType Sll_InsertFront(Sll_ListParams_tst * ListParams_pst, sint32 Data_s32)
{
	Sll_Node_tpst NewNode_pst = NULL;
	Std_ReturnType RetVal_s8 = LIST_OPS_FAILURE;

	/* Allocate memory for the node to be inserted. */
	NewNode_pst = (Sll_Node_tpst) malloc(sizeof(Sll_Node_tst));
	
	/* Check if memory allocation was successful. */
	if(NewNode_pst == NULL)
	{
		printf("Dynamic memory allocation failed.\n");
		RetVal_s8 = MEMORY_ALLOC_FAILED;
	}
	
	else
	{
		NewNode_pst->NodeData_s32 = Data_s32;
		
		/* Check if there is no head node at all and whether this insertion
		 * shall be the first node of the list.
		 */
		if(ListParams_pst->Sll_HeadNode_pst == NULL)
		{
			/* Inserting the head element of the list. */
			NewNode_pst->NextNode_pst = NULL;
		}
		
		else
		{
			/* This new insertion shall not be the first node of the list and
			 * there already exists at least one node in the list.
			 */
			NewNode_pst->NextNode_pst = ListParams_pst->Sll_HeadNode_pst;
		}
		
		/* Update the head node of the list. */
		ListParams_pst->Sll_HeadNode_pst = NewNode_pst;
		
		/* Increment the node counter. */
		ListParams_pst->Sll_ListCurrSize_u32++;

		RetVal_s8 = LIST_OPS_SUCCESS;
	}

	return RetVal_s8;
}

/**
 * Function to insert a node at the rear end of the single linked list.
 * 
 * /param	head	Address of the pointer holding the first node of the list.
 * 					In case this function updates the list such that the first element is altered,
 * 					then this parameter shall be updated with the new node address.
 *
 * /param	data	Data of the new node
 *
 * /return 	LIST_OPS_SUCCESS - If adding a node in the beginning was successful.
 * 			LIST_OPS_FAILURE - If adding a node in the beginning was a failure.
 * 			MEMORY_ALLOC_FAILED	 - If dynamic memory allocation failed.	
 */

Std_ReturnType Sll_InsertRear(Sll_ListParams_tst * ListParams_pst, sint32 Data_s32)
{
	Sll_Node_tpst NewNode_pst = NULL;
	Sll_Node_tpst TraverseNode_pst = NULL;
	
	Std_ReturnType RetVal_s8 = LIST_OPS_FAILURE;

	NewNode_pst = (Sll_Node_tpst) malloc(sizeof(Sll_Node_tst));
	if(NewNode_pst == NULL)
	{
		printf("Dynamic memory allocation failed.\n");
		RetVal_s8 = MEMORY_ALLOC_FAILED;
	}
	
	else
	{
		/* Copy the data onto the new node. */
		NewNode_pst->NodeData_s32 = Data_s32;

		/* Update the link of the new node with NULL pointer. */
		NewNode_pst->NextNode_pst = NULL;

		/* Check if the list is empty. If so, then add the current node as the first node. */
		if(ListParams_pst->Sll_HeadNode_pst == NULL)
		{
			printf("List is empty. Adding the first node.\n");
			ListParams_pst->Sll_HeadNode_pst = NewNode_pst;
		}

		/* List is not empty. Thus traverse the list until the last node is reached. Then insert the new node. */
		else
		{
			TraverseNode_pst = ListParams_pst->Sll_HeadNode_pst;

			/* Traverse the list until the last node is found. */
			while(TraverseNode_pst->NextNode_pst != NULL)
			{
				TraverseNode_pst = TraverseNode_pst->NextNode_pst;
			}

			/* Link the current last node with this new node. */
			TraverseNode_pst->NextNode_pst = NewNode_pst;
		}
		
		/* Increment the node counter. */
		ListParams_pst->Sll_ListCurrSize_u32++;
		
		RetVal_s8 = LIST_OPS_SUCCESS;
	}

	return RetVal_s8;
}

/**
 * Function to delete the first node (otherwise called the head node) of a list.
 * 
 * /param	head	Address of the pointer holding the first node of the list.
 * 					In case this function updates the list such that the first element is altered,
 * 					then this parameter shall be updated with the new node address.
 *
 * /return 	LIST_OPS_SUCCESS - If adding a node in the beginning was successful.
 * 			LIST_OPS_FAILURE - If adding a node in the beginning was a failure.
 * 			MEMORY_ALLOC_FAILED	 - If dynamic memory allocation failed.	
 */

Std_ReturnType Sll_DeleteFront(Sll_ListParams_tst * ListParams_pst)
{
	Sll_Node_tpst TempNode_pst = NULL;
	Std_ReturnType RetVal_s8 = LIST_OPS_FAILURE;

	/* Check if the list is empty. */
	if(ListParams_pst->Sll_HeadNode_pst == NULL)
	{
		printf("List is empty. Nothing to delete.\n");
		RetVal_s8 = LIST_OPS_FAILURE;
	}

	/* List is not empty. Delete the first node. */
	/* This case is also valid when there is only one node. */
	else
	{
		/* Backup the link of the first node. */
		TempNode_pst = ListParams_pst->Sll_HeadNode_pst->NextNode_pst;

		/* Free memory of the first node. */
		free(ListParams_pst->Sll_HeadNode_pst);

		/* The second node is now the head node. */
		ListParams_pst->Sll_HeadNode_pst = TempNode_pst;
		
		/* Decrement the node counter. */
		ListParams_pst->Sll_ListCurrSize_u32--;

		RetVal_s8 = LIST_OPS_SUCCESS;
	}	

	return RetVal_s8;
}

/**
 * Function to delete the last node of the list.
 * 
 * /param	head	Address of the pointer holding the first node of the list.
 * 					In case this function updates the list such that the first element is altered,
 * 					then this parameter shall be updated with the new node address.
 *
 * /return 	LIST_OPS_SUCCESS - If adding a node in the beginning was successful.
 * 			LIST_OPS_FAILURE - If adding a node in the beginning was a failure.
 * 			MEMORY_ALLOC_FAILED	 - If dynamic memory allocation failed.	
 */

Std_ReturnType Sll_DeleteRear(Sll_ListParams_tst * ListParams_pst)
{
	Sll_Node_tpst CurrNode_pst = NULL;
	Sll_Node_tpst PrevNode_pst = NULL;

	Std_ReturnType RetVal_s8 = LIST_OPS_FAILURE;

	/* Check if the list is empty. */
	if(ListParams_pst->Sll_HeadNode_pst == NULL)
	{
		printf("List is empty. Nothing to delete.\n");
		RetVal_s8 = LIST_OPS_FAILURE;
	}

	/* Check if there is only one node in the list. */
	else if(ListParams_pst->Sll_HeadNode_pst->NextNode_pst == NULL)
	{
		free(ListParams_pst->Sll_HeadNode_pst);
		
		ListParams_pst->Sll_HeadNode_pst = NULL;
		
		/* Decrement the node counter. */
		ListParams_pst->Sll_ListCurrSize_u32--;
	
		RetVal_s8 = LIST_OPS_SUCCESS;
	}

	/* There are multiple nodes in the list. Delete the last node. */
	else
	{
		CurrNode_pst = ListParams_pst->Sll_HeadNode_pst;

		/* Traverse the list until the last node is found. */
		while(CurrNode_pst->NextNode_pst != NULL)
		{
			PrevNode_pst = CurrNode_pst;
			CurrNode_pst = CurrNode_pst->NextNode_pst;
		}

		/* The end of the list has been reached. */
		PrevNode_pst->NextNode_pst = NULL;
		free(CurrNode_pst);
		
		/* Decrement the node counter. */
		ListParams_pst->Sll_ListCurrSize_u32--;
	
		RetVal_s8 = LIST_OPS_SUCCESS;
	}

	return RetVal_s8;
}
 
/**
 *	Function to insert a node after the node specified by 'Position_u32' argument.
 *
 *	\param		ListParams_pst		Pointer to the structure holding the properties
 *									of the Linked list
 *
 *	\param		Position_u32		The number of the node starting from the first
 *									node after which the new node has to be placed.
 *									Note: The first node in the list has the number 1.
 *
 *	\param		Data_s32			The data that shall be associated with the new
 *									node
 *
 *	\return		LIST_OPS_FAILURE	Inserting the specified node was a failure due to
 *									one among the following reasons:
 *									- The first node of the specified Linked list was
 *									  NULL
 *									- The Position parameter specified was equal to 0
 *									- The Position argument was greater that the
 *									  current length of the specified Linked List.
 *
 *				MEMORY_ALLOC_FAILED	If dynamic memory allocation failed.	
 *
 *				LIST_OPS_SUCCESS	Inserting the node at the specified position was a
 *									success
 */

Std_ReturnType Sll_InsertSpecPos(Sll_ListParams_tst * ListParams_pst, uint32 Position_u32, sint32 Data_s32)
{
	Sll_Node_tpst CurrNode_pst = NULL;
	Sll_Node_tpst PrevNode_pst = NULL;
	
	Sll_Node_tpst NewNode_pst = NULL;
	
	Std_ReturnType RetVal_s8 = LIST_OPS_FAILURE;

	/* Holds the count value of the number of nodes traversed. */
	uint32 TravCnt_u32 = 0;
	
	/* Check if the list is empty and the position is not equal to 1. */
	if(ListParams_pst->Sll_HeadNode_pst == NULL)
	{
		printf("The referenced Linked List is empty. Please re-consider the arguments. Quitting the function !!!\n");
	}

	/* Check if the position is beyond the current length of the List. */	
	else if(Position_u32 > ListParams_pst->Sll_ListCurrSize_u32)
	{
		printf("The position specified is greater than the length of the linked list. Please re-consider the arguments. Quitting the function. \n");
	}

	/* Position is within the length of the linked list. */
	else
	{
		NewNode_pst = (Sll_Node_tpst) malloc(sizeof(Sll_Node_tst));

		if(NewNode_pst == NULL)
		{
			printf("Dynamic memory allocation failed.\n");
			RetVal_s8 = MEMORY_ALLOC_FAILED;
		}

		else
		{
			/* Copy the data onto the new node. */
			NewNode_pst->NodeData_s32 = Data_s32;
			
			/* Check if the request was to insert at the beginning of the list. */
			if(Position_u32 == 0u)
			{
				NewNode_pst->NextNode_pst = ListParams_pst->Sll_HeadNode_pst;
				
				/* Update the head node. */
				ListParams_pst->Sll_HeadNode_pst = NewNode_pst;
			}

			else
			{
				CurrNode_pst = ListParams_pst->Sll_HeadNode_pst;

				/* Traverse until either the count becomes equal to the position value OR the list reaches an end. */
				for(TravCnt_u32 = 0u; TravCnt_u32 < Position_u32; TravCnt_u32++)
				{
					PrevNode_pst = CurrNode_pst;
					CurrNode_pst = CurrNode_pst->NextNode_pst;
				}

				PrevNode_pst->NextNode_pst = NewNode_pst;
				NewNode_pst->NextNode_pst = CurrNode_pst;
			}
			
			/* Increment the node counter. */
			ListParams_pst->Sll_ListCurrSize_u32++;
				
			RetVal_s8 = LIST_OPS_SUCCESS;
		}
	}
	
	return RetVal_s8;
}

/**
 *	This function deletes the node whose number with reference to the head of the
 *	of the is specified by the argument 'Position_u32'.
 *
 *	\param		ListParams_pst		Pointer to the structure holding the properties
 *									of the Linked list
 *
 *	\param		Position_u32		The number of the node which has to be deleted.
 *									Note: The first node in the list has the number 1.
 *
 *	\return		LIST_OPS_FAILURE	Deleting the specified node was a failure due to
 *									one among the following reasons:
 *									- The head node of the specified Linked list was
 *									  NULL
 *									- The Position parameter specified was equal to 0
 *									- The Position argument was greater that the
 *									  current length of the specified Linked List.
 *
 *				
 *				LIST_OPS_SUCCESS	Deleting the specified node was a success
 */

Std_ReturnType Sll_DeleteSpecPos(Sll_ListParams_tst * ListParams_pst, uint32 Position_u32)
{
	Sll_Node_tpst CurrNode_pst = NULL;
	Sll_Node_tpst PrevNode_pst = NULL;
	
	Std_ReturnType RetVal_s8 = LIST_OPS_FAILURE;
	
	/* Holds the count value of the number of nodes traversed. */
	uint32 TravCnt_u32 = 0;
	
	/* Check if the list is empty and the position is not equal to 1. */
	if(ListParams_pst->Sll_HeadNode_pst == NULL)
	{
		printf("The referenced Linked List is empty. Please re-consider the arguments. Quitting the function !!!\n");
	}
	
	else if(Position_u32 == 0u)
	{
		printf("The position specified is zero. Please re-consider the arguments. Quitting the function !!!\n");
	}

	/* Check if the position is beyond the current length of the List. */	
	else if(Position_u32 > ListParams_pst->Sll_ListCurrSize_u32)
	{
		printf("The position specified is greater than the length of the linked list. Please re-consider the arguments. Quitting the function. \n");
	}
	
	/* Position is within the length of the linked list. */
	else
	{
		/* Start the traverse from the head node. */
		CurrNode_pst = ListParams_pst->Sll_HeadNode_pst;
		
		/* Here the loop runs for one unit lesser than the value in 'Position_u32'.
		 * This is done so that at the end of the loop, the Current Node pointer
		 * points to the node to be deleted.
		 */
		for(TravCnt_u32 = 0u; TravCnt_u32 < (Position_u32 - 1); TravCnt_u32++)
		{
			PrevNode_pst = CurrNode_pst;
			CurrNode_pst = CurrNode_pst->NextNode_pst;
		}
		
		/* Assign the link of the node to he deleted to the previous node. */
		PrevNode_pst->NextNode_pst = CurrNode_pst->NextNode_pst;
		
		free(CurrNode_pst);
		
		/* Decrement the node counter. */
		ListParams_pst->Sll_ListCurrSize_u32--;
		
		RetVal_s8 = LIST_OPS_SUCCESS;
	}
	
	return RetVal_s8;
}

/**
 *	This function displays the contents of all the nodes of the list.
 *
 *	\param		ListParams_pst		Pointer to the structure holding the properties
 *									of the Linked list
 *
 *	\return		LIST_OPS_FAILURE	Displaying all the node contents was a failure
 *									due to the following reason:
 *									- The head node of the specified Linked list was
 *									  NULL
 *				
 *				LIST_OPS_SUCCESS	Displaying all the node contents was a success
 */

Std_ReturnType Sll_DisplayListData(Sll_ListParams_tst * ListParams_pst)
{
	/* Pointer to traverse the node. */
	Sll_Node_tpst TravNode_pst = NULL;
	
	/* Holds the count value of the number of nodes traversed. */
	uint32 TravCnt_u32 = 0;
	
	/* Return value. */
	Std_ReturnType RetVal_s8 = LIST_OPS_FAILURE;
	
	/* Check if the first node is not equal to NULL. */
	if(ListParams_pst->Sll_HeadNode_pst == NULL)
	{
		printf("The specified list is empty. Please provide valid list parameters.\n");
	}

	else
	{
		printf("\nDisplaying list contents:\n\n");

		TravNode_pst = ListParams_pst->Sll_HeadNode_pst;

		for(TravCnt_u32 = 0u; TravCnt_u32 < ListParams_pst->Sll_ListCurrSize_u32; TravCnt_u32++)
		{
			printf("Data in Node %d: %d\n", TravCnt_u32 + 1, TravNode_pst->NodeData_s32);
			TravNode_pst = TravNode_pst->NextNode_pst;
		}
		
		RetVal_s8 = LIST_OPS_SUCCESS;
	}

	return RetVal_s8;
}


