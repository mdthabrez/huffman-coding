#include "frequencycounter.h"
// function iterates through the encoded string s
// if s[i]=='1' then move to node->right
// if s[i]=='0' then move to node->left
// if leaf node append the node->data to our output string

string decode_file(struct MinHeapNode* root, string s)
{
    string ans = "";
    struct MinHeapNode* curr = root;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == '0')
           curr = curr->left;
        else
           curr = curr->right;
  
        // reached leaf node
        if (curr->left==NULL and curr->right==NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    // cout<<ans<<endl;
    return ans+'\0';
}


// The main function that builds a Huffman Tree and print codes by traversing the built Huffman Tree
MinHeapNode* HuffmanCodes(char data[], int freq[], int size)

{
	// Construct Huffman Tree
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
	// Print Huffman codes using the Huffman tree built above
	int arr[MAX_TREE_HT], top = 0;

	printCodes(root, arr, top);

	return root;
}

//a function to read the given file
void read_file(string filename,char str[])
{
    //filename=filename+".txt";
    string s;
    fstream fp;
    fp.open(filename);
    getline(fp,s);
    strcpy(str,s.c_str());
	while (getline(fp,s))
	{
		strcat(str,s.c_str());
	}
    fp.close();
}

string read_string(char str[])
{
    string s;
    for(int i=0;i!=strlen(str);i++){
        for(int j:codes[str[i]]){
            s.push_back(j+'0');
        }
    }
    return s;
}

string read_file_enc(string filename)
{
    fstream fp;
    fp.open(filename);
	string s,ans;
	while (getline(fp,s))
	{
        ans=ans+s;
	}
    return ans;

}
// a function to write the encoded message into a file 
void write_file(string filename,char str[])
{
    //string s_enc=s+"ENC.txt";
    fstream fp_enc;
    fp_enc.open(filename , ofstream::out | ofstream::trunc);
    for(int i=0;i<strlen(str);i++){
		for(auto j=codes[str[i]].begin();j!=codes[str[i]].end();++j){
			fp_enc << (*j) ;//Writing encoded message into the file
	}
	}
	
	fp_enc.close();
}
// function that displays :
// frequency table
// codes for each character
// encoded message
void display(map<char,int> frequency,char str[]){
    cout<<"Frequency table:"<<endl;
    for(auto i=frequency.begin();i!=frequency.end();++i){
        cout<<(*i).first<<" = "<<(*i).second<<endl;
    }

    cout<<"\nCodes for individual characters:"<<endl;
    for(auto i=codes.begin();i!=codes.end();++i){
        cout<<(*i).first<<" : ";
        for(auto j=(*i).second.begin();j!=(*i).second.end();++j){
            cout<<(*j);
        }
        cout<<endl;
    }
    
    cout<<"Encoded form:\n";
    for(int i=0;i!=strlen(str);i++){
        for(auto j=codes[str[i]].begin();j!=codes[str[i]].end();++j){
            cout<<(*j);
        }
    }
}

