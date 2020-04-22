//Registrar Simulation
//Rose Albrecht ealbrecht@chapman.edu #2300456 (section 1)
//Jordan Farmer jfarmer@chapman.edu #2289033 (section 2)
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

    void insert(T data) //Queue is a first in first out data structue, we want to add objects to the back
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
