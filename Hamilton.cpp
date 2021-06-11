#include<bits/stdc++.h>
using namespace std;

int n,matrix[1005][1005];
int ham[1005]  = {0};
bool chuaxet[1005];
// int v;
void __init__()
{
    ifstream file("matrix.txt",ios::in);
    file >> n;
    for (int i = 1;  i <= n; i++)
        for (int j = 1; j <= n; j++)
            file >> matrix[i][j];
}

void Hamilton(int k)
{   
    int s = k - 1;
    for (int i = 1; i <= n; i++)
        if (matrix[s][i] == 1)
            if ((k == n+1) && (i == 3))
                {
                    for (int i = 1 ; i <= n; ++i)
                        cout << ham[i] << " ";
                }
            else if (chuaxet[i] == true)
                {
                    ham[k] = i;
                    chuaxet[i] = false;
                    Hamilton(k+1);
                    chuaxet[i] = true;
                }
            
}
void Hamilton_Cycle()
{
    for (int i = 1; i <= n; i++)
        chuaxet[i] = true;
    ham[1] = 3;
    chuaxet[3] = false;
    Hamilton(2);
}
int main()
{
    __init__();
    memset(chuaxet,false,sizeof(chuaxet));
    Hamilton_Cycle();
    return 0;
}