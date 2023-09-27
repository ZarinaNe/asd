
#ifndef LAB_ASD_8_GRAPH_HPP
#define LAB_ASD_8_GRAPH_HPP
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

class graph {
private:
    std::vector<std::vector<int>> _g;
    std::vector<bool> _L_const;
    int find_min_unvisited(std::vector<int> V);
public:
    graph(std::vector<std::vector<int>> g);
    std::vector<int> GetAdj(int vertex);
    void Dijkstra(int startV);
};


#endif //LAB_ASD_8_GRAPH_HPP
