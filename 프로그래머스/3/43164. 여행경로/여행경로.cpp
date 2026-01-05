#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(const vector<vector<string>>& tickets,
         vector<bool>& visited,
         const string& current,
         int used,
         vector<string>& path)
{
    path.push_back(current);

    if (used == tickets.size())
    {
        return true;
    }
        
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (!visited[i] && tickets[i][0] == current)
        {
            visited[i] = true;
            if (DFS(tickets, visited, tickets[i][1], used + 1, path))
            {
                return true;
            }     
            visited[i] = false;
        }
    }

    path.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end());

    vector<string> answer;
    vector<bool> visited(tickets.size(), false);

    DFS(tickets, visited, "ICN", 0, answer);

    return answer;
}