#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int charToAscii(char character);
string charToEncode(char c, map<string,string> encodedList);

int main( int argc, char* argv[]){

  cout << "this is a program for encoding Huffman" << endl;

  ifstream encodedFile(argv[1]);  
  map<string, string> mapOfEncodedAscii;
  string line1;
  while (getline(encodedFile, line1))
    {
      istringstream iss(line1);
      string ascii_value;
      string encode_value;
      iss >> ascii_value;
      iss >> encode_value;

      mapOfEncodedAscii[ascii_value] = encode_value;  
    }  



  bool moreThanOneLine = false;
  if(mapOfEncodedAscii.count("10") > 0) moreThanOneLine = true;
  string line2;
  while (getline (cin, line2))
    {       
      for(int i=0; i<line2.length(); i++){
        cout << line2[i] << " ==> " << charToEncode(line2[i], mapOfEncodedAscii) << endl;
      }
      if(moreThanOneLine == true) cout << mapOfEncodedAscii["10"] << endl;
    }
  return 0;
}

int charToAscii(char character){
  int ascii = static_cast<int>(character);
  if(ascii < 0) return (256 + ascii);
  else return ascii;
}

string charToEncode(char c, map<string,string> encodedList){
  int value = charToAscii(c);
  string ascii = to_string(value);
  return encodedList[ascii];
}



