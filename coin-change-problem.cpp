
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    //finer version of code
    //input
    int coins = 0; int total = 0; int n = 0;
    //  cout << "enter the total change to be required:" << endl;
    cin >> total;
    // cout << "enter the total number of coins required:" << endl;
    cin >> n;
    int x[n + 1]; //const
    //int x[5];
    x[0] = 0;
    // cout << "enter the denominations" << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> x[i];
    }
    sort(x, x + n + 1);
    // cout << "the sorted array" << endl;
   //  for (int i = 0; i <= n; i++)
   //  {
    //     cout << x[i] << "=x[" << i<<"]" << endl;
    // }




     //process
     //int m[coins][total];int64_t
    int64_t m[n + 1][total + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= total; j++)
        {
            if (i == 0 && j > 0)
            {
                m[i][j] = 0;
            }
            if (i == 0 && j == 0)
            {
                m[i][j] = 1;
            }
            if (x[i] > j && i != 0)
            {
                m[i][j] = m[i - 1][j];
            }
            else if (j >= x[i] && i != 0)
            {
                m[i][j] = m[i - 1][j] + m[i][j - x[i]];
            }
        }
    }

    //displaying the matrix


   // cout << "the matrix is as follows:" << endl;
   // for (int i = 0; i <=n; i++)
   // {
   //     for (int j = 0; j <= total ; j++)
   //     {
   //         cout << "m[" << i << "][" << j << "]=" << m[i][j] << " ";
   //     }
   //     cout << endl;
   // }
   // cout << "the solution is as follows:" << endl;
    cout << m[n][total];
}



