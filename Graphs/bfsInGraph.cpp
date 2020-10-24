#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Graph{
    map<T, list<T>> _list;
    map<T, bool> visited;

public:
    void addEdge(T node1, T node2){
        _list[node1].push_back(node2);
        _list[node2].push_back(node1);
    }

    void bfs(T srcNode, bool all = false){

        cout << "BFS Traversal: ";
        queue<T> q;

        q.push(srcNode);
        visited[srcNode] = true;

        while(!q.empty()){
            T poppedNode = q.front();
            q.pop();

            cout << poppedNode << ", ";

            for(auto neighbour : _list[poppedNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

        if(all){
            for(auto node : _list){
                if(!visited[node.first]){
                    bfs(node.first, true);
                }
            }
        }
    }
};

int main(){
    Graph<int> g = Graph<int>();

    // connected graph
    /* g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(1, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0); */

    // disconnected graph
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 4);
    g.addEdge(5, 6);
    g.bfs(1, true);

    

    cout << endl;

    return 0;
}