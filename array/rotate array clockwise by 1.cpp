
void rotate(int arr[], int n)
{
    int temp=arr[0];
    arr[0]=arr[n-1];
    arr[n-1]=temp;
    for(int i=n-1;i>=2;i--){
        int t=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=t;
    }

}
