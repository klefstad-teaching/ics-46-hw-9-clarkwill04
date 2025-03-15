#include "ladder.h"
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

vector<string> generate_word_ladder(
  const string& begin_word, const string& end_word, const set<string>& word_list)
{
  if (not_in_set(end_word, word_list)) return {};
  if (begin_word == end_word) return {};
  queue<vector<string>> ladder_queue;
  ladder_queue.push({begin_word});

  set<string> visited;
  visited.insert(begin_word);

  while (!ladder_queue.empty())
  {
    // get the front ladder for BFS.
    vector<string> ladder = ladder_queue.front();
    ladder_queue.pop();

    // get the last word in the current ladder.
    string last_word = ladder.back();

    for (const auto& word : word_list) {
      if (is_adjacent(last_word, word)) {
        if (not_in_set(word, visited))
        {
          visited.insert(word);
          vector<string> new_ladder = ladder;
          new_ladder.push_back(word);
          if (word == end_word)
            {
            found_ladder();
            return new_ladder;
            }
          ladder_queue.push(new_ladder);
        }
      }
    }
  }
  cout << "No word ladder found.";
  return {};  
}

void found_ladder()
{
  cout << "Word ladder found: ";
}

bool not_in_set(string const &word, set<string> set) 
{
  return set.find(word) == set.end(); 
}

bool is_adjacent(const string& str1, const string& str2)
{
  return edit_distance_within(str1, str2, 1);
}
// returns true if strings within one edit distance
// adapted from the Levenshtein algorithm
bool edit_distance_within(const string& str1, const string& str2, int total) {

  int tot = total;
  int len1 = str1.length(), len2 = str2.length();

  // if strs differ by more than 'total' character

  if (abs(len1 - len2) > total) return false;
  if (str1 == str2) return true;

  int i = 0, j = 0, numEdits = 0;

  while (i < len1 && j < len2)
  {
    // chars dont match
    if (str1[i] != str2[j])
    {
      // more than one edit --> this one will make it 2
      if (numEdits > total) return false;

      // ensures that every index is checked
      // by incrementing the greater len strings idx
      // and then comparing that 'char' value to 
      // the 'char' of the smaller len string. 
      if (len1 > len2)
        ++i;
      else if (len1 < len2)
        ++j;
      else
        ++i, ++j;

      ++numEdits;
    }
    else
      ++i, ++j;
  }

  if (i < len1 || j < len2 )
    ++numEdits;

  return (numEdits <= tot);

}

void load_words(set<string> & word_list, const string& file_name)
{
  ifstream file(file_name);
  if (!file) error("", "", "error opening file");
  string word;
  while (file >> word) word_list.insert(word);
}

void print_word_ladder(const vector<string>& ladder){
  
  for (const auto &word : ladder)
    cout << word << " ";
  cout << endl;
}


void verify_word_ladder() 
{
  set<string> word_list;
  load_words(word_list, "src/words.txt");
  my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
  my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
  my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
  my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
  my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
  my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}

void error(string word1, string word2, string msg) {

  cerr << "[ERROR: " << msg << "] WORDS : " << word1 << " | " << word2 << endl;
}
