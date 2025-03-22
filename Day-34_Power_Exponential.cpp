#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    // Case handling for known values
    if (n == 0)
        return 1.0;
    if (x == 0)
        return 0.0;
    if (x == 1)
        return 1.0;
    if (x == -1 && n % 2 == 0)
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;

    // if power in negative
    long binForm = n;
    double ans = 1;
    if (n < 0)
    {
        x = 1 / x;
        binForm = -binForm;
    }
    // Converting power in to binary form
    // reduce time complexity from O(n) to O(logn)
    while (binForm > 0)
    {
        if (binForm % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        binForm /= 2;
    }
    return ans;
}
int main()
{
    double x;
    cout << "Enter a integer: ";
    cin >> x;
    int n;
    cout << "Enter power: ";
    cin >> n;
    double result = myPow(x, n);
    cout << result << endl;
    return 0;
}