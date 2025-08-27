#include <string>
#include <vector>


using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(char c : s)
    {
        if(c == 32)
        {
            answer += c;
            continue;
        }
        if('A' <= c && c <= 'Z')
        {
            c += n;
            if( 'Z' < c)
            {
                c -= 26;
            }
            answer += c;
            continue;
        }
        else if('a' <= c && c <= 'z')
        {
            c -= 26;
            c += n;
            
            if('a' <= c)
            {
                answer += c;
                continue;
            }
            else
            {
                c += 26;
                answer += c;
                continue;
            }

        }
    }
    return answer;
}