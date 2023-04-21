#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

int main(void) {
    Zombie billy = Zombie("Billy");
    Zombie *jack = newZombie("Jack");

    billy.announce();
    jack->announce();
    randomChump("BOB");
    delete jack;
    return (0);
}