import java.util.ArrayList;
import java.util.Scanner;

public class Guia0201 {
    //funcao para converter de binariopara decimal
     public static double bin2double(String binario) {
        // definir dados
        double decimal = 0.0;
        int ponto = binario.indexOf(".");
        
        // Converter a parte inteira 
        int potencia = 0;
        if (ponto != -1) {
            // anterior ao "."
            for (int i = ponto - 1; i >= 0; i--) {
                //  converte um caractere para seu valor inteiro
                int parteInteira = Character.getNumericValue(binario.charAt(i));
                // multiplica com a potencia correspondente e soma ao anterior
                decimal += parteInteira * Math.pow(2, potencia);
                potencia++;
            }
        } 
        // Converter a parte fracionaria 
        potencia = -1;
        for (int i = ponto + 1; i < binario.length(); i++) {
            int parteFracionaria = Character.getNumericValue(binario.charAt(i));
            decimal += parteFracionaria * Math.pow(2, potencia);
            potencia--;
        }
        
        return decimal;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite um número binário: ");
        String binario = scanner.nextLine();

        double decimal = bin2double(binario);

        System.out.println("Numero " + binario + "(2)" + " em decimal " + decimal + "(10)");
    }
}
