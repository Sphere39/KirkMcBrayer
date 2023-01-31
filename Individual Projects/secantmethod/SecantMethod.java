/**
* This program computes the secant method to determine the zero of a function.
*
* CSC 2262 Programming project No 2
*
* @author Kirk McBrayer
* @since 9/24/2020
*
*/
package secantmethod;
import java.io.*;
import java.util.*;
public class SecantMethod 
{
    /**
* This method computes the function of the Secant Method.
*
* method: F
*
* return type: double
*
* parameters:
* x [double] the function point of the function.
*
*
* @author Kirk McBrayer
* @since 9/24/2020
*
*/
    public static double F(double x)
    {
        return Math.cos(x) - x;
    }
    /**
* This method computes the volume (in liters) of a pack of
* soda cans.
*
* method: SecantFunction
*
* return type: double
*
* parameters:
* n [double] the number of elements in the method.
*
*
* @author Kirk McBrayer
* @since 9/24/2020
*
*/
    public static double SecantFunction(int n)
    {
        double x_0 = 0.0; //is the first value of the interval.
        double x_1 = Math.PI/2; //is the second value of the interval.
        double x_n = 0.0; //is the function return value.
        System.out.printf("%10s%35.25f%35.25f\n","0",x_0,F(x_0));
        System.out.printf("%10s%35.25f%35.25f%35.25f\n","1",x_1,F(x_1),x_1 - x_0);
        //loop n times.
        for(int i = 2; i <= n; i++)
        {
            x_n = x_1-F(x_1)/((F(x_1) - F(x_0))/(x_1 - x_0));
            double y = F(x_n);
            System.out.printf("%10d%35.25f%35.25f%35.25f\n",i,x_n,y,x_n - x_1);
            x_0 = x_1;
            x_1 = x_n;
        }
        return x_n;
    }
    public static void main(String[] args) 
    {
        System.out.printf("%10s%35s%35s%35s\n","n","xn","f(xn)","xn-x(n-1)"); 
        int n = 5;
        SecantFunction(n);
    }
    
}
