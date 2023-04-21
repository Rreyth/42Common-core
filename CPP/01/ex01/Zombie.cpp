#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::~Zombie() {
    std::cout << this->name << " Destroyed" << std::endl;
}

void    Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) {
    this->name = name;
}