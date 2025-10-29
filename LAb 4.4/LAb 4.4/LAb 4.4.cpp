// LAb 4.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

// ====== 9–13. Класс MyMath ======
class MyMath {
public:
    static int callCount; // 10. Статическое поле — счётчик вызовов

    static double Add(double a, double b) {
        ++callCount; // 11
        return a + b;
    }

    static double Sub(double a, double b) {
        ++callCount;
        return a - b;
    }

    static double Mult(double a, double b) {
        ++callCount;
        return a * b;
    }

    static double Div(double a, double b) {
        ++callCount;
        if (b == 0) {
            std::cerr << "Ошибка: деление на ноль!" << std::endl;
            return 0.0;
        }
        return a / b;
    }
};

// Определение статического поля (обязательно вне класса!)
int MyMath::callCount = 0;

// ====== 5. Класс Characteristic ======
class Weapon; // Предварительное объявление (forward declaration)

class Characteristic {
private:
    double strength;

public:
    Characteristic(double s) : strength(s) {}

    // 7. Метод, возвращающий сумму силы и урона оружия
    double GetDamage(const Weapon& weapon) const;
};

// ====== 1–4. Класс Weapon ======
class Weapon {
private:
    std::string name;
    double weight;
    double damage; // новое поле — урон

public:
    // Конструктор
    Weapon(const std::string& n = "Неизвестное", double w = 0.0, double d = 0.0)
        : name(n), weight(w), damage(d) {
        std::cout << "Создано оружие: " << name << " (вес: " << weight
            << " кг, урон: " << damage << ")" << std::endl;
    }

    // Деструктор
    ~Weapon() {
        std::cout << "Удаляется оружие: " << name << " (вес: " << weight
            << " кг, урон: " << damage << ")" << std::endl;
    }

    // 2. GET-методы
    std::string getName() const { return name; }
    double getWeight() const { return weight; }
    double getDamage() const { return damage; }

    // 3. SET-метод для урона
    void setDamage(double d) { damage = d; }

    // 6. Дружественный класс
    friend class Characteristic;
};

// ====== 7. Реализация GetDamage (после определения Weapon) ======
double Characteristic::GetDamage(const Weapon& weapon) const {
    return strength + weapon.damage; // доступ к приватному полю благодаря friend
}

// ====== Основная функция — проверка всего ======
int main() {
    setlocale(LC_ALL, "ru");
    // === 1–4. Проверка Weapon с закрытыми полями и геттерами/сеттерами ===
    Weapon sword("Меч", 3.5, 25.0);
    std::cout << "Название: " << sword.getName()
        << ", вес: " << sword.getWeight()
        << ", урон: " << sword.getDamage() << std::endl;

    sword.setDamage(30.0);
    std::cout << "После изменения урона: " << sword.getDamage() << std::endl;

    // === 5–8. Проверка Characteristic и дружбы ===
    Characteristic hero(50.0); // сила = 50
    double totalDamage = hero.GetDamage(sword);
    std::cout << "Общий урон (сила + оружие): " << totalDamage << std::endl;

    // === 9–13. Проверка MyMath ===
    std::cout << "\n--- Проверка MyMath ---" << std::endl;
    std::cout << "Add(10, 5) = " << MyMath::Add(10, 5) << std::endl;
    std::cout << "Sub(10, 5) = " << MyMath::Sub(10, 5) << std::endl;
    std::cout << "Mult(10, 5) = " << MyMath::Mult(10, 5) << std::endl;
    std::cout << "Div(10, 5) = " << MyMath::Div(10, 5) << std::endl;

    std::cout << "Количество вызовов статических методов: " << MyMath::callCount << std::endl;

    // Убедимся, что деструкторы вызываются
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
