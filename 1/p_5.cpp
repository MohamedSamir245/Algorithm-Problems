#include <iostream>
#include <vector>
#include <set>
using namespace std;
void mincolors(vector<vector<int>> graph, int &min, vector<int> colors, vector<int> &finalcolors)
{
    if (colors.size() == graph.size())
    {
        vector<int> temp;
        for (int i = 0; i < graph.size(); i++)
        {
            temp.clear();
            bool hasdublicates = false;
            for (int j = 0; j < graph[i].size(); j++)
            {
                temp.push_back(colors[graph[i][j]]);
            }
            for (int m = 0; m < temp.size(); m++)
            {
                if (temp[m] == colors[i])
                    hasdublicates = true;
            }

            if (hasdublicates)
            {
                return;
            }
        }
        set<int> s(colors.begin(), colors.end());
        if (s.size() < min)
        {
            min = s.size();
            finalcolors = colors;
        }

        return;
    }
    for (int i = 0; i < graph.size(); i++)
    {
        colors.push_back(i);
        mincolors(graph, min, colors, finalcolors);
        colors.pop_back();
    }
}
int main()
{
    vector<vector<int>> g;
    g = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2}};
    vector<int> temp;
    vector<int> final;

    int minc = INT_MAX;

    mincolors(g, minc, temp, final);
    cout << minc;

    return 0;
}