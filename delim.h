#include <iostream>//I/O
#include <fstream>//File streaming
#include <string>//string class
#include "GenStack.cpp"//stack
using namespace std;

class delim{
  public:
    delim();//default constructor
    ~delim();//destructor
    GenStack<string> *stack;//string based stack
    int m_line;//counts number of lines in the file
    int LBracket;//counts [
    int RBracket;//counts ]
    int LParenth;//counts (
    int RParenth;//counts )
    int LCurl;//counts {
    int RCurl;//counts }
    bool initStack(string fname);//enters lines from file into stack
    bool parseString(string line, int lineNum);//counts brackets, curly brackets, and parentheses in each line

};
