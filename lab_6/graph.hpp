#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>

struct Edge {
    int _node_1, _node_2, _weight;
    Edge(int node_1, int node_2, int weight) {
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
// Массив root хранит корни вершин.
// Изначально, все вершины считаются независимыми и root: 1,2,3,4 ... size
// Когда возникает зависимость, допустим, между 1 и 2 вершиной, то root: 2,2,3,4...size
// То есть он работает как ссылки: вершина 1 ссылается на 2, а 2 на саму себя, значит у вершин 1,2 общий корень = 2
// Пусть возникла зависимость между 2 и 3 вершиной тогда root: 2,3,3,4...size: вершина 1 ссылается на 2, 2 cсылается на 3, 3 сам на себя, значит 1,2,3 с общим корнем
    static bool compare(Edge a, Edge b);
    int findRoot(int x);
public:
    graph(std::vector<Edge> graph, int amountVertex);
    void print();
    void sortEdges();
    void Kruskal();
};



