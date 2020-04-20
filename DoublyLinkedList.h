#include <iostream>
#include "ListNode.h"

//Not sure if this class needs an overloaded constructor or not, don't really think it can use one

using namespace std;

template <class List>
class DoublyLinkedList
{

  public:

    ListNode<Node> *front; //pointer to the front of the linked list
    ListNode<Node> *back; //pointer to the back of the linked list
    unsigned int size; //size of the list, can't be negative so it is unsigned

    DoublyLinkedList() //Default constructor
    {
      size = 0; //new list so it is empty
      front = new ListNode<Node>(); //list is empty at this point, so the new node is the front and back
      back = new ListNode<Node>(); //list is empty at this point, so the new node is the front and back
    }

    ~DoublyLinkedList()
    {

    }

    //Functions of a linked list

    void insertFront(List data){

      ListNode<Node> *node = new ListNode(data);

      //Check if list is full and empty before inserting, then move on to the conditions

      ListNode<Node> *temp = front;
      front = node;
      node->next = temp;
      temp->prev = node;
      node->prev = NULL;
      size++;
      
    }

};
