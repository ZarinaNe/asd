#include "graph.hpp"

int main() {
    std::cout << "Лабораторная работа №8 \n"
                 "Реализовать алгоритм Дейкстры поиска кратчайших путей "
                 "\nиз одной вершины, используя в качестве приоритетной очереди обычный массив." << std::endl;
    int size;
    std::ifstream in("../input.txt");
    in >> size;
    std::vector<std::vector<int>> V(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            in >> V[i][j];
        }
    }
    graph G(V);
    G.Dijkstra(0);
    return 0;
}
