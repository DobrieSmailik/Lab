// GA5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Функция для BFS с восстановлением пути
vector<string> bfsShortestPath(const unordered_map<string, vector<string>>& graph,
    const string& start, const string& end) {
    if (start == end) return { start };

    queue<string> q;
    unordered_map<string, string> parent; // для восстановления пути
    unordered_set<string> visited;

    q.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        for (const string& neighbor : graph.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                parent[neighbor] = current;
                q.push(neighbor);

                if (neighbor == end) {
                    // Восстанавливаем путь
                    vector<string> path;
                    string node = end;
                    while (!node.empty()) {
                        path.push_back(node);
                        node = parent[node];
                    }
                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }

    // Путь не найден
    return {};
}

int main() {
    // Определяем граф лабиринта (список смежности)
    unordered_map<string, vector<string>> graph = {
        {"S", {"A", "B", "E"}},
        {"A", {"S", "F"}},
        {"B", {"S", "C", "D"}},
        {"C", {"B", "J"}},
        {"D", {"B", "G", "E"}},
        {"E", {"S", "D", "F"}},
        {"F", {"A", "E", "G"}},
        {"G", {"D", "F", "H"}},
        {"H", {"G"}},
        {"I", {"J"}},
        {"J", {"C", "I"}}
    };

    string start = "S";
    string end = "I";



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
