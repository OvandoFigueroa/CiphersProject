#ifndef QUEUE_H
#define QUEUE_H
class Queue
{
	struct QueueNode
	{
		int value;
		QueueNode *next;
		QueueNode( char value1, QueueNode *next1 = nullptr )
		{
			value = value1;
			next = next1;
		}

	};

	QueueNode *front;
	QueueNode *rear;

	public:
		Queue();
		~Queue();

		void enqueue(char);
		void dequeue(char &);
		bool isEmpty() const;
		bool isFull() const;
		void clear();
		char item() const;



};

#endif
