#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int count = -1; 
    
    for(int i = 0; i < s.size(); ++i)
    {
        for(int j = i-1; j >= 0; --j)
        {
            if(s[i] == s[j])
            {
                count = i-j;
                break;
            }
        }
        answer.push_back(count);
        count = -1;
    }
    return answer;
}