#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "../Common/LinkedList.hpp"
#endif


using namespace std;

//FIFO
template <typename T>
class Queue
{
    private:
        LinkedList<T> list;
    public:
        void Push(T data);
        T Pop();
};