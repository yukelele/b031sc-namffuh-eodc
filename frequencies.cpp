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

  for (map<int,int>::iterator it=mapOfAscii.begin(); it!=mapOfAscii.end(); ++it)
    cout << it->first << "    " << it->second << '\n';

  return 0; 
}

int charToAscii(char character){
  int ascii = static_cast<int>(character);
  if(ascii < 0) return (256 + ascii);
  else return ascii;
}
