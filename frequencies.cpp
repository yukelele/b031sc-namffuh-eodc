#include <iostream>
#include <map>
 
using namespace std; 

int charToAscii(char character);

int main(int argc, char* argv[]) {
  
  map<int,int> mapOfAscii;
  string line;
  int numberOfLine = 0;
  while ( getline (cin,line) )
    { 
      numberOfLine++;
      for(int i=0; i<line.length(); i++){
	      mapOfAscii[charToAscii(line[i])]++;
      }	 	
    }
  if(numberOfLine > 1) mapOfAscii[10] = numberOfLine; //frequency for Ascii '\n'

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

