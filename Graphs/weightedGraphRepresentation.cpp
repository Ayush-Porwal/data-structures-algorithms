#include<bits/stdc++.h>

using namespace std;

class Graph{
    unordered_map<string, list<pair<string, int>>> _list;

public:
    void addEdge(string node1, string node2, int weight, bool bi = true){
        _list[node1].push_back({node2, weight});
        if(bi){
            _list[node2].push_back({node1, weight});
        }
    }

    void printGraph(){
        for(auto node : _list){
            cout << "Node " << node.first << " has neighbours -> ";
            for(auto neighbour : node.second){
                cout << neighbour.first << " (w: " << neighbour.second << "), ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g = Graph();

    g.addEdge("A", "B", 20);
    g.addEdge("A", "C", 10);
    g.addEdge("C", "D", 30);
    g.addEdge("B", "D", 40);
    g.addEdge("A", "D", 50, false);

    g.printGraph();
    return 0;
}