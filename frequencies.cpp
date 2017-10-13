#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std; 

int arrayOfAscii[10000];
//vector <int> listOfAscii;
map<int,int> mapOfAscii;

int charToAscii(char character);

int main() {
  
  string line;
  ifstream myfile ("test_files/test2.in");
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  cout << line << '\n';
	  cout << line.length() << endl;
	  cout << line[0] << endl;

	  
	  for(int i=0; i<line.length(); i++){
	    //arrayOfAscii[charToAscii[line(i)]]++;
	    mapOfAscii[charToAscii(line[i])]++;
	  }	 	

	}
      myfile.close();
    }

  else cout << "Unable to open file"; 

  for (map<int,int>::iterator it=mapOfAscii.begin(); it!=mapOfAscii.end(); ++it)
    cout << it->first << " => " << it->second << '\n';

  
  return 0; 
}

int charToAscii(char character){
  return static_cast<int>(character);
}
