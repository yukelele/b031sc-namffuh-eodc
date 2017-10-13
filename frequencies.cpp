#include <iostream>
#include <fstream>
#include <map>
 
using namespace std; 

map<int,int> mapOfAscii;

int charToAscii(char character);

int main() {
  
  string line;
  ifstream myfile ("test_files/test2.in");
  if (myfile.is_open())
    {
      int numberOfLine = 0;
      while ( getline (myfile,line) )
	{ 
	  numberOfLine++;
	  for(int i=0; i<line.length(); i++){
	    mapOfAscii[charToAscii(line[i])]++;
	  }	 	
	}
      if(numberOfLine > 1) mapOfAscii[10] = numberOfLine; //frequency for Ascii '\n'
      myfile.close();
    }

  else cout << "Unable to open file"; 

  for (map<int,int>::iterator it=mapOfAscii.begin(); it!=mapOfAscii.end(); ++it)
    cout << it->first << "    " << it->second << '\n';

  return 0; 
}

int charToAscii(char character){
  int ascii = static_cast<int>(character);
  if(ascii < 0) return (256 + ascii);
  else return ascii;
}
