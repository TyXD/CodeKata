#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> Tmap;
    vector<int> Tvec;
    
    for( auto& tang : tangerine)
    {
        Tmap[tang]++;   
    }
    
    for(auto& map : Tmap)
    {
        Tvec.push_back(map.second);
    }
    
    sort(Tvec.begin(), Tvec.end(), greater<int>());
    

    int count = 0;
    while( k > 0)
    {
        k -= Tvec[count];
        count++;
    }
    answer = count;
    return answer;
}