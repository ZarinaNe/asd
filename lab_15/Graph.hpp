#ifndef LAB_ASD_15_GRAPH_HPP
#define LAB_ASD_15_GRAPH_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class Graph {
private:
    std::vector<std::vector<int>> _g;  // граф задается матрицей смежности
    std::vector<bool> _isColored; // Окрашена ли вершина
    std::vector<std::pair<int,int>> _D; // Массив пар: номер вершины <--> степень вершины
    static bool compare(std::pair<int,int> p1, std::pair<int,int> p2); // функция сравнения для отсортировки вершин списка D по неубыванию стеепеней вершин
    int getDegree(int x);// Получение степени вершины
    int next(int cur); // Возвращает первую по списку D неокрашенную вершину
public:
    Graph(std::vector<std::vector<int>> g);
    std::vector<int> GetAdjacentNodes (int node); // Получаем список соседей всех вершин node
    int Coloring(std::string colors[]); // // Хроматическое число графа g
};


#endif //LAB_ASD_15_GRAPH_HPP
