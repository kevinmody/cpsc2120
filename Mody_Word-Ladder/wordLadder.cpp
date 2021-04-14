/*
 * Name: Kevin Mody
 * Date Submitted: 04/14/21
 * Lab Section: Word Ladder
 * Assignment Name: Kevin Mody
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type
unordered_map<string, bool> visited;
unordered_map<string, string> pred;
unordered_map<string, int> dist;
unordered_map<string, vector<string>> nbrs;

int path_finder(string, string, vector<string>&);
void build_graph();

//Implement breadth-first search, refer to Lab 10

void wordLadder(string s, string t, int &steps, vector<string> &p)
{
   build_graph();
   //Implement this function
   queue<string> to_visit;
   to_visit.push(s);
   visited[s] = true;
   dist[s] = 0;

   while (!to_visit.empty()) {
   string curnode = to_visit.front();
   to_visit.pop();
   for (string n : nbrs[curnode])
       if (!visited[n]) {
           pred[n] = curnode;
           dist[n] = 1 + dist[curnode];
           visited[n] = true;
           to_visit.push(n);
       }
   }

   steps = path_finder(s, t, p);
}

int path_finder(string start, string end,vector<string> &path)   {

   // Catch seg fault by ensuring that end node has a predecessor
   if(pred.find(end) == pred.end())
       return 0;
   if(start.compare(end) != 0)   {
       int step = 1 + path_finder(start, pred[end],path);
       path.push_back(end);
       return step;
   }
   else   {
       path.push_back(end);
       return 0;
   }
  
}
void build_graph(void)   {
   ifstream word_file ("wordlist05.txt");
   string current_word;

   while( word_file >> current_word )
       V.push_back( current_word );

   for(auto word : V)   {
       for(int place = 0; place < word.length(); place++)   {
           for(char letter = 'a'; letter <= 'z'; letter++)   {
               if(letter == word.at(place))
                   continue;

               string current = word;
               current.at(place) = letter;
               nbrs[word].push_back(current);

           }
       }
   }

}



int main(void)
{
  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0)
  {
      cout << "No path!\n";
  }
  else
  {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << endl;
      }
  }
  return 0;
}
