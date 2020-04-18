#include<iostream>
#include<stdlib.h>
#include<deque>
#include<conio.h>
#include <windows.h>
#include<ctime>
using namespace std;
const int n = 11;
int hexc[n][n + 1], hexp[n][n + 1], hexpc[n][n + 1], reach[n][n + 1], k = n/2,hexcr[n][n+1],hexcb[n][n+1], reach1[n][n + 1];
char hexx[n][n + 1],hexpv[n][n+1];
deque<int> q,qq;
struct  moves
{
    int a, b;
    char c;
} m[1000], m1[1000];
void textcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}
void initialise()
{
    int i, j, cl;
    for (i = 0; i < n; i++)
    {
        cl = 0;
        if (i <= k)
        {
            for (j = k - i; j >= 0; j--)
            {
                hexcr[i][cl]=0;
                hexcb[i][cl]=0;
                hexc[i][cl]=0;
                cl++;
            }
         for (j = 0; j <= i; j++)
            {
                hexcr[i][cl]=1;
                hexcb[i][cl]=1;
                hexc[i][cl]=1;
                cl++;
            }
            for (j = 1; j <= i; j++)
            {
                hexcr[i][cl]=1;
                hexcb[i][cl]=1;
                hexc[i][cl]=1;
                cl++;
            }
            for (j = k - i; j >= 0; j--)
            {
                hexcr[i][cl]=0;
                hexcb[i][cl]=0;
                cl++;
            }
        }
        else
        {
            for (j = k; j <= i; j++)
            {
                hexcr[i][cl]=0;
                hexcb[i][cl]=0;
                hexc[i][cl]=0;
                cl++;
            }

            for (j = n - 1; j >= i; j--)
            {
                hexcr[i][cl]=1;
                hexcb[i][cl]=1;
                hexc[i][cl]=1;
                cl++;
            }

            for (j = n - 2; j >= i; j--)
            {
                hexcr[i][cl]=1;
                hexcb[i][cl]=1;
                hexc[i][cl]=1;
                cl++;
            }

            for (j = k; j <= i; j++)
            {
                hexcr[i][cl]=0;
                hexcb[i][cl]=0;
                hexc[i][cl]=0;
                cl++;
            }
        }
    }

}
int sdist(int sxx, int syy,int hexw[n][n+1],char c)
{
    int i, j, ii, jj = 0,d=0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n + 1; j++)
        {
            reach1[i][j] = 0;
        }
    reach1[sxx][syy] = 1;
    qq.push_back(sxx);
    qq.push_back(syy);
    qq.push_back(d);

    while (qq.size() != 0)
    {
        i = qq.front();
        qq.pop_front();
        j = qq.front();
        qq.pop_front();
        d = qq.front();
        qq.pop_front();

        if (c == 'B' || c == 'b')
        {
            jj = 0;
            for (ii = k; ii < n; ii++)
            {
                if (i == ii && j == (k + ii - 2 * jj + 1))
                {
                    qq.clear();
                    return d;
                }
                jj++;
            }
        }
        else if (c == 'R' || c == 'r')
        {
            for (ii = 0; ii <= k; ii++)
                if (i == 0 + ii && j == k + ii + 1)
                {
                    qq.clear();
                    return d;
                }
        }


        if (hexw[i][j + 1] && ! reach1[i][j + 1])
        {
             reach1[i][j + 1] = 1;
            qq.push_back(i);
            qq.push_back(j + 1);
            if (c == 'B' || c == 'b')
            {
                if(hexp[i][j+1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
            else if (c == 'R' || c == 'r')
            {
                if(hexpc[i][j+1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
        }
        if (hexw[i][j - 1] && ! reach1[i][j - 1])
        {
             reach1[i][j - 1] = 1;
            //hexpv[i][j-1]=c;
            qq.push_back(i);
            qq.push_back(j - 1);
            if (c == 'B' || c == 'b')
            {
                if(hexp[i][j-1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
            else if (c == 'R' || c == 'r')
            {
                if(hexpc[i][j-1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
        }

        if (hexw[i - 1][j] && ! reach1[i - 1][j])
        {
             reach1[i - 1][j] = 1;
            //hexpv[i-1][j]=c;
            qq.push_back(i - 1);
            qq.push_back(j);
            if (c == 'B' || c == 'b')
            {
                if(hexp[i-1][j])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);

            }
            else if (c == 'R' || c == 'r')
            {
                if(hexpc[i-1][j])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
        }
        if (hexw[i + 1][j] && ! reach1[i + 1][j])
        {
             reach1[i + 1][j] = 1;
            //hexpv[i+1][j]=c;
            qq.push_back(i + 1);
            qq.push_back(j);
            if (c == 'B' || c == 'b')
            {
                if(hexp[i+1][j])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
            else if (c == 'R' || c == 'r')
            {
                if(hexpc[i+1][j])
                    qq.push_back(d);
                else
                   qq.push_back(d+1);
            }
        }
        if (hexw[i + 1][j + 1] && ! reach1[i + 1][j + 1])
        {
             reach1[i + 1][j + 1] = 1;
            //hexpv[i+1][j+1]=c;
            qq.push_back(i + 1);
            qq.push_back(j + 1);
            if (c == 'B' || c == 'b')
            {
                if(hexp[i+1][j+1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
            else if (c == 'R' || c == 'r')
            {
                if(hexpc[i+1][j+1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
        }
        if (hexw[i + 1][j - 1] && ! reach1[i + 1][j - 1])
        {
             reach1[i + 1][j - 1] = 1;
            //hexpv[i+1][j-1]=c;
            qq.push_back(i + 1);
            qq.push_back(j - 1);
            if (c == 'B' || c == 'b')
            {
                if(hexp[i+1][j-1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
            else if (c == 'R' || c == 'r')
            {
                if(hexpc[i+1][j-1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
        }
        if (hexw[i - 1][j - 1] && ! reach1[i - 1][j - 1])
        {
             reach1[i - 1][j - 1] = 1;
            //hexpv[i-1][j-1]=c;
            qq.push_back(i - 1);
            qq.push_back(j - 1);
            if (c == 'B' || c == 'b')
            {
                if(hexp[i-1][j-1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);

            }
            else if (c == 'R' || c == 'r')
            {
                if(hexpc[i-1][j-1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
        }
        if (hexw[i - 1][j + 1] && ! reach1[i - 1][j + 1])
        {
             reach1[i - 1][j + 1] = 1;
            //hexpv[i-1][j+1]=c;
            qq.push_back(i - 1);
            qq.push_back(j + 1);
            if (c == 'B' || c == 'b')
            {
                if(hexp[i-1][j+1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
            else if (c == 'R' || c == 'r')
            {
                if(hexpc[i-1][j+1])
                    qq.push_back(d);
                else
                    qq.push_back(d+1);
            }
        }
    }
    qq.clear();
    return 0;
}
int hval(char c)
{
    int ii, jj,sdc=INT_MAX,kk;
    if (c == 'B' || c == 'b')
    {
        ii = 0;
        jj = k + 1;
        while (ii <= k && jj > 0)
        {
            kk = sdist(ii, jj,hexcb,c);

            if(kk<sdc)
                sdc=kk;


            ii++;
            jj--;
        }
    }
    else if (c == 'R' || c == 'r')
    {

        ii = k;
        jj = 1;
        while (ii < n && jj <=k+1)
        {
            kk = sdist(ii, jj,hexcr,c);
            if(kk<sdc)
                sdc=kk;

            ii++;
            jj++;
        }
    }
    return sdc;

}
int chval(char c)
{
    int a,b;
    a=hval('B');
    b=hval('R');
    if (c == 'B' || c == 'b')
        return a-b;
    else if (c == 'R' || c == 'r')
       return  b-a;
}
void disp()
{
    int i, j, cl;

    textcolor(15);
    for (i = 0; i <= n; i++)
    {
        if (i == 0)
            cout << "      ";
        else if (i < 10)
            cout << i - 1 << "  ";
        else if (i == 10)
            cout << i - 1 << "  ";
        else
            cout << i - 1 << " ";
    }
    cout << "\n";
    for (i = 0; i < n - 6; i++)
        cout << "   ";
    textcolor(11);
    cout << "     B";
    textcolor(12);
    cout << " R\n";
    textcolor(15);

    for (i = 0; i < n; i++)
    {
        cl = 0;
        cout << i;
        if (i == k)
        {
            textcolor(12);
            cout << " " << "R";
            textcolor(11);
            cout<<"B";
            textcolor(15);
        }
        else if (i < 10)
            cout << "    ";
        else
            cout << "   ";

        if (i <= k)
        {
            for (j = k - i; j >= 0; j--)
            {
                if (j == 0)
                {
                    cout << "";
                    //hexc[i][cl] = 0;
                    cl++;
                }

                else if (j == 1)
                {
                    textcolor(11);
                    cout << "B  ";
                    //hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);

                }
                else
                {
                    cout << "   ";
                    // hexc[i][cl] = 0;
                    cl++;
                }
            }

            for (j = 0; j <= i; j++)
            {

                if(hexx[i][cl]=='B'||hexx[i][cl]=='b')
                    textcolor(11);
                else if(hexx[i][cl]=='R' || hexx[i][cl]=='r')
                    textcolor(12);

                cout << " " << hexx[i][cl] << " ";
                cl++;
                textcolor(15);

            }

            for (j = 1; j <= i; j++)
            {

                if(hexx[i][cl]=='B'||hexx[i][cl]=='b')
                    textcolor(11);
                else if(hexx[i][cl]=='R' || hexx[i][cl]=='r')
                    textcolor(12);

                cout << " " << hexx[i][cl] << " ";
                cl++;
                textcolor(15);

            }

            for (j = k - i; j >= 0; j--)
            {
                if (j == k - i && j != 0)
                {
                    textcolor(12);
                    cout << "  R";
                    // hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);
                }
                else if (i == k)
                {
                    cout << "";
                    hexc[i][cl] = 0;
                    cl++;
                }
                else
                {
                    cout << "   ";
                    // hexc[i][cl] = 0;
                    cl++;
                }
            }
            if (i == k)
            {
                textcolor(12);
                cout << "R";
                textcolor(11);
                cout<<"B";
                textcolor(15);
            }
        }
        else
        {
            for (j = k; j <= i; j++)
            {
                if (j == k)
                {
                    cout << "";
                    // hexc[i][cl] = 0;
                    cl++;
                }

                else if (j == i && i == 10)
                {
                    textcolor(12);
                    cout << "R  ";
                    hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);
                }
                else if (j == i)
                {
                    textcolor(12);
                    cout << "R  ";
                    // hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);
                }
                else if (i == 10 && j == i - 1)
                {
                    cout << "  ";
                    //hexc[i][cl] = 0;
                    cl++;
                }
                else
                {
                    cout << "   ";
                    // hexc[i][cl] = 0;
                    cl++;
                }
            }

            for (j = n - 1; j >= i; j--)
            {

                if(hexx[i][cl]=='B'||hexx[i][cl]=='b')
                    textcolor(11);
                else if(hexx[i][cl]=='R' || hexx[i][cl]=='r')
                    textcolor(12);

                cout << " " << hexx[i][cl] << " ";
                cl++;
                textcolor(15);

            }

            for (j = n - 2; j >= i; j--)
            {

                if(hexx[i][cl]=='B'||hexx[i][cl]=='b')
                    textcolor(11);
                else if(hexx[i][cl]=='R' || hexx[i][cl]=='r')
                    textcolor(12);

                cout << " " << hexx[i][cl] << " ";
                cl++;
                textcolor(15);

            }
            for (j = k; j <= i; j++)
            {
                if (j == k)
                {
                    textcolor(11);
                    cout << "  B";
                    //  hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);
                }
                else
                {
                    cout << "   ";
                    // hexc[i][cl] = 0;
                    cl++;
                }
            }
        }
        cout << "\n";
    }
    for (i = 0; i < n - 6; i++)
        cout << "   ";
    textcolor(12);
    cout << "    R ";
    textcolor(11);
    cout<<"B\n";
    textcolor(15);

}
void disppath()
{
    int i, j, cl;

    textcolor(15);
    for (i = 0; i <= n; i++)
    {
        if (i == 0)
            cout << "      ";
        else if (i < 10)
            cout << i - 1 << "  ";
        else if (i == 10)
            cout << i - 1 << "  ";
        else
            cout << i - 1 << " ";
    }
    cout << "\n";
    for (i = 0; i < n - 6; i++)
        cout << "   ";
    textcolor(11);
    cout << "     B";
    textcolor(12);
    cout << " R\n";
    textcolor(15);

    for (i = 0; i < n; i++)
    {
        cl = 0;
        cout << i;
        if (i == k)
        {
            textcolor(12);
            cout << " " << "R";
            textcolor(11);
            cout<<"B";
            textcolor(15);
        }
        else if (i < 10)
            cout << "    ";
        else
            cout << "   ";
        if (i <= k)
        {
            for (j = k - i; j >= 0; j--)
            {
                if (j == 0)
                {
                    cout << "";
                    hexc[i][cl] = 0;
                    cl++;
                }

                else if (j == 1)
                {
                    textcolor(11);
                    cout << "B  ";
                    hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);
                }
                else
                {
                    cout << "   ";
                    hexc[i][cl] = 0;
                    cl++;
                }
            }

            for (j = 0; j <= i; j++)
            {
                if(hexpv[i][cl]=='B'||hexpv[i][cl]=='b')
                    textcolor(11);
                else if(hexpv[i][cl]=='R' || hexpv[i][cl]=='r')
                    textcolor(12);

                cout << " " << hexpv[i][cl] << " ";
                cl++;
                textcolor(15);

            }

            for (j = 1; j <= i; j++)
            {

                if(hexpv[i][cl]=='B'||hexpv[i][cl]=='b')
                    textcolor(11);
                else if(hexpv[i][cl]=='R' || hexpv[i][cl]=='r')
                    textcolor(12);

                cout << " " << hexpv[i][cl] << " ";
                cl++;
                textcolor(15);

            }

            for (j = k - i; j >= 0; j--)
            {
                if (j == k - i && j != 0)
                {
                    textcolor(12);
                    cout << "  R";
                    hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);
                }
                else if (i == k)
                {
                    cout << "";
                    hexc[i][cl] = 0;
                    cl++;
                }
                else
                {
                    cout << "   ";
                    hexc[i][cl] = 0;
                    cl++;
                }

            }
            if (i == k)
            {
                textcolor(12);
                cout << "R";
                textcolor(11);
                cout<<"B";
                textcolor(15);
            }
        }
        else
        {
            for (j = k; j <= i; j++)
            {
                if (j == k)
                {
                    cout << "";
                    hexc[i][cl] = 0;
                    cl++;
                }

                else if (j == i && i == 10)
                {
                    textcolor(12);
                    cout << "R  ";
                    hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);
                }
                else if (j == i)
                {
                    textcolor(12);
                    cout << "R  ";
                    hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);
                }
                else if (i == 10 && j == i - 1)
                {
                    cout << "  ";
                    hexc[i][cl] = 0;
                    cl++;
                }
                else
                {
                    cout << "   ";
                    hexc[i][cl] = 0;
                    cl++;
                }
            }

            for (j = n - 1; j >= i; j--)
            {

                if(hexpv[i][cl]=='B'||hexpv[i][cl]=='b')
                    textcolor(11);
                else if(hexpv[i][cl]=='R' || hexpv[i][cl]=='r')
                    textcolor(12);

                cout << " " << hexpv[i][cl] << " ";
                cl++;
                textcolor(15);

            }

            for (j = n - 2; j >= i; j--)
            {

                if(hexpv[i][cl]=='B'||hexpv[i][cl]=='b')
                    textcolor(11);
                else if(hexpv[i][cl]=='R' || hexpv[i][cl]=='r')
                    textcolor(12);

                cout << " " << hexpv[i][cl] << " ";
                cl++;
                textcolor(15);

            }

            for (j = k; j <= i; j++)
            {
                if (j == k)
                {
                    textcolor(11);
                    cout << "  B";
                    hexc[i][cl] = 0;
                    cl++;
                    textcolor(15);
                }
                else
                {
                    cout << "   ";
                    hexc[i][cl] = 0;
                    cl++;
                }
            }
        }
        cout << "\n";
    }
    for (i = 0; i < n - 6; i++)
        cout << "   ";
    textcolor(12);
    cout << "    R ";
    textcolor(11);
    cout<<"B\n";
    textcolor(15);

}
int check(int sx, int sy,int hexw[n][n+1],char c)
{

    int i, j, ii, jj = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n + 1; j++)
        {
            reach[i][j] = 0;
            hexpv[i][j]='-';
        }

    q.push_back(sx);
    q.push_back(sy);
    hexpv[sx][sy]=c;
    reach[sx][sy] = 1;


    while (q.size() != 0)
    {
        i = q.front();
        q.pop_front();
        j = q.front();
        q.pop_front();
        //hexpv[i][j+1]=c;
        if (c == 'B' || c == 'b')
        {
            jj = 0;
            for (ii = k; ii < n; ii++)
            {
                if (i == ii && j == (k + ii - 2 * jj + 1))
                {
                    hexpv[i][j+1]=c;
                    q.clear();
                    return 1;
                }
                jj++;
            }
        }
        else if (c == 'R' || c == 'r')
        {
            for (ii = 0; ii <= k; ii++)
                if (i == 0 + ii && j == k + ii + 1)
                {
                    hexpv[i][j+1]=c;
                    q.clear();
                    return 1;
                }
        }
        if (hexw[i][j + 1] && !reach[i][j + 1])
        {
            reach[i][j + 1] = 1;
            hexpv[i][j+1]=c;
            q.push_back(i);
            q.push_back(j + 1);
        }
        if (hexw[i][j - 1] && !reach[i][j - 1])
        {
            reach[i][j - 1] = 1;
            hexpv[i][j-1]=c;
            q.push_back(i);
            q.push_back(j - 1);
        }
        if (hexw[i - 1][j] && !reach[i - 1][j])
        {
            reach[i - 1][j] = 1;
            hexpv[i-1][j]=c;
            q.push_back(i - 1);
            q.push_back(j);
        }
        if (hexw[i + 1][j] && !reach[i + 1][j])
        {
            reach[i + 1][j] = 1;
            hexpv[i+1][j]=c;
            q.push_back(i + 1);
            q.push_back(j);
        }
        if (hexw[i + 1][j + 1] && !reach[i + 1][j + 1])
        {
            reach[i + 1][j + 1] = 1;
            hexpv[i+1][j+1]=c;
            q.push_back(i + 1);
            q.push_back(j + 1);
        }
        if (hexw[i + 1][j - 1] && !reach[i + 1][j - 1])
        {
            reach[i + 1][j - 1] = 1;
            hexpv[i+1][j-1]=c;
            q.push_back(i + 1);
            q.push_back(j - 1);
        }
        if (hexw[i - 1][j - 1] && !reach[i - 1][j - 1])
        {
            reach[i - 1][j - 1] = 1;
            hexpv[i-1][j-1]=c;
            q.push_back(i - 1);
            q.push_back(j - 1);
        }
        if (hexw[i - 1][j + 1] && !reach[i - 1][j + 1])
        {
            reach[i - 1][j + 1] = 1;
            hexpv[i-1][j+1]=c;
            q.push_back(i - 1);
            q.push_back(j + 1);
        }
    }
    q.clear();
    return 0;
}
void iai(int i,char c)
{
    int j,ii,jj ,x, y, co = 0,hv,kk=999,xm,ym;
    if (c == 'B' || c == 'b')
        c = 'R';
    else if (c == 'R' || c == 'r')
        c = 'B';

    for(ii=0; ii<n; ii++)
    {
        for(jj=1; jj<n+1; jj++)
        {
            if(hexc[ii][jj])
            {
                if (c == 'B' || c == 'b')
                   {
                    if(hexcb[ii][jj])
                    {
                        x=ii;
                        y=jj;
                    }
                    else
                        continue;
                   }
                else if (c == 'R' || c == 'r')
                       {

                        if(hexcr[ii][jj])
                        {
                            x=ii;
                            y=jj;
                        }
                        else
                            continue;
                       }

                co=0;
                for (j = 0; j < i; j++)
                {
                    if (m[j].a == y-1 && m[j].b == x || m1[j].a == y-1 && m1[j].b == x)
                        break;
                    else
                        co++;
                }

                if (co == i)
                {
                    if (c == 'B' || c == 'b')
                    {
                        hexp[x][y] = 1;
                        hexcr[x][y]=0;

                    }

                    else if (c == 'R' || c == 'r')
                    {
                        hexpc[x][y] = 1;
                        hexcb[x][y]=0;

                    }

                    hv=chval(c);

                    if (c == 'B' || c == 'b')
                    {
                        hexp[x][y] = 0;
                        hexcr[x][y]=1;

                    }

                    else if (c == 'R' || c == 'r')
                    {
                        hexpc[x][y] = 0;
                        hexcb[x][y]=1;

                    }
                    if(hv<kk)
                    {
                        kk=hv;
                        ym = y-1;
                        xm = x;

                    }

                }
            }
        }
    }
    if (c == 'B' || c == 'b')
    {
        m1[i].a = ym;
        m1[i].b = xm;
        m1[i].c = c;
        hexp[m1[i].b][m1[i].a+1] = 1;
        hexcr[m1[i].b][m1[i].a+1]=0;
        hexx[m1[i].b][m1[i].a+1]=c;
    }
    else if (c == 'R' || c == 'r')
    {
        m1[i].a = ym;
        m1[i].b = xm;
        m1[i].c = c;
        hexpc[m1[i].b][m1[i].a+1] = 1;
        hexcb[m1[i].b][m1[i].a+1]=0;
        hexx[m1[i].b][m1[i].a+1]=c;
    }
    system("cls");
    disp();
}
void ai(int i, char c)
{
    int j, x, y, co = 0;
    if (c == 'B' || c == 'b')
        c = 'R';
    else if (c == 'R' || c == 'r')
        c = 'B';

    while (1)
    {
        x = rand() %( n );
        y = rand() %( n + 1);
        if (hexc[x][y + 1] == 1)
        {
            co=0;
            for (j = 0; j < i; j++)
            {
                if (m[j].a == y && m[j].b == x || m1[j].a == y && m1[j].b == x)
                    break;
                else
                    co++;
            }
            if (co == i)
            {
                m1[i].a = y;
                m1[i].b = x;
                m1[i].c = c;
                hexx[x][y + 1] = c;
                if (c == 'B' || c == 'b')
                {
                    hexp[x][y + 1] = 1;
                    hexcr[x][y+1]=0;
                }

                else if (c == 'R' || c == 'r')
                {
                    hexpc[x][y + 1] = 1;
                    hexcb[x][y+1]=0;
                }

                system("cls");
                disp();
                break;
            }
        }
    }
}
void previous(int i, char c)
{
    int j;
    cout << "PREVIOUS MOVES:\n";
    cout << "Players Moves\t\t\tComputers Moves\n";
    for (j = 0; j < i; j++)
    {
        if (c == 'B' || c == 'b')
        {
            textcolor(11);
            if (hexp[m[j].b][m[j].a + 1])
                cout << m[j].a << " " << m[j].b << " " << m[j].c << "\t\t\t\t\t";
            textcolor(12);
            if (hexpc[m1[j].b][m1[j].a + 1])
                cout << m1[j].a << " " << m1[j].b << " " << m1[j].c << "\t\n";
        }
        else if (c == 'R' || c == 'r')
        {
            textcolor(12);
            if (hexpc[m[j].b][m[j].a + 1])
                cout << m[j].a << " " << m[j].b << " " << m[j].c << "\t\t\t\t\t";
            textcolor(11);
            if (hexp[m1[j].b][m1[j].a + 1])
                cout << m1[j].a << " " << m1[j].b << " " << m1[j].c << "\t\n";
        }
    }
    textcolor(15);
}
int ctowin(int i, char c)
{
    int co = 0, j, ii, jj;
    if (c == 'B' || c == 'b')
    {
        ii = 0;
        jj = k + 1;
        while (ii <= k && jj > 0)
        {
            if (hexp[ii][jj])
                if (check(ii, jj,hexp,c))
                {
                    system("cls");
                    disp();
                    disppath();
                    textcolor(11);
                    cout << "Player : " << c << " Has Won the Game \n";
                    //disppath();
                    textcolor(15);
                    _getch();
                    return 1;
                }

            ii++;
            jj--;
        }
    }
    else if (c == 'R' || c == 'r')
    {

        ii = k;
        jj = 1;
        while (ii < n && jj <=k+1)
        {
            if (hexpc[ii][jj])
                if (check(ii, jj,hexpc,c))
                {
                    system("cls");
                    disp();
                    disppath();
                    textcolor(12);
                    cout << "Player : " << c << " Has Won the Game \n";
                    // disppath();
                    _getch();
                    textcolor(15);
                    return 1;
                }
            ii++;
            jj++;
        }
    }
    return 0;

}
int playcheck(int i,char c)
{
    int co = 0, j;
    for (j = 0; j <i; j++)
    {
        if (m[j].a == m[i].a && m[j].b == m[i].b || m1[j].a == m[i].a && m1[j].b == m[i].b)
            break;
        else
            co++;
    }
    if (co == i)
    {
        hexx[m[i].b][m[i].a + 1] = c;
        if (c == 'B' || c == 'b')
        {
            hexp[m[i].b][m[i].a + 1] = 1;
            hexcr[m[i].b][m[i].a + 1] =0;
        }

        else if (c == 'R' || c == 'r')
        {
            hexpc[m[i].b][m[i].a + 1] = 1;
            hexcb[m[i].b][m[i].a + 1] =0;
        }

        return ctowin(i,c);
    }
    return 0;
}
int main()
{
    int i, j, fl;
    char c;
    initialise();
    srand(time(0));
    textcolor(15);
    cout << "RULES ARE:\n";
    cout << "Need To Connect The Corresponding Colour With A Line To Win\n\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n + 1; j++)
        {
            hexx[i][j] = '-';
            //hexc[i][j] = 1;
            hexp[i][j] = 0;
            hexpc[i][j] = 0;
            hexpv[i][j]='-';
        }
    disp();
    cout << "Which Colour do you want to play as(";
    textcolor(11);
    cout<<"B ";
    textcolor(15);
    cout<<"or ";
    textcolor(12);
    cout<<"R";
    textcolor(15);
    cout<<"):";
    cin >> c;
    while(1)
    {
        if(c=='B' || c=='b' || c=='R' || c=='r')
            break;
        cout << "Invalid Entry.Please Try Again.\n";
        cin>>c;
    }
    i = 0;
    while (1)
    {
        cout << "Enter column no. then row no.(3 4)(enter -1 to exit)\n";
        cin >> m[i].a;
        if (m[i].a == -1)
            break;
        while(cin.fail())
        {
            cout << "Invalid Entry.Please Try Again.\n" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> m[i].a;
        }
        cin >> m[i].b;
        while(cin.fail())
        {
            cout << "Invalid Entry.Please Try Again.\n" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> m[i].b;
        }
        m[i].c = c;
        if(m[i].a>20 || m[i].b>20)
        {
            cout << "Invalid Move.Please Try Again.\n";
            continue;
        }
        if (hexc[m[i].b][m[i].a + 1] && !hexpc[m[i].b][m[i].a + 1] && !hexp[m[i].b][m[i].a + 1])
            fl = playcheck(i, c);
        else
        {
            cout << "Invalid Move.Please Try Again.\n";
            continue;
        }
        if (fl)
            break;
        system("cls");
        disp();
        iai(i, c);
        if(c=='B' || c=='b')
            fl = ctowin(i, 'R');
        else
            fl = ctowin(i, 'B');
        if (fl)
            break;
        i++;
        previous(i, c);

    }
    return 0;
}
