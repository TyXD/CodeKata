#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char pars = '\n';
    int cor = 0;
    int incor = 0;
    
    for( const auto& ch : s)
    {
        if(pars == '\n')
        {
            pars = ch;
            cor++;
            continue;
        }
        
        if(pars == ch)
        {
            cor++;
        }
        else
        {
            incor++;
        }
        
        if(cor == incor)
        {
            pars = '\n';
            cor = 0;
            incor = 0;
            answer++;
        }
    }
    if(pars != '\n')
    {
        answer++;
    }
    return answer;
}