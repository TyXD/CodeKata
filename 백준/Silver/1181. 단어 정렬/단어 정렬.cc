#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b)
{
    if(a.size() == b.size())
    {
        return a < b;
    }
    else
    {
        return a.size() < b.size();
    }
}
int main() {
    int A;
    vector<string> answers;
    string B;
    cin >> A;
    
    while (answers.size() != A) 
    {
        cin >> B;
        answers.push_back(B);
    }
    sort(answers.begin(), answers.end(), compare);
    answers.erase(unique(answers.begin(), answers.end()), answers.end());
    for(const auto& answer : answers)
    {
        cout << answer << endl;
    }
    return 0;
}