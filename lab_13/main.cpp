#include <iostream>
#include <map>

bool contains(std::map<char, int> m, char c) {
    if(m.find(c) != m.end()) {
        return true;
    } else {
        return false;
    }
}

std::map<char, int> getHashTable(std::string s) {
    std::map<char,int> table; // Ассоциативный массив в формате символ --> удаленность от конца строки
    table['*'] = s.length()-1; // Для любых символов, которые не содержаться в строке s
    for(int i = s.length()-2; i > -1; i--) {
        if(!contains(table,s[i])) {// Если в первые встречаем символ
            int value = (s.length()-1)-i;
            table.insert(std::make_pair(s[i],value));
        }
    }
    if(!contains(table,s[s.length()-1])) {// Если последний символ строки раннее не был встречен
        int value = s.length()-1;
        table.insert(std::make_pair(s[s.length()-1],value));
    }
    return table;
}

int BM_search(std::string s, std::string subS) {
    std::map<char, int> offsetTable = getHashTable(subS); // Таблица хэшей
    if (s.length() < subS.length()) {
        return -1;
    }
    int i = subS.length() - 1; // указатель на текущий символ строки
    int j = i; // указатель на текущий символ образца
    int k = i; // вспомогательный указатель тоже на строчку s
    while (j >= 0 && i <= s.length() - 1) {
        j = subS.length() - 1; // j изначально смотрит в последний символ образца
        k = i;
        while (j >= 0 && s[k] == subS[j]) {
            k--;
            j--;
        }
        if(contains(offsetTable,s[i])) {
            i += offsetTable[s[i]]; // значение по ключу s[i]
        } else {
            i += offsetTable['*']; // двигаем на длину подстроки
        }
    }
    if (k >= s.length() - subS.length()) {// вышли за строку и ничего не нашли
        return -1;
    } else {
        return k + 1; // указатель на элемент строки, с которого начинается искомая подстрока
    }
}

int main() {
    std::cout << "Лабораторная работа №13"
                 "\nРеализовать алгоритм Бойера-Мура для поиска по образцу" << std::endl;
    std::string s, t;
    std::cout << "Введите проверяемую строку s" << std::endl;
    std::cin >> s;
    std::cout << "Введите проверяемую подстроку t" << std::endl;
    std::cin >> t;
    int pos = BM_search(s, t);
    if (pos != -1) {
        std::cout << "Подстрока находится на позиции = " << pos << std::endl;
    } else {
        std::cout << "Подстрока не найдена" << std::endl;
    }
    return 0;
}
