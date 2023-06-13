#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Graph{
    map<T, list<T>> _list;

public:
    void addEdge(T node1, T node2, bool unDirected=true){
        _list[node].push_back(node2);
        if(unDirected){
            _list[node2].push_back(node1);
        }
    }

    void dfs(T srcNode){
        
    }
};

int main(){
    Graph<int> g = Graph<int>();

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.dfs(0);
    cout << endl;

    return 0;
}