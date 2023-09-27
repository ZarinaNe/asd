#include "graph.hpp"

graph::graph(std::vector<std::vector<int>> g) {
    _g = g;
}

bool graph::isEulerGraph() {
    for (int i = 0; i < _g.size(); i++) {
        if(GetDegree(i) % 2 == 1)
            return false;
    }
    return true;
}

int graph::GetDegree(int x) {
    int degree = 0;
    for (int i = 0; i < _g.size(); i++) {
        if(_g[x][i] == 1) degree++;
    }
    return degree;
}

int graph::GetAdjV(int x) {
    for (int i = 0; i < _g.size(); i++) {
        if(_g[x][i] == 1) {
            return i;
        }
    }
    return -1;
}

void graph::FindEulerCycle() {
    if(!isEulerGraph()) {
        std::cout << "Граф не содержит эйлеров цикл" << std::endl;
        return;
    }
    std::stack<int> st;
    std::vector<int> res;
    st.push(0);
    while(!st.empty()) {
        int cur_v = st.top();
        int v_Adj = GetAdjV(cur_v);
        if (v_Adj != -1) {
            st.push(v_Adj);
            _g[cur_v][v_Adj] = _g[v_Adj][cur_v] = 0;
        } else {
            while (GetAdjV(st.top()) == -1) {
                res.push_back(st.top());
                st.pop();
                if (st.empty()) { break; }
            }
        }
    }
    std::cout << "Эйлеров цикл:" << std::endl;
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
}
