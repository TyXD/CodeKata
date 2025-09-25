#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b; 
        b = a % b;   
        a = temp; 
    }
    return a;
}
int solution(vector<int> arr) {
    int answer = 1;
   
    for(int& num : arr)
    {
        int gcdcount = gcd(answer, num);
        answer = answer * num / gcdcount;
    }
    return answer;
}