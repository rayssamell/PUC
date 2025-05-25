import java.lang.Math;
import java.util.*;

public class Integral2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a, b, n;

        a = sc.nextInt();
        b = sc.nextInt();
        n = sc.nextInt();

        double integral = 0.0; 
        double deltax = (double)(b - a)/n;
       
        integral += (32 * Math.PI * deltax);
        System.out.println(integral);

        sc.close();
    }
}
