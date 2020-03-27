public class sorting
{
    public static display(int[] arr)
    {
        for( int ele:arr)
        {
            System.out.print(ele+" ");
        }
        System.out.println();
    }

    public static swap(int[] arr,int i,int j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }


    public static void main(String[] args)
    {
        int[]arr={};
    }
}