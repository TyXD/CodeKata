#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> a;
    
    for(int i = numbers.size(); i > 0; --i)
    {
        if(a.empty())
        {
            answer[i-1] = -1;
            a.push(numbers[i-1]);
        }
        else
        {
            while(!a.empty())
            {
                if(a.top() > numbers[i-1])
                {
                    answer[i-1] = a.top();
                    a.push(numbers[i-1]);
                    break;
                }
                else
                {
                    a.pop();
                }
            }
            if(a.empty())
            {
                answer[i-1] = -1;
                a.push(numbers[i-1]);
            }
        }
    }
    return answer;
}