/*
 * Name: Kevin Mody
 * Date Submitted: 02/05/2021
 * Lab Section:004
 * Assignment Name:Lab 3 - Finding Groups Using Recursion
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Represents an occupied square in the grid
//Do not modify the GridSquare class or its member functions
class GridSquare
{
    private:
        int row, col;
    public:
        GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square
        GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square
        //Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const
        {
            if ((row == r.row) && (col == r.col))
            {
                return true;
            }
            return false;
        }
        int getRow() { return row; } //return row value
        int getCol() { return col; } //return column value
        //Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

/*
Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be changed based
on how the function is implemented
*/
class Grouping
{
    private:
        int grid[10][10];
        vector<vector<GridSquare>> groups;
    public:
        Grouping() : grid{},groups() {} //Default constructor, no groups
        Grouping(string fileName); //Implement this function
        void findGroup(int r, int c); //Implement this function (recursive)
        void printGroups() //Displays grid's groups of squares
        {
            for(int g=0; g<groups.size(); g++)
            {
                cout << "Group " << g+1 << ": ";
                for(int s=0; s<groups[g].size(); s++)
                {
                    cout << " " << groups[g][s];
                }
                cout << endl;
            }
        }
        vector<vector<GridSquare>> getGroups() //Needed in unit tests
        {
            return groups;
        }
};

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string fileName) {
    string fileInput;
    ifstream input(fileName);
    vector<GridSquare> vecStorage;
    
    for ( int i = 0; i < 10; i++) {
        getline(input, fileInput);
        for(int j = 0; j < 10; j++) {
            if (fileInput[j] == 'X') {
                grid[i][j] = 1;
            } else if(fileInput[j] == '.') {
                grid[i][j] = 0;
            }
        }
    }
    for( int x = 0; x < 10; x++) {
        for(int y = 0; y < 10; y++) {
            if(grid[x][y] == 1) {
                groups.push_back(vecStorage);
                findGroup(x,y);
            }
        }
    }
}
void Grouping::findGroup(int r, int c){
    if(grid[r][c] == 0) {
        return;
    }
    grid[r][c] = 0;
    int upBound = 10;
    int lowBound = 0;
    groups.back().push_back(GridSquare(r,c));
    if( (r + 1) < upBound) {
        findGroup(r + 1, c);
    }
    if( (r - 1) >= lowBound) {
        findGroup(r-1, c);
    }
    if( (c + 1) < upBound) {
        findGroup(r, c + 1);
    }
    if( (c - 1) >= lowBound) {
        findGroup(r, c - 1);  
    }
}





//Simple main function to test Grouping
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}
