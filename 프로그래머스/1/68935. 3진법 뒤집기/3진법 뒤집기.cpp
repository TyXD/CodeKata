#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    vector<int>cont;
    int answer = 0;
    int mul = 0;
        
    while(n != 0)
    {
        cont.push_back(n % 3);
        n /= 3;
    }
    for(auto it = cont.rbegin(); it != cont.rend(); it++)
    {
        answer += *it * pow(3, mul);
        ++mul;
    }

    return answer;
}