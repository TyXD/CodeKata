#include <string>
#include <vector>
#include <queue>


using namespace std;



int check(const vector<string>& place, int x, int y, bool visited[][5])
{
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    queue<pair<int, int>> place_queue;
    place_queue.push({x, y});
    visited[x][y] = true;
    
    while(!place_queue.empty())
    {
        auto[cx, cy] = place_queue.front();
        place_queue.pop();
        int dist = abs(cx - x) + abs(cy - y);
        
        if(dist == 2 && place[cx][cy] == 'P')
        {
            return 0;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i]; 
            int ny = cy + dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            {
                continue;
            }
            if(!visited[nx][ny])
            {
                if(place[nx][ny] == 'O')
                {
                    visited[nx][ny] = true;
                    place_queue.push({nx, ny});
                }
                else if(place[nx][ny] == 'P' && dist <= 1)
                {
                    return 0;
                }
            }
        }
    }
    
    return 1;
}
vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer;
    for(const auto& place : places)
    {
        bool visited[5][5] = {false,};
        bool bIsTrue = true;
        for(int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(place[i][j] == 'P' && !visited[i][j])
                {
                    if(check(place, i, j, visited) == 0) 
                    {
                        bIsTrue = false;
                        break;
                    }
                }
            }
            if(bIsTrue == false)
            {
                break;
            }
        }
        answer.push_back(bIsTrue ? 1:0);
    }
    return answer;
}