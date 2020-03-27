import java.util.ArrayList;

public class returntype
{

    
    public static String removehi(String str)
    {

         if(str.length()==0)
{
    return " ";
}
        char ch = str.charAt(0);
            if(str.length()>1&& str.charAt(0)=='h'&& str.charAt(1)=='i')
        return removehi(str.substring(2));

        else
        return ch+removehi(str.substring(1));
    }
    public static  String removehiwithouthit(String str)
    {  if(str.length()==0)
    {
        return " ";
    }
        
         char ch=str.charAt(0);
        if(str.length()>2&&str.charAt(0)=='h'&&str.charAt(1)=='i'&&str.charAt(2)=='t')
        return "hit"+removehiwithouthit(str.substring(3));
        else if(str.length()>1&&str.charAt(0)=='h'&&str.charAt(1)=='i')
        return removehiwithouthit(str.substring(2));
        else
        return ch+removehiwithouthit(str.substring(1));
    }
    public static String seq(String str)
    {  if(str.length()==0)
    {
        return " ";
    }
        char ch=str.charAt(0);
        if(str.length()>1&&ch==str.charAt(1))
        return seq(str.substring(1));
        else
        return ch+seq(str.substring(1));
    }
    public static ArrayList <String>subseq(String str)
    {
        if(str.length()==0)
        {
            ArrayList<String>base=new ArrayList<>();
            base.add(" ");
            return base;

        }
        char ch=str.charAt(0);
         String ros=str.substring(1);
        ArrayList<String>smallans=subseq(ros);
        ArrayList<String>myans=new ArrayList<>();
        myans.addAll(smallans);
        for(String s:smallans)
        {
            myans.add(ch+s);
        }
        return myans;

    }

    public static ArrayList <String>mazepath_D(int sr,int sc,int ec,int er)
    {   if(sr==er&&sc==ec)
    {
        ArrayList<String> base=new ArrayList<>();
        base.add(" ");
        return base;

    }
        
        ArrayList<String>myans=new ArrayList<>();
        if(sc+1<=ec)
       { ArrayList<String> horizontal=mazepath_D(sr,sc+1,er,ec);
         for(String s:horizontal){
             myans.add("h"+s);
         }
       }

         if(sr+1<=er)
       { ArrayList<String> vertical=mazepath_D(sr+1,sc,er,ec);
         for(String s:vertical){
             myans.add("v"+s);
         }
       }
         if(sc+1<=ec&&sr+1<=er)
       { ArrayList<String> diagonal=mazepath_D(sr,sc+1,er,ec);
         for(String s:diagonal)
         {
             myans.add("d"+s);
         }

         
       
    }
    return myans;
       }

       public static int mazeheight(int sr,int sc,int er,int ec)
       { if(sr==er&&sc==ec)
       {
           return 0;
       }
            int hori=0;
       int verti=0;
       int diagonal=0;
           if(sc+1<=ec)
           {
             hori=mazeheight(sr,sc+1,er,ec);
           }

           if(sr+1<=er)
           {
             hori=mazeheight(sr+1,sc,er,ec);
           }

           if(sc+1<=ec&&sr+1<=er)
           {
             hori=mazeheight(sr+1,sc+1,er,ec);
           }
           int ans=Math.max(hori,Math.max(verti,diagonal));
           return ans+1;
       }
   
   
    public static ArrayList<String> multimove(int sr,int sc,int er,int ec)
    {   if(sr==er&&sc==ec)
    {
        ArrayList<String>base=new ArrayList<>();
        base.add("");
        return base;
    }
        
        ArrayList<String>myans=new ArrayList<>();
        for(int jump=1;sc+jump<=ec;jump++)
        {ArrayList<String>horizontal=multimove(sr,sc+jump,er,ec);
          for(String s:horizontal)
          {
              myans.add("h"+jump+s);
          }
        }


        for(int jump=1;sr+jump<=er;jump++)
        {ArrayList<String>vertical=multimove(sr+jump,sc,er,ec);
          for(String s:vertical)
          {
              myans.add("v"+jump+s);
          }
        }

        for(int jump=1;sc+jump<=ec&&sr+jump<=er;jump++)
        {ArrayList<String>diagonal=multimove(sr+jump,sc+jump,er,ec);
          for(String s:diagonal)
          {
              myans.add("d"+jump+s);
          }
        }

        return myans;
    }

   public static ArrayList<String> permutation(String str)
    {  if(str.length()==1)
    {
        ArrayList<String>base=new ArrayList<>();
        base.add(str);
        return base;
    }
        
        char ch= str.charAt(0);
        ArrayList<String>smallans= permutation(str.substring(1));
        ArrayList<String>myans=new ArrayList<>();
        for(String s:smallans)
        for(int i=0;i<=s.length();i++)
        {
           myans.add(s.substring(0,i)+ ch+s.substring(i));
        }

        return myans;
    }

    public static boolean isafe(int x,int y,int er ,int ec,boolean[][]board)
    {
        if(x<0||y<0||x>=er||y>=ec||board[0][0]==true)return false;
        return true;
    }
     direction[][]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
     String[]dir={"R","1","u","2","l","3","d","4"};
    public static int floodfill(int sr,int sc,int er,int ec,boolean[][]board)
    {
        board[sr][sc]=true;
        
        for(int i=0;i<dir.length();i++)
        {int x=sc+direction[i][0];
        int y=sr+direction[i][1];
       if(issafe(x,y,er,ec,board))
       
        }

    }
     public static void solve()
    {
       //System.out.print(removehi("hihihhihhhhiijj"));
       //System.out.print(removehiwithouthit("hithihihihhtitjjh"));
        //System.out.print(seq("aabbcccddfg"));
        // ArrayList<String>ans=subseq("abcd");
        // for(String s:ans)
        // {
        //     System.out.print(s+" ");
        // }
        // ArrayList<String>ans=mazepath_D(0,0,2,2);
        // for(String s:ans)
        // {
        //     System.out.print(s+" ");
        // }
       // System.out.print(mazeheight(0,0,2,2));
    //    ArrayList<String>ans=multimove(0,0,2,2);
    //    for(String s:ans)
    //    {
    //        System.out.print(s+" ");
    //    }
    ArrayList<String> ans=permutation("abcd");
    for(String s:ans)
    {
        System.out.print(s+" ");
    }

    }
    public static void basic()
    {
        solve();
    }
    public static void main(String args[])
    {
        basic();
    }
}