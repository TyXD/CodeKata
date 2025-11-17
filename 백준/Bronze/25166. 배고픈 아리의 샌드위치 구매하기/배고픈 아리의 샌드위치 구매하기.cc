#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    vector<int>coins = {512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    vector<int>dugi_coins = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int index = 0;
    cin >> a >> b;

    if(a < 1024)
    {
        cout << "No thanks" << '\n';
    }
    else
    {
        for(const int& coin : coins)
        {
            if(b >= coin)
            {
                dugi_coins[index]++;  
                b -= coin;
            }
            ++index;
        }
        
        a -= 1023;
        index = 0;
        for(const int& coin : coins)
        {
            if(a >= coin)
            {
                if(dugi_coins[index] != 0)
                {
                    a -= coin;
                    dugi_coins[index] = 0;
                }
                else
                {
                    break;
                }
            }
            ++index;        
        }
        if(a == 0)
        {
            cout << "Thanks" << '\n';
        }
        else
        {
            cout << "Impossible" << '\n';
        }
    }
    return 0;
}