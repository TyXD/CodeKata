#include <string>
#include <vector>
#include <queue>

using namespace std;



int solution(int x, int y, int n) 
{
    queue<pair<int, int>> ChangeNum;
    vector<bool> visited(1000001, false);
    ChangeNum.push({x, 0});
    visited[x] = true;
    while(!ChangeNum.empty())
    {
        int current = ChangeNum.front().first;
        int count = ChangeNum.front().second;
        
        ChangeNum.pop();
        
        if(current == y)
        {
            return count;
        }
        int next = current + n;
        if(next <= y && !visited[next])
        {
            visited[next] = true;
            ChangeNum.push({next, count+1});
        }
        next = current * 2;
        if(next <= y && !visited[next])
        {
            visited[next] = true;
            ChangeNum.push({next, count+1});
        }
        next = current * 3;
        if(next <= y && !visited[next])
        {
            visited[next] = true;
            ChangeNum.push({next, count+1});
        }
    }
    
    return -1;
}