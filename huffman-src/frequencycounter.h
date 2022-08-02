#include"MinHeapManipulation.h"
void string_convertor(char* str, map<char,int>& frequency){

	for(int i=0;i<strlen(str);i++){
        if(frequency.empty()==true){
        frequency[str[i]]=1;
        }
        else{
        auto j=frequency.find(str[i]);
        if(j==frequency.end())
        frequency[str[i]]=1;
        else
        (*j).second++;
        }
    }

}

void freq_calculator(char chr[],int freq[],map<char,int> frequency,int& c){

	for(auto i=frequency.begin();i!=frequency.end();++i){
        chr[c]=(*i).first;
        freq[c++]=(*i).second;
    }

}