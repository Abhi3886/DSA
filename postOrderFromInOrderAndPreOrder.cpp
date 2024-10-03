#include <iostream>
#include <map>
using namespace std;

// Definition of the Node class for the binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor for creating a new node
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in post-order traversal
void printPreOrder(Node *root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

class Solution{
    private: 
    // Helper function to recursively build the tree
    Node* solve(int in[], int post[], int &postOrderIndex, int inOrderStartIndex, int inOrderEndIndex, map<int,int> &mapInOrder){

        // Base Case
        if(postOrderIndex < 0 || inOrderStartIndex > inOrderEndIndex){
            return NULL;
        }

        // Get the current element from postorder traversal and create the root node
        int element = post[postOrderIndex--];
        Node* root = new Node(element);

        // Find the index of this element in the inorder traversal
        int inIndex = mapInOrder[element];

        // Recursively build the right subtree first, because in postorder traversal,
        // the right subtree comes just before the root element.
        root->right = solve(in, post, postOrderIndex, inIndex + 1, inOrderEndIndex, mapInOrder);

        // Recursively build the left subtree
        root->left = solve(in, post, postOrderIndex, inOrderStartIndex, inIndex - 1, mapInOrder);

        return root;
    }
    
    public:
    // Function to build the tree from inorder and postorder arrays
    Node* buildTree(int in[], int post[], int n)
    {
        int postOrderIndex = n - 1;
        map<int,int> mapInOrder;

        // Create a map of inorder elements to their index for quick lookups
        for(int i = 0; i < n; i++){
            mapInOrder[in[i]] = i;
        }

        // Build the tree recursively
        Node* ans = solve(in, post, postOrderIndex, 0, n - 1, mapInOrder);

        return ans;
    }
};

int main()
{
    int n;
    // Take the size of the tree as input
    cout << "Enter the number of elements in the tree: ";
    cin >> n;

    // If no nodes are provided, return
    if (n <= 0) {
        cout << "Tree cannot be built with zero or negative number of nodes!" << endl;
        return 0;
    }

    int inorder[n], postorder[n];
    
    // Input for inorder traversal
    cout << "Enter inorder traversal: ";
    for(int i = 0; i < n; i++)
        cin >> inorder[i];

    // Input for postorder traversal
    cout << "Enter postorder traversal: ";
    for(int i = 0; i < n; i++)
        cin >> postorder[i];

    // Create an instance of the Solution class
    Solution obj;
    Node *root = obj.buildTree(inorder, postorder, n);

    // Print Pre-order traversal of the constructed tree
    cout << "Pre-order traversal of the constructed tree: ";
    printPreOrder(root);
    cout << endl;

    return 0;
}
