#include "Node.hpp"

template <typename T>
class LinkedList
{
    private:
        Node<T> *head, *tail;
        void deleteNode(Node<T>* del_node);
    
    public: 
        LinkedList();
        void AddNode(T data);
        void Display();
        Node<T>* GetFirst();
        Node<T>* GetLast();
        void DeleteLast();
        void DeleteFirst();
        int GetCount();
};