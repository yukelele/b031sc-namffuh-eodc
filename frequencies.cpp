#include <iostream>

using namespace std; 

int main() {

  string line;
  ifstream myfile ("test1.in");
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  cout << line << '\n';
	}
      myfile.close();
    }

  else cout << "Unable to open file"; 

  return 0; 
}
