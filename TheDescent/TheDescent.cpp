#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{

    while (true) {
        int tallestIndex = -1; // Reset each new loop
        int tallestHeight = -1; // Reset each new loop
        
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of index at i.
            std::cin >> mountainH; std::cin.ignore();
        
            if(tallestIndex != -1)
            {
                if(mountainH > tallestHeight)
                {
                    tallestIndex = i;
                    tallestHeight = mountainH;
                }
            }
            else
            {
                tallestIndex = i;
                tallestHeight = mountainH;
            }
        
        }
        
        std::cout << tallestIndex << std::endl;
    }
}
