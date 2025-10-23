#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long n) 
{
    if(n == 0 || n == 1)
    {
        return false;
    }
	for (int i = 2; i <= sqrt(n); i++) 
    {
		if (n%i == 0) 
        {
			return false;
		}
	}
	return true;
}

int solution(int n, int k) {
    int answer = 0;
    string nums;
    string ITS;
    while(n != 0)
    {
        ITS = to_string(n % k);
        n /= k;
        
        nums = ITS + nums;
    }


    string PN;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] != '0')
        {
            PN = PN + nums[i];
        }
        else
        {
            if(!PN.empty())
            {
                if(isPrime(stoll(PN)))
                {
                    ++answer;   
                }

                PN.clear();
            }
        }
    }
    if(!PN.empty() &&isPrime(stoll(PN)))
    {
        ++answer;   
    }
    return answer;
}