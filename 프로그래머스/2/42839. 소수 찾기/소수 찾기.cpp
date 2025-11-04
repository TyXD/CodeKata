#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n)
{
    if(n < 2)
    {
        return false;
    }
    
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers) 
{
    int answer = 0;
    
    set<int> NS;
    
    sort(numbers.begin(), numbers.end());
    
    do{
        
        for(int i = 1; i <= numbers.length(); ++i)
        {
            int num = stoi(numbers.substr(0, i));
            NS.insert(num);
        }
        
    }while(next_permutation(numbers.begin(), numbers.end()));

    for(int num : NS)
    {
        if(isPrime(num))
        {
            answer++;
        }
    }
    return answer;
}