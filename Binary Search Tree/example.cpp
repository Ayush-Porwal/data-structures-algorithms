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

//bfs code copied from previous file
void bfs(node *root){
    queue<node *> nodes;

    nodes.push(root);
    nodes.push(nullptr);

    while(!nodes.empty()){
        node *dummy = nodes.front();
        nodes.pop();

        if(!nodes.empty()){
            if(dummy){
            if(dummy->left) nodes.push(dummy->left);
            if(dummy->right) nodes.push(dummy->right);
            cout << dummy->data << " ";
            }
            else{
                cout << endl;
                nodes.push(nullptr);
            }
        }
    }
}

//insert node in BST
node *insertNodeInBST(node *root, int value){
    //base case
    if(root==nullptr){
        return new node(value); //new automatically returns the address
    }

    //recursion logic
    if(value<=root->data){
        root->left = insertNodeInBST(root->left, value);
    }
    else{
        root->right = insertNodeInBST(root->right, value);
    }

    return root;

}

//build a BST
node *buildBST(){
    int data;
    cin >> data;

    node *root = nullptr;

    while(data!=-1){
        root = insertNodeInBST(root, data);
        cin >> data;
    }
    return root;
}

//Search in BST
bool searchBST(node *root, int value){
    //base case
    if(root==nullptr){
        return false;
    }

    if(root->data==value){
        return true;
    }

    //recursion logic
    if(value<=root->data){
        return searchBST(root->left, value);
    }
    else{
        return searchBST(root->right, value);
    }
}

node *deleteNoddeInBST(node *root, int value){
    
}

int main(){
    node *root = buildBST();
    bfs(root);
    cout << endl;

    if(searchBST(root, 9)){
        cout << "Present\n";
    }
    else{
        cout << "Absent\n";
    }
    
    return 0;
}