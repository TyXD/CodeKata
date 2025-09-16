#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    int temp;
    string sTemp;
    vector<int> todays;
    vector<int> vPrivacy;
    vector<int> answer;
    unordered_map<string, int> mTerm;
    stringstream st(today);
    
    while(st >> temp)
    {
        todays.push_back(temp);
        
        st.ignore();
    }
    
    for( auto& term : terms)
    {
        stringstream ssTerm(term);
        
        ssTerm >> sTemp;
        ssTerm >> temp;
        mTerm[sTemp] = temp;
    }
    
    for(int i = 0; i < privacies.size(); ++i)
    {
        stringstream ssPrivac(privacies[i]);
        
        for(int j = 0; j < 3; j++)
        {
            ssPrivac >> temp;
            vPrivacy.push_back(temp);
            ssPrivac.ignore();
        }
        ssPrivac >> sTemp;
        vPrivacy[1] += mTerm[sTemp];
        if(vPrivacy[1] > 12)
        {
            vPrivacy[0] += (vPrivacy[1] -1) / 12;
            vPrivacy[1] = vPrivacy[1] % 12;
            if(vPrivacy[1] == 0)
            {
                vPrivacy[1] = 12;
            }
        }
        
        for(int k = 0; k < 3; ++k)
        {
            if(todays[k] > vPrivacy[k])
            {
                answer.push_back(i+1);
                break;
            }
            else if(todays[k] < vPrivacy[k])
            {
                break;
            }
            else if(k == 2 && todays[k] == vPrivacy[k])
            {
                answer.push_back(i+1);
                break;
            }
        }
        vPrivacy.clear();
        
        
    }
    /*
    privacies vector int parsar a b c to plus;
    mm > 12 yyyy+1, mm%12;
    
    last for today == privacies delete;
    */

    return answer;
}