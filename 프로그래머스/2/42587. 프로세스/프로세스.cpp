#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> priority_value;
    priority_queue<int> priority_count;
    int index = 0;
    
    for(int pri : priorities)
    {
        priority_value.push_back(make_pair(pri, index));
        priority_count.push(pri);
        ++index;
    }
    
    pair<int, int> current_process;
    int pri, idx;

    
    while(!priority_value.empty())
    {
        current_process = priority_value.front();
        pri = current_process.first;  
        idx = current_process.second; 
        
        if(pri == priority_count.top())
        {
            ++answer;
            if (idx == location) 
            {
                break;
            }
            else
            {
                priority_value.pop_front();
                priority_count.pop();
                continue;
            }
        }
        
        else
        {
            priority_value.pop_front();
            priority_value.push_back(current_process);
        }
        
    }
    return answer;
}