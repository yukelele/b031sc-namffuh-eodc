// Yuki Mano, ysm@umail.ucsb.edu, CS130B, Fall 2017

#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Huffman node
struct node{                          
    unsigned freq;             
    node *left, *right;
    string data; 
 
    node(string data, unsigned freq){
        this->data = data;
        this->freq = freq;
        left = right = NULL;  
    }
};

// comparing child's frequency 
struct pickMin{                
    bool operator()(node* l, node* r){
        return (l->freq > r->freq);
    }
};

void builtHuffmanTree(vector<string> data, vector<int> freq, int size); // construct huffman tree
void displayValue(struct node* root, string str); // display char value as huffman code

int main(int argc, char* argv[]){

    vector <int> frequency;
    vector <string> data;
    string line;
    
    // read from stdin one character at a time
    while ( getline (cin, line) )
      {
        istringstream iss(line);
        int freq; 
        string value;
        iss >> value;
        iss >> freq;

        frequency.push_back(freq);       
        data.push_back(value); 
      }

    int size = data.size();
    if (size == 1){
        cout << data[0] << "    " << "0" << endl;
    } 
    else {
        builtHuffmanTree(data, frequency, data.size());
    }
    
    return 0; 
}

// construct huffman tree
void builtHuffmanTree(vector<string> data, vector<int> freq, int size){
    struct node *left, *right, *peak;
 
    priority_queue<node*, vector<node*>, pickMin> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new node(data[i], freq[i]));
 
    while (minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
 
        peak = new node("_", left->freq + right->freq);
        peak->left = left;
        peak->right = right;
        minHeap.push(peak);
    }

    displayValue(minHeap.top(), "");
}

// display char value as huffman code
void displayValue(struct node* root, string str){
    if (!root)
        return;
 
    if (root->data != "_")
        cout << root->data << "    " << str << "\n";
 
    displayValue(root->left, str + "0");
    displayValue(root->right, str + "1");
}