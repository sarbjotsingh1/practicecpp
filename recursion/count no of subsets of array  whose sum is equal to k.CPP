#include <bits/stdc++.h>
using namespace std;
string sum(string s1, string s2, int i, int j, int carry)
{
    if (s1.size() < s2.size())
    {
        return sum(s2, s1, j, i, carry);
    }


    if (i < 0)
    {
        if (carry == 1)
        {
            return "1";
        }
        return "";
    }

    if (j < 0)
    {
        int sumcurr = (s1[i] - '0') + carry;
        carry = sumcurr / 10;
        sumcurr = sumcurr % 10;

        char temp = sumcurr + '0';
        return sum(s1, s2, i - 1, j - 1, carry) + temp;

    }

    int sumcurr = (s1[i] - '0') + carry + (s2[j] - '0');
    carry = sumcurr / 10;
    sumcurr = sumcurr % 10;

    char temp = sumcurr + '0';
    return sum(s1, s2, i - 1, j - 1, carry) + temp;

}
int main() {
    // your code goes here

    string s1, s2;
    cin >> s1 >> s2;
    cout << sum(s1, s2, s1.size() - 1, s2.size() - 1, 0) << endl;

    return 0;
}
