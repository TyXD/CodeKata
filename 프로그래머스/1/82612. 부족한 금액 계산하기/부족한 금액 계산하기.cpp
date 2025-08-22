using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    for(int i = 1; i <= count; ++i)
    {
        answer += i;
    }
    answer *= price;
    if(money - answer >= 0)
    {
        return 0;
    }
    else
    {
        answer = (-1) * (money - answer);
    }
    return answer;
}