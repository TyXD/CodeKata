#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b)
{
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> sn;
    
    for(int v : numbers)
    {
        sn.push_back(to_string(v));
    }
    
    sort(sn.begin(), sn.end(), compare);
    
    for(string s : sn)
    {
        answer += s;
    }
    
    if(answer[0] == '0')
    {
        return "0";
    }
    return answer;
}