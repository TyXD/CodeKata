#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 새로 추가!
    cin.tie(nullptr); // 새로 추가!

    int a, b;
    cin >> a >> b;
    
    string as, bs;
    map<string, string>passwordMap;
    while (passwordMap.size() != a)
    {
        cin >> as >>bs;
        passwordMap[as] = bs;
    }
    vector<string> answers;
    
    while (answers.size() != b)
    {
        cin >> as;
        answers.push_back(passwordMap[as]);
    }
    
    for(const auto& answer : answers )
    {
        cout << answer << '\n';
    }
}