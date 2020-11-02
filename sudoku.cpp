#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("sudoku.in");
ofstream fout("sudoku.out");

int v[13][13];


void afisare ()
{
    int i,j;
    for (i=1; i<=9; i++)
    {
        for (j=1; j<=9; j++)
            fout<<v[i][j]<<" ";
        fout<<"\n";
    }
}

void Back (int x, int y)
{
    int l,c,n,m,viz[10];
    if (x==10 && y==1)
    {
        afisare ();
        exit (0);
    }
    else if (v[x][y]==0)
    {
        memset (viz, 0, sizeof (viz));

        for (int i=1; i<=9; i++)
        {
            viz[v[i][y]]++;
            viz[v[x][i]]++;
        }

        if (x<4) l=1;
        else if (x<7) l=4;
        else l=7;
        if (y<4) c=1;
        else if (y<7) c=4;
        else c=7;
        n=l+3;
        m=c+3;

        for (int i=l; i<n; i++)
            for (int j=c; j<m; j++)
                viz[v[i][j]]++;

        for (int i=1; i<=9; i++)
            if (viz[i]==0)
            {
                v[x][y]=i;
                if (y!=9) Back (x,y+1);
                else Back (x+1, 1);
                v[x][y]=0;
            }
    }
    else if (y==9) Back (x+1,1);
    else Back (x, y+1);
}

int main()
{
    int i,j;
    for (i=1; i<=9; i++)
        for (j=1; j<=9; j++)
            fin>>v[i][j];

    Back (1,1);


    return 0;
}
