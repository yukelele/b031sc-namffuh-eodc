// Yuki Mano, ysm@umail.ucsb.edu, CS130B, Fall 2017

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

// Huffman tree node
struct MinHeapNode{          
    string data;                // One of the input characters
    unsigned freq;             // Frequency of the character
    MinHeapNode *left, *right; // Left and right child
 
    MinHeapNode(string data, unsigned freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

 // For comparison of two heap nodes (needed in min heap) 
struct compare{                
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode* root, string str); // Prints huffman codes from the root of Huffman Tree.
void HuffmanCodes(vector<string> data, vector<int> freq, int size); // Construct a Huffman Tree and print codes by traversing the built Huffman Tree

int main(int argc, char* argv[]){

    vector <string> data;
    vector <int> frequency;

    string line;
    while ( getline (cin, line) )
      {
        istringstream iss(line);
        string value;
        int freq; 
        iss >> value;
        iss >> freq;

        data.push_back(value);
        frequency.push_back(freq);        
      }

    int size = data.size();
    if (size == 1) cout << data[0] << "    " << "0" << endl;
    else HuffmanCodes(data, frequency, size);

    return 0; 
}


// Prints huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str){
    if (!root)
        return;
 
    if (root->data != "$")
        cout << root->data << "    " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
 
// Construct a Huffman Tree and print codes by traversing the built Huffman Tree
void HuffmanCodes(vector<string> data, vector<int> freq, int size){
    struct MinHeapNode *left, *right, *top;
 
    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
 
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1){
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
 
        // Create a new internal node with frequency equal to the sum of the two nodes frequencies. 
        // Make the two extracted node as left and right children of this new node. 
        // Add this node to the min heap
        // '$' is a special value for internal nodes, not used
        top = new MinHeapNode("$", left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
 
    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");
}