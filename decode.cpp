// Yuki Mano, ysm@umail.ucsb.edu, CS130B, Fall 2017

#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

const char* hex_char_to_bin(char c);

int main (int argc, char* argv[]){

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
  
  int line = 0;
  while (!cin.eof())
    {
      
      char c = cin.get();
      //char d = cin.get();
      if(!cin.eof()){
        cout << "line " << line++ << " : " ;
      
       
        cout << hex_char_to_bin(c) << endl;
      }
    }


    //bitset<8> set("11110000");
    //cout << hex << set.to_ulong() << endl;
    //string heximal = hex << set.to_ulong() << endl;
    //cout << "binary is " << bitset<sizeof(char) * CHAR_BIT> binary('a') << endl;
    //cout << hex_char_to_bin('0') << endl;

    /*
    cout << "this is testing" << endl;
 
    string s = "11110000";
    char str = s[1];
    char d = '\x00';
    
    cout << d << " = " << ord('\x00') << endl;
    d = d | str;
    cout << d << " = " << ord('\x01') << endl;
    d = d << 1;
    cout << d << " = " << '\x10' << endl;
    d = d | str; 
    cout << d << " = " << '\x11' << endl;
    
    cout << "convert char to bin" << endl;
    */
    //d = d >> 2; 
    //cout << d << endl;



    //cout << "converting char to binary" << endl;
    //cout << (d & 1) << endl;
    //cout << ((d >> 1) )<< endl;
    //cout << char(str) << endl;

  return 0;
}


const char* hex_char_to_bin(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}