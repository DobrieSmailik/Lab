// GA2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

// === Задача 1: Вывести числа от 1 до n ===
void printFrom1ToN(int current, int n) {
    if (current > n) return;
    std::cout << current << " ";
    printFrom1ToN(current + 1, n);
}

// === Задача 2: Вывести числа от A до B (в нужном порядке) ===
void printRange(int a, int b) {
    std::cout << a << " ";
    if (a == b) return;
    if (a < b)
        printRange(a + 1, b);
    else
        printRange(a - 1, b);
}

// === Задача 3: Сумма цифр числа ===
int digitSum(int n) {
    if (n == 0) return 0;
    return (n % 10) + digitSum(n / 10);
}

// === Задача 4: Простые делители (O(√n)) ===
void primeFactors(int n, int divisor = 2) {
    if (n == 1) return;
    if (divisor * divisor > n) {
        std::cout << n << " ";
        return;
    }
    if (n % divisor == 0) {
        std::cout << divisor << " ";
        primeFactors(n / divisor, divisor);
    }
    else {
        primeFactors(n, divisor + 1);
    }
}

// === Основная функция ===
int main() {
    int n, A, B, N, N2;

    // --- Задача 1 ---
    std::cin >> n;
    printFrom1ToN(1, n);
    std::cout << std::endl;

    // --- Задача 2 ---
    std::cin >> A >> B;
    printRange(A, B);
    std::cout << std::endl;

    // --- Задача 3 ---
    std::cin >> N;
    std::cout << digitSum(N) << std::endl;

    // --- Задача 4 ---
    std::cin >> N2;
    primeFactors(N2);
    std::cout << std::endl;

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
