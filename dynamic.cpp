#include<iostream>
#include<vector>
#include<string>
#define vi vector<int>
#define vii vector<vi>

using namespace std;


void display(vi &dp)
{
    for(int ele:dp)
    {
        cout<<ele<<" ";
    }

    cout<<endl;
}

void display2d(vii &dp)
{
    for(vi &ar:dp)
    {
        for(int &ele:ar)
        {
            cout<<ele<<" ";
            
        }
        cout<<endl;
    }
}
int fibo_01(int n)
{

    if(n<=1)
    {
        return n;
    }
    int ans=fibo_01(n-1)+fibo_01(n-2);
    return ans;
}

int fibo_02(int n,vi &dp)
{
    if(n<=1)
    {
        dp[n]=n;
        return n;
    }

    if(dp[n]!=0) return dp[n];//it will check if the ans is already there in the array or not.
    int ans=fibo_02(n-1,dp)+fibo_02(n-2,dp);
    dp[n]=ans;//dp will on and off

    return ans;
}

int fibo_03(int n,vi &dp)
{
    for(int i=0;i<=n;i++)
    {
        if(i<=1)
        {
            dp[i]=i;
            continue;
        }
    

    dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int mazepathHV_01(int sr,int sc,int er,int ec,vii &dp)
{
    if(sr==er && sc==ec)
    {
        return 1;
    }

    int count=0;

    if(sr+1<=er) count+=mazepathHV_01(sr+1,sc,er,ec,dp);
    if(sc+1<=ec) count+=mazepathHV_01(sr,sc+1,er,ec,dp);

    return count;

}

int mazepathHV_02(int sr,int sc,int er,int ec,vii &dp)
{
    if(sr==er && sc==ec)
    {
        return dp[sr][sc]=1;
        return 1;
    }

    int count=0;
    if(dp[sr][sc]!=0)
    return dp[sr][sc];

    if(er==ec && dp[sc][sr]!=0)//mirrror image property
    return dp[sc][sr];

    if(sr+1<=er) count+=mazepathHV_02(sr+1,sc,er,ec,dp);
    if(sc+1<=ec) count+=mazepathHV_02(sr,sc+1,er,ec,dp);

    dp[sr][sc]=count;
    if(er==ec)
    dp[sc][sr]=count;

    return count;

    
    
}

int mazepathHV_03(int er,int ec,vii &dp)
{  
    for(int sr=er;sr>=0;sr--)
    {
        for(int sc=ec;sc>=0;sc--)
        {
    if(sr==er && sc==ec)
    {
        dp[sr][sc]=1;
        continue;
    }

    int count=0;

    if(sr+1<=er) count+=dp[sr+1][sc];
    if(sc+1<=ec) count+=dp[sr][sc+1];
    dp[sr][sc]=count;
        }
    }

    return dp[0][0];

}
int mazepathD_01(int sr,int sc,int er,int ec,vii &dp)
{
    if(sr==er && sc==ec)
    {
        return 1;
    }

    int count=0;

    if(sr+1<=er) count+=mazepathD_01(sr+1,sc,er,ec,dp);
    if(sc+1<=ec) count+=mazepathD_01(sr,sc+1,er,ec,dp);
    if(sc+1<=ec &&sr+1<=er) count+=mazepathD_01(sr+1,sc+1,ec,er,dp);

    return count;

}

int mazepathD_02(int sr,int sc,int er,int ec,vii &dp)
{
    if(sr==er && sc==ec)
    { 
        dp[sr][sc]=1;
        return 1;
    }

    int count=0;
    if(dp[sr][sc]!=0) return dp[sr][sc];
    if(er==ec&& dp[sc][sr]!=0)  return dp[sc][sr];

    if(sr+1<=er) count+=mazepathD_01(sr+1,sc,er,ec,dp);
    if(sc+1<=ec) count+=mazepathD_01(sr,sc+1,er,ec,dp);
    if(sc+1<=ec &&sr+1<=er) count+=mazepathD_01(sr+1,sc+1,ec,er,dp);
    dp[sr][sc]=count;
    if(er==ec)
    dp[sc][sr]=count;


    return count;

}
int mazepathD_03(int er,int ec,vii &dp)
{
    for(int sr=er;sr>=0;sr--)
    {
        for(int sc=ec;sc>=0;sc--)
    {
        if(sr==er && sc==ec)
    {
        dp[sr][sc]=1;
        continue;
    }

    int count=0;

    if(sr+1<=er) count+=dp[sr+1][sc];
    if(sc+1<=ec) count+=dp[sr][sc+1];
    if(sc+1<=ec &&sr+1<=er) count+=dp[sr+1][sc+1];

    dp[sr][sc]=count;
    }
    }
    return dp[0][0];

}


int multimove_01(int sr,int sc, int er, int ec,vii &dp)
{
    if(sr==er && sc==ec)
    {
        return 1;
    }
    int count=0;
    for(int jump=1;jump+sr<=er;jump++)
    {
        count+=multimove_01(sr+jump,sc,er,ec,dp);
    }

    for(int jump=1;jump+sc<=ec;jump++)
    {
        count+=multimove_01(sr,sc+jump,er,ec,dp);
    }

    for(int jump=1;jump+sc<=ec&& jump+sr<=er;jump++)
    {
        count+=multimove_01(sr+jump,sc+jump,er,ec,dp);
    }

    return count;
}

int multimove_02(int sr,int sc, int er, int ec,vii &dp)
{
    if(sr==er && sc==ec)
    {
        dp[sr][sc]=1;
        return 1;
    }
    int count=0;
    if(dp[sr][sc]!=0) return dp[sr][sc];
    for(int jump=1;jump+sr<=er;jump++)
    {
        count+=multimove_02(sr+jump,sc,er,ec,dp);
    }

    for(int jump=1;jump+sc<=ec;jump++)
    {
        count+=multimove_02(sr,sc+jump,er,ec,dp);
    }

    for(int jump=1;jump+sc<=ec&& jump+sr<=er;jump++)
    {
        count+=multimove_02(sr+jump,sc+jump,er,ec,dp);
    }

    dp[sr][sc]=count;

    return count;
}

int multimove_03( int er, int ec,vii &dp)
{  for(int sr=er;sr>=0;sr--)
{
   for(int sc=ec;sc>=0;sc--)
   {
    if(sr==er && sc==ec)
    {
        dp[sr][sc]=1;
        continue;
    }
    int count=0;
    
    for(int jump=1;jump+sr<=er;jump++)
    {
        count+=dp[sr+jump][sc];
    }

    for(int jump=1;jump+sc<=ec;jump++)
    {
        count+=dp[sr][sc+jump];
    }

    for(int jump=1;jump+sc<=ec&& jump+sr<=er;jump++)
    {
        count+=dp[sr+jump][sc+jump];
    }

    dp[sr][sc]=count;

   }
}

    return dp[0][0];
}


int targetsum_01(int st, int end,vi &dp)
{
    if(st==end)
    {
       
        return 1;

    }

    int count=0;

    for(int i=1;i<=6;i++)
    {
        if(st+i<=end)
        count+=targetsum_01(st+i,end,dp);
    }

    return count;
}

int targetsum_02(int st, int end,vi &dp)
{
    if(st==end)
    {
       dp[st]=1;
        return 1;

    }

    int count=0;
     if(dp[st]!=0) return dp[st];
    for(int i=1;i<=6;i++)
    {
        if(st+i<=end)
        count+=targetsum_02(st+i,end,dp);
    }
    dp[st]=count;
    return count;
}
int targetsum_03(int stp, int end,vi &dp)
{for(int st=end;st>=stp;st--)
{
    if(st==end)
    {
       dp[st]=1;
        continue;

    }

    int count=0;
     
    for(int i=1;i<=6;i++)
    {
        if(st+i<=end)
        count+=dp[st+i];
    }
    dp[st]=count;
   
}
return dp[0];
}
int outcomes_01(int st, int end,vi &outcomes,vi &dp)
{
    if(st==end)
    {
       
        return 1;

    }

    int count=0;

    for(int i=0;i<=outcomes.size();i++)
    {
        if(st+outcomes[i]<=end)
        count+=outcomes_01(st+outcomes[i],end,outcomes,dp);
    }

    return count;
}

int outcomes_02(int st, int end,vi &outcomes,vi &dp)
{
    if(st==end)
    {
       dp[st]=1;
        return 1;

    }

    int count=0;
    if(dp[st]!=0) return dp[st];
    for(int i=0;i<=outcomes.size();i++)
    {
        if(st+outcomes[i]<=end)
        count+=outcomes_02(st+outcomes[i],end,outcomes,dp);
    }
   dp[st]=count;
    return count;
}

int outcomes_03(int stp, int end,vi &outcomes,vi &dp)
{  for(int st=end;st>=stp;st--)
{
    if(st==end)
    {
       dp[st]=1;
        continue;

    }

    int count=0;

    for(int i=0;i<=outcomes.size();i++)
    {
        if(st+outcomes[i]<=end)
        count+=dp[st+outcomes[i]];
    }
    dp[st]=count;
}
return dp[0];
    
}
//set02====================================
int climbStairs_01(int n) {

    if(n<=1)
    {
        return 1;
    }
    int ans=0;
    int a=1; int b=1;
    for(int i=2;i<=n;i++)
    {
        ans=a+b;
        a=b;
        b=ans;
    }

    return ans;
   
        
}
// int minCostClimbingStairs(vector<int>& cost)
// {
//     cost.push_back(0);
//     return minCostClimbingStairs_01(cost.size(),cost);
// }
int minCostClimbingStairs_01(int n,vector<int>& cost)
{  cost.push_back(0);
    if(n<=1)
    {
        return cost[n];
    }

    int c1=minCostClimbingStairs_01(n-1,cost);
    int c2=minCostClimbingStairs_01(n-2,cost);

    return cost[n]+min(c1,c2);
}

int minCostClimbingStairs_02(int n,vector<int>& cost,vi &dp)
{  cost.push_back(0);
    if(n<=1)
    {   dp[n]=cost[n];
        return cost[n];
    }
    if(dp[n]!=0) return dp[n];
    int c1=minCostClimbingStairs_02(n-1,cost,dp);
    int c2=minCostClimbingStairs_02(n-2,cost,dp);
    
    return dp[n]=cost[n]+min(c1,c2);
}
int minCostClimbingStairs_03(vector<int>& cost)
{ 
    cost.push_back(0);
     if(cost.size()==1) return cost[0];
   if(cost.size()==2) return min(cost[0],cost[1]);


   int a=cost[0];
   int b=cost[1];


   for(int i=2;i<cost.size();i++)
   {
       int ans=cost[i]+min(a,b);
       a=b;
       b=ans;
   }

   return min(a,b);
}
// int minPathSum_01(int sr,int sc,int er, int ec,vector<vector<int>>& grid)
// {
//     if(sr==er &&sc==ec)
//     {
//         return 0;
//     }
//  int c1,c2=0;
//     if(sr+1<=er)
//     {   c1+=grid[sr+1][sc];
//         minPathSum_01(sr+1,sc,er,ec,grid);
//     }

//     if(sc+1<=ec)
//     {    c2+=grid[sr][sc+1];
//         minPathSum_01(sr,sc+1,er,ec,grid);
//     }

//     return grid[sr][sc]+min(c1,c2);
// }




   
void set1()
{
    int n=3;
     vector<int> dp(n+1,0);
    cout<<fibo_01(n)<<endl;
    display(dp);

    // vii dp(n,vi (n,0));
    // cout<<multimove_03(n-1,n-1,dp)<<endl;
    // display2d(dp);
    //vi dice={1,2,3,4,5,6};
    vi outcomes={2,3,5,7};
    //cout<<targetsum_03(0,n,dp)<<endl;
    //cout<<outcomes_03(0,n,outcomes,dp)<<endl;
    //display(dp);
    //cout<<climbStairs_01(n)<<endl;
//    vi cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
//     //cout<<minCostClimbingStairs_03(cost)<<endl;
//    // display(dp);
//   vii grid= {
//   {1,3,1},
//   {1,5,1},
//   {4,2,1}
//   };
//    cout<<minPathSum_01(0,0,n-1,n-1,grid)<<endl;
   
    

}

void solve()
{
  set1();
}

int main()
{
    solve();
    return 0;
}
