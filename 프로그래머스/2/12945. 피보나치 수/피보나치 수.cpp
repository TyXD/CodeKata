#include <string>
#include <vector>

using namespace std;

vector<int> memo(1000000, -1);

int fibo(int n)
{
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = ( fibo(n - 1) + fibo(n - 2) )% 1234567;
    return memo[n];
}
int solution(int n) {
    int answer = 0;
    answer = fibo(n) ;
    return answer;
}