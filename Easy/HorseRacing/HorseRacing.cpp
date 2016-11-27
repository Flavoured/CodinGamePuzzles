#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::vector <int>HorseArray;
    std::cin >> N; std::cin.ignore();
    for (int i = 0; i < N; i++) {
        int Pi;
        std::cin >> Pi; std::cin.ignore();
        HorseArray.push_back(Pi);
    }

    std::sort(HorseArray.begin(), HorseArray.end()); // Sorts in ascending order
    
    int last = -1, current = -1, smallestDif = -1, currentDif = -1;
    
    for(int in : HorseArray)
    {
        current = in;
        if(last==-1)
            last = current;
        else
        {
            currentDif = current-last;
            
            if(currentDif < smallestDif || smallestDif == -1)
                smallestDif = currentDif;
            
            last = current;
        }
    }
    std::cout << smallestDif << std::endl;
}
