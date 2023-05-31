#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../Common/LinkedList.hpp"
#endif


using namespace std;

//Lifo
template <typename T>
class Stack
{
    private:
        LinkedList<T> list;
    public:
        void Push(T data);
        T Pop();
};