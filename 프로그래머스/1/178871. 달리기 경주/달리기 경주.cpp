#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) 
{
    vector<string> answer;
    unordered_map<string, int> ranking;
    for(int i = 0; i < players.size(); ++i)
    {
        ranking[players[i]] = i; 
        answer.push_back(players[i]);
    }
    for(string& call : callings)
    {
        int current_pos = ranking[call];

        if (current_pos == 0) 
        {
            continue;
        }

        int target_pos = current_pos - 1;
        string target_horse = answer[target_pos];
        
        swap(answer[current_pos], answer[target_pos]);
        ranking[call] = target_pos;
        ranking[target_horse] = current_pos;
    }
    
    return answer;
}