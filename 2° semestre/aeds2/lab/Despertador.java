import java.util.Scanner;

public class Despertador {
    public static void despertar(int h1, int m1, int h2, int m2){
        int minutos1 = (h1 * 60) + m1;
        int minutos2 = (h2 * 60) + m2;
        int horario;


        if (minutos2 <= minutos1) {
            minutos2 += 24 * 60;
        }

        // Calcula a diferença de minutos
        horario = minutos2 - minutos1;

        System.out.println(horario);
        
    }
    public static void main(String[] args){
        int h1, m1, h2, m2;
        Scanner sc = new Scanner(System.in);

        h1 = sc.nextInt();
        m1 = sc.nextInt();
        h2 = sc.nextInt();
        m2 = sc.nextInt();

        while(!(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)){
            despertar(h1, m1, h2, m2);
            
            h1 = sc.nextInt();
            m1 = sc.nextInt();
            h2 = sc.nextInt();
            m2 = sc.nextInt();
        }

        sc.close();
    }
}