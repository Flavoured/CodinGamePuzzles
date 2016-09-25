#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    std::cin >> lightX >> lightY >> initialTX >> initialTY; std::cin.ignore();

    int thorPosX = initialTX;
    int thorPosY = initialTY;
    
    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        std::cin >> remainingTurns; std::cin.ignore();

        std::string moveDir = "";

        if(thorPosY > lightY){ moveDir += "N"; thorPosY -= 1; } 
        else if(thorPosY < lightY){ moveDir += "S"; thorPosY += 1; }
        
        
        if(thorPosX > lightX){ moveDir += "W"; thorPosX -= 1; } 
        else if(thorPosX < lightX){ moveDir += "E"; thorPosX += 1; }
        
        
        std::cout << moveDir << std::endl;
    }
}
