#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(int N, vector<vector<int> > roads, int K) 
{
    int answer = 0;
    
    vector<vector<pair<int, int>>> graph(N+1);
    
    for(auto& road : roads)
    {
        graph[road[0]].push_back({road[1], road[2]});
        graph[road[1]].push_back({road[0], road[2]});

    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priority_road;

    vector<int> distance(N + 1, INT_MAX);
    
    distance[1] = 0;
    
    priority_road.push({0, 1});
    
    while(!priority_road.empty())
    {
        int time = priority_road.top().first;
        int node = priority_road.top().second;
        priority_road.pop();
        
        if(distance[node] < time)
        {
            continue;
        }
        
        for(auto& edge : graph[node])
        {
            int next_node = edge.first;
            int next_time = edge.second;
            
            if(distance[node] + next_time < distance[next_node])
            {
                distance[next_node] = distance[node] + next_time;
                priority_road.push({distance[next_node], next_node});
            }
        }
    }
    
    for(int i = 1; i <= N; ++i)
    {
        if(distance[i] <= K)
        {
            answer++;
        }
    }
    

    return answer;
}