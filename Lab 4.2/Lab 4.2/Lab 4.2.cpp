// Lab 4.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Weapon {
private:
    string name;   
    int damage;     
    float weight;   

public:
    
    Weapon(string weaponName, int weaponDamage, float weaponWeight)
        : name(weaponName), damage(weaponDamage), weight(weaponWeight) {
        cout << "Создано оружие: " << name << endl;
    }

   
    Weapon() : Weapon("Меч-кладенец", 15, 5.2f) {
    }

    
    ~Weapon() {
        cout << "\nУдаление оружия:" << endl;
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
        cout << "Оружие успешно удалено!" << endl;
    }

    
    void displayInfo() {
        cout << "\nИнформация об оружии:" << endl;
        cout << "Название: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
    }

   
    bool canLift(float maxWeight) {
        return weight > maxWeight; 
    }

   
    float totalWeight(const Weapon& otherWeapon) {
       
        return totalWeight(otherWeapon.weight);
    }

    
    float totalWeight(float otherWeight) {
        return weight + otherWeight;
    }

    
    string getName() const { return name; }
    int getDamage() const { return damage; }
    float getWeight() const { return weight; }
};

int main() {
    setlocale(LC_ALL, "ru");
    cout << "=== Тестирование класса Weapon ===" << endl;

   
    cout << "\n--- Создание статического объекта ---" << endl;
    Weapon sword("Двуручный меч", 25, 8.5f);
    sword.displayInfo();

 
    cout << "\n--- Создание динамического объекта ---" << endl;
    Weapon* bow = new Weapon("Лук", 12, 3.1f);
    bow->displayInfo();

 
    cout << "\n--- Тестирование метода canLift() ---" << endl;

    float maxWeight = 5.0f;
    cout << "Максимальный вес, который может поднять персонаж: " << maxWeight << " кг" << endl;

    cout << "Проверка для меча (вес: " << sword.getWeight() << " кг): ";
    if (sword.canLift(maxWeight)) {
        cout << "слишком тяжело!" << endl;
    }
    else {
        cout << "можно поднять!" << endl;
    }

    cout << "Проверка для лука (вес: " << bow->getWeight() << " кг): ";
    if (bow->canLift(maxWeight)) {
        cout << "слишком тяжело!" << endl;
    }
    else {
        cout << "можно поднять!" << endl;
    }

  
    cout << "\n--- Тестирование методов totalWeight() ---" << endl;

 
    Weapon axe("Боевой топор", 30, 7.8f);

  
    float extraWeight = 2.5f;
    cout << "Суммарный вес меча и дополнительного веса " << extraWeight << " кг: ";
    cout << sword.totalWeight(extraWeight) << " кг" << endl;

 
    cout << "Суммарный вес меча (" << sword.getWeight() << " кг) и топора (" << axe.getWeight() << " кг): ";
    cout << sword.totalWeight(axe) << " кг" << endl;

 
    cout << "\n--- Удаление динамического объекта ---" << endl;
    delete bow;

    cout << "\n--- Конец работы программы ---" << endl;
  

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
