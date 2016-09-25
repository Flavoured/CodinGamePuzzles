#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    std::cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; std::cin.ignore();
    
    int elevatorMap[nbElevators+1];
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        std::cin >> elevatorFloor >> elevatorPos; std::cin.ignore();
        elevatorMap[elevatorFloor] = elevatorPos;
    }

    // game loop

    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        std::string direction; // direction of the leading clone: LEFT or RIGHT
        std::cin >> cloneFloor >> clonePos >> direction; std::cin.ignore();
        
        
        std::string Task = "WAIT";
        if(cloneFloor != exitFloor)
        {
            if(nbElevators > 0)
            {  
                int distanceToElevator = clonePos - elevatorMap[cloneFloor];
                if(direction == "RIGHT" && distanceToElevator > 0)
                {
                    Task = "BLOCK";
                }
                else if(direction == "LEFT" && distanceToElevator < 0)
                {
                    Task = "BLOCK";
                }
            }
            else
            {
                if(clonePos == 0 || clonePos == width-1)
                {
                    Task = "BLOCK";
                }
            }
        }
        else
        {
            int distanceToExit = clonePos - exitPos;
            if(direction == "RIGHT" && distanceToExit > 0)
            {
                Task = "BLOCK";
            }
            else if(direction == "LEFT" && distanceToExit < 0)
            {
                Task = "BLOCK";
            }
        }
        
        std::cout << Task << std::endl; // action: WAIT or BLOCK
    }
}
