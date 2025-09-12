#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> hamburger;
    
    for (const auto& in : ingredient)
    {
        hamburger.push_back(in);
        
        if(hamburger.size() >= 4)
        {
            if(hamburger[hamburger.size()-1] == 1 &&
               hamburger[hamburger.size()-2] == 3 &&
               hamburger[hamburger.size()-3] == 2 &&
               hamburger[hamburger.size()-4] == 1 )
            {
                answer++;
                hamburger.pop_back();
                hamburger.pop_back();
                hamburger.pop_back();
                hamburger.pop_back();
            }
        }
    }

    return answer;
}