#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) 
{
    int answer = 0;
    
    unordered_map<int, int> topOne;
    unordered_map<int, int> topTwo;
    
    for(const int& topp : topping)
    {
        topTwo[topp]++;
    }
    
    for(const int& topp : topping)
    {
        topOne[topp]++;
        topTwo[topp]--;
        if(topTwo[topp] == 0)
        {
            topTwo.erase(topp);
        }
        
        if(topOne.size() == topTwo.size())
        {
            answer++;
        }
    }

    return answer;
}