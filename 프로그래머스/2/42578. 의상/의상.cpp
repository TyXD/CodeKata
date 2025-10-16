#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int>cloth_map;
    
    for(auto cloth : clothes)
    {
        cloth_map[cloth[1]]++;
    }
    for(auto mapc : cloth_map)
    {
        answer *= mapc.second + 1;
    }
    --answer;
    return answer;
}