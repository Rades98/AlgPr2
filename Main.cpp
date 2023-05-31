#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Common/LinkedList.cpp"
#endif
#include "Queue/Queue.cpp"
#include "Stack/Stack.cpp"
#include <iostream>

using namespace std;

void LinkedListTests();
void QueueTests();
void StackTests();

int main()
{
    LinkedListTests();
    QueueTests();
    StackTests();
    return 1;
}

void StackTests()
{
    cout << endl << "Stack tests" << endl;

    //Arrange
    Stack<char> s;
    char last = 'g';
    s.Push('b');
    s.Push('c');
    s.Push(last);

    //Act1
    char res = s.Pop();

    //Assert1
    if(res == last)
    {
        cout << "Test OK! - Stack (LIFO) works! Last inserted item has been removed as first(" << last << ")" << endl;
    }
    
    //Act2
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    char res2 = s.Pop();

    //Assert2
    if(res2 == NULL)
    {
        cout << "Test OK! - Stack (LIFO) works! Pop does not destroy everything in case of lack of data" << endl;
    }
}

void QueueTests()
{
    cout << endl << "Query tests" << endl;
    
    //Arrange
    Queue<char const*> q;
    char const* first = "qqqqqq";
    q.Push(first);
    q.Push("qwe");
    q.Push("adadss");

    //Act1
    char const* res = q.Pop();

    //Assert1
    if(res == first)
    {
        cout << "Test OK! - Query (FIFO) works! First inserted item has been removed as first(" << first << ")" << endl;
    }

    //ACT2
    q.Pop();
    q.Pop();
    q.Pop();
    q.Pop();
    q.Pop();
    char const* res2 = q.Pop();

    //Assert2
    if(res2 == NULL)
    {
        cout << "Test OK! - Query (FIFO) works! Pop does not destroy everything in case of lack of data" << endl;
    }
}

void LinkedListTests()
{
    cout << endl << "Linked list tests" << endl;

    //Arrange
    LinkedList<int> list;
    list.AddNode(1);
    list.AddNode(8);
    list.AddNode(12);
    list.AddNode(13);
    list.AddNode(4);
    list.AddNode(888);
    cout << "Before delete" << endl;
    list.Display();

    int count = list.GetCount();
    
    //Act
    cout << endl << "Delete last: (" << list.GetLast()->Data << ")" << endl; 
    list.DeleteLast();

    cout << endl << "Delete first: (" << list.GetFirst()->Data << ")" << endl; 
    list.DeleteFirst();

    //Assert

    cout << endl << "After delete: " << endl;
    list.Display();

    int first = list.GetFirst()->Data;
    int last = list.GetLast()->Data;
    int actualCount = list.GetCount();

    Node<int>* firstTest = list.GetFirst();
    Node<int>* lastTest = list.GetLast();

    for(int i = 0; i < count - actualCount+1; i++)
    {
        Node<int>* firstTmp = firstTest->Next;
        firstTest = firstTmp;

        Node<int>* lastTmp = lastTest->Previous;
        lastTest = lastTmp;
    }

    if(last == firstTest->Data)
    {
        cout << "Test OK! - Last from first is: (" << first << ")" << endl;
    }

    if(first == lastTest->Data)
    {
        cout << "Test OK! - First from last is: (" << last << ")" << endl;
    }

    if(count > actualCount)
    {
        cout << "Test OK! - Count after delete (" << actualCount << ") is lesser than before (" << count << ")"<< endl;
    }
}
