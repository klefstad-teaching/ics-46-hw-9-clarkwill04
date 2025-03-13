#include "ladder.h"

















// returns true if strings within one edit distance
// adapted from the Levenshtein algorithm
bool edit_distance_is_one(const std::string& str1, const std::string& str2) {
  int len1 = str1.length(), len2 = str2.length();
  int numEdits = 0;

  // if strs differ by more than 1 character
  // or are equal. 
  // they cant be within one edit
  if (abs(len1 - len2) > 1) return false;
  if (str1 == str2) return false;

  int i = 0, j = 0;

  while (i < len1 && j < len2)
  {
    // chars dont match
    if (str1[i] != str2[j])
    {
      // more than one edit --> this one will make it 2
      if (numEdits == 1) return false;

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

  return (numEdits == 1);

}


void error(string word1, string word2, string msg) {

  cerr << "[ERROR: " << msg << "] WORDS : " << word1 << " | " << word2 << endl;
}
