#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;

int timeToMinute(const string& time) 
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<int> answer;
    
    map<string, int> parkingCars;
    map<string, int> totalTime;
    
    for(const auto& record : records)
    {
        stringstream ss(record);
        string timeS, carNum, InOut;
        ss >> timeS >> carNum >> InOut;
        
        int time = timeToMinute(timeS);
        
        if(InOut == "IN")
        {
            parkingCars[carNum] = time;
        }
        else
        {
            int inTime = parkingCars[carNum];
            int parkTotal = time - inTime;
            
            if(totalTime.find(carNum) == totalTime.end())
            {
                totalTime[carNum] = 0;
            }
            
            totalTime[carNum] += parkTotal;
            parkingCars.erase(carNum);
        }
    }
    
    for(const auto& carOut : parkingCars)
    {
        int parkLastTotal = 1439 - carOut.second;
        
        if(totalTime.find(carOut.first) == totalTime.end())
        {
            totalTime[carOut.first] = 0;
        }
        
        totalTime[carOut.first] += parkLastTotal;
    }
    for(const auto& result : totalTime)
    {
        if(result.second <= fees[0])
        {
            answer.push_back(fees[1]);
            continue;
        }
        else
        {
            int resultFees;
            double basetime = static_cast<double>(result.second - fees[0]) / fees[2];
            int ceiltime = static_cast<int>(ceil(basetime));
            resultFees = ceiltime * fees[3] + fees[1];
            answer.push_back(resultFees);
        }
    }
    return answer;
}