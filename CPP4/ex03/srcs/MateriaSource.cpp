#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = NULL;
    if (LOG)
	    std::cout << "\e[31mMaterialSource\e[0m was created !" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &input)
{
	*this = input;
    if (LOG)
        std::cout << "\e[31mMaterialSource\e[0m copy constructor called !" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
        return *this;
	for (int i = 0; i < 4; i++) {
		if (src.slots[i] != NULL) {
			this->slots[i] = src.slots[i]->clone();
            if (LOG)
	            std::cout << "\e[31mMaterialSource\e[0m copied " << src.slots[i]->getType() << std::endl;
		}
		else
			this->slots[i] = NULL;
	}
    if (LOG) { std::cout << "\e[31mMaterialSource\e[0m assignement constructor called !" << std::endl; }
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] != NULL)
			delete slots[i];
	}
    if (LOG)
        std::cout << "\e[31mMaterialSource\e[0m was destroyed !" << std::endl;
}

void MateriaSource::learnMateria(AMateria * m)
{
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] == NULL) {
			this->slots[i] = m;
            if (LOG)
			    std::cout << "\e[31mMaterialSource\e[0m just learnt " << m->getType() << " at slots " << i << std::endl;
			m = NULL;
			break ;
		}
	}
	if (m != NULL) {
        if (LOG)
		    std::cout << "\e[31mMaterialSource\e[0m tried to learn " << m->getType() << " but it's full!" << std::endl;
		delete m;
	}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) {
		if (this->slots[i] != NULL && this->slots[i]->getType() == type)
			return (this->slots[i]->clone());
	}
	return 0;
}