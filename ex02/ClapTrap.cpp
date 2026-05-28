#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no hit points left and cannot attack!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points left and cannot attack!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already destroyed and cannot take more damage!" << std::endl;
        return;
    }
    if (amount >= this->_hitPoints)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " takes " << amount
                  << " points of damage and is destroyed!" << std::endl;
    }
    else
    {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount
                  << " points of damage! Remaining hit points: " << this->_hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no hit points left and cannot repair itself!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points left and cannot repair itself!" << std::endl;
        return;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount
              << " hit points! Current hit points: " << this->_hitPoints << std::endl;
}
