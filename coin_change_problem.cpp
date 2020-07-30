
#include <iostream>
using namespace std;

int main()
{
    //input
    int coins=0; int total=0;
    cout << "enter the largest denomination of the coin" << endl;
    cin >> coins;
    cout << "enter the total of the change required" << endl;
    cin >> total;

    //process
    //int m[coins][total];
    int m[6][6];
    for (int i = 0; i <= coins-1; i++)
    {
        for (int j = 0; j <= total-1 ; j++)
        {
            if (i == 0 && j > 0)
            {
                m[i][j] = 0;
            }
            if (i == 0 && j == 0)
            {
                m[i][j] = 1;
            }
            if (i > j && i!=0)
            {
                m[i][j] = m[i - 1][j];
            }
            else if(j>=i && i!=0) 
            {
                m[i][j] = m[i - 1][j] + m[i][j - i];
            }
        }
    }
     
    //displaying the matrix


    cout << "the matrix is as follows:" << endl;
    for (int i = 0; i <= coins-1; i++)
    {
        for (int j = 0; j <= total-1; j++)
        {
            cout << "m[" << i << "][" << j << "]=" << m[i][j]<<" ";
        }
        cout << endl;
    }
}


