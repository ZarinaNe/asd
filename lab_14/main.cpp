#include <iostream>
#include <cmath>

#define B 13 // константа B
#define Q 997 // любое простое число

std::string get_sub_string(std::string s, int startPos, int lastPos) {
    std::string subS;
    for (int k = startPos; k <= startPos+lastPos; k++) {
        if (k > s.length()-1) { break; }
        subS += s[k];
    }
    return subS;
} // Возвращает подстроку в интервале от startPos до lastPos

int get_hash(std::string s) {
    int hornerHash = 0;
    for(int i = 0; i < s.length(); i++) {
        hornerHash = (B * hornerHash + int(s[i])) % Q; // метод Хорнера вычисления полиномиального многочлена
    }
    return hornerHash;
}

int search_pattern_in_string(std::string text, std::string pattern) {
    int count_pattern = 0; // Возвращаемое значение функции - это количество совпадений в строке;
    int pattern_len = pattern.length();
    int text_len = text.length();
    if(text_len < pattern_len) {
        return -1;
    }
    int m = pow(B,pattern_len-1); // Значение B в максимально возможной степени

    //Находим хэш паттерна и хэш первой подстроки text
    int pattern_hash = get_hash(pattern);
    int text_hash = get_hash(get_sub_string(text,0,pattern_len-1)); // Хэш первой посдтроки длины паттерна
    // Проходим по каждому символу строки
    for (int i = 0; i < text_len - pattern_len + 1; i++)
    {
        if(pattern_hash == text_hash)
        {
            std::string s = get_sub_string(text,i,pattern_len-1);
            if(s==pattern) {
                count_pattern++;
            } else {
                std::cout << "Случилась коллизия" << " ";
                break;
            }
        }
        if(i < text_len - pattern_len) {
            text_hash = ((text_hash - int(text[i]) * m) * B + int(text[i + pattern_len])) % Q;
        } //Скользящий хэш
        if (text_hash < 0) {
            text_hash += Q;
        }
    }
    return count_pattern;
}

int main() {
    std::cout << "Лабораторная работа №14"
                 "\nРеализовать алгоритм Рабина для поиска по образцу" << std::endl;
    std::string s, t;
    std::cout << "Введите проверяемую строку s" << std::endl;
    std::cin >> s;
    std::cout << "Введите проверяемую подстроку t" << std::endl;
    std::cin >> t;
    int pos = search_pattern_in_string(s, t);
    if (pos != -1) {
        std::cout << "Количество искомых подстрок в тексте = " << pos << std::endl;
    } else {
        std::cout << "Подстрока не найдена" << std::endl;
    }
    return 0;
}
