#include <iostream>

#include "etat.h"
#include "automate.h"
#include "simulator.h"

int main()
{
    Automate automate(126);
    std::cout << "Automate: " << automate << std::endl;
    Etat etat = Etat(160);
    etat.setCellule(80, true);
    std::cout << etat << std::endl;

    Simulator simulator(automate, etat);

    for (unsigned int i = 0; i < 70; i++)
    {
        simulator.next();
        std::cout << simulator.last() << std::endl;
    }

    std::string pause;
    std::cin >> pause;

    return 0;
}