/**
* This program computes both implementations of the Trapezoidal and Simpson Rules.
*
* CSC 2262 Programming project No 5
*
* @author Kirk McBrayer
* @since 10/28/2020
*
*/
package trapazoidalsimpsonrule;
public class TrapazoidalSimpsonRule 
{
    /**
* This method computes the function for both Trapezoidal and Simpson Rules.
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
* @since 10/28/20
*
*/        
    public static double Func(double x)
    {
        return Math.log(x);
    }
       /**
* This method implements the Trapezoidal Rule.
*
* method: trapazoidalRule
*
* return type: double
*
* parameters:
* a [double] the starting point of the integral.
* b [double] the ending point of the integral.
* n [double] the number of elements in the method.
* 
* 
* @author Kirk McBrayer
* @since 10/28/20
*
*/        
    public static double trapazoidalRule(double a, double b, double n)
    {
        double h = (b - a)/n; //h is the pattern of the subintervals
        double s = Func(a) + Func(b); //s is the addition of the starting and ending points of the function.
        // loop n times.
        for (int i = 1; i < n; i++)
        {
            s += 2*Func(a + i*h);
        }
        return (h/2)*s;
    }
          /**
* This method implements the Simpson Rule.
*
* method: simpsonRule
*
* return type: double
*
* parameters:
* a [double] the starting point of the integral.
* b [double] the ending point of the integral.
* n [double] the number of elements in the method.
* 
* 
* @author Kirk McBrayer
* @since 10/28/20
*
*/       
    public static double simpsonRule(double a, double b, double n)
    {
        double h = (b - a)/n; //h is the pattern of the subintervals
        double x; //x is the domain
        double fx; //fx is the range
        double res = 0.0; //res is the result of the Simpson Rule.
        // loop n times.
        for (int i = 0; i <= n; i++)
        {
            x = a + i*h;
            fx = Func(x);
            if (i == 0 || i == n)
                res += fx;
            else if (i % 2 != 0)
                res += 4*fx;
            else
                res += 2*fx;
        }
        res = res*(h/3);
        return res;
    }
    public static void main(String[] args) 
    {
        double x0 = 1.0;
        double xn = 3.0;
        int n = 512;
        System.out.printf("%10s%35.25f\n", "Trapezoidal Rule: T512(f) = ", trapazoidalRule(x0, xn, n));
        System.out.printf("%10s%35.25f", "Simpson Rule: T512(f) = ", simpsonRule(x0, xn, n));
    }
    
}
