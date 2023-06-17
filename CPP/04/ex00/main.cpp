#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wc = new WrongCat();
	const WrongAnimal* wd = new WrongDog();
	const WrongAnimal* wmeta = new WrongAnimal();

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl << "Wrong animals :" << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	std::cout << wd->getType() << " " << std::endl;
	wc->makeSound();
	wd->makeSound();
	wmeta->makeSound();
	std::cout << std::endl;
	
	delete(meta);
	delete(j);
	delete(i);
	delete(wc);
	delete(wd);
	delete(wmeta);
	return (0);
}