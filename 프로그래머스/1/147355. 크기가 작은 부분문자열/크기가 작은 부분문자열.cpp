#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    vector<string> vecs;
    for(int i= 0; i <= t.size() -p.size() ; ++i)
    {
        answer += (stoll(t.substr(i, p.size())) <= stoll(p) ? 1 : 0 );
    }

    return answer;
}