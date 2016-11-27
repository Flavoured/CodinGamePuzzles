#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string expression;
    cin >> expression; cin.ignore();
    cerr << "IN: " << expression << endl;
    
    unordered_map<char, int> bM;
    
    bool valid = true;
    
    for(auto c : expression)
    {
        if((bM['{']==0 && c=='}') || (bM['[']==0 && c==']') || (bM['(']==0 && c==')'))
            valid = false;
        else
            bM[c]++;
    }
    
    int cu, sq, r;
    cu = bM['{']-bM['}'];
    sq = bM['[']-bM[']'];
    r = bM['(']-bM[')'];
    
    if(!valid)
        cout << "false" << endl;
    else
        if(cu == 0 && sq == 0 && r== 0)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        
}
