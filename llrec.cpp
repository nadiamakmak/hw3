#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head == NULL){ //if at the end, make sure all lists end with nullptr
		smaller = NULL;
		larger = NULL;
		return;
	}
	if(head->val>pivot){ //if the value is greater than the pivot, set the current node to that object
		larger = head;
		Node* nextOne = head->next;
		llpivot(nextOne, smaller, larger->next, pivot); //go to next object in the input, and increase node in larger
	}
	else{ //if the value is less than the pivot, set the current node to that object
		smaller = head;
		Node* nextOne = head->next;
		llpivot(nextOne, smaller->next, larger, pivot); //go to next object in the input, and increase node in smaller
	}
	head = NULL; //setting all nodes to null on the way back
}

