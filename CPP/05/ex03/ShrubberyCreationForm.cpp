#include "ShrubberyCreationForm.hpp"
#include <fstream>

////////////////////////////////////////////////////////////////////////////////
// Constructors and destructor
////////////////////////////////////////////////////////////////////////////////
ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Default_Shrubbery", 145, 137)
{
	_target = "Default";
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target + "_Shrubbery", 145, 137)
{
	_target = target;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj._target + "_Shrubbery", 145, 137)
{
	*this = obj;
}


ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}


////////////////////////////////////////////////////////////////////////////////
// Getters and setters
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Operators
////////////////////////////////////////////////////////////////////////////////
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this == &obj)
		return (*this);
	_target = obj._target;
	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	this->plant_tree();
}

void	ShrubberyCreationForm::plant_tree() const
{
	std::string name = _target + "_shrubbery";
	std::ofstream output(name.c_str(), std::ofstream::out);

	if (!output.is_open())
    {
        std::cout << name << ": Permission denied" << std::endl;
        return;
    }

	output << "                                                     ." << std::endl;
	output << "                                          .         ;" << std::endl;
	output << "             .              .              ;%     ;;" << std::endl;
	output << "               ,           ,                :;%  %;" << std::endl;
	output << "                :         ;                   :;%;'     .," << std::endl;
	output << "       ,.        %;     %;            ;        %;'    ,;" << std::endl;
	output << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	output << "          %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
	output << "           ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	output << "            `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	output << "             `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	output << "                `:%;.  :;bd%;          %;@%;'" << std::endl;
	output << "                  `@%:.  :;%.         ;@@%;'" << std::endl;
	output << "                    `@%.  `;@%.      ;@@%;" << std::endl;
	output << "                      `@%%. `@%%    ;@@%;" << std::endl;
	output << "                        ;@%. :@%%  %@@%;" << std::endl;
	output << "                          %@bd%%%bd%%:;" << std::endl;
	output << "                            #@%%%%%:;;" << std::endl;
	output << "                            %@@%%%::;" << std::endl;
	output << "                            %@@@%(o);  . '" << std::endl;
	output << "                            %@@@o%;:(.,'" << std::endl;
	output << "                        `.. %@@@o%::;" << std::endl;
	output << "                           `)@@@o%::;" << std::endl;
	output << "                            %@@(o)::;" << std::endl;
	output << "                           .%@@@@%::;" << std::endl;
	output << "                           ;%@@@@%::;." << std::endl;
	output << "                          ;%@@@@%%:;;;." << std::endl;
	output << "                      ...;%@@@@@%%:;;;;,.." << std::endl;

	output.close();
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////
