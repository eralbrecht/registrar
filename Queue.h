#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template <class T>
class Queue
{
  public:

    DoublyLinkedList<T> myQueue;


    Queue() //Default constructor
    {

    }

    ~Queue() //Destructor
    {

    }

    //Functions

    void insert(T data) //Queue is a FIFO data structure, insert at back
    {
      myQueue.insertBack(data);
    }

    T remove() //Queue must remove from the front
    {
      myQueue.removeFront();
    }

    int getSize(){
      return myQueue.getSize();
    }

    bool isEmpty(){
      return myQueue.isEmpty();
    }

};
