#include <iostream>
#include "dbms2.hh"
using namespace std;
#include <cstdlib>
#include <cstring>
#include "vdb.hh"
#include <vector>

namespace dbms2{

//constructor
LinkedListDbTable::LinkedList(){
      head = NULL; // set head to NULL
  }
// destructor
LinkedListDbTable::~LinkedList(){
      Node *next = head;
      while(next) {              // iterate over all elements
          Node *deleteMe = next;
          next = next->next;     // save pointer to the next element
          delete deleteMe;       // delete the current entry
      }
  }
bool LinkedListDbTable::add(movie &a){
      Node *n = new Node();   // create new Node
      n->x = &a;             // set value
      n->next = head;         // make the node point to the next node.
                              //  If the list is empty, this is NULL, so the end of the list --> OK
      head = n;               // last but not least, make the head point at the new node.
      return true;
  }
  // returns the first element in the list and deletes the Node.
  // caution, no error-checking here!
bool LinkedListDbTable::remove(){
    struct node * nodeToFree;
    temp = head;
    while(temp != NULL){
    nodeToFree = temp;
    temp = temp->next;
    if (nodeToFree != NULL)
    free( nodeToFree);
    }
    return true;

  }
const int LinkedListDbTable::rows(){
    int i;
    temp = head;
    while(temp != NULL){
      nodeToFree = temp;
      temp = temp->next;
    i++;
    }
    return i;
  }
bool LinkedListDbTable::show(const int num){
  //iterate through list outputting each element
   temp = head;
   printf("\n\nList elements are - \n");
   while(temp != NULL){
   printf("%d --->",temp->data);
   temp = temp->next;
  }
}

}
