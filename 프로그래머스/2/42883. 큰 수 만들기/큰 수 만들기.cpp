#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    stack<char> numstack;
    int stackindex = k;
    
    for(auto ch : number)
    {
        if(numstack.empty())
        {
            numstack.push(ch);
            continue;
        }
        
        while(!numstack.empty() && numstack.top() < ch && stackindex != 0)
        {
            numstack.pop();
            --stackindex;
        }
        
        if(numstack.size() < number.length() - k)
        {
            numstack.push(ch);
        }
        
        
    }
    while(!numstack.empty())
    {
        answer = numstack.top() + answer;
        numstack.pop();
    }
    return answer;
}