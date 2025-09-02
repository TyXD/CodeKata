#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    vector<int> answer;
    multiset<int> ms;
    
    for( const auto& s : score)
    {
        ms.insert(s);
        if(ms.size() <= k || k >= score.size())
        {
            auto it = ms.begin();
            answer.push_back(*it);
        }
        else
        {
            auto it = next(ms.rbegin(), k-1);
            answer.push_back(*it);
        }
    }
    return answer;
}