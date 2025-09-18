#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) 
{
    vector<int> answer;
    int StartX =0;
    int StartY =0;
    int flag = 0;
    
    char op;
    int pos;
    for(int i = 0; i < park.size(); ++i)
    {
        
        for(int j = 0; j <park[i].size(); ++j)
        {
            if(park[i][j] == 'S')
            {
                StartX = i;
                StartY = j;
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }

    for(auto& route : routes)
    {
        stringstream Rss;
        Rss.str(route);
        Rss >> op;
        Rss >> pos;
        if(op == 'N')
        {
            if(StartX-pos < 0)
            {
                continue;
            }
            for(int i = 1; i <= pos; ++i)
            {
                if(park[StartX-i][StartY] == 'X')
                {
                    break;
                }
                else if(i == pos)
                {
                    StartX -= pos;
                }
            }
        }
        else if(op == 'S')
        {
            if(StartX+pos >= park.size())
            {
                continue;
            }
            for(int i = 1; i <= pos; ++i)
            {
                if(park[StartX+i][StartY] == 'X')
                {
                    break;
                }
                else if(i == pos)
                {
                    StartX += pos;
                }
            }       
        }
        else if(op == 'W')
        {
            if(StartY-pos < 0)
            {
                continue;
            }
            for(int i = 1; i <= pos; ++i)
            {
                if(park[StartX][StartY-i] == 'X')
                {
                    break;
                }
                else if(i == pos)
                {
                    StartY -= pos;
                }
            }
        }
        else if(op == 'E')
        {
            if(StartY+pos >= park[StartX].size())
            {
                continue;
            }
            for(int i = 1; i <= pos; ++i)
            {
                if(park[StartX][StartY+i] == 'X')
                {
                    break;
                }
                else if(i == pos)
                {
                    StartY += pos;
                }
            }
        }

    }
    answer.push_back(StartX);
    answer.push_back(StartY);
    
    return answer;
    
}