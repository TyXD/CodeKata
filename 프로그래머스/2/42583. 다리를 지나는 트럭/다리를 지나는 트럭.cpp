#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    int currentWeight = 0;
    int index = 0;
    vector<int> truck_time;
    queue<int> truck_queue;
    
    truck_queue.push(truck_weights[index]);
    truck_time.push_back(bridge_length);
    currentWeight += truck_weights[index];
    while(!truck_queue.empty())
    {
        ++answer;
        
        if(answer == truck_time[0])
        {
            currentWeight -= truck_queue.front();
            truck_queue.pop();
            truck_time.erase(truck_time.begin());
        }
        if(currentWeight + truck_weights[index+1] <= weight && index+1 < truck_weights.size())
        {
            ++index;
            truck_queue.push(truck_weights[index]);
            truck_time.push_back(bridge_length + answer);
            currentWeight += truck_weights[index];
        } 
         
    }
    return answer+1;
}