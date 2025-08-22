#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.size() == 4 || s.size() == 6)
    {
        if(all_of(s.begin(), s.end(), ::isdigit))
        {

        }
        else
        {
            answer = false;
        }
    }
    else
    {
        answer = false;
    }
    return answer;
}