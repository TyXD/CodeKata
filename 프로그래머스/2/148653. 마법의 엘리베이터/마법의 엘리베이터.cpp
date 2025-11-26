#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int index = 0;
    int next_index = 0;
    while(storey != 0)
    {
        index = storey  % 10;
        next_index = (storey / 10) % 10;
        if(index < 6)
        {
            answer += index;
            if(index == 5)
            {
                if(next_index >= 5)
                {
                    storey += 10;
                }
            }
        }
        else
        {
            answer += (10 - index);
            storey += 10;
        }
        storey /= 10;
    }
    return answer;
}