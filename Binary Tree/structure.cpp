#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

        node(int value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
};

node *buildTree(){
    int data;
    cin >> data;

    if(data==-1){
        return nullptr;
    }

    node *root = new node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void printPreOrder(node *root){
    
    if(root==nullptr){
        return;
    }
    
    cout << root->data << " ";

    printPreOrder(root->left);
    printPreOrder(root->right);
}

// we print the left children first, the parent second and lastly the right children.
void printInOrder(node *root){

    if(root==nullptr){
        return;
    }
    
    printInOrder(root->left);
    
    cout << root->data << " ";
    
    printInOrder(root->right);
}

// we print all children nodes of node first and then the node
void printPostOrder(node *root){
    
    if(root==nullptr){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);


    cout << root->data << " ";
}

void printKthLevelOrder(node *root, int k){
    if(root==nullptr){
        return;
    }
    if(k==1){
        cout << root->data << " ";
        return;
    }

    printKthLevelOrder(root->left, k-1);
    printKthLevelOrder(root->right, k-1);
    return;
}

int heightOfTree(node *root){
    if(root==nullptr){
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight,rightHeight) + 1;
}

void printLevelOrder(node *root){
    int height = heightOfTree(root);

    for(int i=1; i<=height; i++){
        printKthLevelOrder(root,i);
        cout << endl;
    }
}

int main(){
    node *root = buildTree(); // example input: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    cout << "Preorder: ";
    printPreOrder(root);
    cout << "\nInorder: ";
    printInOrder(root);
    cout <<"\nPostorder: ";
    printPostOrder(root);
    cout <<"\nHeight of Tree: " << heightOfTree(root);
    cout << "\nLevelOrder:\n";
    printLevelOrder(root);
    cout << endl;
    return 0;
}