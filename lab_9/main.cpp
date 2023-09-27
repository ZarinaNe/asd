#include "graph.hpp"

int main() {
    int amountVertex; int amountEdge;
    std::ifstream in("../input.txt");
    if (in.is_open()){
        in >> amountVertex;
        std::cout << "Количество вершин графа " << amountVertex << std::endl;
        in >> amountEdge;
        std::cout << "Количество ребер графа " << amountEdge << std::endl;
        std::vector<Edge> edges; // Массив отрезков
        for (int i = 0; i < amountEdge; i++) {
            int node_1;
            int node_2;
            int weight;
            in >> node_1 >> node_2 >> weight;
            Edge e(node_1, node_2, weight);
            edges.push_back(e);
        }
        graph G(edges, amountVertex);
        G.Bellman_Ford(0);
    }  else {
        std::cout << "ERROR: unable to open file" << std::endl;
    }
    return 0;
}
