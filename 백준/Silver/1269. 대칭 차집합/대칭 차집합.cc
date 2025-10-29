#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int main() {
    int A, B, Ai;
    set<int> Sa, Sb;
    vector<int> answer;
    cin >> A >> B;
    
    while(A != Sa.size())
    {
        cin >> Ai;
        Sa.insert(Ai);
    }
    
    while(B != Sb.size())
    {
        cin >> Ai;
        Sb.insert(Ai);
    }
    
    set_difference(Sa.begin(), Sa.end(), Sb.begin(), Sb.end(), back_inserter(answer));
    set_difference(Sb.begin(), Sb.end(), Sa.begin(), Sa.end(), back_inserter(answer));
    
    cout << answer.size() << endl;
}