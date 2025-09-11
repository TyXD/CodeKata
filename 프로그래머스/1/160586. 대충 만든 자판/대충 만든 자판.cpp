#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    unordered_map<char, int>keymapping;
    vector<int> answer;
    int res = 0;
    for( const auto& keyM : keymap)
    {
        for(int i = 0; i < keyM.size(); ++i)
        {
            auto it = keymapping.find(keyM[i]);

            if (it == keymapping.end() || i+1 < it->second) 
            {
                keymapping[keyM[i]] = i+1;
            }
            
        }
    }
    for(const auto& target : targets)
    {
        for(const auto& ch : target)
        {
            if(keymapping[ch] == 0)
            {
                res = -1;
                break;
            }
            else
            {
                res += keymapping[ch];
            }
        }
        answer.push_back(res);
        res = 0;
    }

    return answer;
}