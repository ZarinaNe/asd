
#ifndef LAB1_GRAPH_HPP
#define LAB1_GRAPH_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <list>

namespace graph {

    class graph {
    private:
        int _size;
        std::vector<std::vector<int>> _g;
        std::vector<bool> _visitedNodes;
        int GetUnvisitedNode();

    public:
        graph(int size, std::vector<std::vector<int>> g);
        void printGraph();
        std::vector<int> GetAdjacentNodes(int node);
        void BFS (int startPos);// Алгоритм обхода графа в ширину и поиска кратчайших путей
        void FindConnectivityComponentByBFS();// Алгоритм подсчета компонентов связности, c помощью BFS
        void recursiveDFS(int startPos);//Рекурсивный обход в глубину
        void FindConnectivityCompopnentByDFS();// Алгоритм подсчета компонентов связности, c помощью DFS
        std::vector<std::vector<int>> GetReachabilityMatrix();// Получаем матрицу достижимости графа, используя иттеративный DFS
        std::vector<std::vector<int>> GetProductMatrix(std::vector<std::vector<int>> reachMatrix);
        void FindStrongComponents();// Поиск сильных компонент связности
        bool find_Q(std::queue<int> Q, int x);
        bool find_L(std::list<int> L, int x);
    };

    void printMatrix(std::vector<std::vector<int>> &Matrix);
    void Lab2(graph G, int startPos);
    void Lab3(graph G);
    void Lab4(graph G);
    void Lab5 (graph G);

    void lab1(graph graph1, int i);
} // graph

#endif //LAB1_GRAPH_HPP
