public class recursion
{
    public static int factorial(int n)
    {   if(n==1)
    {
        return 1 ;
    }
    

        // factorial(n-1);
        int ans=n*factorial(n-1);

       return(ans);
    }

    public static int power(int a, int b)
    {  
        if(b==0)
        {
            return 1;
        }
        // power(a,b-1);
        int ans=a*power(a,b-1);
        return ans;
    }
public static int optimisedpower(int a, int b)
    {  
        if(b==0)
        {
            return 1;
        }
        // power(a,b-1);
        int ans=power(a,b/2);
        ans*=ans;
        return (b%2!=0?a*ans:ans);
    }

    public static int fibonacci(int n)
    { if(n<=1)
    {
        return n;
    }

       int ans= fibonacci(n-1) + fibonacci(n-2);
        return (ans);
    }

public static void main( String args[])
{
    //System.out.print(factorial(5));
    //System.out.print(power(5,3));
    //System.out.print(optimisedpower(5,3));
    System.out.print(fibonacci(5));
}
}