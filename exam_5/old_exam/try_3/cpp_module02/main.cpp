#include "TargetGenerator.hpp"
#include "Warlock.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Fwoosh.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"

int	main()
{

Warlock richard("Richard", "foo");
richard.setTitle("Hello, I'm Richard the Warlock!");

TargetGenerator tarGen;
BrickWall model1;
tarGen.learnTargetType(&model1);

Polymorph* polymorph = new Polymorph();
Fireball* fireball = new Fireball();

richard.learnSpell(polymorph);
richard.learnSpell(fireball);

ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

richard.introduce();
richard.launchSpell("Polymorph", *wall);
richard.launchSpell("Fireball", *wall);

}
