#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor for creating a tree node
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from user input
TreeNode *buildTree() {
    int data;
    cout << "Enter data (-1 for null): ";
    cin >> data;

    // Return null if data is -1
    if (data == -1) {
        return nullptr;
    }

    // Create a new node with the given data
    TreeNode *node = new TreeNode(data);

    // Recursive calls to create left and right children
    cout << "Enter data for left child of " << data << ": ";
    node->left = buildTree();

    cout << "Enter data for right child of " << data << ": ";
    node->right = buildTree();

    return node;
}

// Function to perform level order traversal of the binary tree
void levelOrderTraversal(TreeNode *root) {
    if (!root) return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        // Push left and right children if they exist
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }

    cout << endl;
}

int main() {
    TreeNode *root = nullptr;

    // Build tree from user input
    root = buildTree();

    // Display level order traversal
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    return 0;
}
