#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int Level;
    cin >> Level; cin.ignore();
    int Xp;
    cin >> Xp; cin.ignore();
    int N;
    cin >> N; cin.ignore();
    int CurXP = 0;

    for(int i = 0; i < N; i++)
    {
        CurXP += 300;
        while(CurXP >= Xp)
        {
            Level++;
            CurXP -= Xp;
            Xp = int( Level * sqrt(Level) * 10 );
        }
        
    }

    cout << Level << endl;
    cout << Xp-CurXP << endl;
}
