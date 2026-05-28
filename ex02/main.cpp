#include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(void)
{
    std::cout << "=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Target");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << std::endl << "=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Enemy");
    scav.guardGate();
    scav.takeDamage(20); //mirar asi aqui esta bien que claptrap scav tome el daño
    scav.beRepaired(15);

    std::cout << std::endl << "=== Testing FragTrap construction chaining ===" << std::endl;
    FragTrap frag("Fraggy");

    std::cout << std::endl << "=== Testing FragTrap attack ===" << std::endl;
    frag.attack("Bad Guy");

    std::cout << std::endl << "=== Testing FragTrap highFivesGuys ===" << std::endl;
    frag.highFivesGuys();

    std::cout << std::endl << "=== Testing FragTrap damage and repair ===" << std::endl;
    frag.takeDamage(40);
    frag.beRepaired(25);

    std::cout << std::endl << "=== Testing FragTrap copy ===" << std::endl;
    FragTrap fragCopy(frag);
    fragCopy.highFivesGuys();

    std::cout << std::endl << "=== Testing FragTrap assignment ===" << std::endl;
    FragTrap fragAssign("Temp");
    fragAssign = frag;
    fragAssign.attack("Final Boss");

    std::cout << std::endl << "=== End of tests, destructors will be called ===" << std::endl;
    return 0;
}
