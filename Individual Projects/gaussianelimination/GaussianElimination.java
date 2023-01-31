/**
* This program computes the process of the Gaussian Elimination
* Method, which helps solving matrices in the form of Ax = b, which are
* linear systems.
*
* CSC 2262 Programming project No 8
*
* @author Kirk McBrayer
* @since 11/13/2020
*
*/

package gaussianelimination;
import java.util.Scanner;
public class GaussianElimination 
{
    /**
* This method computes finding the numbers of x.
*
* method: matrix
*
* return type: double
*
* parameters:
* A double[][] the matrix of the problem
* b[] the matrix of the answer
*
*
* @author Kirk McBrayer
* @since 11/13/2020
*
*/
    public static double[] matrix(double[][] A, double[] b)
    {
        System.out.printf("%s\n\n ", "Ax = b");  
        System.out.printf("%s\n ", "A =");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s\n ","|", A[0][0],"|",A[0][1],"|",A[0][2],"|",A[0][3],"|");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s\n ","|", A[1][0],"|",A[1][1],"|",A[1][2],"|",A[1][3],"|");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s\n ","|", A[2][0],"|",A[2][1],"|",A[2][2],"|",A[2][3],"|");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s\n\n ","|", A[3][0],"|",A[3][1],"|",A[3][2],"|",A[3][3],"|");
        System.out.printf("%s\n ", "b =");
        System.out.printf("%s%.3f%s\n ","|", b[0],"|");
        System.out.printf("%s%.3f%s\n ","|", b[1],"|");
        System.out.printf("%s%.3f%s\n ","|", b[2],"|");
        System.out.printf("%s%.3f%s\n\n ","|", b[3],"|"); 
        int n = b.length; //the length of b
        //loops n times.
        for(int k = 0; k < n; k++)
        {
            int max = k;// the maximum of k
            //loops n times.
            for(int i = k + 1; i < n; i++)
            {
                if (Math.abs(A[i][k]) > Math.abs(A[max][k]))
                        max = i;
            }
            //swaps between rows of A
            double[] temp = A[k];
            A[k] = A[max];
            A[max] = temp;
            //swaps between rows of b
            double t = b[k];
            b[k] = b[max];
            b[max] = t;
            //loops n times/
            for (int i = k + 1; i < n; i++)
            {
                double f = A[i][k] / A[k][k]; //reduces the number to zero.
                b[i] -= f * b[k];
                //loops n times.
                for(int j = k; j < n; j++)
                {
                    A[i][j] -= f * A[k][j];
                }
            }
        }
        double[] x = new double[n]; //the domains of the matrix.
        //loops n times.
        for(int i = n - 1; i >= 0; i--)
        {
            double sum = 0.0; //the sum of the linear system.
            //loops n times.
            for (int j = i + 1; j < n; j++)
            {
                sum += A[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
        return x;
    }
    public static void main (String[] args) 
    {
        double[][]A = {{2, 1, -1, -2}, {4, 4, 1, 3}, {-6, -1, 10, 10}, {-2, 1, 8, 4}};
        double[] b = {2, 4, -5, 1};
        double[] x = matrix(A,b);  
        System.out.printf("%s\n ", "x =");
        System.out.printf("%s%.3f%s\n ","|", x[0],"|");
        System.out.printf("%s%.3f%s\n ","|", x[1],"|");
        System.out.printf("%s%.3f%s\n\n ","|", x[2],"|");            
    }   
}
