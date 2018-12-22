#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string key,ky="";
    cin>>key;
for(int i=0;i<key.length()-1;i++){
            for(int j=i+1;j<key.length();j++){
                if(key[i]==key[j]&&key[j]!='@'){
                    key[j]='@';
                }
            }
        }
        for(int i=0;i<key.length();i++){
            if(key[i]!='@')
            ky=ky+key[i];
        }
        key=ky;
        cout<<key;
return 0;
}
