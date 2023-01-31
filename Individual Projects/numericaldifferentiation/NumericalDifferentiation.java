/**
* This program computes the different methods for the Numerical Differentiation.
*
* CSC 2262 Programming project No 6
*
* @author Kirk McBrayer
* @since 11/3/2020
*
*/
package numericaldifferentiation;
public class NumericalDifferentiation 
{
       /**
* This method computes the function for the numerical differentiation methods.
*
* method: F
*
* return type: double
*
* parameters:
* x [double] the function point of the function
*
*
* @author Kirk McBrayer
* @since  11/3/2020
*
*/
    public static double F(double x)
    {
        return Math.sin(x);
    }
    /**
* This method computes the numerical differentiation method, the Forward Difference Formula.
*
* method: ForwardDifferenceFormula
*
* return type: double
*
* parameters:
* x [double] the function point of the formula
* h [double] the point addition of the formula
*
*
* @author Kirk McBrayer
* @since  11/3/2020
*
*/
    public static double ForwardDifferenceFormula(double x, double h)
    {
        double Dhfx = 0.0; //Dhfx is the total of the method.
        Dhfx = (F(x + h) - F(x))/h;
        return Dhfx;
    }
    /**
* This method computes the numerical differentiation method, the Backward Difference Formula.
*
* method: BackwardDifferenceFormula
*
* return type: double
*
* parameters:
* x [double] the function point of the formula
* h [double] the point addition of the formula
*
*
* @author Kirk McBrayer
* @since  11/3/2020
*
*/
    public static double BackwardDifferenceFormula(double x, double h)
    {
        double Dhfx = 0.0; //Dhfx is the total of the method.
        Dhfx = (F(x) - F(x - h))/h;
        return Dhfx;
    }
    /**
* This method computes the numerical differentiation method, the Lagrange Basis.
*
* method: LagrangeBasis
*
* return type: double
*
* parameters:
* x [double] the function point of the formula
* h [double] the point addition of the formula
*
*
* @author Kirk McBrayer
* @since  11/3/2020
*
*/
    public static double LagrangeBasis(double x, double h)
    {
        double Dhfx = 0.0; //Dhfx is the total of the method.
        Dhfx = (F(x + h) - F(x - h))/(2*h);
        return Dhfx;
    }
    /**
* This method computes the numerical differentiation method, the Undetermined Coefficients.
*
* method: UndeterminedCoefficients
*
* return type: double
*
* parameters:
* t [double] the function point of the formula
* h [double] the point addition of the formula
*
*
* @author Kirk McBrayer
* @since  11/3/2020
*
*/
    public static double UndeterminedCoefficients(double t, double h)
    {
        double Dhft = 0.0; //Dhft is the total of the method.
        Dhft = (F(t + h) -(2*F(t)) + F(t - h))/Math.pow(h, 2);
        return Dhft;
    }
    public static void main(String[] args) 
    {
        double x = (2*Math.PI)/3;
        double h = 0.1;
        System.out.printf("%35s%35s%35s%35s%35s\n","h","FDF","BDF","LB","UC");
        System.out.printf("%35.25f%35.25f%35.25f%35.25f%35.25f\n",h,ForwardDifferenceFormula(x, h),BackwardDifferenceFormula(x, h),LagrangeBasis(x, h),UndeterminedCoefficients(x, h)); 
        h = 0.05;
        System.out.printf("%35.25f%35.25f%35.25f%35.25f%35.25f\n",h,ForwardDifferenceFormula(x, h),BackwardDifferenceFormula(x, h),LagrangeBasis(x, h),UndeterminedCoefficients(x, h)); 
        h = 0.025;
        System.out.printf("%35.25f%35.25f%35.25f%35.25f%35.25f\n",h,ForwardDifferenceFormula(x, h),BackwardDifferenceFormula(x, h),LagrangeBasis(x, h),UndeterminedCoefficients(x, h)); 
        h = 0.0125;
        System.out.printf("%35.25f%35.25f%35.25f%35.25f%35.25f\n",h,ForwardDifferenceFormula(x, h),BackwardDifferenceFormula(x, h),LagrangeBasis(x, h),UndeterminedCoefficients(x, h)); 
        h = 0.00625;
        System.out.printf("%35.25f%35.25f%35.25f%35.25f%35.25f\n",h,ForwardDifferenceFormula(x, h),BackwardDifferenceFormula(x, h),LagrangeBasis(x, h),UndeterminedCoefficients(x, h)); 
    }
    
}
