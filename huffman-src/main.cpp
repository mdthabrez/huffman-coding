#include "Huffman.h"
int main(){
    int ch,flag=0;
    char cont = 'y';
    map<char,int> frequency;

    cout<<"************* HUFFMAN ENCODING IN C++ ************"<<endl;;
    cout<< "---BY : \n\tGAUTHAM ,\n\tMANISH KUMAR S and\n\tMOHAMMED THABREZ G \n--- ";
    cout<<endl<<endl;
    cout<<"Huffman coding is a lossless data compression algorithm."<<endl<<"The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters."<<endl<<"The most frequent character gets the smallest code and the least frequent character gets the largest code."<<endl;

    cout<<endl;

    while(cont == 'y')
    {

    int c=0;
    string filename;
    char str[1000];
    char chr[100];
    int freq[50];
    MinHeapNode*huff;
	string decoded_answer,s_enc;
    int ch2;

    cout<<"\n1.INSERT\n2.DISPLAY\n3.DECODE\n4.EXIT\n";
    cin>>ch;
    switch(ch){

        case 1:
            cout<<"Would you like to "<<endl<<"1. Enter the string to be decoded"<<endl<<"2. Upload a file?.."<<endl;

            cin>>ch2;

            switch(ch2){
                    case 1:
                        if(!frequency.empty()){
                            frequency.clear();
                        }
                        codes.clear();
                        cin>>str;
                        string_convertor(str,frequency);
                        freq_calculator(chr,freq,frequency,c);
                        huff = HuffmanCodes(chr,freq,c);

                        flag++;
                        cout<<"\nENCODED"<<endl;
                        break;
                    case 2:
                        if(!frequency.empty()){
                            frequency.clear();
                        }
                        codes.clear();
                        read_file("filename.txt",str);
                        string_convertor(str,frequency);
                        freq_calculator(chr,freq,frequency,c);
                        huff = HuffmanCodes(chr,freq,c);
                        write_file("filenameENC.txt",str);
                        flag++;
                        break;
                }
            break;

        case 2:
            if(flag>0)
            {
                display(frequency,str);
            }
            break;

        case 3:
            cout<<"DECODING:"<<endl;
            if(ch2==1)
            {
                s_enc=read_string(str);
                decoded_answer = decode_file(huff,s_enc);
                cout<<"Decoded Form:"<<decoded_answer<<endl;

            }
            else if(ch2==2)
            {
            s_enc = read_file_enc("filenameENC.txt");
	        decoded_answer = decode_file(huff,s_enc);
	        cout<<"Decoded Form:"<<decoded_answer<<endl;

            }
            break;

        case 4:
            cout<<"EXITING..."<<endl<<endl;
            cout<<"Thank Yous from Gautham , Manish and Thabrez..";
            cont='n';
            break;
        default:
            break;



    }


    }
    //getch();
    //cin>>cont;
  return 0;

}
