#include<iostream>

using namespace std;

void heapify(int arr[],int n, int i){
    int largest = i ; 
    int l  = 2 * i + 1;
    int r  = 2 * i + 2;
    if( l<n && arr[l] > arr[largest]){
        largest = l;
    }
    if( r<n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);

        heapify(arr,n,largest);
    }
}
