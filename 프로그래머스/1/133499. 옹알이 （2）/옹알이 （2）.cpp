#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    int dup = 0;
    
    for( auto& bab : babbling)
    {
        if(bab.size() == 0)
        {
            continue;
        }
        while(bab.size() != 0)
        {
            if(bab[0] == 'a')
            {
                if(bab.substr(0, 3) == "aya" && dup != 1)
                {
                    bab.erase(0, 3);
                    dup = 1;
                    
                    continue;
                }
                else
                {
                    dup = 0;
                    break;
                }
            }
            else if(bab[0] == 'y')
            {
                if(bab.substr(0, 2) == "ye" && dup != 2)
                {
                    bab.erase(0, 2);
                    dup = 2;

                    continue;
                }
                else
                {
                    dup = 0;
                    
                    break;
                }
            }
            else if(bab[0] == 'w')
            {
                if(bab.substr(0, 3) == "woo" &&  dup != 3)
                {
                    bab.erase(0, 3);
                    dup = 3;
                    
                    continue;
                }
                else
                {
                    dup = 0;
                    
                    break;
                }
            }
            else if(bab[0] == 'm')
            {
                if(bab.substr(0, 2) == "ma" &&  dup != 4)
                {
                    bab.erase(0, 2);
                    dup = 4;
                    
                    continue;
                }
                else
                {
                    dup = 0;
                    
                    break;
                }
            }
            break;
        }
        if(bab.size() == 0)
        {
            answer++;
        }
        dup = 0;

    }
    return answer;
}