#include "Weapon.h"

Weapon::Weapon(const std::string& n, int d) : name(n), damage(d) {}


std::string Weapon::GetName() const {
    return name;
}

int Weapon::GetDamage() const {
    return damage;
}

=
void Weapon::SetDamage(int d) {
    damage = d;
}