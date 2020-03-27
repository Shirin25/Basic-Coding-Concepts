public class Mystack{
    public static void main(String[] args)
    {
        solve();
    }
    public static void solve()
    {
        stack st=new stack();
        for(int i=0;i<10;i++)
        {
            st.push(i+10);
        }
        st.print();
    }

    public static class stack
    {
        private int[] st;
        private int idx=-1;
    
    stack()
    {
        this.st=new int [10];
    }
    stack(int size)
    {
        this.st=new int [size];
    }
    
    public void print()
    {
        System.out.print("[");
        for(int i=idx;i>0;i--)
        {
            
            System.out.print(st[i]+",");

        }
        System.out.print(st[0]+"]");
    }

    public int size()
    {
        return idx+1;
    }
    public boolean isEmpty()
    {
        return idx==-1;
    }
    public int top()
    {
        if(idx==-1)
        {
            System.out.println("stackisempty");
            return -1;
        }
        return st[idx];
    }

    public void push(int data)
    {
        if(this.idx==st.length)
        {
           System.err.println("stackisoverflow");
           return;
        }
        idx++;
        this.st[idx]=data;
    }
    public int pop()
    {
        if(this.idx==-1)
        {
          System.err.println("stackisempty");
          return -1;
        }

        int rv=this.st[idx];
        this.st[idx]=0;
        idx--;
        return rv;
    }

    }

}