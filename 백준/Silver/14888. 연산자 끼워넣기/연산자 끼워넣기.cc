#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> numbers;
int operators[4]; // +, -, *, /

void calc(int& maxI, int& minI, int idx, int answer)
{
    if(idx == numbers.size())
    {
        maxI = max(maxI, answer);
        minI = min(minI, answer);
        return;
    }
    for(int j = 0; j < 4; ++j)
    {
        if(operators[j] != 0)
        {
            operators[j]--;
            switch(j)
            {
                case 0 :
                    calc(maxI, minI, idx+1, answer + numbers[idx]);
                    break;
                case 1 :
                    calc(maxI, minI, idx+1, answer - numbers[idx]);
                    break;
                case 2 :
                    calc(maxI, minI, idx+1, answer * numbers[idx]);
                    break;
                case 3 :
                    calc(maxI, minI, idx+1, answer / numbers[idx]);
                    break;
            }
            operators[j]++;
        }
    }     
}

int main() {
    // 입력
    cin >> n;
    
    numbers.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    for(int i = 0; i < 4; i++) {
        cin >> operators[i];
    }
    
    // 여기에 알고리즘 로직 작성
    int maxResult = -1000000000;
    int minResult = 1000000000;
    
    // TODO: 백트래킹으로 연산자 순열 생성 및 계산
    calc(maxResult, minResult, 1, numbers[0]);
    // 출력
    cout << maxResult << "\n";
    cout << minResult << "\n";
    
    return 0;
}