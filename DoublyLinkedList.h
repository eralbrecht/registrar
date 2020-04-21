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

    ~DoublyLinkedList()//Destructor
    {

    }

    //Helper Functons

    unsigned int getSize()
    {

      return size;
    }

    bool isEmpty()
    {

      return (size == 0);
    }

    void printList()
    {

      ListNode<Node> *current = front;

      while (curr != NULL){

        cout << curr->data << endl;
        current = current->next;
      }
    }

    //Main Functions

    void insertFront(List data)
    {

      ListNode<Node> *node = new ListNode(data);

      //Check if list is empty before inserting, then move on to the conditions

      ListNode<Node> *temp = front;
      front = node;
      node->next = temp;
      temp->prev = node;
      node->prev = NULL;
      size++;

    }

    void insertBack(List data)
    {

      ListNode<Node> *node = new ListNode(data);

      //CHeck if list is empty before inserting, then move on to the conditions

      ListNode<Node> *temp = back;
      back = node;
      node->prev = temp;
      temp->next = node;
      node->next = NULL;
      size++;
    }

    List removeFront()
    {

      ListNode<Node> *tempNode = front;

      //Check if list is empty before removing

      if(front->next = NULL)  //Only one node in the list
      {
        back = NULL;
      }else //More than one element int he list
      {
        front->next->prev = NULL;
      }

      front = front->next;
      tempNode->next = NULL;
      List temp = tempNode->data;
      size--;
      delete tempNode;
      return temp;

    }

    List removeBack()
    {

      ListNode<Node> *tempNode = back;

      //Check if list is empty before removing

      if(back->prev = NULL) //There is only one element in the list
      {
        front = NULL;
      }else //More than one element in the list
      {
        back->prev->next = NULL;
      }

      back = back->prev;
      tempNode->prev = NULL;
      List temp = tempNode->data;
      size--
      delete tempNode;
      return temp;
    }

    List remove(List data)
    {
      ListNode<Node> *curr = front;

      //Look for the node with the data
      while(curr->data != data)
      {
        curr = curr->next;

        if(curr == NULL)
        {
          cout << "No matching data found." << endl;
          return -1;
        }
      }

      //If we hit this point, data has been found
      if(curr == front)//if node to be removed is the front node
      {
        front = curr->next;
      }else
      {
        curr->prev->next = curr->next;
      }

      if(curr == back)
      {
        back = curr->prev;
      }else
      {
        curr->next->prev = curr->prev;
      }

      curr->next = NULL;
      curr->prev = NULL;
      List temp = curr->data;
      size--;
      delete curr;
      return temp;
    }

    List removeAtPosition(int position)
    {
      ListNode<Node> *curr = front;

      for(int i = 0; i < position; i++) //Iterate from the front until we reach the indicated index
      {
        curr = curr->next;
      }

      if(curr = NULL)
      {
        cout << "This position does not exist in the list." << endl;
        return -1;
      }

      //If we hit this point, the position has been found
      if(curr == front)//If the position is the first position
      {
        front = curr->next;
      }else
      {
        curr->prev->next = curr->next;
      }

      if(curr == back)//If the position is the last position
      {
        back = curr->prev;
      }else
      {
        curr->next->prev = curr->prev;
      }

      curr->next = NULL;
      curr->prev = NULL;
      List temp = curr->data;
      size--;
      delete curr;
      return temp;

    }

    List search(List data)
    {
      ListNode<List> *curr = front;
      int count = 0;

      //Look for the node with the data
      while(curr->data != data)
      {
        curr = curr->next;
        count++;

        if(curr == NULL)
        {
          cout << "No matching data found." << endl;
          return -1;
        }
      }

      //Once we exit the while loop, we found the position
      return count;
    }
};
