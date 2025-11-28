#include <string>
#include <vector>
#include <numeric>

using namespace std;

int getGCD(vector<int> cont)
{
    int temp = cont[0];
    for(int i = 1; i < cont.size(); ++i)
    {
        temp = gcd(temp, cont[i]);
        if(temp == 1)
        {
            return 1;
        }
    }
    return temp;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int a_GCD = getGCD(arrayA);
    int b_GCD = getGCD(arrayB);
    
    bool a_correct = true;
    bool b_correct = true;
    for(int v : arrayA)
    {
        if(v % b_GCD == 0)
        {
            a_correct = false;
        }
    }
    for(int v : arrayB)
    {
        if(v % a_GCD == 0)
        {
            b_correct = false;
        }
    }
    
    if(a_correct == true)
    {
        if(b_correct == true)
        {
            return a_GCD > b_GCD ? a_GCD : b_GCD; 
        }
        else
        {
            return b_GCD;
        }
    }
    else
    {
        if(b_correct == true)
        {
            return a_GCD;
        }
    }
    return answer;
}