#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{

    // game loop
    std::string thrust = "100";
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        std::cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; std::cin.ignore();
        int opponentX;
        int opponentY;
        std::cin >> opponentX >> opponentY; std::cin.ignore();
        
        if (nextCheckpointAngle > 90 || nextCheckpointAngle < -90)
        {
            thrust = "0";
        }
        else
        {
            thrust = "100";
            if(nextCheckpointDist > 2000)
            {
                thrust = "BOOST";
            }
        }
        
        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        std::cout << nextCheckpointX << " " << nextCheckpointY << " " << thrust << std::endl;
    }
}
