#include <string>
#include <vector>

using namespace std;

int isDivisor(int num)
{
    if(num == 1)
    {
        return 1;
    }
    int divisor = 2;
    
    for(int i = 2; i*i<= num; ++i)
    {
        if(num % i == 0)
        {
            divisor += 2;
        }
        if(num == i*i)
        {
            divisor--;
        }
    }
    
    return divisor;
}
int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1; i <= number; i++)
    {
        int div = isDivisor(i);
        if(limit < div )
        {
            answer += power;
            continue;
        }
        answer += div;
    }
    return answer;
}