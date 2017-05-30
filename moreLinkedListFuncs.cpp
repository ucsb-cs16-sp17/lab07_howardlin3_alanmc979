#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element  
// If more than one element has largest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node * pointerToMax(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list!=NULL);
  assert(list->head != NULL);
  Node *p,*r;
  p = list->head;
  r=list->head;
  int maxVal=p->data;
  while(p != NULL){
    if(p->data > maxVal){
      maxVal = p->data;
      r=p;
    }
    p = p->next;
  }
  return r;
} 
  // TODO: Insert code here to calculate and return
  //   value of pointer to max element (first one if ties.)
 

// list: ptr to a linked list of Node (each with int data, and Node * next)     // Return a pointer to node with the smallest value.  
// You may assume list has at least one element
// If more than one element has smallest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head


Node * pointerToMin(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);
  Node *p,*r;
  p = list->head;
  r=list->head;
  int minVal=p->data;
  while(p != NULL){
    if(p->data < minVal){
      minVal = p->data;
      r=p;
    }
    p = p->next;
  }
  return r;
}


  // TODO: Insert code here to calculate and return
  //   value of pointer to min element 
  //   (first one such value that occurs if there are ties.)


// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);
  Node *p;
  p = list->head;
  int maxVal=p->data;
  while(p != NULL){
    if(p->data > maxVal){
      maxVal = p->data;
    }
    p = p->next;
  }


  // TODO: Insert code here to calculate and return
  //   largest value in list (which may not be unique).

  return maxVal;
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);
  Node *p;
  p = list->head;
  int minVal=p->data;
  while(p != NULL){
    if(p->data < minVal){
      minVal = p->data;
    }
    p = p->next;
  }

  // TODO: Insert code here to calculate and return
  //   smallest value in list (which may not be unique).

  return minVal;

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList * list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  Node *p;
  p = list->head;
  int sum=0;
  if(p==NULL){
    return sum;
  }
  else{
    while(p != NULL){
      sum+= p->data;
      p = p->next;
    }
  }

  // TODO: Insert code here to calculate and return
  //   sum of all values in list (0 if there are none).

  return sum; // STUB!  Replace this line with correct code

}

//Precondition: A pointer to a LinkedList object created on the heap that
////contains all nodes in sorted (ascending) order. The list may be empty.
////The list may have multiple copies of the same element
////Postcondition: Insert a node with the given value at the appropriate
////location in the list, so that the new list also contains nodes in sorted
////(ascending) order. The list may have multiple copies of the same element

void insertNodeToSortedList(LinkedList *list, int value){
  Node * val= new Node;
  val->data=value;
  val->next=NULL;
  Node *p;
  p=list->head;
  if (list==NULL){
    Node *q= new Node;
    q=list->head;
    return;
    }
  else if(p->data >= value){
    val->next=p->next;
    p=val;
  }
  else{
    while(p && p->data<value){
      p=p->next;
    }
    val->next=p->next;
    p->next=val->next;
    p=val;
  } 

}
