#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int GetNeighbours(int x, int y, vector<string> grid)
{  
    int neighbours = 0;
    int h=grid.size()-1, w=grid[0].size()-1;
    
    if(x!=0&&y!=0) neighbours += grid[y-1][x-1]-48;
    if(y!=0) neighbours += grid[y-1][x]-48;
    if(x!=w&&y!=0) neighbours += grid[y-1][x+1]-48;
    if(x!=0) neighbours += grid[y][x-1]-48;
    if(x!=w) neighbours += grid[y][x+1]-48;
    if(x!=0&&y!=h) neighbours += grid[y+1][x-1]-48;
    if(y!=h) neighbours += grid[y+1][x]-48;
    if(x!=w&&y!=h) neighbours += grid[y+1][x+1]-48;

    return neighbours;
}

int main()
{
    int width, height;
    vector<string> map, prev;
    
    cin >> width >> height; cin.ignore();
    for (int i = 0; i < height; i++) {
        string line;
        cin >> line; cin.ignore();
        map.push_back(line);
        prev.push_back(line);
    }

    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            int LN = GetNeighbours(x,y,prev);

            if(prev[y][x]=='1')
            {
                if(LN<2||LN>3)
                    map[y][x]='0';
            }
            else
            {
                if(LN==3)
                    map[y][x]='1';
            }
        }
    }

    for(auto mapLine : map)
    {
        cout << mapLine << endl;
    }
}
