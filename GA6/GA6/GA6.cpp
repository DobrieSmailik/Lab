// GA6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// ----------------------------
// Задача 1: Дейкстра по матрице
// ----------------------------
void solveTask1() {
    int N, S, F;
    cin >> N >> S >> F;
    S--; F--;

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            if (x == -1)
                graph[i][j] = INF;
            else
                graph[i][j] = x;
        }
    }

    vector<int> dist(N, INF);
    vector<bool> visited(N, false);
    dist[S] = 0;

    for (int iter = 0; iter < N; ++iter) {
        int u = -1;
        for (int i = 0; i < N; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (u == -1 || dist[u] == INF) break;
        visited[u] = true;

        for (int v = 0; v < N; ++v) {
            if (graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    if (dist[F] == INF)
        cout << -1 << endl;
    else
        cout << dist[F] << endl;
}

// ----------------------------
// Задача 2: Заправки
// ----------------------------
void solveTask2() {
    int N;
    cin >> N;

    vector<int> cost(N);
    for (int i = 0; i < N; ++i)
        cin >> cost[i];

    int M;
    cin >> M;

    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Особый случай: один город
    if (N == 1) {
        cout << 0 << endl;
        return;
    }

    vector<int> dist(N, INF);
    vector<bool> visited(N, false);
    dist[0] = 0;

    for (int iter = 0; iter < N; ++iter) {
        int u = -1;
        for (int i = 0; i < N; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (u == -1 || dist[u] == INF) break;
        visited[u] = true;

        for (int v : adj[u]) {
            // Платим за бензин в городе u при выезде
            if (dist[u] + cost[u] < dist[v]) {
                dist[v] = dist[u] + cost[u];
            }
        }
    }

    if (dist[N - 1] == INF)
        cout << -1 << endl;
    else
        cout << dist[N - 1] << endl;
}

// ----------------------------
// Основная функция
// ----------------------------
int main() {
    solveTask1();
    solveTask2();
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
