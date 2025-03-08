#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	if (LOG) { std::cout << std::endl << "############ creating a new spellbook ############" << std::endl << std::endl; }
	MateriaSource *spellBook = new MateriaSource();
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	
	if (LOG) {std::cout << std::endl << "############ copying spellbook ############" << std::endl << std::endl; }
	IMateriaSource *spellBookCopy = new MateriaSource(*spellBook);
	
	if (LOG) { std::cout << std::endl << "############ learn new spells in spellbook ############" << std::endl << std::endl; }
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Ice());
	
	if (LOG) { std::cout << std::endl << "############ learn new spells in spellbook-copy ############" << std::endl << std::endl; }
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());
	spellBookCopy->learnMateria(new Cure());
	
	if (LOG) { std::cout << std::endl << "############ creating the new character Bomboclat ############" << std::endl << std::endl; }
	AMateria *tmp;
	Character *Bomboclat = new Character("Bomboclat");
	
	tmp = spellBookCopy->createMateria("cure");
	Bomboclat->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	Bomboclat->equip(tmp);



	if (LOG) { std::cout << std::endl << "############ copy the a new character Bomboclat ############" << std::endl << std::endl; }
	Character *BomboclatCopy = new Character(*Bomboclat);
	
	BomboclatCopy->use(1, *Bomboclat);
	BomboclatCopy->use(0, *Bomboclat);
	Bomboclat->unequip(1);
	delete tmp;


	if (LOG) { std::cout << std::endl << "############ creating a new character DarckVador ############" << std::endl << std::endl; }
	ICharacter* darckvador = new Character("DarckVador");

	tmp = spellBookCopy->createMateria("ice");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("ice");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	delete tmp;
	tmp = spellBookCopy->createMateria("cure");
	darckvador->equip(tmp);
	delete tmp;
	tmp = spellBookCopy->createMateria("ice");
	darckvador->equip(tmp);
	delete tmp;

	if (LOG) { std::cout << std::endl << "############ creating a new character SpongeBob ############" << std::endl << std::endl; }
	ICharacter *spongebob = new Character("SpongeBob");
	darckvador->use(0, *spongebob);
	darckvador->use(1, *spongebob);
	spongebob->use(0, *darckvador);
	spongebob->use(1, *darckvador);

	if (LOG) { std::cout << std::endl << "############ destroying Bomboclat-copy ############" << std::endl << std::endl; }
	delete BomboclatCopy;

	if (LOG) { std::cout << std::endl << "############ destroying Bomboclat-copy ############" << std::endl << std::endl; }
	delete Bomboclat;

	if (LOG) { std::cout << std::endl << "############ destroying SpongeBob ############" << std::endl << std::endl; }
	delete spongebob;

	if (LOG) { std::cout << std::endl << "############ destroying DarckVador ############" << std::endl << std::endl; }
	delete darckvador;

	if (LOG) { std::cout << std::endl << "############ destroying spellbook ############" << std::endl << std::endl; }
	delete spellBook;
	
	if (LOG) { std::cout << std::endl << "############ destroying spellbook Copy ############" << std::endl << std::endl; }
	delete spellBookCopy;
	return (0);
}