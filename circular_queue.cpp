//	William Sullivan
//
//	From: https://leetcode.com/problems/design-circular-queue/description/
//
//	Design your implementation of the circular queue. 
//	The circular queue is a linear data structure in which the operations are performed based
//	on FIFO (First In First Out) principle and the last position is connected back to the first
//	position to make a circle. It is also called "Ring Buffer".
//
//	One of the benefits of the circular queue is that we can make use of the spaces in front of
//	the queue.  In a normal queue, once the queue becomes full, we cannot insert the next element
//	even if there is a space in front of the queue.  But using the circular queue, we can use the
//	space to store new values.
//
//	Your implementation should support following operations:
//
//	MyCircularQueue(k) : Constructor, set the size of the queue to be k.
//	Front : Get the front item from the queue.If the queue is empty, return -1.
//	Rear : Get the last item from the queue.If the queue is empty, return -1.
//	enQueue(value) : Insert an element into the circular queue.Return true if the operation is successful.
//	deQueue() : Delete an element from the circular queue.Return true if the operation is successful.
//	isEmpty() : Checks whether the circular queue is empty or not.
//	isFull() : Checks whether the circular queue is full or not.
//
//	Note:
//
//	All values will be in the range of[0, 1000].
//	The number of operations will be in the range of[1, 1000].
//	Please do not use the built - in Queue library.


#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue 
{
private:
	vector<int> queue;
	int size;
	int head;
	int tail;

	// Given an index, returns the next index.
	int next(int index)
	{
		return (index + 1) % size;
	}

	// Given an index, returns the previous index.
	int previous(int index)
	{
		return (size + index - 1) % size;
	}

public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) 
	{
		size = k;
		queue.assign(size, 0);
		head = -1;
		tail = -1;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) 
	{
		// If the queue is full, return false.
		if (isFull())
		{
			return false;
		}

		// Otherwise
		// increment the tail index
		tail = next(tail);
		
		// if the queue was empty, set the head to equal the tail.
		if (isEmpty())
		{
			head = tail;
		}
		
		// Add the value to the tail, return true.
		queue[tail] = value;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() 
	{
		// If the queue is empty return false;
		if (isEmpty())
		{
			return false;
		}
		
		// Check if the item is the last in the list
		if (head == tail)
		{
			// reinitialize the queue to empty.
			head = -1;
			tail = -1;
			return true;
		}
		// Otherwise, increment the head index.
		else
		{
			head = next(head);
			return true;
		}
	}

	/** Get the front item from the queue. */
	int Front()
	{
		// If the head doesn't exist, return -1
		if (head < 0)
		{
			return tail;
		}
		// Otherwise return the value at the head index
		else
		{
			return queue[head];
		}
	}

	/** Get the last item from the queue. */
	int Rear()
	{
		// if the tail doesn't exist, return -1
		if (tail < 0)
		{
			return tail;
		}
		// Otherwise return the value at the tail index
		else
		{
			return queue[tail];
		}
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() 
	{
		// The head and tail index should be -1 if empty.
		if (head < 0 || tail < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() 
	{
		// if its full the next index after the tail should be the head.
		if (next(tail) == head)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void showQueue()
	{
		if (isEmpty())
		{
			cout << "[empty]" << endl;
		}
		else
		{
			cout << "[ " << flush;
			for (int i = 0; i <size; i++)
			{
				cout << queue[i] << " " << flush;
			}
			cout << "]" << endl;
			cout << "Head: " << head << "   Tail: " << tail << endl;
		}
	}
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue obj = new MyCircularQueue(k);
* bool param_1 = obj.enQueue(value);
* bool param_2 = obj.deQueue();
* int param_3 = obj.Front();
* int param_4 = obj.Rear();
* bool param_5 = obj.isEmpty();
* bool param_6 = obj.isFull();
*/


int main()
{
	MyCircularQueue myQueue(6);
	
	myQueue.enQueue(1);
	myQueue.enQueue(2);
	myQueue.enQueue(3);
	
	myQueue.deQueue();

	cout << "Front is: " << myQueue.Front() << endl;
	cout << "Rear is: " << myQueue.Rear() << endl;

	return 0;
}