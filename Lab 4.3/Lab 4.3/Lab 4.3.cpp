// Lab 4.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>

// ============ ОПРЕДЕЛЕНИЕ КЛАССА (как в Weapon.h) ============
class Weapon {
public:
    std::string name;
    double weight;

    Weapon(const std::string& n = "Неизвестное", double w = 0.0);
    ~Weapon();

    bool isTooHeavy(double maxWeight) const;
    double getTotalWeight(const Weapon& other) const;
    double getTotalWeight(double otherWeight) const;
};

// ============ РЕАЛИЗАЦИЯ МЕТОДОВ (как в Weapon.cpp) ============

Weapon::Weapon(const std::string& n, double w) : name(n), weight(w) {
    std::cout << "Создано оружие: " << name << " (вес: " << weight << " кг)" << std::endl;
}

Weapon::~Weapon() {
    std::cout << "Удаляется оружие: " << name << " (вес: " << weight << " кг)" << std::endl;
}

bool Weapon::isTooHeavy(double maxWeight) const {
    return weight > maxWeight;
}

double Weapon::getTotalWeight(const Weapon& other) const {
    return getTotalWeight(other.weight); // используем перегрузку
}

double Weapon::getTotalWeight(double otherWeight) const {
    return weight + otherWeight;
}

// ============ ОСНОВНАЯ ПРОГРАММА ============
int main() {
    setlocale(LC_ALL, "ru");
    // 2. Статический объект
    Weapon sword("Меч", 3.5);
    std::cout << "Статический объект: " << sword.name << ", вес: " << sword.weight << " кг" << std::endl;

    // 3. Динамический объект
    Weapon* axe = new Weapon("Топор", 5.2);
    std::cout << "Динамический объект: " << axe->name << ", вес: " << axe->weight << " кг" << std::endl;

    // 9. Проверка всех методов
    double maxLift = 4.0;

    if (sword.isTooHeavy(maxLift)) {
        std::cout << sword.name << " слишком тяжёл для подъёма (макс. " << maxLift << " кг)" << std::endl;
    }
    else {
        std::cout << sword.name << " можно поднять (макс. " << maxLift << " кг)" << std::endl;
    }

    if (axe->isTooHeavy(maxLift)) {
        std::cout << axe->name << " слишком тяжёл для подъёма (макс. " << maxLift << " кг)" << std::endl;
    }
    else {
        std::cout << axe->name << " можно поднять (макс. " << maxLift << " кг)" << std::endl;
    }

    std::cout << "Общий вес меча и топора: " << sword.getTotalWeight(*axe) << " кг" << std::endl;
    std::cout << "Общий вес меча и 2.0 кг: " << sword.getTotalWeight(2.0) << " кг" << std::endl;

    // 4. Удаление динамического объекта → вызов деструктора
    delete axe;

    // Деструктор для sword вызовется автоматически при выходе из main
    return 0;
}

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.