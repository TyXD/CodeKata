#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> reports, int k) 
{
    unordered_map<string, unordered_set<string>> user_report;
    unordered_map<string, int> count_mail;
    vector<int> answer;
    
    for(string& report : reports)
    {
        stringstream ss(report);
        string user_id, reported_id;
        ss >> user_id >> reported_id;
        user_report[reported_id].insert(user_id);
    }
    
    for (auto& [reported_id, user_id_lst] : user_report) 
    {
        if (user_id_lst.size() >= k) 
        {
            for (const string& uid : user_id_lst) 
            {
                count_mail[uid]++;
            }
        }
  }
    for (string& id : id_list) 
    {
        answer.push_back(count_mail[id]);
    }

    return answer;
}