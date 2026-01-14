#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 200000000;
int N, E;
vector<pair<int, int>> graph[801];

vector<int> dijkstra(int start)
{
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cost) 
        {
            continue;
        }
        
        for(int i = 0; i < graph[cur].size(); ++i)
        {
            int next = graph[cur][i].second;
            int next_cost = cost + graph[cur][i].first;
            
            if(next_cost < dist[next])
            {
                dist[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
        
    }
    
    return dist;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E;

    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        // 양방향 그래프
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    
    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist_start = dijkstra(1);
    vector<int> dist_v1 = dijkstra(v1);
    vector<int> dist_v2 = dijkstra(v2);

    long long path1 = (long long)dist_start[v1] + dist_v1[v2] + dist_v2[N];
 
    long long path2 = (long long)dist_start[v2] + dist_v2[v1] + dist_v1[N];

    long long answer = min(path1, path2);

    if (answer >= INF) {
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }

    return 0;
}
