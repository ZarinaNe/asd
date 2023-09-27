#ifndef LAB_ASD_9_GRAPH_HPP
#define LAB_ASD_9_GRAPH_HPP
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

struct Edge {
    int _node_1;
    int _node_2;
    int _weight;
    Edge(int node_1, int node_2, int weight)
    {
        _node_1 = node_1;
        _node_2 = node_2;
        _weight = weight;
    }

};

class graph {
private:
    std::vector<Edge> _g;
    std::vector<int> _root;
    int _amountVertex;
public:
    graph(std::vector<Edge> graph, int amountVertex);
    void Bellman_Ford(int startV);
};



#endif //LAB_ASD_9_GRAPH_HPP
