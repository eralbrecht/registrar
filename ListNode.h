#include <iostream>

using namespace std;

template <class Node>
class ListNode
{

  public:

    List data; //data of the node
    ListNode *prev; //pointer to previous node
    ListNode *next; //pointer to next node


    //Implementations

    ListNode() //i don't think this will ever really be called because you need to assign some data to the node
    {

    }

    ListNode(List d)
    {
      data = d;
      prev = NULL:
      next = NULL;
    }

    ~ListNode(){

    }
};
