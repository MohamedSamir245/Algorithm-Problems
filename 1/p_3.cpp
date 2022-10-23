#include <iostream>
#include <string>
#include <vector>
using namespace std;
int lis(vector<int> arr, int index)
{
    if (index == arr.size())
    {
        // add 1 because we didn't count first number
        // for ex: arr=[1,2]
        // result is 2 not 1
        return 1;
    }
    if (arr.size() == 0)
    {
        return 0;
    }
    if (arr.size() == 1)
    {
        return 1;
    }
    if (arr[index] > arr[index - 1])
    {
        return 1 + lis(arr, index + 1);
    }
    return lis(arr, index + 1);
}
void LIS_brute(const vector<int> &arr, int index, vector<int> &maxseq, vector<int> &currseq)
{
    if (index == arr.size())
    {
        if (currseq.size() > maxseq.size())
        {
            int prev = INT_MIN;
            for (int i = 0; i < currseq.size(); i++)
            {
                if (currseq[i] < prev)
                {
                    return;
                }
                prev = currseq[i];
            }
            maxseq = currseq;
        }
    }
    else
    {
        LIS_brute(arr, index + 1, maxseq, currseq);
        currseq.push_back(arr[index]);
        LIS_brute(arr, index + 1, maxseq, currseq);
        currseq.pop_back();
    }
}
int main()
{
    vector<int> arr(9);
    arr = {12, 24, 9, 35, 21, 50, 41, 62, 82};
    cout << lis(arr, 0) << endl;

    vector<int> maxs;
    vector<int> t;

    LIS_brute(arr, 0, maxs, t);

    for (int i = 0; i < maxs.size(); i++)
    {
        cout << maxs[i] << " ";
    }

    return 0;
}