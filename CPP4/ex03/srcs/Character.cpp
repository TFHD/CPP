#include "Character.hpp"
#include <iostream>

Character::Character(void) {}

Character::Character(std::string NAME) : name(NAME)
{
    if (LOG)
        std::cout << "\e[35mThe Character\e[0m " << this->name << " was created !" << std::endl;
    for (int i = 0; i < 4; i++)
        this->slots[i] = NULL;
    this->last_index_item = 0;
}

Character::~Character(void)
{
    for (int i = 0; i < 4; i++) {
        if (this->slots[i] != NULL)
            delete this->slots[i];
    }
    if (LOG)
        std::cout << "\e[35mThe Character\e[0m " << this->getName() <<" was destroyed !" << std::endl;
}

Character::Character(const Character &cpy)
{
    if (LOG)
        std::cout << "\e[35mThe Character\e[0m was copied !" << std::endl;
    for (int i = 0; i < 4; i++)
        this->slots[i] = NULL;
   *this = cpy;
}

Character	&Character::operator=(const Character &src)
{
    if (LOG)
        std::cout << "\e[35mThe Character\e[0m Assignation operator called" << std::endl;
    if (this == &src)
        return *this;
    this->name = src.getName();
    this->last_index_item = 0;
    for (int i = 0; i < 4; i++)
    {
        if (src.slots[i] != NULL) {
            if (this->slots[i] != NULL)
                delete this->slots[i];
            this->slots[i] = src.slots[i]->clone();
        }
        else
            this->slots[i] = NULL;
    }
	return *this;
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    int find = 0;
    if (m == NULL)
        return ;
    for (int i = 0; i < 4; i++) {
        if (this->slots[i] == NULL) {
            this->slots[i] = m;
            find = 1;
            break;
        }
    }
    if (!find) {
        if (LOG)
            std::cout << "\e[31mYou cannot equip another item, your inventory is full !\e[0m" << std::endl;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 4) {
        if (LOG) { std::cout << "\e[31mYou cannot unequip an item with an index >= 4\e[0m" << std::endl; }}
    else if (this->slots[idx] == NULL) {
        if (LOG) { std::cout << "\e[31mYou cannot unequip an item NULL\e[0m" << std::endl; }}
    else {
        this->slots[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 4) {
        if (LOG) { std::cout << "\e[31mYou cannot use an item with an index >= 4\e[0m" << std::endl; }}
    else if (this->slots[idx] == NULL) {
        if (LOG) { std::cout << "\e[31mYou cannot use an item NULL\e[0m" << std::endl; }}
    else {
        this->slots[idx]->use(target);
    }
}
