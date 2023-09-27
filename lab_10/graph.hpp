
#ifndef LAB_ASD_10_GRAPH_HPP
#define LAB_ASD_10_GRAPH_HPP

#include <stack>
#include <iostream>
#include <fstream>
#include <vector>

class graph {
private:
    std::vector<std::vector<int>> _g;
public:
    graph(std::vector<std::vector<int>> g);
    bool isEulerGraph();
    int GetDegree(int x);
    int GetAdjV(int x);
    void FindEulerCycle();
};


#endif //LAB_ASD_10_GRAPH_HPP
