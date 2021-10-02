#include <bits/stdc++.h>
using namespace std;
  
bool is_Prime(int n)
{
    if (n <= 1)
        return false;
  
    // Check from 2 to n/2
    for (int i = 2; i <= n/2; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
  
// main() function where the program begins.
int main()
{
    int n;
    cout<<"Enter number to check prime or not: ";
    cin>>n;
    is_Prime(n) ? cout << "The number is Prime number." : cout << "The number is not a Prime number.";
    return 0;
}
