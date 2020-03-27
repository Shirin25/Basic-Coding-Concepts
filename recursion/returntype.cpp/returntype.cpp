#include<iostream>
#include<string>
#include<vector>
using namespace std;
string removehi(string str)
{
    if (str.length()==0)
    return "";
    char ch=str[0];
if (str.length()>1&&str.substr(0,2)=="hi")
return removehi(str.substr(2));

else return ch+removehi(str.substr(1));
}
string removehiwithouthit(string str)
{
    if (str.length()==0)
    return"";
    char ch=str[0];
    if( str.length()>2&&str.substr(0,3)=="hit")
    return   "hit"+removehiwithouthit(str.substr(3));
    else if (str.length()>1&&str.substr(0,2)=="hi")
    return removehiwithouthit(str.substr(2));
    else return ch+removehiwithouthit(str.substr(1));
}
string abcdd(string str)
{   if (str.length()==0)
return"";

    char ch=str[0];
    if(str.length()>1&&ch==str[1])
    return abcdd(str.substr(1));
    else return ch+ abcdd(str.substr(1));
}
vector<string> subseq(string str)
{   
    if (str.length()==0) 
    {
        vector<string>base;
        base.push_back("");
        return base;
    }
    char ch=str[0];
    vector<string>smallans=subseq(str.substr(1));
    vector<string>myans(smallans);
    for(string s:smallans)
    {
        myans.push_back(ch+s);

    }
        return myans;
    }
    vector<string> mazePath_d(int sr,int sc,int er,int ec)
    {   if(sr==er&&sc==ec)
    {
        vector<string>base;
        base.push_back(" ");
        return base;
    }
        
        
        vector<string>myans;
        if(sc+1<=ec)
        {
            vector<string>horizontal=mazePath_d(sr,sc+1,er,ec);
            for(string s:horizontal)
            {
                myans.push_back("h"+s);

            }
        }
        if(sr+1<=er)
        {
            vector<string>vertical=mazePath_d(sr+1,sc,er,ec);
            for(string s:vertical)
            {
                myans.push_back("v"+s);
            }
        }
        if(sr+1<=er&&sc+1<=ec)
        {
            vector<string>diagonal=mazePath_d(sr+1,sc+1,er,ec);
            for(string s:diagonal)
            {
                myans.push_back("d"+s);
            }
        }
        return myans;
        
    }

    int  mazePath_d2(int sr,int sc,int er,int ec)
    {   if(sr==er&&sc==ec)
    {
       
        return 0;
    }
        
        
        int hori=0,verti=0,diag=0;
        if(sc+1<=ec)
        {
        hori=mazePath_d2(sr,sc+1,er,ec);
            
        }
        if(sr+1<=er)
        {
            verti=mazePath_d2(sr+1,sc,er,ec);
            
        }
        if(sr+1<=er&&sc+1<=ec)
        {
            diag=mazePath_d2(sr+1,sc+1,er,ec);
            
        }
        return max(hori,max(verti,diag))+1;
        
    }
    vector<string>multimove(int sr,int sc,int er,int ec)
    
    {   if(sr==er&&sc==ec)
    {
        vector<string>base;
        base.push_back(" ");
        return base;
    }
        
        
        vector<string>myans;
        for(int jump=1;sc+jump<=ec;jump++)
        {
            vector<string>horizontal=multimove(sr,sc+jump,er,ec);
            for(string s:horizontal)
            {
                myans.push_back("h"+to_string(jump)+s);

            }
        }
        for(int jump=1;sr+jump<=er;jump++)
        {
            vector<string>vertical=multimove(sr+jump,sc,er,ec);
            for(string s:vertical)
            {
                myans.push_back("v"+to_string(jump)+s);
            }
        }
        for(int jump=1;sr+jump<=er&&sc+jump<=ec;jump++)
        {
            vector<string>diagonal=multimove(sr+jump,sc+jump,er,ec);
            for(string s:diagonal)
            {
                myans.push_back("d"+to_string(jump)+s);
            }
        }
        return myans;
        
    }


    bool issafe(int x,int y,vector<vector<bool>>&board)
    {
        if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]==true)return false;
        return true;
    }
    // vector<int>bomb{{1,0},{2,1},{0,2}};
    // vector<string>bb{"b1","b2","b3","b4"}
    // bool ratsafe(int ,int y,int er,int ec,vector<vector<bool>>&board)
    // {
    //     if(x<0||y<0||x>ec||y>er||board[x][y]=true||board[x][y]==bomb[x][])
    //     return false;
    // }
    vector<vector<int>>direction={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
    vector<string>dir={"R","1","u","2","l","3","d","4"};
   int floodfill(int sr,int sc, int er,int ec,vector<vector<bool>>&board ,string ans)
    {  if(sr==er&&sc==ec)
    {
        cout<<ans<<endl;
        return 1;
    }
        int count =0;
        board[sr][sc]=true;
        for(int d=0;d<8;d++)
        {
            int x=sr+direction[d][0];
            int y=sc+direction[d][1];

            if(issafe(x,y,board))
            {
              count+=floodfill(x,y,er,ec,board,ans+dir[d]);
            }
            
        }
        board[sr][sc]=false;
        return count;

    }
    void floodfill()

    {
        vector<vector<bool>>board(3,vector<bool>(3,false));
        board[1][0]=true;
        board[2][1]=true;
        board[0][2]=true;
        cout<<floodfill(0,0,2,2,board,"");
    }

    vector<string> permutation(string str)
    {  if(str.length()==1)
    {
        vector<string>base;
        base.push_back(str);
        return base;
    }
        char ch=str[0];
        vector<string>smallans=permutation(str.substr(1));
        vector<string>myans;
        for(string s:smallans)
        {
            for(int i=0;i<=s.length();i++)
            {
                string st=s.substr(0,i) + ch + s.substr(i);
            myans.push_back(st);
            }
        }
        return myans;
    }

    vector<string>words={"_","+-/","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","*()%","#@$"};
     
    vector<string> keypad(string str)
    {   
        if(str.length()==0)
        {
            vector<string>base;
            base.push_back(" ");
            return base;
        }
        char ch=str[0];
        string word=words[ch-'0'];
        
        vector<string>ans=keypad(str.substr(1));
        vector<string>myans;
        for(string s:ans)
        {
            for(int i=0;i<word.length();i++)
            {
                myans.push_back(word[i]+s);
            }
        }
        if(str.length()>1&&ch!='0')
        {
            int num=(ch-'0')*10+(str[1]-'0');
            if(num<12)
            {
                string word2=words[num];
                vector<string>ans2=keypad(str.substr(2));
                for(string s:ans2)
        
        
        {
            for(int i=0;i<word2.length();i++)
                {
                myans.push_back(word2[i]+s);
            }
        }
            }
            return myans;
        }
        return myans;
    }

    vector<string> encoding(string str)
    {
        if(str.length()==0)
        {
            vector<string>base;
            base.push_back(" ");
            return base;
        }

        char ch=str[0];
        
        if(ch==0)
        {
            return encoding(str.substr(1));
        }

        vector<string> firstresult= encoding(str.substr(1));
        vector<string>myans;
        // char ch_=(char)(ch-'1'+'a');
       
        for(string s:firstresult)
        {
            myans.push_back(ch+s);
        }
        if(str.length()>1)
        {
            int num=(ch-'0')*10 + (str[1]-'0');
            if(num<= 26)
            {
                  //int num=ch-48;
                 char ch_= num +'a' -'1';
                vector<string>secondresult= encoding(str.substr(2));
                 for(string s:secondresult)
                    {
                        myans.push_back(ch_+s);
                    }


            }

        }

        return myans;
    }
void basic()
{
   // cout<<removehi("iihihiihihihihihhhhihii");
   //cout<<removehiwithouthit("hitiiiihihihihit");
  // cout<<abcdd("aaabbbbccddefg");
    //cout<<abcdd("gaabbbbccddefg");
    // vector<string>ans=subseq("abcd");
    // for(string s:ans)
    // cout<<s<<" ";
    // vector<string>ans=mazePath_d(0,0,3,3);
    // for(string s:ans)
    // {
    //     cout<<s<<" ";
    // }
    // }
    //cout<<mazePath_d2(0,0,3,3);
    // vector<string>ans=multimove(0,0,3,3);
    // for(string s:ans)
    // {
    //     cout<<s;
    //     cout<<endl;
    // }
//    floodfill();
//    vector<string>ans=permutation("abc");
//    for(string s:ans)
//    {
//        cout<<s<<" ";
//    }

// vector<string>recans=keypad("10811");
// for(string s:recans)
// {
//     cout<<s<<endl;
// }
vector<string>ans=encoding("1024");
for(string s:ans)
{
    cout<<s<<endl;
}
}

void solve()
{
    basic();
}
int main()
{
    solve();

}
