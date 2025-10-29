#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <unordered_set>
#include <string>

using namespace std;
int main() {
    string M;
    unordered_set<string> A;
    int answer = 0;
    
    cin >> M;
    
    for(int i = 0; i < M.size(); ++i)
    {
        
        string K = "";
        
        K += M[i];
        A.insert(K);
        int index = i+1;

            
        while(index < M.size())
        {
            K += M[index];
            A.insert(K);
            ++index;
        }
    }
    answer = A.size();
    cout << answer;
}