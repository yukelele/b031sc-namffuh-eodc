#include <iostream>
#include <fstream>

using namespace std; 

int main() {
  
  string line;
  ifstream myfile ("test_files/test1.in");
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  cout << line << '\n';
	  cout << line.length() << endl;
	  cout << line[0] << endl;
	}
      myfile.close();
    }

  else cout << "Unable to open file"; 
  
  return 0; 
}
