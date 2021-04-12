/*
 * Name: Kevin Mody
 * Date Submitted: 04/12/2021
 * Lab Section: 004 
 * Assignment Name: Lab 10 - Using Breadth-First Search to Solve Puzzles
 */
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;
  
  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}

void build_graph(void)
{
  //Implement this function
  state current_state = make_pair(0,0);
   int a = 3, b = 4;
   state end = make_pair(a,b);
  
   while(current_state != end)   {
       state next;

       next = make_pair(a,current_state.second);

       if(next != current_state)   {
           pair<state,state> edge = make_pair(current_state,next);
           nbrs[current_state].push_back(next);
           edge_label[edge] = actions[0];
       }

       next = make_pair(current_state.first,b);

       if(next != current_state)   {
           pair<state,state> edge = make_pair(current_state,next);
           nbrs[current_state].push_back(next);
           edge_label[edge] = actions[1];
       }

       // Action 3: Empty A
       next = make_pair(0,current_state.second);

       if(next != current_state)   {
           pair<state,state> edge = make_pair(current_state,next);
           nbrs[current_state].push_back(next);
           edge_label[edge] = actions[2];
       }

       // Action 4: Empty B
       next = make_pair(current_state.first,0);

       if(next != current_state)   {
           pair<state,state> edge = make_pair(current_state,next);
           nbrs[current_state].push_back(next);
           edge_label[edge] = actions[3];
       }

       // Action 5: Pour A into B
       int difA = current_state.first;
       int difB = current_state.second;
       if(current_state.second < b)   {
           while(difA > 0 && difB < b)   {
               difB++;
               difA--;
           }
           next = make_pair(difA,difB);

           if(next != current_state)   {
               pair<state,state> edge = make_pair(current_state,next);
               nbrs[current_state].push_back(next);
               edge_label[edge] = actions[4];
           }
       }
      
       // Action 6: Pour B into A
       difA = current_state.first;
       difB = current_state.second;
       if(current_state.first < a)   {
           while(difA < a && difB > 0)   {
               difA++;
               difB--;
           }
           next = make_pair(difA,difB);

           if(next != current_state)   {
               pair<state,state> edge = make_pair(current_state,next);
               nbrs[current_state].push_back(next);
               edge_label[edge] = actions[5];
           }
       }

       if(current_state.second == b)
           current_state = make_pair(current_state.first + 1,0);
       else
           current_state = make_pair(current_state.first, current_state.second + 1);
   }
}

int main(void)
{
  build_graph();

  state start = make_pair(0,0);
  
  for (int i=0; i<5; i++)
    nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1));
  search (start);
  if (visited[make_pair(-1,-1)]) 
    print_path (start, pred[make_pair(-1,-1)]);
  else
    cout << "No path!\n";
  
  return 0;
}
