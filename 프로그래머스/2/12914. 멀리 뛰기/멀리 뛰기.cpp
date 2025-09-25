#include <string>
#include <vector>

using namespace std;

vector<int> memo(1000000, -1);

int fibo(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (memo[n] != -1) return memo[n];
    memo[n] = ( fibo(n - 1) + fibo(n - 2) )% 1234567;
    return memo[n];
}

long long solution(int n) 
{
    long long answer = fibo(n);
    return answer;
}