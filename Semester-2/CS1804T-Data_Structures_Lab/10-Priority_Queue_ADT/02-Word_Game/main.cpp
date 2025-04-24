#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    vector<vector<string>> v;
    vector<int> temp;
    vector<string> temp4;
    int num, num1, sum, other1, other2;
    string str;

    vector<vector<int>> out;

    cin >> num;

    for (int h = 0; h < num; h++)
    {
        v.clear();
        cin >> num1;

        for (int i = 0; i < 3; i++)
        {
            temp4 = {};
            for (int j = 0; j < num1; j++)
            {
                cin >> str;
                temp4.push_back(str);
            }
            v.push_back(temp4);
        }
        temp.clear();

        for (int i = 0; i < 3; i++)
        {
            sum = 0;

            for (int j = 0; j < num1; j++)
            {
                int count = 0;

                for (int k = 0; k < num1; k++) // for one word
                {
                    other1 = (i + 1) % 3;
                    other2 = (i + 2) % 3;

                    if (v[other1][k] == v[i][j])
                    {
                        count++;
                    }
                    if (v[other2][k] == v[i][j])
                    {
                        count++;
                    }
                }

                if (count == 1)
                {
                    sum += 1;
                }
                if (count == 0)
                {
                    sum += 3;
                }
            }
            temp.push_back(sum);
        }

        out.push_back(temp);
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
}