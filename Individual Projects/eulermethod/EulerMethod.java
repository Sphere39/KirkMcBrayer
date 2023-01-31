/**
* This program computes the process of the Euler method to solve any ordinary 
* differential equation.
*
*
* CSC 2262 Programming project No 10
*
* @author Kirk McBrayer
* @since 12/2/2020
*
*/
package eulermethod;
import java.io.*;
/**
 *
 * @author kirkm
 */
public class EulerMethod 
{

    /**
* This method computes the differential equation for the Euler Method.
*
* method: func
*
* return type: double
*
* parameters:
* x [double] the function point of the differential equation.
* y [double] the differential point of the differential equation.
*
*
* @author Kirk McBrayer
* @since 12/2/20
*
*/   
    double func(double x, double y) 
    { 
        return (x*y) + ((4.0*x)/y); 
    } 
  
/**
* This method computes the process of the Euler Method.
*
* method: euler
*
* return type: double
*
* parameters: 
* x0 [double] the starting point of the equation
* y [double] the result of the equation
* h [double] the number of the sub-intervals
* x [double] the sub-interval numbers
*
*
* @author Kirk McBrayer
* @since 12/2/2020
*
*/
    void euler(double x0, double y, double h, double x) 
    { 
        double temp = 0; //the swap of the function
        System.out.printf("%10s%10s%10s\n","h","x","yh(x)");
        // loops to x
        while (x0 <= x + 0.01) 
        { 
            System.out.printf("%10.2f%10.2f%10.4f\n",h,x0,y);
            temp = y; 
            y = y + h * func(x0, y); 
            x0 = x0 + h;
        }  
    }
    public static void main(String[] args) 
    {
        EulerMethod obj = new EulerMethod(); 
        double x0 = 0.0; 
        double y0 = 1.0; 
        double h = 0.25; 
        double x = 1.0; 
        obj.euler(x0, y0, h, x); 
    }    
}
