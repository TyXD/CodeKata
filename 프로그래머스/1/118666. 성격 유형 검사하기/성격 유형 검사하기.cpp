#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    string answer = "";
    vector<string> MBTI_Mod = {"RT", "CF", "JM", "AN"};
    unordered_map<char, int> MBTI;
    for(int i = 0; i < choices.size(); ++i)
    {
        if(choices[i] < 4)
        {
            MBTI[survey[i][0]] += 4 - choices[i];
        }
        else if(choices[i] > 4)
        {
            MBTI[survey[i][1]] += choices[i] - 4;
        }
    }
    for(int i = 0; i < 4; ++i)
    {
        if(MBTI[MBTI_Mod[i][0]] >= MBTI[MBTI_Mod[i][1]])
        {
            answer += MBTI_Mod[i][0];
        }
        else
        {
            answer += MBTI_Mod[i][1];
        }
    }
    return answer;
}