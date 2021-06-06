#include<iostream>
#include<math.h>
#include <bits/stdc++.h>

using namespace std; 
int amt,principal,debit;
float rate , rod;
int amount(){
    cout << "Enter principal amount : ";
    cin >> principal;
    cout << "Enter Rate of Interst : ";
    cin >> rate;
    amt =principal * (pow((1 + rate / 100),1));
    cout << "Balance : " << amt << endl;
}
int out (){
    cout << "Enter amount you want to debit :";
    cin >> debit;
    cout << "Enter rate of debit : ";
    cin >> rod;
    amt -= debit;
}

int main () {
    amount();
    out();
    for(int i=1; i <5; i++){
        cout << "balance after " << i  <<" st year" << amt << endl;
        amt =   amt*(1 + rate);
        debit = (((rod/10)*debit) + debit); 
        amt -= debit;
    }
    return 0;
}