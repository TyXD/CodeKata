#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    int deletezero = 0;
    int countone;
    while(s != "1")
    {      
        for(auto& ch : s)
        {
            if(ch == '1')
            {
                countone++;
            }
        }
        
        deletezero += s.size() - countone;
        s.clear();
        while(countone != 0)
        {
            if(countone % 2 == 1)
            {
                s = "1" + s;
            }
            else
            {
                s = "0" + s;
            }
            countone = countone/2;
        }
        count++;
    }
    answer.push_back(count);
    answer.push_back(deletezero);
    return answer;
}