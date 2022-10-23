#include <iostream>
#include <string>
#include <vector>
using namespace std;
int count_stairs(int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
   
    return count_stairs(n - 1) +count_stairs(n-2)+count_stairs(n-3);

}
int main()
{
   cout<<count_stairs(4);
    return 0;
}