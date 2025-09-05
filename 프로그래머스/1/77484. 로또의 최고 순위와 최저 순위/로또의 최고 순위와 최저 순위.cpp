#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int max =0;
    int min = 0;
    for( const auto& lotto : lottos)
    {
        if(lotto == 0)
        {
            max++;
            continue;
        }
        for( const auto& num : win_nums)
        {
            if(lotto == num)
            {
                max++;
                min++;
                break;
            }
        }
    }
    if(max == 0)
    {
        max++;
    }
    if(min == 0)
    {
        min++;
    }
    answer.push_back(7-max);
    answer.push_back(7-min);

    return answer;
}