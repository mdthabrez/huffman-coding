#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

map<char,vector<int>> codes;

#define MAX_TREE_HT 256

struct MinHeapNode {

	// One of the input characters
	char data;
	// Frequency of the character
	unsigned freq;
	// Left and right child of this node
	struct MinHeapNode *left, *right;
};

// A Min Heap: Collection of min-heap (or Huffman tree) nodes
struct MinHeap {

    
    // Current size of min heap
    unsigned size;

    // capacity of min heap
    unsigned capacity;

    // Array of minheap node pointers
    struct MinHeapNode** array;

	
};