#include<iostream>

using namespace std;

int reverse(int arr[],int size){
    for(int i = 0; i<size/2;i++){
        int temp = arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i] = temp;
    }
}

int printArray(int arr[],int size){
    for(int i = 0; i<size;i++){
        cout<< arr[i]<<" ";
    }
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    printArray(arr,6);
    reverse(arr,6);
    printArray(arr,6);
}
