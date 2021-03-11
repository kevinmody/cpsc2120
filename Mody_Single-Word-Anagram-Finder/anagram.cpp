/*
 * Name: Kevin Mody
 * Date Submitted: 03/08/2021
 * Assignment Name: Single-Word Anagram Finder

 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    //making a map with the key being the words with thier chars sorted
    unordered_map<string, vector<string>> dict;
    vector<string> anagramList; //output vect
    string s, sorted_s;
    for(int i = 0; i < wordlist.size(); i++) // reading a word, sorting the chars then use it as a key to the map. 
    {
        sorted_s = wordlist[i];//store the original word as the value
		sort(sorted_s.begin(), sorted_s.end());
		dict[sorted_s].push_back(wordlist[i]);
    }
    //sort the word we are trying to find anagrams for
    sort(word.begin(), word.end());
	auto it = dict.find(word);	// find the sorted string in the map
	anagramList = (*it).second;	// grabing the vector 
	return anagramList; //returning the vector
}