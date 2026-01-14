#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare_genre(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

bool compare_song(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genre_plays;
    unordered_map<string, vector<pair<int, int>>> genre_songs;
    
    for(int i = 0; i < plays.size(); ++i)
    {
        genre_plays[genres[i]] += plays[i];
        genre_songs[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> sorted_genres(genre_plays.begin(), genre_plays.end());
    
    sort(sorted_genres.begin(), sorted_genres.end(), compare_genre);
    
    for(const auto& tag : sorted_genres)
    {
        string current_genre = tag.first;
        vector<pair<int, int>>& songs = genre_songs[current_genre];
        
        sort(songs.begin(), songs.end(), compare_song);
        
        for(int i = 0; i < songs.size() && i < 2; ++i) {
            answer.push_back(songs[i].second);
        }
    }
    return answer;
}