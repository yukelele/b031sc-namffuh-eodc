// Yuki Mano, ysm@umail.ucsb.edu, CS130B, Fall 2017

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

int charToAscii(char character); // Converting a character to its corresponding ASCII value
string charToEncode(char c, map<string,string> encodedList); // Converting a character to its corresponding Encoded value

int main( int argc, char* argv[]){

  // store the encoded list to a map
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

  // read from stdin one character at a time
  int bit_count = 0;
  string bit_string = "";
  while (!cin.eof()) 
    {       
      char c = cin.get();
      if(!cin.eof()){
        string encode = charToEncode(c, mapOfEncodedAscii);
        
        bit_string += encode;
        bit_count += encode.length();    

        while(bit_count >= 8){
          string byte_string = bit_string.substr(0,8);
    
          bit_count -= 8;
          bit_string = bit_string.substr(8, bit_count); 

          bitset<8> set(byte_string);
          cout << hex << set.to_ulong();
        }
      }
    }
    for (int i=0; i<bit_count; i++){
      bit_string += "0";
    }
    bitset<8> set(bit_string);
    cout << hex << set.to_ulong() << endl;

    /////////////////////////////////////////// HOW TO KNOW HOW MANY PATTING BITS

  return 0;
}

// Converting a character to its corresponding ASCII value
int charToAscii(char character){
  int ascii = static_cast<int>(character);
  if(ascii < 0) return (256 + ascii);
  else return ascii;
}

// Converting a character to its corresponding Encoded value
string charToEncode(char c, map<string,string> encodedList){
  int value = charToAscii(c);
  string ascii = to_string(value);
  return encodedList[ascii];
}



