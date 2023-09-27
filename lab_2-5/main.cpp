#include "graph.hpp"

int main() {
    int size;
    std::ifstream in("../input.txt");
    in >> size;
    std::vector<std::vector<int>> V(size, std::vector<int> (size, 0));
    graph::printMatrix(V);
    if (in.is_open()) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                in >> V[i][j];
            }
        }
        graph::printMatrix(V);
        graph::graph  G(size, V);
        graph::Lab2(G, 0);
        graph::Lab3(G);
        graph::Lab4(G);
        graph::Lab5(G);
    } else {
        std::cout << "ERROR: unable to open file" << std::endl;
    }
    return 0;
}
