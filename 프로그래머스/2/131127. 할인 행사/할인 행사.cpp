#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int>want_map;
    bool bIsTrue = false;
    for(int i = 0; i < want.size(); ++i)
    {
        want_map[want[i]] = number[i];
    }
    for(int i = 0; i < discount.size() - 9; ++i)
    {
        unordered_map<string, int>copy_map = want_map;
        bIsTrue = true;
        for(int j = i; j < 10 + i; ++j)
        {
            if(copy_map.find(discount[j]) != copy_map.end())
            {
                if(copy_map[discount[j]] != 0)
                {
                    copy_map[discount[j]]--;
                }
                else
                {
                    bIsTrue = false;
                    break;
                }
            }
            else
            {
                bIsTrue = false;
                break;
            }
        }
        if(bIsTrue == true)
        {
            answer += 1;
        }
    }
    return answer;
}