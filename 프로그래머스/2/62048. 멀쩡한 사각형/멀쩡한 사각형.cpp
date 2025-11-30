#include <algorithm>

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long gcd_wh = __gcd(w, h);
    long long width = w / gcd_wh;
    long long height = h / gcd_wh;
    answer = ((long long)w * (long long)h) - (width + height -1) * gcd_wh;  
        
    return answer;
}