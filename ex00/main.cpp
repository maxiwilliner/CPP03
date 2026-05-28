#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== Testing default constructor ===" << std::endl;
    ClapTrap defaultBot;
    defaultBot.attack("Target Dummy");
    defaultBot.takeDamage(3);
    defaultBot.beRepaired(2);

    std::cout << std::endl << "=== Testing name constructor ===" << std::endl;
    ClapTrap botA("Bot-A");
    botA.attack("Enemy");
    botA.takeDamage(5);
    botA.beRepaired(3);

    std::cout << std::endl << "=== Testing copy constructor ===" << std::endl;
    ClapTrap botB(botA); 
    botB.attack("Another Enemy");

    std::cout << std::endl << "=== Testing copy assignment ===" << std::endl;
    ClapTrap botC("Bot-C"); 
    botC = botA;
    botC.attack("Final Enemy");

    std::cout << std::endl << "=== Testing exhaustion ===" << std::endl;
    ClapTrap botD("Bot-D");
    for (int i = 0; i < 12; i++)
    {
        botD.attack("Training Dummy");
    }
    botD.beRepaired(5);

    std::cout << std::endl << "=== Testing destruction ===" << std::endl;
    botD.takeDamage(100);
    botD.attack("Ghost");
    botD.beRepaired(1);

    return 0;
}
