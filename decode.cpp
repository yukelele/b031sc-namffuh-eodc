// Yuki Mano, ysm@umail.ucsb.edu, CS130B, Fall 2017

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string decimal_to_binary(int num); // Convert decimal value to binary value

int main (int argc, char* argv[]){

  // store the encoded list to a map
  ifstream encodedFile(argv[1]);  
  map<string, string> mapOfEncodedAscii;
  string line1;
  while (getline(encodedFile, line1))
    {
      istringstream iss(line1);
      string ascii_value;
      string huffman_value;
      iss >> ascii_value;
      iss >> huffman_value;

      mapOfEncodedAscii[huffman_value] = ascii_value;  // key is huffman value & value is ascii
    }    
  
  string binary_string = "";
  int bit_count = 0;
  unsigned char c;
  unsigned char d;
  while (!cin.eof())
  {   
        c = cin.get();
        d = cin.get(); 
        if(cin.peek()!=EOF)
        { 
          cin.putback(d);
     
          binary_string += decimal_to_binary(int(c)); 
          bit_count += binary_string.length();

          int i=1;
          bool loop = true;
          while(bit_count!=0 && loop){
            if(i == bit_count) loop = false; 

            if(mapOfEncodedAscii.count(binary_string.substr(0, i)) == 1){
              int asciiVal = stoi(mapOfEncodedAscii[binary_string.substr(0,i)]); 
              char asciiChar = asciiVal;
              cout << asciiChar;

              bit_count -= i;
              binary_string = binary_string.substr(i, bit_count); 
              i = 1;          
            }

            else{
              i++;
            }
          }
        }
        else
        {
          binary_string += decimal_to_binary(int(c)).substr(0,8-int(d));
          bit_count = binary_string.length();

          int i=1;
          bool loop = true;
          while(bit_count!=0 && loop){
            if(i == bit_count) loop = false; 

            if(mapOfEncodedAscii.count(binary_string.substr(0, i)) == 1){
              int asciiVal = stoi(mapOfEncodedAscii[binary_string.substr(0,i)]); 
              char asciiChar = asciiVal;
              cout << asciiChar;

              bit_count -= i;
              binary_string = binary_string.substr(i, bit_count); 
              i = 1;          
            }

            else{
              i++;
            }
          }
        }
    }
  return 0;
}

// Convert decimal value to binary value
string decimal_to_binary(int num)
{
    string result = "";
    if(num < 0)
      num += 256;
    for(int i=0; i<8; i++){
      int bit = pow(2, 8-1-i);
      if(num >= bit){
        result += "1";
        num -= bit;
      } 
      else {
        result += "0";
      }   
    }
    return result;  
}

