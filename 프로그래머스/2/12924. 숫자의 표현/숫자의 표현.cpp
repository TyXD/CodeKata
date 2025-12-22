#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    int prev_index = 0;
    int next_index = 0;
    int sum = 0;
    while(next_index <= n)
    {
        if(sum == n)
        {
            ++answer;
        }
        
        if(sum <= n)
        {
            ++next_index;
            sum += next_index;     
        }
        else
        {
            ++prev_index;
            sum -= prev_index;
        }
    }
    return answer;
}