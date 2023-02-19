/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package compositenoise;

/**
 *
 * @author kirkm
 */
public class CompositeNoise 

{

    public static void main(String[] args)

    {

        double x = -0.7;

        double independentTerm = x*x*x*x*x+0.9*x*x*x*x-1.62*x*x*x-1.458*x*x+0.6561*x+0.59049;

        double nested = 0.59049 + x*(0.6561+x*(-1.458+x*(-1.62+x*(0.9+x))));

        double compositeNoise = independentTerm - nested;

        System.out.printf("%e", compositeNoise);

    }

}