#include "Harl.hpp"

int main(int argc, char **argv)
{
    int id;
    Harl harl;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    if (argc != 2)
    {
        std::cout << "Invalid number of params" << std::endl;
        return (2);
    }
    for (int i = 0; i < 4; i++)
    {
        if (argv[1] == levels[i])
            id = i;
    }
    switch (id)
    {
    case 0:
        std::cout << "[ DEBUG ]" << std::endl;
        harl.complain("DEBUG");
        std::cout << std::endl;
        std::cout << "[ INFO ]" << std::endl;
        harl.complain("INFO");
        std::cout << std::endl;
        std::cout << "[ WARNING ]" << std::endl;
        harl.complain("WARNING");
        std::cout << std::endl;
        std::cout << "[ ERROR ]" << std::endl;
        harl.complain("ERROR");
        std::cout << std::endl;
        break;
    case 1:
        std::cout << "[ INFO ]" << std::endl;
        harl.complain("INFO");
        std::cout << std::endl;
        std::cout << "[ WARNING ]" << std::endl;
        harl.complain("WARNING");
        std::cout << std::endl;
        std::cout << "[ ERROR ]" << std::endl;
        harl.complain("ERROR");
        std::cout << std::endl;
        break;
    case 2:
        std::cout << "[ WARNING ]" << std::endl;
        harl.complain("WARNING");
        std::cout << std::endl;
        std::cout << "[ ERROR ]" << std::endl;
        harl.complain("ERROR");
        std::cout << std::endl;
        break;
    case 3:
        std::cout << "[ ERROR ]" << std::endl;
        harl.complain("ERROR");
        std::cout << std::endl;
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return (0);
}