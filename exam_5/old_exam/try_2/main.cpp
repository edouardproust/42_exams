#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	AAnimal* d = new Dog();
	std::cout << d->getType() << ": ";
	d->makeSound();
	Brain*	dBrain = d->getBrain();
	dBrain->setIdea(0, "I am a dog");
	dBrain->setIdea(1, "My name is Snoopy");
	dBrain->setIdea(2, "I love to sleep on the roof of my house");
	dBrain->printIdeas();

	AAnimal* c = new Cat();
	std::cout << c->getType() << ": ";
	c->makeSound();
	Brain*	cBrain = c->getBrain();
	cBrain->setIdea(0, "My name is NyanCat");
	cBrain->setIdea(1, "I love Jpop and rainbows");
	cBrain->printIdeas();

	delete c;
	delete d;
}
