import java.lang.Math;
import java.util.*;

public class Integral6{
    public static void main(String[] args){
        //Volume do solido de revolucao 
        Scanner sc = new Scanner(System.in);
        int a, b, n;

        //Centro (6,0) raio 4, rotacao no eixo y
        a = sc.nextInt();
        b = sc.nextInt();
        n = sc.nextInt();

        double integral = 0.0; 
        double deltax = (double)(b - a)/n;

        for(int i=1; i <= n; i++){
            double xi = a + i *deltax;
            integral += (2* Math.PI * xi * 2* Math.sqrt(16-Math.pow(xi-6, 2))*deltax);
            
        }
        System.out.println(integral);

        sc.close();
    }
}
