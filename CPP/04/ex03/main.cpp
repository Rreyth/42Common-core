#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
	std::cout << "subject test" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	}
	{
	std::cout << std::endl << "own test" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* ui = new Character("ui");
	ICharacter* Billy = new Character("Billy");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	ui->equip(tmp);
	tmp = src->createMateria("ice");
	Billy->equip(tmp);
	tmp = src->createMateria("cure");
	ui->equip(tmp);
	tmp = src->createMateria("cure");
	Billy->equip(tmp);

	std::cout << "ui attack Billy:" << std::endl;
	ui->use(0, *Billy);
	std::cout << "Billy heals himself and fight back" << std::endl;
	Billy->use(1, *Billy);
	Billy->use(0, *ui);
	Billy->use(0, *ui);
	std::cout << "they drop their ice materias" << std::endl;
	ui->unequip(0);
	Billy->unequip(0);

	delete Billy;
	delete ui;
	delete src;
	}
	return 0;
}