#include <string>
#include <vector>

using namespace std;

int MaxDepth = 0;
bool visited[8] = {false, };

void ExploreDungeon(int depth, int power, vector<vector<int>>& dungeons) 
{
    if(MaxDepth < depth)
    {
        MaxDepth = depth;
    }
    for(int i = 0; i < dungeons.size(); ++i)
    {
        if(visited[i] || dungeons[i][0] > power)
        {
            continue;
        }
        visited[i] = true;
        ExploreDungeon(depth + 1, power - dungeons[i][1], dungeons);
        visited[i] = false;
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    ExploreDungeon(0, k, dungeons);
    return MaxDepth;
}