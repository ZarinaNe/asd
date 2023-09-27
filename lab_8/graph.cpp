#include "graph.hpp"

int graph::find_min_unvisited(std::vector<int> V) {
    int MIN = INT8_MAX;
    int index;
    for (int i = 0; i < V.size(); i++) {
        if(V[i] < MIN && !_L_const[i])
        {
            MIN = V[i];
            index = i;
        }
    }
    return index;
}

graph::graph(std::vector<std::vector<int>> g) {
    _g = g;
    _L_const = std::vector<bool>(g.size(), false);
}

std::vector<int> graph::GetAdj(int vertex) {
    std::vector<int> result;
    for(int i = 0; i < _g.size(); i++ ) {
        if(_g[vertex][i] > 0 && !_L_const[i])
        {
            result.push_back(i);
        }
    }
    return result;
}

void graph::Dijkstra(int startV) {
    std::vector<int> L;
    for(int i = 0; i < _g.size(); i++) {
        if(startV!=i) {
            L.push_back(INT8_MAX); // Изначально пометки для всех вершин, кроме стартовой "бесконечность"
        }
        else {// Вводим начальные данные о стартовой вершине
            L.push_back(0);
            _L_const[startV] = true;
        }
    }
    int current_vertex = startV;
    int steps = 0;
    while (steps != _g.size()-1) {
        std::vector<int> AdjVertex = GetAdj(current_vertex);
        for (const int &v : AdjVertex) {
            int currentV = L[v];
            int possibleV = L[current_vertex]+_g[current_vertex][v];
            if(currentV > possibleV) {
                L[v] = possibleV;
            }
        }
        current_vertex = find_min_unvisited(L);
        _L_const[current_vertex] = true;
        steps++;
    }
    std::cout << "Результат работы алгоритма Дейкстры - поиск кратчайших путей в графе:" << std::endl;
    for (int i = 0; i < _g.size(); i++) {
        std::cout << "Кратчайшее растояние между " << startV << "<-->" << i <<" = " << L[i] << std::endl;
        _L_const[i] = false;
    }
    std::cout << "Количество итераций при алгоритме Дейкстры: " << steps << std::endl;
}

