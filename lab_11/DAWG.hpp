
#ifndef LAB_ASD_11_DAWG_HPP
#define LAB_ASD_11_DAWG_HPP
#include <iostream>
#include <map>
#include <vector>
#include <string>
#define MAXLEN 10000

struct state {//структура данных, которая хранит всю информацию о конкретном переходе.
    // Суффиксный автомат - массив состояний.
    int len; // длина перехода
    int link;// ссылка
    std::map<char,int> next; // список переходов
};
class DAWG {
private:
    state _st[MAXLEN]; // массив состояний
    int _sz = 0; // cчётчик состояний. Начальное состояние - это нулевое состояние;
    int _last = 0; //это состояние, соответствующее всей текущей строке до добавления символа c.
    std::string _s; // строка, по которой строим автомат
public:
    DAWG(std::string s);
    void DAWG_extend(char c);
    void getDAWG();
    bool DAWG_search(std::string t);
};


#endif //LAB_ASD_11_DAWG_HPP
