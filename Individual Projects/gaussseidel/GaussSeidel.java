/**
* This program computes the process of the Gauss-Seidel Iteration
* Method, which helps solving matrices in the form of Ax = b, in
* the most approximate way.
*
* CSC 2262 Programming project No 9
*
* @author Kirk McBrayer
* @since 11/22/2020
*
*/
package gaussseidel;
import java.util.Arrays;
public class GaussSeidel 
{
    public static final int MAX_ITERATIONS = 12;  
    private static double[][] M;
    double[][] matrix = M;
        /**
* This method computes the Vector Form.
*
* method: norm
*
* return type: double
*
* parameters:
* x[] the function point of the matrix
*
*
* @author Kirk McBrayer
* @since 11/22/2020
*
*/
    public static double norm(double[] x)
    {
        double P = 0;//P is the euclidean norm.
        //loops x.length times.
        for(int i = 0; i < x.length; i++)
        {
            P += x[i] * x[i];
        }
        return Math.sqrt(P);
    }
        /**
* This method computes the functions of solving the iterations of x.
*
* method: solve
*
* return type: double
*
* parameters:
*
*
* @author Kirk McBrayer
* @since 11/22/2020
*
*/
    public static double[] solve()
    {
        int iterations = 0; //iterations is the startinf number.
        int n = M.length; // the length of the iterations.
        double epsilon = 1e-15; //epsilon is the limit.
        double[] X = new double[n]; //X is Approximations
        double[] P = new double[n]; //P is Prev
        Arrays.fill(X, 0);
 
        while (true) 
        {
            //loops n times.
            for (int i = 0; i < n; i++) 
            {
                double sum = M[i][n]; //sum means the b_n
                //loop n times.
                for (int j = 0; j < n; j++)
                    if (j != i)
                        sum -= M[i][j] * X[j];
 
        // Update x_i to use in the next row calculation
                X[i] = 1/M[i][i] * sum;
            }
            System.out.printf( "%2d", iterations + 1);
            iterations++; 
            boolean stop = true; //stop is the end of the method.
                if (Math.abs(norm(X) - norm(P)) > epsilon)
                    stop = false;
            System.out.printf("%10.4f%10.4f%10.4f%10.4f%10.4f%10.4f%10.4f\n" ,X[0] ,X[1] ,X[2], X[3], X[4], X[5], (Math.abs(norm(X) - norm(P)))*-1  );
            if (stop || iterations == MAX_ITERATIONS) break;
            P = (double[])X.clone(); //P is the euclidean norm.
        }
        return X;
    }
    
    public static void main(String[] args) 
    {
        double[][]A = {
            {4, -1, 0, -1, 0, 0}, 
            {-1, 4, -1, 0, -1, 0}, 
            {0, -1, 4, 0, 0, -1}, 
            {-1, 0, 0, 4, -1, 0}, 
            {0, -1, 0, -1, 4, -1}, 
            {0, 0, -1, 0, -1, 4}};
        double[] b = {0, 5, 0, 6, -2, 6};
        M = new double [b.length][b.length + 1];
        for(int i = 0; i < b.length; i++)
        {
            for(int j = 0; j < b.length; j++)
            {
                M[i][j] = A[i][j];
            }
            M[i][b.length] = b[i];
        }
        int n = 5;
        System.out.printf("%2s%10s%10s%10s%10s%10s%10s%10s\n","k","x0","x1","x2","x3","x4","x5","Diff");
        System.out.printf("%2d%10.4f%10.4f%10.4f%10.4f%10.4f%10.4f\n", 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
        double[]x = solve();
        System.out.printf("%s\n\n ", "Ax = b");  
        System.out.printf("%s\n ", "A =");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s\n ","|", A[0][0],"|",A[0][1],"|",A[0][2],"|",A[0][3],"|",A[0][4],"|",A[0][5],"|");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s\n ","|", A[1][0],"|",A[1][1],"|",A[1][2],"|",A[1][3],"|",A[1][4],"|",A[1][5],"|");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s\n ","|", A[2][0],"|",A[2][1],"|",A[2][2],"|",A[2][3],"|",A[2][4],"|",A[2][5],"|");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s\n ","|", A[3][0],"|",A[3][1],"|",A[3][2],"|",A[3][3],"|",A[3][4],"|",A[3][5],"|");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s\n ","|", A[4][0],"|",A[4][1],"|",A[4][2],"|",A[4][3],"|",A[4][4],"|",A[4][5],"|");
        System.out.printf("%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s%.3f%s\n\n ","|", A[5][0],"|",A[5][1],"|",A[5][2],"|",A[5][3],"|",A[5][4],"|",A[5][5],"|");    
        System.out.printf("%s\n ", "x =");
        System.out.printf("%s%.3f%s\n ","|", x[0],"|");
        System.out.printf("%s%.3f%s\n ","|", x[1],"|");
        System.out.printf("%s%.3f%s\n ","|", x[2],"|");
        System.out.printf("%s%.3f%s\n ","|", x[3],"|");
        System.out.printf("%s%.3f%s\n ","|", x[4],"|");
        System.out.printf("%s%.3f%s\n\n ","|", x[5],"|");
        System.out.printf("%s\n ", "b =");
        System.out.printf("%s%.3f%s\n ","|", b[0],"|");
        System.out.printf("%s%.3f%s\n ","|", b[1],"|");
        System.out.printf("%s%.3f%s\n ","|", b[2],"|");
        System.out.printf("%s%.3f%s\n ","|", b[3],"|");
        System.out.printf("%s%.3f%s\n ","|", b[4],"|");
        System.out.printf("%s%.3f%s\n ","|", b[5],"|");
    }
}
