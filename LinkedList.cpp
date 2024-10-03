#include <iostream>
#include <vector>

using namespace std;

class linkedList {
public:
    int data;
    linkedList* next;
    linkedList* head;
    linkedList* tail;

    linkedList(int data) {
        this->data = data;
        this->next = NULL;
        head = NULL;
        tail = NULL;
    }

    void dataRead(const vector<int>& arr) {
        if (arr.empty()) return;

        head = nullptr;
        tail = nullptr;

        for (size_t i = 0; i < arr.size(); ++i) {
            linkedList* node = new linkedList(arr[i]);
            if (head == nullptr) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
    }


    void print() const {
        linkedList* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void linkedListReverse(){
      linkedList* current= NULL;
      linkedList* forward= NULL;
      linkedList* prev= NULL;
      
      current = head;
      
      while(current!=NULL){
        forward = current->next;
        current->next = prev;
        prev =current;
        current = forward;
          
      }
      
      head = prev;

      cout<< head-> data;
      
  }
    
};

  

int main() {
    vector<int> apple = {1, 2, 3, 4, 5};

    linkedList one(0);  // Creating an initial node with dummy data

    one.dataRead(apple);
    one.print();
    
    one.linkedListReverse();
    return 0;
}
