#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    // int k = (int)log10(n); 멀티셋이 없더라면...
    
    multiset<int> cont;
    
    while(n != 0)
    {
        cont.insert(n%10);
        n /= 10;
    }
    int index = 0;
    for (auto it = cont.begin(); it != cont.end(); it++)
    {
        answer += *it * pow(10, index);
        ++index;
    }

    return answer;
}