#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cout<<"GIVE ALL THE INPUT IN CAPITAL LETTERS\n";
    cout<<"GIVE THE NUMBER OF INPUT YOU WANT TO GIVE FOR ENCRYPTION\n";
    cin>>t;
    while(t--){
        //INITALIZATION OF VARIABLES
        string key,chip,m;
        cout<<"GIVE A RANDOM CHIPER WITH DISTINCT LETTER\n";
        cin>>key>>m;
        cout<<"GIVE YOUR STATEMENT TO BE CHIPED\n";
        getline(cin,chip);
        chip=m+chip;
        //cout<<key<<"\n"<<chip<<"\n";
        int x;
        if(26%key.length()==0){
            x=26/key.length();
        }
        else
        x=(26/key.length())+1;
        char arr[x][key.length()];
        int hash[27]={0};

        //INTIALIZATION OF ALL VALUES
        for(int i=0;i<x;i++){
            for(int j=0;j<key.length();j++){
                arr[i][j]=static_cast<char>(32);
            }
        }

        //STORING INTIAL KEYWORDS
        for(int i=0;i<key.length();i++){
            arr[0][i]=key[i];
            hash[key[i]-65]=1;
        }

        int count=1,coun=0;
        //STORING REST KEYWORDS
        for(int i=0;i<27;i++){
            if(hash[i]==0){
                if(i+65<91){
                arr[count][coun]=static_cast<char>(i+65);
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
        char cho[27];
        int co=0;
        for(int i=0;i<key.length();i++){
            for(int j=0;j<x;j++){
                if(arr2[i][j]!=32){
                cho[co]=arr2[i][j];
                //cout<<cho[co];
                co++;
                }
            }
        }

        //THIS IS THE ENCRYPTION PART:-
        //TRANSFORMING THE REAL TEXT TO MEANINGLESS CHEAPER
        for(int i=0;i<chip.length();i++){
            if(chip[i]!=32)
            chip[i]=cho[chip[i]-65];
        }
        //RESULT AFTER ENCRYPTING
        cout<<"-------------------------\n";
        cout<<"Encrypted to "<<chip<<"\n";


        //THIS IS DECRYPTION PART:-
        for(int i=0;i<chip.length();i++){
            for(int j=0;j<27;j++){
                if(chip[i]==cho[j]&&chip[i]!=32){
                    chip[i]=static_cast<char>(j+65);
                    break;
                }
            }
        }
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
    //ANALYSIS
    cout<<"ANALYSIS:-\n";
    cout<<"NO. OF CHIPERS CAN BE FORMED WITH CAPITAL ALPHABETS ARE \n IT IS ADVICED TO FORM CHIPERS OF LENGTH 4 TO 6(AS 1 TO 8 LENGTH CHIPER CAN BE FORMED) FOR GOOD SECURITY\nLET CONSIDER 4 TO 6 LENGTH CHIPERS, THE TOTAL CHIPER CAN BE CONSIDERED IS(TAKING ALL ALPHABET DISTINCT)\n";
int cal1=26*25*24*23;
int cal2=cal1*22;
int cal3=cal2*21;
cout<<"FOR 4 ALPHABETS "<<cal1<<"+ FOR 5 ALPHABETS "<<cal2<<" FOR 6 ALPHABETS "<<cal3;
int total=cal1+(cal2)+(cal3);
cout<<"\nTOTAL IS :-"<<total;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
