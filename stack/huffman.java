import java.util.Arrays;
import java.util.HashMap;
import java.util.PriorityQueue;
class huffman
{
    static HashMap<String,String> encode=new HashMap<>();
    static HashMap<String,String> decode=new HashMap<>();
  static class Node implements Comparable<Node>{
      String str;
      int frq;
      Node left;
      Node right;

      Node(String str,int frq,Node left,Node right)
      {
          this.str=str;
          this.frq=frq;
          this.left=left;
          this.right=right;
      }
      Node()
      {

      }
      public int compareTo(Node o)
    {
        return this.frq=o.frq;
    }
  }


  static void huffman_travel(Node root,String str)
  {
      if(root.left==null&&root.right==null)
  { encode.put(root.str,str);
  decode.put(str,root.str);
      return;
  }


  
     
     
      huffman_travel(root.left,str+"0");
      huffman_travel(root.right,str+"1");
  }

  static String encode(String str)
  {  StringBuilder ans=new StringBuilder();
     for(int i=0;i<str.length();i++)
     {
         String ch=str.charAt(i)+"";
     

     if(encode.containsKey(ch))
     {
         String res=encode.get(ch);
         ans.append(res);
     }

     }

     return ans.toString();
  }

  static String decode(String str)
  {
      StringBuilder ans=new StringBuilder();
      int i=0;
      for(int j=1;j<=str.length();j++)
      {
          String sub=str.substring(i,j);
          if(decode.containsKey(sub))
          {
              ans.append(decode.get(sub));
              i=j;
          }
      }
      return ans.toString();
  }
  static void huffman_tree(int[] arr)
  {
      PriorityQueue<Node> pq=new PriorityQueue<>();

      for(int i=0;i<arr.length;i++)
      {
          if(arr[i]>0)
          {
              String st=(char)(i+'a')+"";
              Node node=new Node(st,arr[i],null,null);
              pq.add(node);
          }
      }

      while(pq.size()!=1)
      {
          Node one=pq.remove();
          Node two=pq.remove();
          Node node=new Node(one.str+two.str,one.frq+two.frq,one,two);

          pq.add(node);
      }
      huffman_travel(pq.remove(),"");
      System.out.println(encode.toString());
       System.out.println("=============================");
      System.out.println(decode.toString());


       String encoded=encode("aaabcaddeafbccfff");
          String decoded=decode(encoded);
          System.out.println(decoded);
  }

    static void run(String str)
    {
        int[] arr=new int[26];
        for(int i=0;i<str.length();i++)
        {
            char ch=str.charAt(i);
            arr[ch-'a']++;
        }
       // System.out.println(Arrays.toString(arr));
       huffman_tree(arr);
    }
    
  
    public static void main(String[] args)
    {
         String str="aaabcaddeafbccfff";
         run(str);
    }
  
}