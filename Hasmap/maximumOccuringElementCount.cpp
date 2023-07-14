#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str = "abcdefgaaaa" ; //maximum ocuuring element count


    unordered_map<char,int> arrFreq;
    
  

//we map interger with char

    for(int i= 0 ; i< str.length(); i++){
       
        arrFreq[str[i]]++ ; //increase count   for duplicate element
    }

    //print maximum count 
    int ans = INT_MIN ;
    char element ;

    for(int i = 0 ; i < str.size() ; i++){
        if(arrFreq[str[i]] > ans){
         ans = arrFreq[str[i]];
         element = str[i] ;
         }
    }

    cout<< " maximum occurance element count : " <<ans  <<endl ; 
    cout<< " maximum occurance element is : " <<element  <<endl ; 
    return 0;
}