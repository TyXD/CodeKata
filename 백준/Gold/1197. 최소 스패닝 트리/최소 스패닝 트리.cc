#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parents[10001];

int find(int x)
{
    if(parents[x] == x)
    {
        return x;
    }
    else
    {
        return parents[x] = find(parents[x]);
    }
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a != b)
    {
        parents[b] = a;
    }
    return;
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V, E;
    cin >> V >> E;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < E; i++) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());
    
    for(int i = 1; i <= V; ++i)
    {
        parents[i] = i;
    }
    int answer = 0;
    int count = 0;

    for(int i = 0; i < E; ++i)
    {
        int cost = edges[i].first;
        int start = edges[i].second.first;
        int end = edges[i].second.second;
        
        if(find(start) != find(end))
        {
            unite(start, end);
            answer += cost;
            count++;
            if(count == V-1)
            {
                break;
            }
        }
    }
    cout << answer << '\n';  
}
