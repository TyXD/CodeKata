#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> result;
    
    for( auto cmd : commands)
    {
        copy(array.begin() + cmd[0]-1, array.begin() + cmd[1], back_inserter(result));
        sort(result.begin(), result.end());
        answer.push_back(result[cmd[2]-1]);
        result.clear();
    }
    return answer;
}