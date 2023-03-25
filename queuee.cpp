//#include <iostream>
//#include "queuee.h"
//
//template <typename t>
//queuee<t>::queuee() {
//	values = new double[10];
//	maxSize = 10;
//	front = 0;
//	rear = -1;
//	counter = 0;
//}
//
//template <typename t>
//queuee<t>::queuee(int size) {
//	values = new double[size];
//	maxSize = size;
//	front = 0;
//	rear = -1;
//	counter = 0;
//}
//
//
//
//template <typename t>
//bool queuee<t>:: isEmpty() {
//	if (counter) return false;
//	else
//		return true;
//}
//
//template <typename t>
//bool queuee<t>::isFull() {
//	if (counter==maxSize) return true;
//	else
//		return false;
//}
//
//template <typename t>
//bool queuee<t>:: Enqueue(t x) {
//	if (isFull()) {
//		std::cout << "Error";
//		return false;
//	}
//	else {
//		rear = (rear + 1) % maxSize;
//		*(values + rear) = x;
//		counter++;
//		return true;
//
//	}
//}
//
//template <typename t>
//bool queuee<t>::Dequeue(t& x) {
//	if (isEmpty()) {
//		std::cout << "empty queue";
//		return false;
//	}
//	else {
//		x = *(values + front);
//		front = (front + 1) % maxSize;
//		counter--;
//		return true;
//	}
//}
//
//template <typename t>
//t queuee<t>::ffront() {
//	return front;
//}
//
//
//	

#include "queuee.h"
#include <iostream>
using namespace std;
template <class T>
queuee<T>::queuee(int size)
{
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
template <class T>
void queuee<T>::pop()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
    }
    else
    {
        front = (front + 1) % capacity;
        count--;
    }
}
template <class T>
void queuee<T>::push(T item)
{
    if (isFull())
    {
        cout << "Overflow\n";
    }
    else
    {
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }
}
template <class T>
T queuee<T>::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
    }
    else
        return arr[front];
}
template <class T>
int queuee<T>::size() {
    return count;
}
template <class T>
bool queuee<T>::isEmpty() {
    return (size() == 0);
}
template <class T>
bool queuee<T>::isFull() {
    return (size() == capacity);
}