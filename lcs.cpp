

#include<bits/stdc++.h>
using namespace std;

void LCS(string x,string y,int xx,int yy){
        int xy[xx+1][yy+1];

        for(int i=0;i<=xx;i++){
            for(int j =0;j<=yy;j++){
                if(i == 0||j==0)
                    xy[i][j] =0;
                else if(x[i-1] == y[j-1])
                    xy[i][j] = xy[i-1][j-1] +1;
                 else
                    xy[i][j] = max(xy[i-1][j],xy[i][j-1]);
            }
        }

        int index = xy[xx][yy];
        char final[index+1];
        final[index] = '\0';


        int i =xx,j= yy;
        while(i>0&&j>0){
            if(x[i-1] == y[j-1])
            {
                final[index-1] = x[i-1];
                i--;j--;index--;
            }else if(xy[i-1][j]> xy[i][j-1])
                i--;
            else
                j--;
        }

        cout << final << endl;
}


int main()
{

    string x,y;
     cin >> x>> y;
     LCS(x,y,x.size(),y.size());


    return 0;
}
