#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    int answer = n;
    map<int, int>people;
    
    for(const auto& l : lost)
    {
        people[l]--;
    }
    for(const auto& r : reserve)
    {
        people[r]++;
    }
    
   for(int i = 1; i <= n; i++)
   {
       if(people[i] == -1)
       {
           if(people[i-1] == 1)
           {
               people[i-1]--;
               people[i]++;
           }
           else if(people[i+1] == 1)
           {
               people[i+1]--;
               people[i]++;
           }
           else
           {
               answer--;
           }
       } 
   }
    return answer;
}