#include "LinkedList.hpp"
#include <iostream>

using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
    this -> head = NULL;
    this -> tail = NULL;
}

template <typename T>
void LinkedList<T>::AddNode(T data)
{
    Node<T>* newNode = new Node<T>;
    newNode->Data = data;
    newNode->Next = NULL;

    Node<T>* temp = head;
    if (head == NULL) {
        newNode->Previous = NULL;
        head = newNode;
        return;
    }

    while (temp->Next != NULL)
        temp = temp->Next;
   
    temp->Next = newNode;

    tail = newNode;

    newNode->Previous = temp;
}

template <typename T>
void LinkedList<T>::Display()
{
    Node<T>* temp = head;

    while(temp != tail)
    {
        cout << temp->Data << ", ";
        temp = temp->Next;
    }

    cout << tail->Data << endl;
}

template <typename T>
Node<T>* LinkedList<T>::GetFirst()
{
    return head;
}

template <typename T>
Node<T>* LinkedList<T>::GetLast()
{
    return tail;
}

template <typename T>
void LinkedList<T>::DeleteLast()
{
    Node<T>* tmp = tail->Previous;
    deleteNode(tail);

    tail = tmp;
}

template <typename T>
void LinkedList<T>::DeleteFirst()
{
    Node<T>* tmp = head->Next;
    deleteNode(head);

    head = tmp;
}

template <typename T>
int LinkedList<T>::GetCount()
{
    Node<T>* tmp = head;
    int i = 0;

    while(tmp != NULL) 
    {
        i++;
        tmp = tmp->Next;
    }

    return i;
}

template <typename T>
void LinkedList<T>::deleteNode(Node<T>* del_node) 
{
    if (head == NULL || del_node == NULL)
    {
        return;
    }

    if (head == del_node)
    {
        head = del_node->Next;
    }

    if (del_node->Next != NULL)
    {
        del_node->Next->Previous = del_node->Previous;
    }

    if (del_node->Previous != NULL)
    {
        del_node->Previous->Next = del_node->Next;
    }

    free(del_node);
}