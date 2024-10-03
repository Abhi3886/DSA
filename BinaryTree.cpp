<<<<<<< HEAD
#include <iostream>
#include <queue>
using namespace std;

class BinaryTree {
public:
    int data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create a new binary tree
BinaryTree* newBT() {
    int data;
    cout << "Enter the node data: ";
    cin >> data;

    // Base case for recursion
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the given data
    BinaryTree* root = new BinaryTree(data);

    // Recursively create the left and right subtrees
    cout << "Enter the left child of " << root->data << endl;
    root->left = newBT();

    cout << "Enter the right child of " << root->data << endl;
    root->right = newBT();

    return root;
}

// Function to print binary tree nodes in level-order and show levels
void BST(BinaryTree* root) {
    if (root == NULL) return;

    queue<BinaryTree*> que;
    que.push(root);
    que.push(NULL);  // NULL marks the end of the first level

    cout << "Binary Tree : " << endl;

    while (!que.empty()) {
        BinaryTree* temp = que.front();
        que.pop();

        if (temp == NULL) {
            cout << endl;  // Print a newline to indicate the end of a level
            if (!que.empty()) {
                que.push(NULL);
            }
        } else {
            cout << temp->data << " ";

            // Enqueue the left and right children if they exist
            if (temp->left != NULL) {
                que.push(temp->left);
            }
            if (temp->right != NULL) {
                que.push(temp->right);
            }
        }
    }
}

void inOrder(BinaryTree* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(BinaryTree* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTree* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Helper function to find the inorder predecessor of a node
BinaryTree* findPredecessor(BinaryTree* currentNode) {
    BinaryTree* predecessor = currentNode->left;
    while (predecessor->right != NULL && predecessor->right != currentNode) {
        predecessor = predecessor->right;
    }
    return predecessor;
}

void morrisTraversal(BinaryTree* root, queue<BinaryTree*>& queMT) {
    BinaryTree* currentNode = root;

    while (currentNode != NULL) {
        if (currentNode->left == NULL) {
            queMT.push(currentNode);
            currentNode = currentNode->right;
        } else {
            BinaryTree* predecessor = findPredecessor(currentNode);
            if (predecessor->right == NULL) {
                predecessor->right = currentNode;
                queMT.push(currentNode);
                currentNode = currentNode->left;
            } else {
                predecessor->right = NULL;
                currentNode = currentNode->right;
            }
        }
    }
}

// // Helper function to find the inorder predecessor of a node
// BinaryTree* findPredecessor(BinaryTree* currentNode) {
//     BinaryTree* predecessor = currentNode->left;
//     while (predecessor->right != NULL && predecessor->right != currentNode) {
//         predecessor = predecessor->right;
//     }
//     return predecessor;
// }

// void morrisTraversal(BinaryTree* root, queue<BinaryTree*>& queMT) {
//     BinaryTree* currentNode = root;

//     while (currentNode != NULL) {
//         if (currentNode->left == NULL) {
//             queMT.push(currentNode);
//             currentNode = currentNode->right;
//         } else {
//             BinaryTree* predecessor = findPredecessor(currentNode);
//             if (predecessor->right == NULL) {
//                 predecessor->right = currentNode;
//                 currentNode = currentNode->left;
//             } else {
//                 predecessor->right = NULL;
//                 queMT.push(currentNode);
//                 currentNode = currentNode->right;
//             }
//         }
//     }
// }



void leafNode(BinaryTree* root, queue<BinaryTree*>& queLeafNode) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        queLeafNode.push(root);
    }

    leafNode(root->left, queLeafNode);
    leafNode(root->right, queLeafNode);
}


// Function to print the contents of the queue (printing the data of the nodes)
void printQueue(queue<BinaryTree*> que) {
    // Check if the queue is empty
    if (que.empty()) {
        cout << "The queue is empty." << endl;
        return;
    }

    cout << "Printing Queue:" << endl;
    
    // Traverse through the queue and print the data of its elements
    while (!que.empty()) {
        BinaryTree* node = que.front();  // Get the front node (pointer)
        cout << node->data << " ";       // Access and print the 'data' of the node
        que.pop();                       // Remove the front element
    }
    cout << endl;
}


int height(BinaryTree* root) {
    if (root == NULL) {
        return 0;
    }

    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(leftH, rightH) + 1;
}

int main() {
    // Create the binary tree
    BinaryTree* root = newBT();

    // Perform different traversals
    cout << "Level-order traversal:" << endl;
    BST(root);

    cout << "In-order traversal: " << endl;
    inOrder(root);
    cout << endl;

    cout << "Pre-order traversal: " << endl;
    preOrder(root);
    cout << endl;

    cout << "Post-order traversal: " << endl;
    postOrder(root);
    cout << endl;

    // Print tree height
    int maxH = height(root);
    cout << "Height of tree is: " << maxH << endl;

    // Queue for leaf nodes
    queue<BinaryTree*> queLeafNode;
    leafNode(root, queLeafNode);

    // Queue for Morris Traversal

    queue<BinaryTree*> queMT;
    morrisTraversal(root, queMT);
    printQueue(queMT);

    return 0;
}

 // 1 2 3 -1 -1 4 -1 5 -1 -1 6 7 -1 9 -1 -1 8 10 -1 -1 -1  

=======
#include <iostream>
#include <queue>

using namespace std;

class BinaryTree {
public:
    int data;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create a new binary tree
BinaryTree* newBT() {
    int data;
    cout << "Enter the node data: ";
    cin >> data;

    // Base case for recursion
    if (data == -1) {
        return NULL;
    }

    // Create a new node with the given data
    BinaryTree* root = new BinaryTree(data);

    // Recursively create the left and right subtrees
    cout << "Enter the left child of " << root->data << endl;
    root->left = newBT();

    cout << "Enter the right child of " << root->data << endl;
    root->right = newBT();

    return root;
}

// Function to print binary tree nodes in level-order and show levels
void BST(BinaryTree* root) {
    if (root == NULL) return;

    queue<BinaryTree*> que;
    que.push(root);
    que.push(NULL);  // NULL marks the end of the first level

    cout << "Binary Tree : " << endl;

    while (!que.empty()) {
        BinaryTree* temp = que.front();
        que.pop();

        if (temp == NULL) {
            // End of the current level
            cout << endl;  // Print a newline to indicate the end of a level

            // If there are more nodes to process, push another level marker (NULL)
            if (!que.empty()) {
                que.push(NULL);
            }
        } else {
            // Print the current node
            cout << temp->data << " ";

            // Enqueue the left and right children if they exist
            if (temp->left != NULL) {
                que.push(temp->left);
            }
            if (temp->right != NULL) {
                que.push(temp->right);
            }
        }
    }
}

void inOrder(BinaryTree* root) {

    cout << "InOrder Binary Tree : " << endl;
    if (root == NULL) {
        cout<<"Empty Binary Tree"<<endl;
        return;
    }
     // Print the current node
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
}

void preOrder(BinaryTree* root) {

    cout << "preOrder Binary Tree : " << endl;
    if (root == NULL) {
        cout<<"Empty Binary Tree"<<endl;
        return;
    }
     // Print the current node
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
}

void postOrder(BinaryTree* root) {

    cout << "postOrder Binary Tree : " << endl;
    if (root == NULL) {
        cout<<"Empty Binary Tree"<<endl;
        return;
    }
     // Print the current node
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
}



int main() {
    // Create the binary tree
    BinaryTree* root = newBT();
    
    BST(root);
    inOrder(root);
    preOrder(root);
    postOrder(root);

    return 0;
}
>>>>>>> 9ae6eaba7ef0972503a0129a9eabd52ad7c19e19
