#include <iostream>
#include <string>
using namespace std;
void printbinary(string s, int k, int n)
{
    if (s.size() == n)
    {
        cout << s << endl;
        return;
    }
    for (int i = 0; i < k; i++)
    {
        printbinary(s + to_string(i), k,n);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    printbinary("",k, n);

    return 0;
}