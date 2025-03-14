#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


void error(string word1, string word2, string msg);
bool is_adjacent(const string& word1, const string& word2);
bool edit_distance_within(const string& word1, const string& word2, int total);
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list);
bool not_in_set(string const &word, set<string> set);
void load_words(set<string> & word_list, const string& file_name);
void print_word_ladder(const vector<string>& ladder);
void verify_word_ladder();
