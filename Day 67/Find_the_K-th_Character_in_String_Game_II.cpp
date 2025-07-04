#include <bits/stdc++.h>
using namespace std;
char kthCharacter(long long k, vector<int> &operations)
{
    int shift = 0;
    vector<long long> lengths;
    long long len = 1;

    for (int op : operations)
    {
        len *= 2;
        lengths.push_back(len);
        if (len >= k)
            break;
    }

    for (int i = lengths.size() - 1; i >= 0; --i)
    {
        long long half = lengths[i] / 2;
        int op = operations[i];
        if (k > half)
        {
            k -= half;
            if (op == 1)
                shift++;
        }
    }

    return (char)((('a' - 'a' + shift) % 26) + 'a');
}

int main()
{
    long long k;
    cin >> k;
    vector<int> operations = {0, 0, 0}; // Example operations
    if (k <= 0)
    {
        cout << "Invalid input. k must be a positive integer." << endl;
        return 1;
    }
    char result = kthCharacter(k, operations);
    cout << result << endl;

    return 0;
}