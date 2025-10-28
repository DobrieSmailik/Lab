// 3.2 Lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

// 1. Функция, принимающая указатели на начало и конец массива и возвращающая сумму элементов
// Примечание: "конец" — это указатель на элемент ПОСЛЕ последнего (как в STL)
int sumArray(int* begin, int* end) {
    int sum = 0;
    for (int* p = begin; p != end; ++p) {
        sum += *p;
    }
    return sum;
}

// 3. Функции суммы и разности
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// 5. Функция, возвращающая указатель на функцию в зависимости от char
// Тип указателя на функцию: int (*)(int, int)
int (*getOperation(char op))(int, int) {
    if (op == '+') {
        return add;
    }
    else if (op == '-') {
        return subtract;
    }
    else {
        // В реальном коде лучше обработать ошибку, но для простоты вернём nullptr
        return nullptr;
    }
}

int main() {
    // 2. Проверка функции sumArray
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int total = sumArray(arr, arr + size); // arr + size — указатель за последний элемент
    cout << "Сумма элементов массива: " << total << endl; // Ожидается: 150
    cout << endl;

    // 6. Проверка функций через указатель на функцию
    char operation = '+';
    int (*funcPtr)(int, int) = getOperation(operation);

    if (funcPtr != nullptr) {
        int result = funcPtr(15, 7);
        cout << "Результат операции '" << operation << "': " << result << endl; // 22
    }

    operation = '-';
    funcPtr = getOperation(operation);
    if (funcPtr != nullptr) {
        int result = funcPtr(15, 7);
        cout << "Результат операции '" << operation << "': " << result << endl; // 8
    }
    cout << endl;

    // 7. Создание динамического указателя типа float
    float* dynFloat = new float(3.14f);

    // 8. Вывод указателя (адреса) и удаление
    cout << "Адрес динамического float: " << dynFloat << endl;
    cout << "Значение по адресу: " << *dynFloat << endl;

    delete dynFloat; // освобождение памяти
    dynFloat = nullptr; // хорошая практика — избежать dangling pointer

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
