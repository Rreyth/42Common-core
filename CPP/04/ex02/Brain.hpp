#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain
{
	private:
			std::string ideas[100];
	public:
			Brain();
			Brain(const Brain &other);
			~Brain();
			Brain & operator = (const Brain &other);
			std::string get_idea(int i) const;
			void set_idea(int i, std::string new_idea);
};

#endif