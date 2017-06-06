#include "linkedListFuncs.h"
#include "moreLinkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;


  //Test your insertNodeToSortedList function
  //Test your code extensively
  int main() {

  int fiveNums[3]={42,48,61};

  LinkedList *list = arrayToLinkedList(fiveNums,3);
  assertEquals( "[42]->[48]->[61]->null", 
		linkedListToString(list),
		"linkedListToString(list)");

  insertNodeToSortedList(list,57);
  assertEquals( "[42]->[48]->[57]->[61]->null", 
		linkedListToString(list),
		"list after adding 57");

  insertNodeToSortedList(list,57);
  assertEquals( "[42]->[48]->[57]->[57]->[61]->null", 
		linkedListToString(list),
		"list after adding 57");
  
  freeLinkedList(list);
  
  int empty[0]={};
  LinkedList *emptyList = arrayToLinkedList(empty,0);

  assertTrue(list->head == NULL,"list->head == NULL");
  assertTrue(list->tail == NULL,"list->tail == NULL)");
  assertEquals( "null", 
		linkedListToString(emptyList),
		"linkedListToString(emptyList)");

  addIntToEndOfList(list,7);

  assertTrue(list->head != NULL);
  if (list->head != NULL) {
    assertTrue(list->head->data == 7,"list->head->data == 7");
  }

  assertTrue(list->tail != NULL);
  if (list->tail != NULL) {
    assertTrue(list->tail->data == 7,"list->tail->data == 7)");
  }

  assertEquals( "[7]->null", 
		linkedListToString(list),
		"list after adding 7");

  assertTrue(list != NULL,"list != NULL");
  assertTrue(list->head == list->tail,"list->head == list->tail");

  insertNodeToSortedList(list,-6);

  assertEquals( "[-6]->[7]->null", 
		linkedListToString(list),
		"list after adding -6");

  freeLinkedList(emptyList);
  
  return 0;
}
