#include<iostream>
using namespace std;

void merge(int arr[],int l ,int mid,int r){

int n1 = (mid -l) + 1 ;
int n2 = r - mid ;

int a[n1] ; //temporary arrays
int b[n2] ;

//assigning values to this arrays

for(int i = 0 ;  i < n1 ; i++){
    a[i] = arr[l+i];
}
for(int j = 0 ;  j < n2 ; j++){
    b[j] = arr[mid+j+1]; //notice
}

//merging sorted temporary arrays 
int i = 0 ;
int j = 0 ;
int k = l ;

while (i < n1 && j < n2){
    if(a[i] < b[j]){
        arr[k] = a[i];
        i++ ;
        k++ ;
    }
    else{
        arr[k] = b[j];
        j++;
        k++ ;
    }
}

//while need both condtion to be true if one of them is false then we have 
//to put remaining values to arr so for that we  run more while loops 

while(i < n1){
    arr[k] = a[i];
    i++  ;
    k++;
}
while(j < n2){
    arr[k] = b[j];
    j++  ;
    k++;
}

}

void mergeSort(int arr[] , int l , int r ){
    if(l<r){
    int mid = (l+r) /2 ;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);

    merge(arr,l,mid,r);
    }
}
int main()
{
    int arr[] = {6,3,9,5,2,8,7,1} ;
    mergeSort(arr,0,7);

    //printing sorted array 
    for(int i = 0 ; i < 8 ; i++ ){
        cout <<arr[i] <<" ";
    }
    cout <<endl ;
    
    return 0;
}