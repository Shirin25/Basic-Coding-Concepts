import java.util.Scanner;
import java.util.Stack;

public class class3{
    public static void main(String[] args)
    {
       // int arr[]={1,3,2,4,8,6,5,9,1};
        int arr1[]={6,2,5,4,5,1,6};
        char arr[][]={{'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','0','1','0'}
        };
        //System.out.println(Darray(arr));
        int arr2[]={6,10,2,5,6,-1,8,7,2,4};

        //greateronleft(arr);
        //greateronright(arr);
        //smalleronleft(arr);
        //smalleronright(arr);
        //histogram(arr1);
    }

    public static void greateronleft(int[] arr)
    {
       Stack<Integer> st=new Stack<>();
        for(int i=0;i<arr.length;i++)
        {
            
           
           
           

           while(st.size()!=0&&arr[i]>=st.peek())
           {
               st.pop();
               
               
           }
           if(st.size()==0)
           System.out.println(arr[i]+"->"+"-1");
           else
           System.out.println(arr[i]+"->"+st.peek());
           st.push(arr[i]);

        }
        
        

    }

    public static void greateronright(int[] arr)
    {
         Stack<Integer> st=new Stack<>();
        for(int i=arr.length-1;i>=0;i--)
        {
            while(st.size()!=0&&arr[i]>=st.peek())
            {
                st.pop();
            }

            if(st.size()==arr.length-1||st.size()==0)
            {
                System.out.println(arr[i]+"->"+"-1");
            }

            else 
            {
                System.out.println(arr[i]+"->"+st.peek());
                
            }
            st.push(arr[i]);
        }
    }

    public static void smalleronleft(int[] arr)
    {
         Stack<Integer> st=new Stack<>();

         for(int i=0;i<arr.length;i++)
         {
             while(st.size()!=0&&arr[i]<=st.peek())
             {
                 st.pop();
             }

             if(st.size()==0)
             {
                 System.out.println(arr[i]+"->"+"-1");
             }
             else
             System.out.println(arr[i]+"->"+st.peek());
             st.push(arr[i]);
         }
    }

    public static void smalleronright(int[] arr)
    {
         Stack<Integer> st=new Stack<>();
        for(int i=arr.length-1;i>=0;i--)
        {
            while(st.size()!=0&&arr[i]<=st.peek())
            {
                st.pop();
            }

            if(st.size()==arr.length-1||st.size()==0)
            {
                System.out.println(arr[i]+"->"+"-1");
            }
            else
            System.out.println(arr[i]+"->"+st.peek());
            st.push(arr[i]);
        }
    }


    public static int histogram(int[] arr1)
    {
         Stack<Integer> st=new Stack<>();
        
             int maxarea=0;
             
             int i=0;
             for (i=0;i<arr1.length;i++)
             {
                 if(st.size()==0||arr1[st.peek()]<=arr1[i])
                 {
                     st.push(i);
                 }

                 else
                 while(st.size()!=0&&arr1[st.peek()]>=arr1[i])
                 {
                     int idx=st.pop();
                     int he=arr1[idx];
                     int width=i-(st.size()==0?-1:st.peek())-1;
                     int currentarea=he*width;

                     maxarea=Math.max(maxarea,currentarea);
                 }
                 st.push(i);
             }

             while(st.size()!=0)
             {
                 int idx=st.pop();
                     int he=arr1[idx];
                     int width=i-(st.size()==0?-1:st.peek())-1;
                     int currentarea=he*width;

                     maxarea=Math.max(maxarea,currentarea);

             }

             //System.out.println(maxarea);
             return maxarea;

             

        
    }

    public static int Darray(char[][] arr)
    {   
        if(arr.length==0)
        return 0;
        int[] ar=new int[arr[0].length];
        int max_=0;
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[0].length;j++)
            {
                ar[j]=arr[i][j]=='0'?0:ar[j]+1;
            }
            max_=Math.max(max_,histogram(ar));
        }
        return max_;
    }

    public static class minstack
    {
        Stack<Integer> st=new Stack<>();

        int Minsf=0;

        public void push(int val)
        {
            if(st.size()==0)
            {
                st.push(val);
                Minsf=val;
                return;
            }
            else if(Minsf<val)
            {
                st.push(val);
            }
            else
            {
                st.push(2*val-Minsf);
                Minsf=val;
            }
        }

        public int pop()
        {
            if(st.size()==0)
            return 0;

            else if(st.peek()<val)
            {
                int actualvalue=Minsf;
                int recoveredvalue=2*Minsf-st.pop();
                Minsf=recoveredvalue;
                return actualvalue;
            }
            else
            {
                return st.pop();
            }
            
        }
        public int top()
        {
          if(st.size()==0)
          return -1;

          else if(st.peek()<Minsf)
          return Minsf;

          else
          return st.peek();
        }
        public int getMin()
        {
            if(st.size()==0)
            return -1;
            return Minsf;
        }
    }
}
