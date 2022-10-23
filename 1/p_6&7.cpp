#include <iostream>
#include <string>
#include <vector>
using namespace std;

void minpath_(vector<vector<int>> warr, vector<vector<bool>> &varr, vector<int> &minpath, vector<int> path, int rid, int cid, int &mincost, int cost, int n)
{
    if ((rid < 0 || rid >= n || cid < 0 || cid >= n) || varr[rid][cid])
        return;
    if (cost > mincost)//the add to be sol of p_7
        return;
    cost += warr[rid][cid];
    path.push_back(warr[rid][cid]);
    if (rid == n - 1 && cid == n - 1)
    {
        if (cost < mincost)
        {
            mincost = cost;
            minpath = path;
        }
        return;
    }
    varr[rid][cid] = true;
    minpath_(warr, varr, minpath, path, rid, cid+1, mincost, cost, n);
    minpath_(warr, varr, minpath, path, rid, cid-1, mincost, cost, n);
    minpath_(warr, varr, minpath, path, rid+1, cid, mincost, cost, n);
    minpath_(warr, varr, minpath, path, rid-1, cid, mincost, cost, n);
    varr[rid][cid] = false;
}
int main()
{
    vector<int>minpath;
    vector<int> path;

    vector<vector<int>> arr(3, vector<int>(3));
    arr[0][0] = 3;
    arr[0][1] = 1;
    arr[0][2] = 3;
    arr[1][0] = 8;
    arr[1][1] = 16;
    arr[1][2] = 2;
    arr[2][0] = 2;
    arr[2][1] = 2;
    arr[2][2] = 2;
    vector<vector<bool>> varr(3, vector<bool>(3, false));
    int cost = INT_MAX;
    
    minpath_(arr,varr,minpath,path,0,0,cost,0,3);
   
    for(int i=0;i<minpath.size();i++)
    {
        cout<<minpath[i]<<'-';
    }

    return 0;
}