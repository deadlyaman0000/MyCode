#include<iostream>
using namespace std;

void subseq(string str , string ans){
    if(str.length()== 0){
        cout << ans <<endl ;
        return ;
    }
    char ch = str[0];
    string ros = str.substr(1);

    subseq(ros,ans);
    subseq(ros,ans+ch);

    
}

int main()
{
    string str = "ABC";
  
    subseq(str,"");
    
    return 0;
}