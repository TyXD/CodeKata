#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string X, string Y)
{
    string answer="";
    map<char,int> mx;
    for(char c : X) mx[c]++;
    map<char,int> my;
    for(char c : Y) my[c]++;
    for(int i=9; i>=0; i--)
    {
        int num=min(mx[i+'0'],my[i+'0']);
        for(int j=0; j<num; j++) answer+=i+'0';
    }
    if(answer=="") answer="-1";
    else if(answer[0]=='0' && answer.size()>1) answer="0";
    return answer;
}