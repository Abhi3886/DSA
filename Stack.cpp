#include <iostream>
#include <vector> 
            
using namespace std;

class Stack {
public:
    int top;
    int size;
    vector<int> arr;
    
    // Constructor to initialize the stack with an array
    Stack(int* array, int size) {
        this->size = size;
        top = -1;
        arr.reserve(size);
        
        for (int i = 0; i < size; i++) { 
            top++;
            arr.push_back(array[i]);
        }
    }
    
    // Constructor to initialize an empty stack with a given size
    Stack(int size) {
        this->size = size;
        arr.reserve(size);
        top = -1;
    }

    // Method to check if the stack is full
    bool isFull() {
        return top == size - 1;
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Method to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full" << endl;
        } else {
            top++;
            arr.push_back(value);
        }
    }

    // Method to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            int value = arr[top];
            arr.pop_back();
            top--;
            return value;
        }
    }
};

int main() {
    Stack stk(5);
    stk.push(10);
    int popped = stk.pop();
    cout << popped << endl;
    popped = stk.pop();
    cout << popped << endl;

    int arr[] = {1, 2, 3, 4};
    Stack stk2(arr, sizeof(arr) / sizeof(arr[0]));

    popped = stk2.pop();
    cout << popped << endl;

    return 0;
}
