#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;//("abcdefgh");
    string b;//("abcxcdefgh");
    while(cin>>a>>b){
	
    short match[2111][2111];
    short incensive[2111][2111];
    for(int i = 0; i <= a.size(); i++)
    {
        match[i][0] = 0;
        incensive[i][0] = 0;
    }
    
    for(int i = 1; i <= a.size(); i++)
            for(int j = 1; j <= b.size(); j++)
            {
            	match[i][j] = max(match[i][j-1],match[i-1][j]);// 
                if(a[i-1]==b[j-1])
                {
                	incensive[i][j] = incensive[i-1][j-1] + 1;                                   
                    if(incensive[i][j] > 3)
                    	
                    		match[i][j] = max(match[i][j],max((short)(match[i-3][j-3]+3),(short)(match[i-1][j-1]+1)));
                    else if(incensive[i][j] == 3)
                    	match[i][j] = max(match[i][j],(short)(match[i-3][j-3]+3));
                }
                else
                {
                    incensive[i][j] = 0;
                    
                }
            }
   
    cout<<match[a.size()][b.size()]<<endl;
    //for(int i = 1 ; i <= a.size(); i++)
    //{
//	for(int j = 1; j <= b.size(); j++)
    //cout<<match[i][j]<<incensive[i][j]<<' ';
   // cout<<endl;//	}
	}
}
short max(short a,short b)
{
	if(a>b)return a;
    else return b;
}

