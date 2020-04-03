#include "delim.h"

delim::delim(){
  stack = new GenStack<string>();
  //initiate ints to 0
  m_line = 0;
  LBracket = 0;
  RBracket = 0;
  LParenth = 0;
  RParenth = 0;
  LCurl = 0;
  RCurl = 0;
}

delim::~delim(){
  //stack is dynamically allocated so it's being deleted
  delete stack;
}

bool delim::initStack(string fname){
  ifstream inFS;
  string line;
  inFS.open(fname);
  if(inFS.fail()){//ensures valid file name is inputted
    cout << "INVALID FILE NAME" << endl;
    return false;
  }
  while(!inFS.eof() && !inFS.fail()){//checks to ensure file doesn't crash
    m_line++;
    getline(inFS, line); // read line
    stack->push(line); // push line onto stack
  }
  inFS.close();
  return true;
}
bool delim::parseString(string line, int lineNum){
  char curr = '\0';
  for(int i = 0; i < line.length(); ++i){//reads each char in string and identifies it
    curr = line[i];
    if(curr == ']'){
      RBracket++;
    }
    else if(curr == ')'){
      RParenth++;
    }
    else if(curr == '}'){
      RCurl++;
    }
    else if(curr == '['){
      LBracket++;
    }
    else if(curr == '('){
      LParenth++;
    }
    else if(curr == '{'){
      LCurl++;
    }
  }
  if(RBracket != LBracket || RParenth != LParenth){//checks to make sure delimiters are even(besides "{}")
    cout << "Line " << lineNum << ": " << "expected: ";//error messages
    if(RBracket > LBracket)
      cout << "\"[\"";
    else if(RBracket < LBracket)
      cout << "\"]\"";
    else if(RParenth > LParenth)
      cout << "\"(\"";
    else if(RParenth < LParenth)
      cout << "\")\"";
  return false;
}
return true;
}
