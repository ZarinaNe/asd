#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Лабораторная работа №18 "
                 "\n Решить задачу о суммах подмножеств, используя жадный алгоритм." << std::endl;
    std::vector<int> set = {5, -7, 7, 3, -4}; // Исходное множество
    int max_sum = INT8_MAX; // Максимальное значение
    std::vector<int> resultSet; // Будущее подмножество суммы 0
    for(int index = 0; index < set.size(); index++) {
        std::vector<int> middleSet; // Промежуточное подмножество
        int sum = set[index];
        middleSet.push_back(sum);
        for(int i = 0; i < set.size(); i++) { // Для всех элементов исходного множества, кроме index
            if(i==index) continue;
            if(abs(sum + set[i]) < abs(sum)) { // Если модуль суммы sum и текущего элемента исходного множества меньше sum,
                sum += set[i];
                middleSet.push_back(set[i]);   // то полагаем, что этот элемент надо включить
            }
        }
        if(sum == 0) { // Нашли хотя бы одно промежуточное подмножество, этого достаточно
            resultSet = middleSet;
            break;
        }
        if(sum < max_sum ) {
            resultSet = middleSet;
            max_sum = sum;
        }
    }
    for(auto s: resultSet) {// Вывод всех элементов множества
        std::cout << s << " ";
    }
    return 0;
}
