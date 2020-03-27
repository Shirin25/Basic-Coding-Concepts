#include<iostream>
#include<string>
#include<vector>
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
using namespace std;
vector<string>words={"_","+-/","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","*()%","#@$"};
     


int subseq(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    count+=subseq(str.substr(1),ans);
    count+=subseq(str.substr(1),ans+str[0]);

    return count;
}


int keypad(string ques,string ans)
{
    if(ques.length()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int idx1=ques[0]-'0';
      string word=words[idx1];

    int count=0;
    for(int i=0;i<word.length();i++)
    {
        count+=keypad(ques.substr(1),ans+word[i]);
    }


    if(ques.length()>=2)
    {
        int idx=idx1*10+(ques[1]-'0');
        if(idx>=10&&idx<=11)
        {
            word=words[idx];

            for(int i=0;i<word.length();i++)
            {
                count+=keypad(ques.substr(2),ans+word[i]);
            }
        }

    }
    return count;

    

}
int permutation(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return 1;

    }
     
     int count=0;
    for(int i=0;i<str.length();i++)
    {
       string ques=str.substr(0,i)+str.substr(i+1);
    

    count+=permutation(ques,ans+str[i]);
    }

    return count;
}

int permutation2(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    int arr=0;
    

     for(int i=0;i<str.length();i++)
     {  
         int mask=1<<(str[i]-'a');
    
         if((arr&mask)==0)
         {
             arr|=mask;
             string nstr=str.substr(0,i)+str.substr(i+1);
             count+=permutation2(nstr,ans+str[i]);
         }
         
     }
     return count;
}

int permutationinfi(vector<int> &arr,int target,string ans)
{
    if(target==0)
    {
        cout<<ans<<endl;
        return 1;

    }

    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        if(target-arr[i]>=0)
        {
            count+= permutationinfi(arr,target-arr[i],ans+to_string(arr[i]));
        }
    }
    return count;
}

int combinationiwithoutrepe(vector<int> &arr,int idx,int target,string ans)
{
    if(target==0)
    {
        cout<<ans<<endl;
        return 1;

    }

    int count=0;
    
    for(int i=idx;i<arr.size();i++)
    {   
        if(target-arr[i]>=0)
        {   
            count+=combinationiwithoutrepe(arr,i+1,target-arr[i],ans+to_string(arr[i]));
        }
    }
    return count;
}
int combinationinfi(vector<int> &arr,int idx,int target,string ans)
{
    if(target==0)
    {
        cout<<ans<<endl;
        return 1;

    }

    int count=0;
    
    for(int i=idx;i<arr.size();i++)
    {   
        if(target-arr[i]>=0)
        {   
            count+= combinationinfi(arr,i,target-arr[i],ans+to_string(arr[i]));
        }
    }
    return count;
}
int permutationwithoutrepe(vector<int> &arr,vector<bool> vis,int target,string ans)
{
    if(target==0)
    {
       cout<<ans<<endl;
       return 1;
    }
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        
        if(target-arr[i]>=0 && !vis[i])
        {     vis[i]=true;
            count+=permutationwithoutrepe(arr,vis, target-arr[i], ans+to_string(arr[i])+"");
            vis[i]=false;
        }
    }
    return count;
}

int combiinfisubseq(vector<int> &arr,vector<bool> vis,int idx,int target,string ans)
{
    if(target==0||idx==arr.size())
    {  if(target==0)
       {cout<<ans<<endl;
        return 1;
       }
       return 0;
    }

    int count=0;
   if(!vis[idx]&& target-arr[idx]>=0)
   {  vis[idx]=true;

   
        count+=combiinfisubseq(arr, vis,idx+1, target-arr[idx], ans+to_string(arr[idx]));
         

    }
    return count ;
}

int subset(vector<int> &arr,int idx,string ans)
{
    cout<<ans<<endl;
    if(idx==arr.size())
    {
        return 1;
    }

    int count=0;

    for(int i=idx;i<arr.size();i++)
    {
        count+=subset(arr,i+1,ans+to_string(arr[i])+" ");
    }

    return count;
}


void combipermu()
{
     vector<int> arr={2,3,5,7};
    int target=10;
    vector<bool> vis(arr.size(),false);

    //cout<<permutationinfi(arr,target,"");
  //cout<< combinationinfi(arr,0, target, "");
 // cout<<permutationwithoutrepe(arr,vis,target,"");
 // cout<<combiinfisubseq(arr,vis, 0, target, "");doubt
 //cout<<subset(arr,0,"");

}

int queencombi(int box,int lqpl,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    for(int i=lqpl;i<box;i++)
    {
        count+=queencombi(box,i+1,qpsf+1,tnq,ans+"b"+to_string(i)+"q"+to_string(qpsf));
    }
    return count;
}

int queenpermu(vector<bool> &box,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    for(int i=0;i<box.size();i++)
    {
        if(!box[i])
        {
            box[i]=true;
            count+=queenpermu(box,qpsf+1,tnq,ans+"b"+ to_string(i)+"q"+to_string(qpsf));
            box[i]=false;
        }
    }
    return count;
}
int queencombisubseq(int box,int lqpl,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq|| lqpl==box)
    {

        if(qpsf==tnq)
        {cout<<ans<<endl;
        return 1;
        }
        return 0;
    }
    int count=0;

    
       count+=queencombisubseq(box,lqpl+1,qpsf+1,tnq,ans+"b"+to_string(lqpl)+"q"+to_string(qpsf)+"");
       count+=queencombisubseq(box,lqpl+1,qpsf,tnq,ans);
    
    return count;
}
int queenpermusubseq(vector<bool> &box,int lqpl,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq|| lqpl==box.size())
    {  if(qpsf==tnq){
        {cout<<ans<<endl;
        return 1;}
    }
    return 0;
    }
    int count=0;
      if(!box[lqpl])
        {   box[lqpl]=true;
            count+=queenpermusubseq(box,0,qpsf+1,tnq,ans+"b"+to_string(lqpl)+"q"+to_string(qpsf)+"");
             box[lqpl]=false;
        }
        count+=queenpermusubseq(box,lqpl+1,qpsf,tnq,ans);
    
    return count;
}

int queen2dcombi(vector<vector<bool>> &board,int lqpl,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=lqpl;i<board.size()*board[0].size();i++)
    {
        int x=lqpl/board[0].size();
        int y=lqpl%board[0].size();

        count+=queen2dcombi(board,i+1,qpsf+1,tnq,ans+"("+to_string(x)+","+to_string(y)+")");
        
    }
    return count;
}

int queen2dpermu(vector<vector<bool>>&board,int lqpl,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<board.size()*board[0].size();i++)
    {
        int x=lqpl/board[0].size();
        int y=lqpl%board[0].size();
        if(!board[x][y])
        {
           board[x][y]=true;
           count+=queen2dpermu(board,i,qpsf+1,tnq,ans+"("+to_string(x)+","+to_string(y)+")");
           board[x][y]=false;
        }
        
    }
    return count;

    
    
}

bool isSafeToPlacQueen(vector<vector<bool>> & board,int x,int y)
{
    vector<vector<int>> dir={{-1,0},{0,-1} ,{-1,-1},{-1,1},
                             {1,0},{0,1} ,{1,1},{1,-1}};
    for(int i=0;i<dir.size();i++){
        for(int rad=1;rad<max(board.size(),board[0].size());rad++){
            int nx=x+ rad*dir[i][0];
            int ny=y+ rad*dir[i][1];
            if(nx<0 || ny<0 || nx>=board.size() || ny>=board[0].size()) break;
            if(board[nx][ny]) return false;
        }
    }
    return true;
}
int calls=0;
int queen2DCombisafe(vector<vector<bool>> &board, int lqpl, int tnq, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    calls++;
    for (int i = lqpl; i < board[0].size() * board.size(); i++)
    {
        int x = i / board[0].size();
        int y = i % board[0].size();

        if (isSafeToPlacQueen(board, x, y))
        {
            board[x][y] = true;
            count += queen2DCombisafe(board, i + 1, tnq - 1,
                                  ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            board[x][y] = false;
        }
    }
    return count;
}

int queen2DPermusafe(vector<vector<bool>> &board, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < board.size() * board[0].size(); i++)
    {
        int x = i / board[0].size();
        int y = i % board[0].size();
        if (!board[x][y] && isSafeToPlacQueen(board, x, y))
        {
            board[x][y] = true;
            count += queen2DPermusafe(board, qpsf + 1, tnq,
                                  ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            board[x][y] = false;
        }
    }
    return count;
}


int queen( int r,int tnq,vb &col,vb &diag,vb &adiag, string ans){
    int n=col.size();
if(r==n || tnq==0){
    if ( tnq==0)
    {
        cout << ans << endl;
        return 1;
    }
    return 0;
}
int count=0;
calls++;
for(int c=0;c<n;c++){
     if (!col[c]&&!diag[r+c]&&!adiag[r-c+n-1])
        {
           col[c]=true;
           diag[r+c]=true;
           adiag[r-c+n-1]=true;
           count+=queen(r+1,tnq-1,col,diag,adiag,ans + "(" + to_string(r) + ", " + to_string(c) + ") ");
           col[c]=false;
           diag[r+c]=false;
           adiag[r-c+n-1]=false;
        }

}

return count;
}

int queen2( int n,int r,int tnq,int &col,int &diag,int &adiag, string ans){
   
if(r==n || tnq==0){
    if ( tnq==0)
    {
        cout << ans << endl;
        return 1;
    }
    // cout << tnq;
    return 0;
}
int count=0;
calls++;
for(int c=0;c<n;c++){
    int w=1<<(c);
    int x=1<<(r+c);
    int y=1<<(r-c+n-1);
     if (!(col&w)&&!(diag&x)&&!(adiag&y))
        {
           col^=w;
           diag^=x;
           adiag^=y;
           count+=queen2(n,r+1,tnq-1,col,diag,adiag,ans + "(" + to_string(r) + ", " + to_string(c) + ") ");
           col^=w;
           diag^=x;
           adiag^=y;
        }

}

return count;
}



void queens()
{
    //vector<bool> box(5,false);
    vector<vector<bool>>board(4,vector<bool>(4,false));
   //cout<<queencombi(5,0,0,3,"")<<endl;
   // cout<<queenpermu(box,0,3,"")<<endl;
   //cout<<queencombisubseq(5,0,0,3,"")<<endl;
   //cout<<queenpermusubseq(box,0,0,3,"")<<endl;
   //cout<<queen2dcombi(board,0,0,4,"");
   //cout<<queen2dpermu(board,0,0,4,"");
  // cout << queen2DCombisafe(board, 0, 10, "") << endl;
     //cout << queen2DPermusafe(board, 0, 4, "") << endl;
      int r=4,c=4;
    //   vb col(4,false);
    //   vb diag(r+c-1,false);
    //   vb adiag(r+c-1,false);
    //   cout<<queen(0,r,col,diag,adiag,"");
    int col=0;
    int diag=0;
    int adiag=0;
    cout<<queen2(c,0,r,col,diag,adiag,"");
    //cout<<calls<<endl;
}
void basicques()
{
   // cout<<subseq("abc","")<<endl;
      //cout<<keypad("1011","")<<endl;
     //cout<<permutation("abc","")<<endl;
    cout<<permutation2("abc","")<<endl;
    //combipermu();
    //queens();
}
void display(vvi &board)
{
    for (vi ar : board)
    {
        for (int ele : ar)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
}
vi row(9, 0);
vi col(9, 0);
vvi mat(3, vi(3, 0));

int sudoku_01(vvi &board, vi &calls, int idx)
{
    if (idx == calls.size())
    {
        display(board);
        return 1;
    }

    int x = calls[idx] / 9;
    int y = calls[idx] % 9;
    int count = 0;
    for (int num = 1; num <= 9; num++)
    {
        int mask = 1 << num;
        if (!(row[x] & mask) && !(col[y] & mask) && !(mat[x / 3][y / 3] & mask))
        {
            board[x][y] = num;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x / 3][y / 3] ^= mask;

            count += sudoku_01(board, calls, idx + 1);

            board[x][y] = 0;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x / 3][y / 3] ^= mask;
        }
    }
    return count;
}

void sudoku()
{
    vvi board = {{0, 0, 6, 0, 0, 8, 0, 0, 0},
                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    vi calls;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
                calls.push_back(i * 9 + j);
            else
            {
                int mask = 1 << board[i][j];
                row[i] |= mask;
                col[j] |= mask;
                mat[i / 3][j / 3] |= mask;
            }
        }
    }
    cout << sudoku_01(board, calls, 0) << endl;
}

vector<vector<char>> board = {
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

bool isSafePWH(int x, int y, string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x][y + i] != '-' && board[x][y + i] != word[i])
            return false;
    }
    return true;
}

vb PWH(int x, int y, string word)
{
    vb loc(word.size(), false);
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x][y] == '-')
        {
            loc[i] = true;
            board[x][y + i] = word[i];
        }
    }
}

void UnPWH(int x, int y, vb &loc)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if (loc[i])
        {
            board[x][y + i] = '-';
        }
    }
}

bool isSafePWV(int x, int y, string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x + i][y] != '-' && board[x + i][y] != word[i])
            return false;
    }
    return true;
}

vb PWV(int x, int y, string word)
{
    vb loc(word.size(), false);
    for (int i = 0; i < word.size(); i++)
    {
        if (board[x][y] == '-')
        {
            loc[i] = true;
            board[x + i][y] = word[i];
        }
    }
}

void UnPWV(int x, int y, vb &loc)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if (loc[i])
        {
            board[x + i][y] = '-';
        }
    }
}

int crossWord(vector<string> &arr, int idx)
{
    if (idx == arr.size())
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return 1;
    }

    string word = arr[idx];
    int count = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '-' || board[i][j] == word[0])
            {
                if (isSafePWH(i, j, word))
                {
                    vb loc = PWH(i, j, word);
                    count += crossWord(arr, idx + 1);
                    UnPWH(i, j, loc);
                }

                if (isSafePWV(i, j, word))
                {
                    vb loc = PWV(i, j, word);
                    count += crossWord(arr, idx + 1);
                    UnPWV(i, j, loc);
                }
            }
        }
        return count;
    }
}

void crossW()
{
    vector<string> words = {"agra", "norway", "england", "gwalior"};
    cout << crossWord(words, 0) << endl;
}


void solve()
{
    basicques();
}

int main(int args,char** argv)
{
    solve();
}