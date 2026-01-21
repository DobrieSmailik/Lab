#include <iostream>
#include "Weapon.h" 

class Weapon; 


class Characteristic {
private:
    int strength;

public:
    Characteristic(int s) : strength(s) {}

   
    int GetDamage(const Weapon& weapon);
};


class MyMath {
private:
    static int callCount;

public:
    static int Add(int a, int b) {
        ++callCount;
        return a + b;
    }

    static int Sub(int a, int b) {
        ++callCount;
        return a - b;
    }

    static int Mult(int a, int b) {
        ++callCount;
        return a * b;
    }

    static int Div(int a, int b) {
        ++callCount;
        return (b != 0) ? a / b : 0;
    }

    static int GetCallCount() {
        return callCount;
    }
};


int MyMath::callCount = 0;

int Characteristic::GetDamage(const Weapon& weapon) {
    return strength + weapon.damage; 
}


int main() {
  
    Weapon sword("Меч", 20);
    std::cout << "Оружие: " << sword.GetName() << std::endl;
    std::cout << "Урон до изменения: " << sword.GetDamage() << std::endl;

    sword.SetDamage(25);
    std::cout << "Урон после изменения: " << sword.GetDamage() << std::endl;

 
    Characteristic charac(15);
    int totalDamage = charac.GetDamage(sword);
    std::cout << "Общий урон (сила + оружие): " << totalDamage << std::endl;

   
    std::cout << "\nMyMath тесты:" << std::endl;
    std::cout << "Add(10, 5) = " << MyMath::Add(10, 5) << std::endl;
    std::cout << "Sub(10, 5) = " << MyMath::Sub(10, 5) << std::endl;
    std::cout << "Mult(10, 5) = " << MyMath::Mult(10, 5) << std::endl;
    std::cout << "Div(10, 5) = " << MyMath::Div(10, 5) << std::endl;

   
    std::cout << "\nКоличество вызовов статических методов: "
        << MyMath::GetCallCount() << std::endl;

    return 0;
}