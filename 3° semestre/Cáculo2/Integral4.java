import java.lang.Math;
import java.util.*;

public class Integral4{
    public static void main(String[] args){
        //Volume da esfera de raio 3 com casca cilindrica
        Scanner sc = new Scanner(System.in);
        int a, b, n;

        a = sc.nextInt();
        b = sc.nextInt();
        n = sc.nextInt();

        double integral = 0.0; 
        double deltax = (double)(b - a)/n;

        for(int i=1; i <= n; i++){
            double xi = a + i *deltax;
            integral += (4* Math.PI * xi * Math.sqrt(9-Math.pow(xi, 2))*deltax);
            
        }
        System.out.println(integral);

        sc.close();
    }
}
