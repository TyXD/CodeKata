#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
bool selected[13]; 
int min_chicken_dist = INT_MAX;

int chicken_house_dist(const pair<int, int>& a, const pair<int, int>& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void backtracking_chicken()
{
    int current_city_dist = 0;
    
    for(const auto& house : houses)
    {
        int min_dist_for_house = INT_MAX;
        
        for (int i = 0; i < chickens.size(); ++i) 
        {
            if (selected[i]) 
            {
                int dist = chicken_house_dist(house, chickens[i]);
                
                if (dist < min_dist_for_house) 
                {
                    min_dist_for_house = dist;
                }
            }
        }
        current_city_dist += min_dist_for_house;
    }
    
    if (current_city_dist < min_chicken_dist) 
    {
        min_chicken_dist = current_city_dist;
    }
}

void select_chickens(int index, int count) 
{
    if (count == M) 
    {
        backtracking_chicken();
        return;
    }

    for (int i = index; i < chickens.size(); ++i) 
    {
        if (!selected[i]) 
        {
            selected[i] = true;   
            select_chickens(i + 1, count + 1);
            selected[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> N >> M)) return 0;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            int info;
            cin >> info;
            
            if (info == 1) {
                houses.push_back({r, c});
            } 
            else if (info == 2) {
                chickens.push_back({r, c});
            }
        }
    }

    select_chickens(0, 0);

    cout << min_chicken_dist << endl;

    return 0;
}