#include <iostream>
#include <string>
#include <vector>

std::vector<int> prefixFunction(std::string s) {
    std::vector<int> pi(s.length(), 0); // Будущая префикс функция, количество элементов = длине входной строки, заполним 0
    for (int i = 1; i < s.length(); i++) { // Индекс i указывает на элементы строки s, индекс j на элементы массива pi
        int j = pi[i - 1];  //текущая длина префикса, который мы хотим продолжить
        while (j > 0 && s[i] != s[j]) {//уменьшаем его длину до следующей возможной
            j = pi[j - 1];
        }
        //Теперь j - максимальная длина префикса, который мы можем продолжить, или 0, если такового не существует.
        if (s[i] == s[j]) {
            pi[i] = j + 1;
        } else {
            pi[i] = 0;  //такое может произойти только при j = 0
        }
    }
    return pi;
}

int KMP_search(std::string s, std::string subS, int start_index) {
    std::vector <int> pi = prefixFunction(subS);
    int j = 0; // указывает на символы подстроки
    for (int i = start_index; i < s.length(); i++) {
        while (j > 0 && s[i] != subS[j])  {// Пока текущий символ строки не совпадают с j символом подстроки и индекс j > 0
            j = pi[j-1]; //значение j берется из π[j-1]
        }
        if(s[i] == subS[j]) {  // Если мы добились совпадающих символов, то увеличваем j на 1
            j += 1;
        }
        if(j >= subS.length()) {// Если после увеличения j = длине подстроки, то мы нашли искомую подстроку и вернем
            return i - j + 1; //Первый символ с которого, наша subS содержится в S
        }
    }
    return -1; // Мы прошли по всем элементам s и ничего не нашли;
}


int main() {
    std::cout << "Лабораторная работа №12"
                 "\nРеализовать алгоритм Кнута-Морриса-Пратта для поиска по образцу" << std::endl;
    std::string s, t;
    std::cout << "Введите проверяемую строку s" << std::endl;
    std::cin >> s;
    std::cout << "Введите проверяемую подстроку t" << std::endl;
    std::cin >> t;
    int pos = KMP_search(s, t, 0);
    if (pos == -1) {
        std::cout << "Подстрока не найдена" << std::endl;
    } else {
        std::cout << "Подстрока находится на позиции = " << pos << std::endl;
    }
    return 0;
}
