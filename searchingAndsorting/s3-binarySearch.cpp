#include<iostream>
using namespace std;


int binarySearch(int arr[], int l , int r ,int key ){

    int mid = (l+ r) /2 ;
    if(l <= r){
        if(arr[mid]== key){
            return 0 ;
        }

        else if(arr[mid] < key){
            return binarySearch(arr,mid+1,r,key);
        }

         else if(arr[mid] > key){
            return binarySearch(arr,l,mid-1,key);
        }

    }
    return -1 ;
}

int main()
{
    int arr[] ={1,2,3,5,9,11,45,78,99,999} ;
    int key = 999 ;
    int l = 0;
    int r = 9 ;
    cout << binarySearch(arr,l,r,key);
    
    return 0;
}