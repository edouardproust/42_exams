#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain created" << std::endl;
}

Brain::Brain(Brain const& src)
{
	for (int i = 0; i < 100; ++i) {
		this->_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain copied" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed" << std::endl;
}

Brain&	Brain::operator=(Brain const& rhs)
{
	if (this != &rhs) {
		for (int i = 0; i < 100; ++i) {
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return (*this);
}

void	Brain::setIdea(int index, std::string const& idea)
{
	if (0 <= index && index < 100) {
		_ideas[index] = idea;
	}
}

std::string const	Brain::getIdea(int index) const
{
	if (0 <= index && index < 100) {
		return (_ideas[index]);
	}
	return ("");
}

void	Brain::printIdeas() const
{
	for (int i = 0; i < 100; ++i) {
		std::string const idea = getIdea(i);
		if (!idea.empty()) {
			std::cout << " idea #" << i << ": " << idea << std::endl;
		}
	}
}
