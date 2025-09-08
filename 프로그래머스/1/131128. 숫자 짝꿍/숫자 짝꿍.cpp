#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    priority_queue<char> qX;
    priority_queue<char> qY;
    
    for (auto& x : X)
    {
        qX.push(x);
    }
    for (const auto& y : Y)
    {
        qY.push(y);
    }
    
    while(!qX.empty() && !qY.empty())
    {
        if(qX.top() == qY.top())
        {
            if(answer == "" && qX.top() == '0')
            {
                answer = answer + qX.top();
                break;
            }
            answer += qX.top();
            qX.pop();
            qY.pop();
        }
        else
        {
            if(qX.top() > qY.top())
            {
                qX.pop();
            }
            else
            {
                qY.pop();
            }
        }
    }
    if(answer == "")
    {
        answer = "-1";
    }
    return answer;
}