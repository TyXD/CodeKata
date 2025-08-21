#include <string>
#include <vector>

using namespace std;

int solution(int num) {

    
    for(int answer = 0; answer <= 500; ++answer)
    {
        if(num == 1)
        {
            return answer;
        }
        
        if(num % 2 == 0)
        {
            num /= 2;
        }
        else if(num % 2 == 1)
        {
            num = (num*3)+1;
        }
    }
    
    return -1;
}