#include <iostream>
#include <cstdlib>
#include "Queue.h"
using namespace std;

/*
 * This entire queue section is from the textbook
*/

// Constructor
Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
}

// Destructor
Queue::~Queue()
{
	QueueNode * garbage = front;
	while ( garbage != nullptr )
	{
		front = front->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = front;
	}
}

// Function enqueue inserts the value in character
// at the rear of the queue.
void Queue::enqueue( char character )
{
	if ( isEmpty() )
	{
		front = new QueueNode(character);
		rear = front;
	}
	else
	{
		rear->next = new QueueNode(character);
		rear = rear->next;
	}
}	

// Function dequeue removes the value at the
// front of the queue, and copies it into character
void Queue::dequeue( char &character )
{
	QueueNode *temp = nullptr;
	if ( isEmpty() )
	{
		cout << "The queue is empty.." << endl;
	}
	else
	{
		character = front->value;
		temp = front;
		front = front->next;
		delete temp;
	}
}

// Goes through the queue with a counter and if it reaches
// 100 elements then it returns true
// if its less than 100 elements then it returns false
bool Queue::isFull() const
{
	int counter = 1;
	QueueNode *temp;
	temp = front;
	if ( !isEmpty() ){
		while ( temp != nullptr ){
			temp = temp->next;
			counter++;
		}
	}

	if ( counter >= 100 ){
		return true;
	}
	return false;
}

// Function clear dequeues all the elements in the queue
void Queue::clear()
{
	char character;

	while ( !isEmpty() )
		dequeue(character);
}

// Function isEmpty returns true if the queue
// is empty, and false otherwise
bool Queue::isEmpty() const
{
	if ( front == nullptr )
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Returns the character value inside the current node
char Queue::item() const
{
	return front->value;
}
