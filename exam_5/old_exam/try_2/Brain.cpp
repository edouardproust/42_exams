#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(Brain const& src)
{
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain copied" << std::endl;
}

Brain&	Brain::operator=(Brain const& rhs)
{
	if (&rhs != this) {
		for (int i = 0; i < 100; ++i) {
			_ideas[i] = rhs._ideas[i];
		}
	}
	std::cout << "Brain assigned" << std::endl;
	return (*this);
}

Brain::~Brain()
{	
	std::cout << "Brain destroyed" << std::endl;
}

void	Brain::setIdea(int index, std::string const& idea)
{
	if (0 <= index && index < 100) {
		_ideas[index] = idea;
	}
}

void	Brain::printIdeas() const
{	
	for (int i = 0; i < 100; ++i) {
		if (!_ideas[i].empty()) {
			std::cout << "idea #" << i << ": " << _ideas[i] << std::endl;
		}
	}
}
