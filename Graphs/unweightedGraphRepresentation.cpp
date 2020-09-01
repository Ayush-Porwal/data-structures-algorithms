/*
    This is undirected unweighted graph representation using adjacency list
*/

#include<bits/stdc++.h>

using namespace std;

class Graph{
    int nodes;
    list<int> *_list;

public:
    Graph(int nodesNum){
        nodes = nodesNum;
        _list = new list<int>[nodesNum];
    }

    void addEdge(int node1, int node2){
        _list[node1].push_back(node2);
        _list[node2].push_back(node1);
    }

    void printGraph(){
        for(int i=0; i<nodes; i++){
            cout << "Node " << i << " has neighbours -> ";
            for(auto item : _list[i]){
                cout << item << ", ";
            }
            cout << endl;
        }
    }

};

int main(){

    Graph g = Graph(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.printGraph();

    return 0;
}