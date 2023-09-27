
#include "DAWG.hpp"

int main() {
    std::cout << "Лабораторная работа №10"
                 "\nРеализовать алгоритм поиска по образцу с помощью конечного автомата" << std::endl;
    std::string s, t;
    std::cout << "Введите проверяемую строку s" << std::endl;
    std::cin >> s;
    std::cout << "Введите проверяемую подстроку t" << std::endl;
    std::cin >> t;
    DAWG suffix_auto(s);
    suffix_auto.DAWG_search(t);
    return 0;
}
