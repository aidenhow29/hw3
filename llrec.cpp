#include "llrec.h"
#include "iostream"


//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

  Node* temp = head;
  head = NULL;

    if(temp == NULL){
        smaller = NULL;
        larger = NULL;

        return;
    }

    if(temp->val > pivot){
        larger = temp;
        llpivot(temp->next, smaller, larger->next, pivot);
    }

    if(temp->val <= pivot){
        smaller = temp;
        llpivot(temp->next, smaller->next, larger, pivot);
    }



}
