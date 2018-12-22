#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stdint.h>
using namespace std;


int main() {
    int t;
    cout<<" CAN GIVE AY TYPE OF INPUT\n";
    cout<<"GIVE THE NUMBER OF INPUTS YOU WANT TO GIVE FOR ENCRYPTION\n";
    cin>>t;
    while(t--){
        //INITALIZATION OF VARIABLES
        string key,chip,m,ky="";
        cout<<"GIVE A RANDOM CHIPER WITH ANY CHARACTERS\n";
        cin>>key>>m;
        cout<<"GIVE YOUR STATEMENT TO BE CHIPED\n";
        getline(cin,chip);
        chip=m+chip;
        for(int i=0;i<key.length()-1;i++){
            for(int j=i+1;j<key.length();j++){
                if(key[i]==key[j]&&key[i]!='@'){
                 key[j]='@';
                }
            }
        }
        for(int i=0;i<key.length();i++){
            if(key[i]!='@')
            ky=ky+key[i];
        }
        key=ky;
        //cout<<key;
        //cout<<key<<"\n"<<chip<<"\n";
        int x;
        if(95%key.length()==0){
            x=95/key.length();
        }
        else
        x=(95/key.length())+1;
        char arr[x][key.length()];
        int hash[96]={0};

        //INTIALIZATION OF ALL VALUES
        for(int i=0;i<x;i++){
            for(int j=0;j<key.length();j++){
                arr[i][j]=0;
            }
        }

        //STORING INTIAL KEYWORDS
        for(int i=0;i<key.length();i++){
            arr[0][i]=key[i];
            hash[key[i]-32]=1;
        }

        int count=1,coun=0;
        //STORING REST KEYWORDS
        for(int i=0;i<96;i++){
            if(hash[i]==0){
                if(i+32<126){
                arr[count][coun]=static_cast<char>(i+32);
                coun++;
                if(coun==key.length())
                {
                    coun=0;
                    count++;
                }
                }
            }
        }

        //MATRIX SORTING ACCORDING TO THE KEY
        for(int i=0;i<key.length();i++){
            for(int j=0;j<key.length();j++){
                if(arr[0][i]<arr[0][j]){
                    char temp;
                    for(int k=0;k<x;k++){
                        temp=arr[k][i];
                        arr[k][i]=arr[k][j];
                        arr[k][j]=temp;
                    }
                }
            }
        }

        //MATRIX TRANSPOSITION
        char arr2[key.length()][x];
        for(int i=0;i<x;i++){
            for(int j=0;j<key.length();j++){
                arr2[j][i]=arr[i][j];
            }

        }
        //ORDERING THE ALPHABETS
        char cho[96];
        int co=0;
        for(int i=0;i<key.length();i++){
            for(int j=0;j<x;j++){
                if(arr2[i][j]!=0){
                cho[co]=arr2[i][j];
                //cout<<cho[co];
                co++;
                }
            }
        }

        //THIS IS THE ENCRYPTION PART:-
        //TRANSFORMING THE REAL TEXT TO MEANINGLESS CHEAPER
        for(int i=0;i<chip.length();i++){
            if(chip[i]!=0)
            chip[i]=cho[chip[i]-32];
        }
        //RESULT AFTER ENCRYPTING
        cout<<"-----------------------\n";
        cout<<"Encrypted to "<<chip<<"\n";
        cout<<"-----------------------\n";


        //THIS IS DECRYPTION PART:-
        for(int i=0;i<chip.length();i++){
            for(int j=0;j<96;j++){
                if(chip[i]==cho[j]&&chip[i]!=0){
                    chip[i]=static_cast<char>(j+32);
                    break;
                }
            }
        }
        cout<<"-------------------------\n";
        cout<<"Decrypted to "<<chip<<"\n";
        cout<<"--------------------------\n";

        //OUTPUT DISPLAY DEBUGING
        /*for(int i=0;i<key.length();i++){
            for(int j=0;j<x;j++){
                cout<<arr2[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        /*for(int i=0;i<x;i++){
            for(int j=0;j<key.length();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        //


    }
    cout<<"ANALYSIS:-\n";
    cout<<"NO. OF CHIPERS CAN BE FORMED WITH CAPITAL ALPHABETS ARE \n IT IS ADVICED TO FORM CHIPERS OF LENGTH 4 TO 23(AS 1 TO ANY LENGTH CHIPER CAN BE FORMED) FOR GOOD SECURITY\nLET CONSIDER 4 TO 23 LENGTH CHIPERS, THE TOTAL CHIPER CAN BE CONSIDERED IS(TAKING ALL ALPHABET DISTINCT)\n";

uintmax_t con=95*94*93*92,tz=91;
uintmax_t cal[20];
for(int i=0;i<21;i++){
    cal[i]=con;
    con=con*tz;
    tz--;
}
uintmax_t cont=4;
uintmax_t total=0;
for(int i=0;i<21;i++){
cout<<"FOR "<< cont <<" ALPHABETS "<<cal[i]<<"\n";
total=total+cal[i];cont++;
}
cout<<"\nTOTAL IS :-"<<total;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

