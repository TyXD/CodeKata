#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, 0};
    int start = 0;
    int end = 0;
    int sum = sequence[end];
    int len = sequence.size()+1;
    
    while(start != sequence.size())
    {
        if(sum == k)
        {
            if(start == end)
            {
                answer[0] = start;
                answer[1] = end;
                break;
            }
            
            if(len > end - start +1)
            {
                len = end - start +1;
                answer[0] = start;
                answer[1] = end;
            }
            
            sum -= sequence[start];
            ++start;
            
        }
        else if(sum < k)
        {
            ++end;
            if(end > sequence.size())
            {
                break;
            }
            sum += sequence[end];
        }
        else
        {
            sum -= sequence[start];
            ++start;
        }
    }
    
    return answer;
}