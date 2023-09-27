
#include "graph.hpp"

int main() {
    std::cout << "Лабораторная работа №10 \n"
                 "Реализовать алгоритм нахождения эйлерова цикла в неориентированном графе,"
                 "\n заданном матрицей смежности." << std::endl;
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
    G.FindEulerCycle();
    return 0;
}