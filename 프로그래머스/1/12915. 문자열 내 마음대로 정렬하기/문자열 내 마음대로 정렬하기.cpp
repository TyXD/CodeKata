#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
bool compare_str(const string& str1, const string& str2)
{
    return str1[N] < str2[N];

}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    stable_sort(strings.begin(), strings.end());
    stable_sort(strings.begin(), strings.end(), compare_str);
    return strings;
}