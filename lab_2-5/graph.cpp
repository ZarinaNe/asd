#include "graph.hpp"

namespace graph {
    int graph::GetUnvisitedNode() {
        for (int i = 0; i < _size; i++) {
            if (!_visitedNodes[i]) {
                return i;
            }
        }
        return -1;
    }

    graph::graph(int size, std::vector<std::vector<int>> g) {
        _size = size;
        _g = g;
        _visitedNodes = std::vector<bool>(size, false);
    }

    void graph::printGraph() {
        for (auto& i : _g) {
            for (auto& j : i) {
                std::cout << i[j] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::vector<int> graph::GetAdjacentNodes(int node) {
        std::vector<int>AdjNodes;
        for (int i = 0; i < _g.size(); i++) {
            if (_g[node][i] != 0) {
                AdjNodes.push_back(i);
            }
        }
        return AdjNodes;
    }

    void graph::BFS(int startPos) {
        // Шаг 0:
        std::queue<int> q; // Очередь, где будут находится все встречаемые нами вершины
        int distanse[_size]; // Массив расстояний от стартовой вершины до всех остальных
        for(int i = 0; i < _size; i++) {
            distanse[i] = -1;
        }
        q.push(startPos); // Помещаем стартовую в очередь
        distanse[startPos] = 0; // Обновляем расстояние до самой себя, равно = 0;
        //Шаг 1 и последующие
        while (!q.empty()) {// Пока очередь не пуста
            int curNode = q.front(); // Извлекаем вершину в начале очереди
            q.pop(); // удаляем
            _visitedNodes[curNode] = true; // обновляем посещения
            std::vector<int> AdjNodes = GetAdjacentNodes(curNode); // Получаем соседей
            for (int i = 0; i < AdjNodes.size();i++)  {// Для каждого из полученных соседей
                if(!find_Q(q,AdjNodes[i]) && !_visitedNodes[AdjNodes[i]]) { // Нет ли нашего соседа в очереди или в посещенных
                    q.push(AdjNodes[i]); // Помещаем в очередь, если условие верно
                    distanse[AdjNodes[i]] = distanse[curNode]+1; // обновляем расстояния
                }
            }
        }
        //Таким образом массив distance содержит кратчайшие расстояния от стартовой вершины до всех остальных. Печатаем их.
        std::cout << "\nРасстояние расчитаны от стартовой вершины = " << startPos << std::endl;
        std::cout << "Вершина    ";
        for (int i = 0; i < _size; i++) {
            std::cout << i << "|";
        }
        std::cout << "\nРасстояния ";
        for (int i = 0; i < _size; i++) {
            if(distanse[i] > -1) {
                std::cout << distanse[i] << "|";
            } else {
                std::cout << "x" << "|";
            }
        }
    }// Алгоритм обхода графа в ширину и поиска кратчайших путей.

    bool graph::find_Q(std::queue<int> Q, int x) {
        while(!Q.empty()) {
            if(Q.front() == x) { return true; }
            Q.pop();
        }
        return false;
    }

    bool graph::find_L(std::list<int> L, int x) {
        while(!L.empty()) {
            if(L.front() == x) { return true; }
            L.pop_front();
        }
        return false;
    }

    void graph::FindConnectivityComponentByBFS() {
        int cntComponent = 0; // Количество компонент связности графа
        while (GetUnvisitedNode() > -1) {
            BFS(GetUnvisitedNode()); // Получаем первую попавшуюся непосещенную и для нее BFS
            cntComponent++;
        }
        _visitedNodes = std::vector<bool>(_size, false);
        std::cout << "\nКоличество компонент связности графа = " << cntComponent;
    }// Алгоритм подсчета компонентов связности, c помощью BFS

    void graph::recursiveDFS(int startPos) {
        std::cout << startPos  << " ";
        _visitedNodes[startPos]=true;
        for (int i=0; i<_size; i++) {
            if ((_g[startPos][i] != 0) && (!_visitedNodes[i])) { // База рекурсии
                recursiveDFS(i);
            }
        }
    }//Рекурсивный обход в глубину

    void graph::FindConnectivityCompopnentByDFS() {
        int cntComponent = 0; // Количество компонент связности графа
        while (GetUnvisitedNode() > -1) {//  Пока у нас не все вершины в графе,отмечены как посещенные
            std::cout << "Компонента связности №" << cntComponent+1 << ": ";
            recursiveDFS(GetUnvisitedNode()); //Получаем первую попавшуюся непосещенную
            cntComponent++;
            std::cout << std::endl;
        }
        _visitedNodes = std::vector<bool>(_size, false);
        std::cout << "Количество компонент связности графа = " << cntComponent;
    }// Алгоритм подсчета компонентов связности, c помощью DFS

    std::vector<std::vector<int>> graph::GetReachabilityMatrix() {
        std::vector<std::vector<int>> reachabilityMatrix(_size, std::vector<int>(_size, 0)); // Будущая матрица достижимости
        for(int i = 0; i < _size; i++) { // Для каждой вершины,иттеративный DFS
            std::list<int> stack; // CД FIFO
            std::vector<int> Adj_i; // Массив достижимых соседей для текущей верщины i
            stack.push_front(i); // Помещаем текущую вершину i в стэк
            Adj_i.push_back(i);// Каждая вершина достижима сама для себя
            _visitedNodes[i] = true; // Отмечаем ее как посещенную вершину
            while (!stack.empty()) {// Пока стэк не пуст
                int curNode = stack.front(); // Снимаем с вершины стэыка вершину curNode графа
                stack.pop_front(); // Удаляем ее из графа
                _visitedNodes[curNode] = true; // Отмечаем посещенной
                std::vector <int> AdjNodes = GetAdjacentNodes(curNode); // Для curNode ищем соседей
                for (int j = 0; j < AdjNodes.size(); j++) {// Для каждого соседа curNode
                    if (!_visitedNodes[AdjNodes[j]]) {// Если сосед curNode не посещен еще
                        if (find_L(stack, AdjNodes[j])) { // Но сосед curNode уже в стэке
                            stack.remove(AdjNodes[j]); // Удаляеи из стэка и затем продвинем ее к вершине
                        }
                        stack.push_front(AdjNodes[j]); // Добавляем в стэк
                        Adj_i.push_back(AdjNodes[j]); // добавляем в достижмые соседи для нашей вершины i
                    }
                }
            }
            // Затем масссив Adj_i содержит все достижмые из i вершины. Заполняем матрицу достижимсоти
            for (int k: Adj_i) {
                reachabilityMatrix[i][k] = 1;
            }
            _visitedNodes = std::vector<bool>(_size, false);
        }
        return reachabilityMatrix;
    }

    std::vector<std::vector<int>> graph::GetProductMatrix(std::vector<std::vector<int>> reachMatrix) {
        std::vector<std::vector<int>> M(_size,std::vector<int>(_size,0));
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                M[i][j] = reachMatrix[j][i]*reachMatrix[i][j];
            }
        }
        return M;
    }

    void graph::FindStrongComponents() {
        std::vector<std::vector<int>> components;
        std::vector<std::vector<int>> reachMatrix = GetReachabilityMatrix(); // Вычисляем матрицу достижимости
        std::vector<std::vector<int>> M = GetProductMatrix(reachMatrix); // Поэлементное произведение (reachMatrix)^T * reachMatrix;
        // В итоге мы получим матрицу у которой некоторые строки будут одинаковыми, они и формируют сильные компоненты связности
        for (int i = 0; i < _size; i++) {
            if(_visitedNodes[i])
                continue;
            _visitedNodes[i] = true;
            std::vector <int> component_i;
            component_i = std::vector<int>(1,i);
            for(int j = i+1; j < _size; j++) {
                if(M[i] == M[j]) {
                    _visitedNodes[j] = true;
                    component_i.push_back(j);
                }
            }
            components.push_back(component_i);
        }
        _visitedNodes = std::vector<bool>(_size, false);
        // Печать компонентов сильной связности
        std::cout << "Количество сильных компонентов связности графа = " << components.size() << std::endl;
        for (int i = 0; i < components.size(); i++) {
            std::cout << "Cильная компонента № "<< i+1 << ": ";
            auto component = components[i];
            for(int node: component) {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        }
    }


    void printMatrix(std::vector<std::vector<int>> &Matrix) {
        std::cout << "Matrix" << std::endl;
        for (auto& i : Matrix) {
            for (auto& j : i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void Lab2(graph G, int startPos) {
        std::cout << "Лабораторная работа №2 "
                     "\nНайти в заданном графе кратчайшие пути из заданной вершины"
                     " до всех остальных вершин с помощью поиска в ширину" << std::endl;
        G.BFS(startPos);
        std::cout << std::endl;
    }

    void Lab3(graph G) {
        std::cout << "Лабораторная работа №3 "
                     "\nНайти в заданном графе количество и состав компонент связности"
                     " с помощью поиска в ширину." << std::endl;
        G.FindConnectivityComponentByBFS();
        std::cout << std::endl;
    }

    void Lab4(graph G) {
        std::cout << "Лабораторная работа №4 "
                     "\nНайти в заданном графе количество и состав компонент"
                     " связности с помощью поиска в глубину" << std::endl;
        G.FindConnectivityCompopnentByDFS();
        std::cout << std::endl;
    }

    void Lab5(graph G) {
        std::cout << "Лабораторная работа №5 "
                     "\nНайти в заданном орграфе количество и состав"
                     " сильно связных компонент с помощью поиска в глубину." << std::endl;
        G.FindStrongComponents();
        std::cout << std::endl;
    }
} // graph