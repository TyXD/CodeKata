#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    long long avg = 0;
    long long temp1_sum = 0;
    long long temp2_sum = 0;
    queue<int> temp1;
    queue<int> temp2;
    
    for(const int& bit : queue1)
    {
        temp1_sum += bit;
        temp1.push(bit);
    }
    
    for(const int& bit : queue2)
    {
        temp2_sum += bit;
        temp2.push(bit);
    }
    
    avg = temp1_sum + temp2_sum;
    if(avg % 2 == 1)
    {
        return -1;
    }
    avg /= 2;
    int index = 0;
    while(index <= (temp1.size() + temp2.size()) *2)
    {
        if(temp1_sum == avg)
        {
            answer = index;
            break;
        }
        
        if(temp1_sum > avg)
        {
            temp1_sum -= temp1.front();
            temp2_sum += temp1.front();
            temp2.push(temp1.front());
            temp1.pop();
            ++index;
        }
        else
        {
            temp1_sum += temp2.front();
            temp2_sum -= temp2.front();
            temp1.push(temp2.front());
            temp2.pop();
            ++index;
        }
    }
    return answer;
}