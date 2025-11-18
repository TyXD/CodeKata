#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100][100] = {false,};

int dfs(vector<string>& maps, int x, int y)
{
    if(x < 0 || x >= maps.size())
    {
        return 0;
    }
    if(y < 0 || y >= maps[0].size())
    {
        return 0;
    }
    if(visited[x][y] == true || maps[x][y] == 'X')
    {
        return 0;
    }
    visited[x][y] = true;
    
    int sum = maps[x][y] - '0';
    
    sum += dfs(maps, x - 1, y);
    sum += dfs(maps, x + 1, y);
    sum += dfs(maps, x, y - 1);
    sum += dfs(maps, x, y + 1);
    
    return sum;
}
vector<int> solution(vector<string> maps) {
    vector<int> answers;
    
    for(int i = 0; i < maps.size(); ++i)
    {
        for(int j = 0; j < maps[0].size(); ++j)
        {
            if(maps[i][j] != 'X' && visited[i][j] == false)
            {
                int answer = dfs(maps, i, j);
                answers.push_back(answer);
            }
        }
    }
    
    if(answers.empty())
    {
        answers.push_back(-1);
    }
    sort(answers.begin(), answers.end());
    return answers;
}