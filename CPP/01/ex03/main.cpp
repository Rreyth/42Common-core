#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
    Weapon club = Weapon("crude spiked club");
    Weapon club2 = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    HumanB jim("Jim");

    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    jim.setWeapon(club2);
    jim.attack();
    club2.setType("some other type of club");
    jim.attack();
    return (0);
}