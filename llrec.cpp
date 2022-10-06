#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head == NULL){
		smaller = NULL;
		larger = NULL;
		return;
	}
	if(head->val>pivot){
		larger = head;
		Node* nextOne = head->next;
		llpivot(nextOne, smaller, larger->next, pivot);
	}
	else{
		smaller = head;
		Node* nextOne = head->next;
		llpivot(nextOne, smaller->next, larger, pivot);
	}
	head = NULL;
}

