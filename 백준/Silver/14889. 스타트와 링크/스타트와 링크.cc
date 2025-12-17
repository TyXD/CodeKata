#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int ability[20][20];
bool team[20];  // true: 스타트 팀, false: 링크 팀
int minDiff = 100000;

int calc()
{
    int startAb = 0;
    int linkAb = 0;
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            if(team[i] && team[j])
            {
                startAb += ability[i][j] + ability[j][i];
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            if(!team[i] && !team[j])
            {
                linkAb += ability[i][j] + ability[j][i];
            }
        }
    }
    
    return abs(startAb - linkAb);
}
void teamSet(int start, int idx)
{
    if(start == n/2)
    {
        int answer = calc();
        minDiff = min(answer, minDiff);
        return;
    }
    
    if(idx == n)
    {
        return;
    }
    team[idx] = true;
    teamSet(start + 1, idx+1);
    
    team[idx] = false;
    teamSet(start, idx+1); 
}
int main() {
    // 입력
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> ability[i][j];
        }
    }
    
    // 여기에 알고리즘 로직 작성
    
    // TODO: 백트래킹으로 팀 조합 생성 및 능력치 차이 계산
    teamSet(0, 0);
    // 출력
    cout << minDiff << "\n";
    
    return 0;
}
