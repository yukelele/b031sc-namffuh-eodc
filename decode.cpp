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
  
    int line = 0;

  string binary_string = "";
  int bit_count = 0;
  char c;
  char d;
  while (!cin.eof())
    {   
        c = cin.get();
        d = cin.get(); 
        char e = cin.peek();
        

        //cout << decimal_to_binary(int(c)) << endl;
        //cout << decimal_to_binary(int(e)) << endl;
        //cout << int('\xff') << endl;
/*
        char e2 = cin.get();
        char e3 = cin.get();
        char e4 = cin.get();
        char e5 = cin.get();
        char e6 = cin.get();
        char e7 = cin.get();
*/
//cout <<"peeking value is " << e << endl;
        
        if(e!=EOF){ //&& (e2!=EOF) && (e3!=EOF) && (e4!=EOF) && (e5!=EOF) && (e6!=EOF) && (e7!=EOF)){
        
        cin.putback(d);
        /*
        cin.putback(e2);
        cin.putback(e3);
         cin.putback(e4);
         cin.putback(e5);
            cin.putback(e6);
             cin.putback(e7);
       */

        binary_string += decimal_to_binary(int(c)); 
        bit_count += binary_string.length();

        int i=1;
        bool loop = true;
        while(loop){
          if(i == bit_count) loop = false; 

          if(mapOfEncodedAscii.count(binary_string.substr(0, i)) == 1){
            int asciiVal = stoi(mapOfEncodedAscii[binary_string.substr(0,i)]); 
            char asciiChar = asciiVal;

            line++;
//cout << line << ". the character is : " << asciiChar << endl; //MODIFY THIS LINE
            cout << asciiChar;

            //cout << endl; // DELETE LINE

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
          break;
    }
   
 
    binary_string += decimal_to_binary(int(c)).substr(0,8-int(d));

    bit_count = binary_string.length();
    int i=1;
    bool loop = true;
    while(loop){
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

    //cout << endl; // delete line e

    //cout << decimal_to_binary(int(cin.get())) << endl;

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

