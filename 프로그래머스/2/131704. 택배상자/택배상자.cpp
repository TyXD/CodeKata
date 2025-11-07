#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int index = 0;
    int box = 1;
    
    stack<int> cont;
    
    while(box <= order.size() + 1)
    {
        if(order[index] == box)
        {
            ++answer;
            ++index;
            ++box;
            continue;
        }
        if(!cont.empty() && cont.top() == order[index])
        {
            ++answer;
            ++index;
            cont.pop();
            continue;
        }
        
        cont.push(box);
        ++box;
    }
    return answer;
}