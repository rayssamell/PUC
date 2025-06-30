import java.lang.Math;
import java.util.*;

public class Integral1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a, b, n;

        a = sc.nextInt();
        b = sc.nextInt();
        n = sc.nextInt();

        double integral = 0.0; 
        double deltax = (double)(b - a)/n;
        for(int i=1; i <= n; i++){
            double xi = a + i *deltax;
            integral += (2* Math.sqrt(36-(xi*xi))*deltax);
            
        }
        System.out.println(integral);
        sc.close();
    }
}