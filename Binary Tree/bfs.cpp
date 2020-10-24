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
// printing binary tree in O(n)
// each node goes in and out of queue one time only
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

int main(){
    node * root = buildTree(); // use input 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    bfs(root);
    cout << endl;
    return 0;
}