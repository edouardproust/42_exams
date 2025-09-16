#include "Cure.hpp"
#include "Ice.hpp"
#include "Fire.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	// PERSONNAL TESTS

	ICharacter*	me = new Character("Edouard");
	ICharacter*	nico = new Character("Nico");
	
	// Materia constructors
	AMateria*	c1 = new Cure(); // Default constructor (Cure)
	AMateria*	f1 = new Fire(); // Default constructor (Cure)
	AMateria*	i1 = new Ice(); // Default constructor (Ice)
	AMateria*	c2 = new Cure();
	AMateria*	i2 = i1->clone(); // Clone (Ice)
	*c2 = *c1; // Copy operator: does not change type
	std::cout << c1->getType() << std::endl;
	std::cout << c2->getType() << std::endl;
	std::cout << i1->getType() << std::endl;
	std::cout << i2->getType() << std::endl;

	me->equip(c1);
	me->equip(f1);
	me->equip(i1);
	nico->equip(c2);
	nico->equip(i2);
	//std::cerr << me->get(0)->getType() << std::endl;
	me->use(1, *nico);

	// SUBJECT TEST

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me2 = new Character("Edouard");

	me2->equip(src->createMateria("fire"));
	me2->equip(src->createMateria("ice"));
	me2->equip(src->createMateria("cure"));

	me2->use(0, *nico);
	me2->use(1, *nico);

	// FREE

	delete me;
	delete me2;
	delete nico;
	delete src;
 
	return (0);
}
