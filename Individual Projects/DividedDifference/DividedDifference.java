/**
* This program computes the implementation of Newton’s Divided Difference Interpolation
Formula
*
* CSC 2262 Programming project No 3
*
* @author Kirk McBrayer
* @since 9/30/20
*
*/

package divideddifference;
import java.text.*;
import java.math.*;
public class DividedDifference
/**
* This method computes the function for the Divided Difference.
*
* method: Func
*
* return type: double
*
* parameters:
* x [double] the function point of the function.
*
*
* @author Kirk McBrayer
* @since 9/30/20
*
*/        
{
public static double Func(double x)
{
    return Math.sin(x);
}
/**
* This method computes the interpolation for the Divided Difference.
*
* method: proterm
*
* return type: double
*
* parameters:
* n [double] the number of elements in the method.
* value [double] the function point of the function.
* x[] [double[]] the array of the function.
*
*
* @author Kirk McBrayer
* @since 9/30/20
*
*/        
static double proterm(int n, double value, double x[]) 
{ 
    double pro = Func(0); //pro is the first iteration.
    // loop n times.
    for (int i = 1; i < n; i++) 
    { 
        double term = 1.0; // term is the iteration process.
        for (int j = 0; j < i; j++)
        {
            term = term * (value - x[j]);
        }
        pro = pro + term * di(0, i); 
    } 
    return pro; 
}
/**
* This method computes the total Divided Difference.
*
* method: di
*
* return type: double
*
* parameters:
* x0 [double] the starting point of the function.
* xn [double] the ending point of the function.
*
*
* @author Kirk McBrayer
* @since 9/30/20
*
*/        
static double di(int x0, int xn)
{
    double x[] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2}; //x[] are the array values of x.
    if(xn - x0 == 1)
         return(Func(x[xn]) - Func(x[x0])) / (x[xn] - x[x0]);
    return (di(x0 + 1, xn) - di(x0, xn - 1))/(x[xn] - x[x0]);
}  
// Function for calculating 
// divided difference table 
/**
* This method displays the first table of the project.
*
* method: dividedDiffTable
*
* return type: double
*
* parameters:
* x[] [double[]] the array of the function.
* n [double] the number of elements in the method.
*
*
* @author Kirk McBrayer
* @since 9/30/20
*
*/        
static void dividedDiffTable(double x[], int n) 
{ 
    System.out.printf("%10s%35s%35s%35s\n","i","xi","cos(xi)","Di");
    System.out.printf("%10d%35.25f%35.25f%35.25f\n",0,x[0] ,Func(x[0]),Func(x[0]));
    //loop n times.
    for (int i = 1; i < n; i++) 
    { 
        System.out.printf("%10d%35.25f%35.25f%35.25f\n",i,x[i] ,Func(x[i]),di(0,i));
    } 
} 
/**
* This method displays the second table of the project.
*
* method: applyFunction
*
* return type: double
*
* parameters:
* value [double] the function point of the function.
* x[] [double[]] the array of the function.
* y[][] [double[]] the range of the function.
* n [double] the number of elements in the method.
*
*
* @author Kirk McBrayer
* @since 9/30/20
*
*/        
// Function for applying Newton's 
// divided difference formula 
static void applyFormula(double value, double x[], 
                double y[][], int n) 
{ 
    System.out.printf("\n\n%10s%35s%35s%35s\n","n","Pn(0.1)","Pn(0.3)","Pn(0.5)");
    //loop n times.
    for (int i = 1; i < n; i++) 
    { 
    System.out.printf("%10s", i);
    System.out.printf("%35.25f" ,proterm(i+1, 0.1, x));
    System.out.printf("%35.25f" ,proterm(i+1, 0.3, x));
    System.out.printf("%35.25f\n" ,proterm(i+1, 0.5, x));
    } 
} 
    public static void main(String[] args) 
    { 
    int n = 7; 
    double value, sum; 
    double y[][]=new double[10][10]; 
    double x[] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2}; 
   
    y[0][0] = Math.cos(0.0); 
    y[1][0] = Math.cos(0.2); 
    y[2][0] = Math.cos(0.4); 
    y[3][0] = Math.cos(0.6);
    y[4][0] = Math.cos(0.8);
    y[5][0] = Math.cos(1.0);
    y[6][0] = Math.cos(1.2);
  
    dividedDiffTable(x, n); 

    applyFormula(0, x, y, n);  
    }    
}
