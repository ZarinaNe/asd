#include "Graph.hpp"

int main() {
    std::cout << "Лабораторная работа №15 "
                 "\nРешить задачу о раскраске графа." << std::endl;
    int size;
    std::ifstream in("../input.txt");
    in >> size;
    std::vector<std::vector<int>> V(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            in >> V[i][j];
        }
    }
    std::string colors[5] = {"синий", "зеленый", "красный","желтый", "фиолетовый"};
    Graph G(V);
    int n = G.Coloring(colors);
    std::cout << "Хроматическое число графа = " << n;
    return 0;
}
