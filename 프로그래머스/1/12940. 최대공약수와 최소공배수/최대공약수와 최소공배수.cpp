#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int lcm;
    int gcd;
    
    int temp = 1;
    
    gcd = n > m ? n : m;
    lcm = n > m ? m : n;
    
    while(temp != 0)
    {
        temp = gcd%lcm;
        gcd = lcm;
        lcm = temp;
    }
    answer.push_back(gcd);
    
    lcm = n * m / gcd;
    
    answer.push_back(lcm);

    return answer;
}