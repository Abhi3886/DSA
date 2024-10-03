#include <iostream>
#include <vector>

using namespace std;

class Queue {
public:
	int front;
	int rear;
	int size;

	vector<int> arr;

	// Constructor to initialize an empty stack with a given size
	Queue(int size) {
		this->size = size;
		this->front=0;
		this->rear = 0;
		arr.reserve(size);
	}
	
	// Constructor to initialize the stack with an array
	Queue(int* array, int size) {
		this->size = size;
		this-> front=0;
		this->rear = size;
		arr.reserve(size);

		for (int i = 0; i < size; i++) {
			arr.push_back(array[i]);
			cout<< "Constructor"<<endl;
			cout<< rear << front <<endl;
		}
	}


	// Method to check if the stack is full
	bool isFull() {
		return  (rear + 1) % size == front; ;
	}

	// Method to check if the stack is empty
	bool isEmpty() {
		return front == rear;
	}

	// Method to push an element onto the stack
	void enqueue(int value) {
		if (isFull()) {
			cout << "Queue is full" << endl;
			cout<< rear << front <<endl;
		} else {
			cout<< "enqueue else"<<endl;
			arr[rear%size]=value;
			rear = (rear+1) % size;
			cout<< rear << front <<endl;
		}
	}

	// Method to pop an element from the stack
	int dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty" << endl;
			cout<< rear << front <<endl;
			return -1;
		} else {
			cout<< "dequeue else"<<endl;
			int value = arr[front % size];
			arr.pop_back();
			front= (front+1) % size ;
			
			cout<< rear << front <<endl;
			return value;
		}
	}
};

int main() {
	Queue stk(5);
	stk.enqueue(10);
	int popped = stk.dequeue();
	cout << popped << endl;
	popped = stk.dequeue();
	cout << popped << endl;
	stk.enqueue(88);
	 popped = stk.dequeue();
	cout << popped << endl;

	int arr[] = {1, 2, 3, 4};
	Queue stk2(arr, sizeof(arr) / sizeof(arr[0]));

	popped = stk2.dequeue();
	cout << popped << endl;

	return 0;
}
