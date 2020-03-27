import java.util.ArrayList;
public class heap{
    public static void main(String[] args)
    {
        int[] arr = { 10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13 };
        priorityQueue pq = new priorityQueue(arr, false);

        
        while (pq.size() != 0) 
        {
            System.out.print(pq.remove() + " ");
        }
    }
        public static class priorityQueue
        { 
            ArrayList<Integer>arr=new ArrayList<>();
            boolean is_max;
        
        priorityQueue(boolean ismax){
            this.is_max=ismax;
        }
        priorityQueue(int[]arr1,boolean ismax){
        this.is_max=ismax;
        for(int i=0;i<arr1.length;i++)
        {
            arr.add(arr1[i]);
        }
        for(int i=arr.size()-1;i>=0;i--)
        {
                downheapify(i,arr.size()-1);//har ek node pe jaake hop ko satisfy kar rha hai.

        }


        }

        int size(){
            return arr.size();
        }
         public void upheapify(int ci)
        {
            int pi=(ci-1)/2;//(ci-1)>>1;
            if(pi>=0&&compare((int)arr.get(ci),(int)arr.get(pi))>0)
            {
               swap(ci,pi);
               upheapify(pi);
            }
        }

        public void downheapify(int idx,int n)
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
        public  void swap(int x,int y)
        {
            Integer val1=arr.get(x);//arraylist mein aise karna hota hai temp use nahi kar sakte hai.
            Integer val2=arr.get(y);
            arr.set(x,val2);
            arr.set(y,val1);
        }
        
        
    public int compare(int val1,int val2)
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

    public void add(int data)
    {
        arr.add(data);
        upheapify(arr.size()-1);
    }

    public int remove()//this is the top element.
       {
         swap(0,arr.size()-1);
         int remove_ele=arr.get(arr.size()-1);
         arr.remove(arr.size()-1);
         downheapify(0,arr.size()-1);

         return remove_ele;
       }

       public void update(int prev_val,int new_val)
       {
            int idx=-1;
            for(int i=0;i<arr.size()-1;i++)
            {
                if(arr.get(i)==prev_val)
                {
                    idx=i;
                    break;
                }
            }

            if(idx==-1)
            return;

            arr.set(idx,new_val);
            upheapify(idx);
            downheapify(idx,arr.size()-1);
       }
       public int top()
       {
           return arr.get(0);
       }
       
        }


}