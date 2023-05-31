#include "Queue.hpp"

template <typename T>
void Queue<T>::Push(T data)
{
    list.AddNode(data);
}

template <typename T>
T Queue<T>::Pop()
{
    Node<T>* fst = list.GetFirst();

    if(fst != NULL)
    {
        T element = fst->Data;
        list.DeleteFirst();
        return element;
    }
    
    return NULL;
}