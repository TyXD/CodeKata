#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int bfs(int start, int end, int n, const vector<vector<int>>& graph)
{
    int count = 0;
    queue<int> wirequeue;
    
    vector<bool> visited(n + 1, false);
    
    wirequeue.push(start);
    visited[start] = true;
    
    while(!wirequeue.empty())
    {
        int current = wirequeue.front();
        wirequeue.pop();
        count++;
        
        for(int next : graph[current])
        {
            if(next == end || visited[next] == true)
            {
                continue;
            }
            visited[next] = true;
            
            wirequeue.push(next);
        }
    }
    
    return count;
    
}
int solution(int n, vector<vector<int>> wires) 
{
    int answer = n;
    
    vector<vector<int>> WireGraph(n+1);
    for(auto& wire : wires)
    {
        WireGraph[wire[0]].push_back(wire[1]);
        WireGraph[wire[1]].push_back(wire[0]);
    }
    
    for(auto& wire : wires)
    {
        int start = wire[0];
        int end = wire[1];
        
        int count = bfs(start, end, n, WireGraph);
        
        int different = abs(2*count - n);
        
        answer = min(answer, different);
    }
    return answer;
}