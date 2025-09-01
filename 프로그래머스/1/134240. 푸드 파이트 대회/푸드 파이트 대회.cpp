#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    for (int j = 0; j < food.size(); j++)
    {
        if(food[j] == 1)
        {
            continue;
        }
        else
        {
            for(int i = 0; i < food[j]/2; ++i)
            {
                answer += to_string(j);
            }
        }
    }
    answer += to_string(0);
    for(int i = answer.length()-2; i >= 0; --i)
    {
        answer += answer[i];
    }
    return answer;
}