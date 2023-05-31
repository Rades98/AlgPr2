#include "Stack.hpp"

template <typename T>
void Stack<T>::Push(T data)
{
    list.AddNode(data);
}

template <typename T>
T Stack<T>::Pop()
{
    Node<T>* lst = list.GetLast();
    
    if(lst != NULL)
    {
        T element = lst->Data;
        list.DeleteLast();

        return element;
    }

    return NULL;
}