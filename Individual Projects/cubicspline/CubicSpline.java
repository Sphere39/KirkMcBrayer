/**
* This program computes the algorithm of the Natural Cubic Spline Interpolation.
*
* CSC 2262 Programming project No 4
*
* @author Kirk McBrayer
* @since 10/4/2020
*
*/
package cubicspline;
public class CubicSpline 
{
    public static void main(String[] args) 
    {
        //Step 0
        int n, i, j;
        n = 6;
        double[] h = new double[n + 1];
        double[] A = new double[n + 1];
        double[] b = new double[n + 1];
        double[] d = new double[n + 1];
        double[] l = new double[n + 1];
        double[] mu = new double[n + 1];
        double[] z = new double[n + 1];
        double[] c = new double[n + 1];
        double[] x = {17.0, 20.0, 23.0, 24.0, 25.0, 27.0, 27.7};
        double[] a = {4.5, 7.0, 6.1, 5.6, 5.8, 5.2, 4.1}; 
        //Step 1
        //n - 1 times
        for(i = 0; i <= n - 1; i++)
            h[i] = x[i + 1] - x[i];
        //Step 2
        //n - 1 times
        for(i = 1; i <= n - 1; i++)
            A[i] = (3.0*(a[i + 1]*h[i - 1] - a[i]*(x[i + 1] - x[i - 1])+a[i - 1]*h[i]))/(h[i - 1]*h[i]);
        //Step 3    
        l[0] = 1;
        mu[0] = 0;
        z[0] = 0;
        //Step 4
        //n - 1 times
        for(i = 1; i <= n - 1; i++)
        {
            l[i] = 2.0*(x[i + 1] - x[i - 1]) - h[i - 1]*mu[i - 1];
            mu[i] = h[i]/l[i];
            z[i] = (A[i] - h[i - 1]*z[i - 1])/l[i];
        }
        //Step 5
        l[n] = 1;
        z[n] = 0;
        c[n] = 0;
        //Step 6
        //n - 1 times
        for(j = n - 1; j >= 0; j--)
        {
            c[j] = z[j] - mu[j]*c[j + 1];
            b[j] = (a[j + 1] - a[j])/h[j] - h[j]*(c[j + 1] + 2.0*c[j])/3.0;
            d[j] = (c[j + 1] - c[j])/(3.0*h[j]);
        }
        //Step 7
        System.out.printf("%10s%35s%35s%35s%35s%35s\n","j","xj","aj=f(xj)","bj","cj","dj");
        for(i = 0; i <= n; i++)
            System.out.printf("%10d%35.25f%35.25f%35.25f%35.25f%35.25f\n",i,x[i],a[i],b[i],c[i],d[i]);
    }    
}
