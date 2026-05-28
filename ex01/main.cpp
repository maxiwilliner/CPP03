#include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main(void)
{
    std::cout << "=== Testing ClapTrap (base class) ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << std::endl << "=== Testing ScavTrap construction chaining ===" << std::endl;
    ScavTrap scav("Scavvy");

    std::cout << std::endl << "=== Testing ScavTrap attack ===" << std::endl;
    scav.attack("Enemy");

    std::cout << std::endl << "=== Testing ScavTrap guardGate ===" << std::endl;
    scav.guardGate();

    std::cout << std::endl << "=== Testing ScavTrap damage and repair ===" << std::endl;
    scav.takeDamage(30);
    scav.beRepaired(20);

    std::cout << std::endl << "=== Testing ScavTrap copy ===" << std::endl;
    ScavTrap scavCopy(scav);
    scavCopy.attack("Another Enemy");

    std::cout << std::endl << "=== Testing ScavTrap assignment ===" << std::endl;
    ScavTrap scavAssign("Temp");
    scavAssign = scav;
    scavAssign.guardGate();

    std::cout << std::endl << "=== End of tests, destructors will be called ===" << std::endl;
    return 0;
}
