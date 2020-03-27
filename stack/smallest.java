import java.util.ArrayList;
public class smallest{
    static ArrayList<Integer> arr=new ArrayList<>();
    static boolean is_max;

    static void  priorityQueue(int[]arr1){
        
        for(int i=0;i<arr1.length;i++)
        {
            arr.add(arr1[i]);
        }
        for(int i=arr.size()-1;i>=0;i--)
        {
                downheapify(i,arr.size()-1);//har ek node pe jaake hop ko satisfy kar rha hai.

        }


        }

    

    public static void downheapify(int idx,int n)
    {
      int maxidx=idx;
      int lci=(2*idx)+1;
      int rci=(2*idx)+2;

      if(lci<n&&compare((int)arr.get(lci),(int)arr.get(maxidx))>0)
      maxidx=lci;

      if(rci<n&&compare((int)arr.get(rci),(int)arr.get(maxidx))>0)
      maxidx=rci;

      if(maxidx!=idx)
      {
          swap(maxidx,idx);
          downheapify(maxidx,n);
      }
    }

    public static void  swap(int x,int y)
    {
        Integer val1=arr.get(x);
        Integer val2=arr.get(y);
        arr.set(x,val2);
        arr.set(y,val1);

    }

    public static int compare(int val1,int val2)
    {
       if(is_max)
       return val1-val2;

       else
       return val2-val1;
    }


    public static void main(String[] args)
    {
        int brr[]={3,-2,7,8,9,-1,-3};
        is_max=true;
        priorityQueue(brr);
        int k=3;

        for(int i=0;i<k;i++)
        {
            swap(0,arr.size()-i-1);
            downheapify(0,arr.size()-i-1);
        }
       
        System.out.println(arr.get(k-1));
    }
}