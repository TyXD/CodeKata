#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>

using namespace std;
int main() {
    int A, B;
    vector<int> answer;
    set<int> Av;
    
    cin >> A;
    
    while (Av.size() != A) 
    {
        cin >> B;
        Av.insert(B);
    }
    
    cin >> A;
    
    while (answer.size() != A) 
    {
        cin >> B;
        if(Av.find(B) != Av.end())
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    for(const int& ans : answer)
    {
        cout << ans << " ";
    }
    cout << endl;
}