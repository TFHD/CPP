#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <stdlib.h>

int main()
{
	//const Animal *test = new Animal();
	//test->makeSound();

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Cat();
			if (meta[i] == NULL)
			{
				std::cerr << "Allocation failed" << std::endl;
				std::cerr << "Exiting process now" << std::endl;
				exit(1);
			}
		}
		else
		{
			meta[i] = new Dog();
			if (meta[i] == NULL)
			{
				std::cerr << "Allocation failed" << std::endl;
				std::cerr << "Exiting process now" << std::endl;
				exit(1);
			}
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);

	std::cout << std::endl << std::endl;
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Dog *a = new Dog();
	// Cat *a = new Cat();
	if (a == NULL)
	{
		std::cerr << "Allocation failed" << std::endl;
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}

	a->setIdea(0, "I have to sniff it");
	a->setIdea(1, "I have to pee on it");
	a->setIdea(2, "I have to sniff it again");
	a->setIdea(101, "some shit");

	Dog *b = new Dog(*a);
	// Cat *b = new Cat(*a);
	if (b == NULL)
	{
		std::cerr << "Allocation failed" << std::endl;
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting a\033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getAllIdeas(3);
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b\033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getAllIdeas(3);
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
	delete(b);

	return (0);
}