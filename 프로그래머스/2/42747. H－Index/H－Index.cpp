#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int count = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int& citation : citations)
    {
        count++;
        if(count == citation)
        {
            answer = citation;
            break;
        }
        else if(count > citation)
        {
            answer = count -1;
            break;
        }
    }
    if(answer == 0 && count == citations.size())
    {
        answer = citations.size();
    }
    return answer;
}