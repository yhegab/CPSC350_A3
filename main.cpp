#include "delim.cpp"
using namespace std;

int main(int argc, char **argv){
  bool compile = true;
  delim *d = new delim();
  GenStack<string> *mainStack = d->stack;
  cout << argv[2] << endl;
  if(d->initStack(argv[2]) == false){//checks to make sure the file name is valid
    return -1;
  }
  for(int i = d->m_line; i > 0; --i){//parses stack to assess delimiters
    if(!d->parseString(mainStack->pop(), i)){
      compile = false;
      break;
    }
  }
  if(!compile){
    cout << endl << "End program" << endl;
  }
  else if(d->RCurl != d->LCurl){//assess curly brackets
    cout << "Error, expected ";
    if(d->RCurl > d->LCurl)
      cout << "left curly bracket, \"{\"" << endl;
    if(d->RCurl < d->LCurl)
      cout << "right curly bracket, \"}\"" << endl;
  }
  else{
    cout << "Your code works!!" << endl;
  }
}
