import java.util.*;

public class Derivada1 {

    public static void classificar(double fxx, double D){
        if(D>0.0 && fxx > 0.0){
            System.out.println("Ponto de minimo local");
        } else if(D> 0.0 && fxx < 0.0){
            System.out.println("Ponto de maximo local");
        } else if (D < 0.0){
            System.out.println("Ponto de Sela");
        } else {
            System.out.println("Não é possível classificar");
        }
    }
    public static boolean pontoCritico(double resp1, double resp2){
        if(resp1 == 0.0 && resp2 == 0.0){
            System.out.println("Ponto Crítico");
            return true;
        } else {
            System.out.println("Não é ponto critico");
            return false;
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x, y;

        x = sc.nextInt();
        y = sc.nextInt();

        double fx = 12 * Math.pow(x, 5) - (39*4*Math.pow(x, 3)) + (216*2*x);
        double fy = Math.pow(y, 6) + (2*Math.pow(y, 5)) - (101*Math.pow(y, 4)) + (100*Math.pow(y, 2))+(100*2*y)-(101*2*Math.pow(y, 3)); 
        
        if(pontoCritico(fx,fy)){
            double fxx = 60*Math.pow(x, 4) - 468*Math.pow(468, 2) + 432;
            double fyy = Math.pow(y, 5) + (10*Math.pow(y,4)) - (404*Math.pow(y, 3))+(200*y)+200-(606*Math.pow(y, 2));
            double fxy = 0;
            double D = fxx * fyy - Math.pow(fxy, 2);
            classificar(fxx,D);
        }

        sc.close();
    }
}