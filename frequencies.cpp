#include <iostream>
#include <map>
 
using namespace std; 

int charToAscii(char character); // Converting a character to its corresponding ASCII value

int main(int argc, char* argv[]) {
  
  map<int,int> mapOfAscii;

  // read from stdin one character at a time
  while (!cin.eof()){ 
      char c = cin.get();
      if(!cin.eof())
        mapOfAscii[charToAscii(c)]++;
    }

  // print out all ASCII values with their corresponding frequency
  for (map<int,int>::iterator it=mapOfAscii.begin(); it!=mapOfAscii.end(); ++it)
    cout << it->first << "    " << it->second << '\n';

  return 0; 
}

// Converting a character to its corresponding ASCII value
int charToAscii(char character){
  int ascii = static_cast<int>(character);
  if(ascii < 0) return (256 + ascii);
  else return ascii;
}

