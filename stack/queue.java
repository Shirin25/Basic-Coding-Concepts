public class queue{
    public static void main(String[] args)
    {
        solve();
    }

    public static void solve()
    {
        Myqueue arr=new Myqueue();//(object to call non static members of myqueue)
        for(int i=0;i<10;i++)
        {
            arr.push(i+10);
        }
        arr.print();
    }
    public  static class Myqueue{
        private int[] arr;
        private int st=0;
        private int end=0;
        private int size=0;

        Myqueue()
        {
            this.arr=new int[10];
        }
        Myqueue(int size)
        {
            this.arr=new int [size];
        }

        public int size()
        {
            return this.size;
        } 
        public boolean isempty()
        {
            return this.size==0;
        }
        public int front()
        {
            if(this.size==0)
            {
                System.out.print("queueisempty");
                return -1;
            }
            return arr[st];
        }
        public void push(int data)
        {
            if(this.size==this.arr.length)
            {
                System.out.println("queueisoverflow");
                return;
            }

            this.arr[this.end]=data;
            this.end=(this.end+1)%arr.length;
            this.size++;
        }
        public int pop()
        {
            if(this.size==0)
            {
                System.out.println("queueisempty");
                return -1;
            }

            int rv=this.arr[this.st];
            this.size--;
            this.st=(this.st+1)%arr.length;
            return rv;
        }

        public void print()
        {
            if(this.size==0)
        {
            System.out.print("queueisempty");
            return;
        }
            System.out.print("[");
            for(int i=0;i<this.size;i++)
            {
               int idx=(this.st+i)%arr.length;
                System.out.print(this.arr[idx]+",");
            }
            System.out.print("]");
        }
    }
}