// GA3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

// ========================
// 1. Быстрая сортировка для одномерного массива
// ========================
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

// ========================
// 2. Быстрая сортировка для двумерного массива (по первому столбцу)
// ========================
const int COLS = 5; // фиксированное число столбцов

void swapRows(int a[][COLS], int row1, int row2) {
    for (int j = 0; j < COLS; ++j)
        std::swap(a[row1][j], a[row2][j]);
}

void quickSort2D(int arr[][COLS], int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2][0];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i][0] < pivot) i++;
        while (arr[j][0] > pivot) j--;
        if (i <= j) {
            swapRows(arr, i, j);
            i++;
            j--;
        }
    }
    quickSort2D(arr, left, j);
    quickSort2D(arr, i, right);
}

// ========================
// 3. Структура и сравнение для qsort (задача 4)
// ========================
struct Student {
    char name[50];
};

int compareStudents(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

// ========================
// Основная функция
// ========================
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0)); // инициализация генератора

    std::cout << "=== Задача 1: Сортировка 1000 случайных чисел ===\n";
    const int N1 = 1000;
    int arr1[N1];
    for (int i = 0; i < N1; ++i)
        arr1[i] = rand();

    quickSort(arr1, 0, N1 - 1);

    std::cout << "Первые 10 отсортированных чисел: ";
    for (int i = 0; i < 10; ++i)
        std::cout << arr1[i] << " ";
    std::cout << "\n...\nПоследние 10: ";
    for (int i = N1 - 10; i < N1; ++i)
        std::cout << arr1[i] << " ";
    std::cout << "\n\n";

    // --------------------------------------------------

    std::cout << "=== Задача 2: Сортировка [50, 100] ===\n";
    const int N2 = 15;
    int arr2[N2];
    for (int i = 0; i < N2; ++i)
        arr2[i] = 50 + rand() % 51; // [50, 100]

    std::cout << "До: ";
    for (int x : arr2) std::cout << x << " ";
    std::cout << "\n";

    quickSort(arr2, 0, N2 - 1);

    std::cout << "После: ";
    for (int x : arr2) std::cout << x << " ";
    std::cout << "\n\n";

    // --------------------------------------------------

    std::cout << "=== Задача 3: Сортировка строк матрицы по первому столбцу ([5,61]) ===\n";
    const int ROWS = 6;
    int matrix[ROWS][COLS];

    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            matrix[i][j] = 5 + rand() % 57; // [5, 61]

    std::cout << "До:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }

    quickSort2D(matrix, 0, ROWS - 1);

    std::cout << "После (по первому столбцу):\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << "\n";

    // --------------------------------------------------

    std::cout << "=== Задача 4: Сортировка студентов по алфавиту (qsort) ===\n";
    Student students[] = {
        {"Иванов"},
        {"Петров"},
        {"Сидоров"},
        {"Алексеев"},
        {"Богданов"},
        {"Зайцев"},
        {"Волков"}
    };
    const int N4 = sizeof(students) / sizeof(students[0]);

    std::cout << "До:\n";
    for (int i = 0; i < N4; ++i)
        std::cout << students[i].name << "\n";

    qsort(students, N4, sizeof(Student), compareStudents);

    std::cout << "После (qsort):\n";
    for (int i = 0; i < N4; ++i)
        std::cout << students[i].name << "\n";

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
