#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main()
{
    int n; // the number of temperatures to analyse    
    std::cin >> n; std::cin.ignore();
    std::string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    std::getline(std::cin, temps);

    // My Code
    
    std::vector<int> sortedArray;
    
    std::stringstream ssin(temps);
    while (ssin.good()){
        int num;
        while (ssin >> num) sortedArray.push_back(num);
    }
       
    int smallestIndex = 0;
    if(sortedArray.size() > 0)
    {
        std::sort (sortedArray.begin(), sortedArray.end());
        
        int smallestDistance = 0-sortedArray[0];
        int temporaryDistance;
        
        for(int i = 0; i < sortedArray.size(); i++)
        {
            temporaryDistance = 0-sortedArray[i];
            if(temporaryDistance < 0) { temporaryDistance *= -1; }
            
            if(temporaryDistance <= smallestDistance)
            {
                smallestIndex = i;
                smallestDistance = temporaryDistance;
            }
        }
        std::cout << sortedArray[smallestIndex] << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
    
}
