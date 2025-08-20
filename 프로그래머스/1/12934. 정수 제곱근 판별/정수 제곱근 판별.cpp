#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long s = sqrt(n);

    if(pow(s, 2) == n)
    {
        return pow(s+1, 2);
    }
    else
        return -1;
}