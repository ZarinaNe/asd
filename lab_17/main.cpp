//  16.Решить задачу о раскладке по ящикам
#include <iostream>
#include <vector>
#include <cmath>

int boxes = 1;
void backpackProblem(std::vector<int>& things, int maxWeight) {
    int amount = things.size();
    int maxAmount = 0;
    std::vector<int> maxDelete;

    for (int i = 0; i < pow(2, amount); i++) {
        std::vector<int> doTake(amount, 0);

        int number = i;
        for (int j = 0; j < amount; j++) {
            doTake[amount - 1 - j] = number & 1;
            number >>= 1;
        }

        int nowWeight = 0;
        int nowAmount = 0;
        std::vector <int> nowDelete;
        for (int j = 0; j < amount; j++) {
            if (doTake[j]) {
                nowWeight += things[j];
                nowAmount++;
                nowDelete.push_back(j);
            }
        }
        if (nowWeight <= maxWeight && nowAmount > maxAmount) {
            maxAmount = nowAmount;
            maxDelete = nowDelete;
        }
    }

    std::cout << "Box #" << boxes << " : ";  //выводим какие положим в ящик
    for (int i : maxDelete) {
        std::cout << things[i] << " ";
    }
    std::cout << std::endl;
    boxes++;


    int count = 0;         //удаляем вещи
    for (int i : maxDelete) {
        things.erase(things.begin() + i - count);
        count++;
    }
    return;
}

int main() {                           //создаем вектор вещ
    int maxWeight = 10;
    std::vector<int> things({ 1, 2, 5, 4, 10 });

    while (!things.empty()) {                   //вызываем функции пока все вещи не разложим
        backpackProblem(things, maxWeight);
    }

    return 0;
}