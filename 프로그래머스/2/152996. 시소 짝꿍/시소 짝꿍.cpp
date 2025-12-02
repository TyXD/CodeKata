#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

long long solution(vector<int> weights) {

    unordered_map<int, int> WeightMap;
    long long answer = 0;
    
    for(const auto weight : weights)
    {
        WeightMap[weight]++;
    }
    
    for (auto &weight : WeightMap) 
    {
        answer += (long long)weight.second * ((long long)weight.second - 1) / 2; 
    }

    for(auto weight : WeightMap)
    {

        if (weight.first * 3 % 2 == 0) 
        { 
            int target = weight.first * 3 / 2;
            if (WeightMap.find(target) != WeightMap.end())
            {
                answer += weight.second * WeightMap[target];
            }

        }

        {
            int target = weight.first * 2;
            if (WeightMap.find(target) != WeightMap.end())
            {
                answer += weight.second * WeightMap[target];
            }

        }

        if (weight.first * 4 % 3 == 0) 
        {
            int target = weight.first * 4 / 3;
            if (WeightMap.find(target) != WeightMap.end())
            {
                answer += weight.second * WeightMap[target];
            }
        }
    }
    return answer;
}