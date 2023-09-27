#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;

    // Конструктор для создания точки с заданными координатами
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// Функция для определения ориентации трех точек (p, q, r)
// Возвращает значение > 0, если точки p, q, r образуют левый поворот,
// значение < 0, если точки образуют правый поворот и 0, если точки коллинеарны
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val > 0) {
        return 1;  // Левый поворот
    } else if (val < 0) {
        return -1; // Правый поворот
    }
    return 0;     // Коллинеарность
}

// Функция для сортировки точек по полярному углу относительно самой нижней левой точки
bool compare(Point p1, Point p2) {
    int orientationVal = orientation(Point(0, 0), p1, p2);
    if (orientationVal == 0) {
        // Если точки коллинеарны, выбираем ближайшую к начальной точке
        return (p1.x * p1.x + p1.y * p1.y) < (p2.x * p2.x + p2.y * p2.y);
    }
    return orientationVal > 0;
}

// Функция для нахождения выпуклой оболочки
vector<Point> findConvexHull(vector<Point>& points) {
    int n = points.size();

    // Находим самую нижнюю левую точку (startPoint)
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[minIndex].y ||
            (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x)) {
            minIndex = i;
        }
    }

    // Переносим самую нижнюю левую точку в начало массива
    swap(points[0], points[minIndex]);

    // Сортируем остальные точки по полярному углу относительно начальной
    sort(points.begin() + 1, points.end(), compare);

    // Создаем стек и помещаем первые две точки в стек
    stack<Point> convexHull;
    convexHull.push(points[0]);
    convexHull.push(points[1]);

    // Обходим оставшиеся точки и добавляем их в выпуклую оболочку
    for (int i = 2; i < n; i++) {
        while (convexHull.size() >= 2) {
            Point p2 = convexHull.top();
            convexHull.pop();
            Point p1 = convexHull.top();
            int orientationVal = orientation(p1, p2, points[i]);
            if (orientationVal >= 0) {
                // Если точка i образует левый поворот, добавляем ее в стек
                convexHull.push(p2);
                break;
            }
        }
        convexHull.push(points[i]);
    }

    // Конвертируем стек в вектор и возвращаем выпуклую оболочку
    vector<Point> hull;
    while (!convexHull.empty()) {
        hull.push_back(convexHull.top());
        convexHull.pop();
    }

    return hull;
}

int main() {
    int n;
    cout << "Введите количество точек: ";
    cin >> n;

    vector<Point> points;
    int x, y;
    cout << "Введите координаты точек (x, y):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back(Point(x, y));
    }

    // Находим выпуклую оболочку
    vector<Point> convexHull = findConvexHull(points);

    // Выводим вершины выпуклой оболочки
    cout << "Вершины выпуклой оболочки:" << endl;
    for (int i = 0; i < convexHull.size(); i++) {
        cout << "(" << convexHull[i].x << ", " << convexHull[i].y << ")" << endl;
    }

    return 0;
}