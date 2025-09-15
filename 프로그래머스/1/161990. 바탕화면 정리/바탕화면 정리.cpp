#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{
    vector<int> answer;
    
    int lux = wallpaper.size();
    int luy = wallpaper[0].size();
    int rdx = 0;
    int rdy = 0;
    
    for(int i = 0; i < wallpaper.size(); ++i)
    {
        for(int j = 0; j < wallpaper[i].size(); ++j)
        {
            if(wallpaper[i][j] == '#')
            {
                lux = min(i, lux);
                luy = min(j, luy);
                rdx = max(i+1, rdx);
                rdy = max(j+1, rdy);
            }
        }
    }
    
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    return answer;
}