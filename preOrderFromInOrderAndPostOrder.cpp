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
void printPostOrder(Node *root)
{
    if(root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

class Solution{
    private: 
    // Helper function to recursively build the tree
    Node* solve(int in[], int pre[], int &preOrderIndex, int inOrderStartIndex, int inOrderEndIndex, int n, map<int,int> &mapInOrder){

        // Base Case
        if(preOrderIndex >= n || inOrderStartIndex > inOrderEndIndex){
            return NULL;
        }

        // Get the current element from preorder traversal and create the root node
        int element = pre[preOrderIndex++];
        Node* root = new Node(element);

        // Find the index of this element in the inorder traversal
        int inIndex = mapInOrder[element];

        // Recursively build the left and right subtrees
        root->left = solve(in, pre, preOrderIndex, inOrderStartIndex, inIndex - 1, n, mapInOrder);
        root->right = solve(in, pre, preOrderIndex, inIndex + 1, inOrderEndIndex, n, mapInOrder);

        return root;
    }
    
    public:
    // Function to build the tree from inorder and preorder arrays
    Node* buildTree(int in[], int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int,int> mapInOrder;

        // Create a map of inorder elements to their index for quick lookups
        for(int i = 0; i < n; i++){
            mapInOrder[in[i]] = i;
        }

        // Build the tree recursively
        Node* ans = solve(in, pre, preOrderIndex, 0, n - 1, n, mapInOrder);

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

    int inorder[n], preorder[n];
    
    // Input for inorder traversal
    cout << "Enter inorder traversal: ";
    for(int i = 0; i < n; i++)
        cin >> inorder[i];

    // Input for preorder traversal
    cout << "Enter preorder traversal: ";
    for(int i = 0; i < n; i++)
        cin >> preorder[i];

    // Create an instance of the Solution class
    Solution obj;
    Node *root = obj.buildTree(inorder, preorder, n);

    // Print post-order traversal of the constructed tree
    cout << "Post-order traversal of the constructed tree: ";
    printPostOrder(root);
    cout << endl;

    return 0;
}
