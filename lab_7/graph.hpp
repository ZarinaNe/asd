#ifndef LAB_ASD_7_GRAPH_HPP
#define LAB_ASD_7_GRAPH_HPP
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#define MIN  1000;

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
        std::vector<std::vector<int>> _g;
        std::vector<int> _visited;
        bool find(int x);
public:
    graph(std::vector<std::vector<int>> g);
    int FindMinAdj(int vertex);

    void Prima();
};


#endif //LAB_ASD_7_GRAPH_HPP
