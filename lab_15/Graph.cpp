
#include "Graph.hpp"

bool Graph::compare(std::pair<int, int> p1, std::pair<int, int> p2) {
    return p1.second > p2.second;
}

int Graph::getDegree(int x) {
    int degree = 0;
    for (int i = 0; i < _g.size(); i++) {
        if(_g[x][i] == 1) { degree++; }
    }
    return degree;
}

int Graph::next(int cur) {
    for (int i = 0; i < _g.size(); i++) {
        if(!_isColored[_D[i].first]) {
            return _D[i].first;
        }
    }
    return -1;
}

Graph::Graph(std::vector<std::vector<int>> g) {
    _g = g;
    for(int i = 0; i < g.size(); i++)
    {
        _isColored.push_back(false); // Изначально все вершины не окрашены
        // Заполнение массива D
        int d = getDegree(i);
        std::pair<int,int> p(i,d);
        _D.push_back(p);
    }
    // Отсортировка массива D по неубыванию
    std::sort(_D.begin(),_D.end(), compare);
}

std::vector<int> Graph::GetAdjacentNodes(int node) {
    std::vector<int> AdjNodes;
    for (int i = 0; i < _g.size(); i++) {
        if (_g[node][i] == 1 && _isColored[i]) {
            AdjNodes.push_back(i);
        }
    }
    return AdjNodes;
}

int Graph::Coloring(std::string *colors) {
    int chromatic_num = 0;
    std::string color_v[_g.size()]; // Массив, который хранит для каждой вершины ее цвет
    for(int i = 0; i < _g.size(); i++) // Изначально все вершины не имеют цвета
        color_v[i] = "";
// Инциализируем начальные данные, шаг 0:
    int cur = _D[0].first; //Первая вершина, которая имеет наивысшую степень
    int colorNum = 0; // Порядковый номер цвета в массиве colors
//Последующие шаги:
    while (cur != -1)
    {
        _isColored[cur] = true; // Отметили как окрашенную текущую выбранную вершину
        color_v[cur] = colors[colorNum]; // Дали конкретный цвет вершине сur из массива colors
        std::cout << "Окрасили в цвет " << color_v[cur] << " вершины: "<< cur << " ";
        for(int i = cur; i < _D.size(); i++) // Для всех вершин массива D
        {
            if(_isColored[_D[i].first] || _g[cur][_D[i].first] == 1) continue; // окрашенные и смежные вершины мы пропускаем
            std::vector <int> adj = GetAdjacentNodes(_D[i].first);// Смотрим ОКРАШЕННЫЕ вершины СМЕЖНЫЕ с нашей вершиной D[i].first ( i - вершина не смежная с cur)
            bool flag_same_color = false; // Пологаем: Смежная вершина с i имеет НЕ тот же цвет, что  и текущая
            for (int j = 0; j < adj.size(); j++) // Проверка предположения
            {
                if (color_v[adj[j]] == color_v[cur]) // Цвет соседа D[i] совпал с цветом текущим - пропускам D[i]
                {
                    std::cout << adj[j] << "<--->"<< color_v[adj[j]] << std::endl;
                    flag_same_color = true;
                    break;
                }
            }
            if(!flag_same_color)
            {
                // Окрашиваем вершину i в один цвет с текущей вершиной
                _isColored[_D[i].first] = true;
                color_v[_D[i].first]= color_v[cur];
                std::cout << _D[i].first << " ";
            }
        }
        chromatic_num++;
        std::cout << std::endl;
        colorNum++;
        cur = next(cur);
    }
    return chromatic_num;
}
