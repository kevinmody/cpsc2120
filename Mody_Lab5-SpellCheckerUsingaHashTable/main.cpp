/*
 * Name: Kevin Mody
 * Date Submitted: 3/1/2021
 * Lab Section: 004
 * Assignment Name: Lab 5 - Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 void loadStringset(Stringset& words, string filename)
 {
     //Implement this function
    std::ifstream infile(filename);
    std::string currentWord;
    while(std::getline(infile, currentWord)) {
        words.insert(currentWord);
    }
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
     //Implementing this function
     vector<string> diffList; //return vector of possible alternatives
     string newWord = word; //variable to test alternate char on
     for (int i = 0; i < word.length(); i++) { //loop through all characters in word
         for (char j = 'a'; j < 'z' + 1; j++) { //loop through alphabet
             newWord.replace(i, 1, 1, j); //copy of the word with a character replaced at postition i
             if (newWord != word && words.find(newWord)) //if the moddified word is in the string set and isn't the original
                diffList.push_back(newWord);
             newWord = word; //reset the word
         }
     }
     return diffList;
 }