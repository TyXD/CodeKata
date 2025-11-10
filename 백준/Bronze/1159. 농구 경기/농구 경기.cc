#include <iostream>
#include <map>
#include <string>
#include <limits>

using namespace std;

int main() 
{
    int A;
    string B;
    map<char, int> Ma;
    string answer = "";
    cin >> A;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    
    for(int i = 0; i < A; ++i)
    {
        getline(cin, B);
        Ma[B[0]]++;
    }
    
    for(auto& m : Ma)
    {
        if(m.second >= 5)
        {
            answer.push_back(m.first);
        }
            
    }
    
    if(answer != "")
    {
        for(const auto& ch : answer)
        {
            cout << ch;
        }
        return 0;
    }
    cout << "PREDAJA";
    
    return 0;
}