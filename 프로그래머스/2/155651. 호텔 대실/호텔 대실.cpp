#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string exit_time(string time)
{
    
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3)) + 10;
    if(minute >= 60)
    {
        ++hour;
        minute -= 60;
    }
    string hourS, minuteS;
    if(minute < 10)
    {
        minuteS = "0" + to_string(minute);
    }
    else
    {
        minuteS = to_string(minute);
    }
    if(hour < 10)
    {
        hourS = "0" + to_string(hour);
    }
    else
    {
        hourS = to_string(hour);
    }
    return hourS + ":" + minuteS;
}

bool compare(vector<string>& a, vector<string>& b)
{
    return a[0] < b[0];
}

int solution(vector<vector<string>> book_time) 
{
    int answer = 0;
    vector<string> room;
    sort(book_time.begin(), book_time.end(), compare);
    for(const auto& enter_time : book_time)
    {
        bool bIsRoomClear = false;
        int ClearRoom = 0;
        for(int i = 0; i < room.size(); ++i)
        {
            if(room[i] <= enter_time[0])
            {
                ClearRoom = i;
                bIsRoomClear = true;
                break;
            }
        }
        if(bIsRoomClear == true)
        {
            room[ClearRoom] = exit_time(enter_time[1]);
        }
        else
        {
            room.push_back(exit_time(enter_time[1]));
            answer++;
            continue;
        }
        
    }
    return answer;
}