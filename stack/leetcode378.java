impoort java.util.ArrayList;
public class leetcode378{
    ArrayList<Integer> arr=new ArrayList<>();
    static boolean is_max;
    public static int kth_smallest(int arr1[][]){
        for(int i=0;i<arr1.length;i++)
        {
            for(int j=0;j<arr1[0].length;j++)
            {
                arr.add(arr1[i][j]);
            }

        }
        for(int i=arr.size()-1;i>=0;i--)
        {
                downheapify(i,arr.size()-1);//har ek node pe jaake hop ko satisfy kar rha hai.

        }

         public static void downheapify(int idx,int n)
        {
            int maxidx=idx;
            int lci=(2*idx)+1;
            int rci=(2*idx)+2;
            if(lci<n&&compare((int)arr.get(lci),(int)arr.get(maxidx))>0)
            {
                maxidx=lci;
            }
            if(rci<n&&compare((int)arr.get(rci),(int)arr.get(maxidx))>0)
            {
                maxidx=rci;
            }
            if(maxidx!=idx)
           {
                swap(maxidx,idx);
                downheapify(maxidx,n);
           }
        }
        public static void swap(int x,int y)
        {
            Integer val1=arr.get(x);//arraylist mein aise karna hota hai temp use nahi kar sakte hai.
            Integer val2=arr.get(y);
            arr.set(x,val2);
            arr.set(y,val1);
        }
        
        
    public static int compare(int val1,int val2)
    {
        if(is_max)
        {
            return val1-val2;
        }
        else
        {
            return val2-val1;
        }
    }




        
    }

    public static void main(String[] args)
    {
    int matrix[][]={{1,5,9},{10,11,13},{12,13,15}}

    kth_smallest(matrix);
    for(int i=0;i<arr.size();i+=3)
    {
       
    }

    
    }

    
}