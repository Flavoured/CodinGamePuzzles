#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

std::vector<std::vector<std::string>> Letters;
const char* alphabet = "abcdefghijklmnopqrstuvwxyz";

std::vector<std::string> WordToAscii(std::string Word, int H)
{
    std::string tempWord = Word;
    std::transform(tempWord.begin(), tempWord.end(), tempWord.begin(), ::tolower);
    std::string asciiWord = "";
    
    int pos;
    const char* found;
    
    int letterIndex[tempWord.length()];


    int point = 0;
    for(char& c : tempWord) 
    {
        found = strchr(alphabet, c);
       
        pos = found - alphabet;
        if (!found)
            pos = 27;
        else
            pos++;
            
        letterIndex[point] = pos-1;
        point++;
    }
    
    std::vector<std::string> lines;
    
    for(int i = 0; i < H; i++) // loop through layers
    {
        std::string NewLine;
        for(int k = 0; k < tempWord.length(); k++) // loop through letters
        {
            NewLine += Letters[letterIndex[k]][i]; // add letter to our line
        }
        lines.push_back(NewLine); // after finishing our line, push to array
    }
    
    return lines;
}

int main()
{
    int L;
    std::cin >> L; std::cin.ignore();
    int H;
    std::cin >> H; std::cin.ignore();
    std::string T;
    std:;getline(std::cin, T);
    
    std::vector<std::string> ROWS;
    
    
    for (int i = 0; i < H; i++)
    {
        std::string ROW;
        std::getline(std::cin, ROW);
        
        ROWS.push_back(ROW);
    }
    
    for(int i = 0; i < 27; i++)
    {
        std::vector<std::string> NewLetter;
        std::string newRow;
        for(int j = 0; j < H; j++)
        {
            newRow = ROWS[j].substr(L*i, L);
            NewLetter.push_back(newRow);
        }
        Letters.push_back(NewLetter);
    }

    std::vector<std::string> lines = WordToAscii(T, H);
    
    for(int i = 0; i < lines.size(); i++)
    {
        std::cout << lines[i] << std::endl;
    }
}
