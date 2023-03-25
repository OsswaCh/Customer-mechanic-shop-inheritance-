#pragma once
//template <typename t>
//
//class queuee
//{
//private: 
//	int front;
//	int rear;
//	int counter;
//	int maxSize;
//	t* values;
//
//public:
//	queuee();
//	queuee(int size );
//	bool Enqueue(t );
//	bool Dequeue(t& );
//	bool isEmpty();
//	bool isFull();
//	t ffront();
//
//};

#define TEMPLATE_H
template <class T>

class queuee
{
    T* arr;         // array to store queue elements
    int capacity = 10;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue

public:
    queuee(int size = 10);
    void pop();
    void push(T);
    T peek();
    int size();
    bool isEmpty();
    bool isFull();
};
