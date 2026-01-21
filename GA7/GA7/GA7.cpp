// GA7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // ======================
    // Задача 1: Лекции
    // ======================
    int N;
    cin >> N;
    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; ++i) {
        cin >> lectures[i].first >> lectures[i].second;
    }

    // Сортируем по времени окончания
    sort(lectures.begin(), lectures.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });

    int countLectures = 0;
    int lastEnd = -1;
    for (int i = 0; i < N; ++i) {
        if (lectures[i].first >= lastEnd) {
            countLectures++;
            lastEnd = lectures[i].second;
        }
    }

    cout << countLectures << '\n';

    // ======================
    // Задача 2: Коробки
    // ======================
    int n;
    cin >> n;
    vector<pair<long long, long long>> boxes(n); // (вес, грузоподъёмность)
    for (int i = 0; i < n; ++i) {
        long long w, c;
        cin >> w >> c;
        boxes[i] = { w, c };
    }

    // Сортируем по w + c
    sort(boxes.begin(), boxes.end(), [](const auto& a, const auto& b) {
        return a.first + a.second < b.first + b.second;
        });

    long long totalWeight = 0;
    int countBoxes = 0;
    for (int i = 0; i < n; ++i) {
        if (totalWeight <= boxes[i].second) {
            countBoxes++;
            totalWeight += boxes[i].first;
        }
    }

    cout << countBoxes << '\n';

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
