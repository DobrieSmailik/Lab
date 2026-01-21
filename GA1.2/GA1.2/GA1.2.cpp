// GA1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <cstdlib>
#include <ctime>

void selectionSort(int array[], int f) { // Функция сортировки выбором по убыванию
    for (int i = 0; i < f - 1; ++i) {
        int maxIndex = i;
        for (int g = i + 1; g < f; ++g) {
            if (array[g] > array[maxIndex]) {
                maxIndex = g;
            }
        }
        if (maxIndex != i) {
            std::swap(array[i], array[maxIndex]);
        }
    }
}

void printArray(int array[], int f) {
    for (int i = 0; i < f; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int SIZE = 20;
    int array[SIZE];

    std::srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < SIZE; ++i) {
        array[i] = std::rand() % 101;
    }
    setlocale(LC_CTYPE, "Russian");
    std::cout << "Исходный массив:\n";
    printArray(array, SIZE);

    selectionSort(array, SIZE);

    std::cout << "Массив, отсортированный по убыванию:\n";
    printArray(array, SIZE);

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
