#include <iostream>
using namespace std;
void printbinary(string s, int n)
{
    if (s.size() == n)
    {
        cout << s << endl;
        return;
    }

    printbinary(s + "0", n);
    printbinary(s + "1", n);
}
int main()
{
    int n;
    cin>>n;
    printbinary("", n);

    return 0;
}