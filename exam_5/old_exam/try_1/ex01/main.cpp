#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* d = new Dog();
	Animal* c = new Cat();

	std::cout << d->getType() << ": ";
	d->makeSound();
	Brain* dBrain = d->getBrain();
	dBrain->setIdea(0, "I am Snoopy");
	dBrain->setIdea(1, "I love sleeping on my house");
	dBrain->printIdeas();

	std::cout << c->getType() << ": ";
	c->makeSound();
	Brain* cBrain = c->getBrain();
	cBrain->setIdea(0, "I am NyanCat");
	cBrain->setIdea(1, "I love Jpop and rainbows");
	cBrain->printIdeas();

	delete d;
	delete c;
}
