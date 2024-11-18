import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Formatter;
import java.util.Locale;
import java.io.RandomAccessFile;
import java.util.Scanner;

public class Arquivo{

    //funcao para ler arquivo do fim para o inicio
    public static void lerArquivo(int n) {
         try (RandomAccessFile raf = new RandomAccessFile("dados.txt", "r")) {
            //comprimento do arquivo em bytes
            long fileLength = raf.length();
            //posicao do final do arquivo
            long position = fileLength;

            int count = 0;

            while (position > 0 && count < n) {
                raf.seek(--position);
                if (raf.readByte() == '\n' || position == 0) {
                    if (position != 0) {
                        raf.seek(position + 1); // Pular o '\n'
                    } else {
                        raf.seek(position); // Inicio do arquivo
                    }

                    // Le o valor do arquivo e mostra
                    String linha = raf.readLine();
                    if (linha != null && !linha.isEmpty()) {
                        System.out.println(linha);
                        count++;
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in).useLocale(Locale.US);

        int n = sc.nextInt();

        File arquivo = new File("dados.txt");

        // grava no arquivo os n valores lidos
        try (Formatter formatter = new Formatter(new FileWriter(arquivo))) {

            for (int i = 0; i < n; i++) {
                float valor = sc.nextFloat();
                String formattedValue;

                if (valor == (int) valor) {
                    // Imprime como inteiro se for um nuero inteiro
                    formattedValue = String.format(Locale.US, "%d", (int) valor);
                } else {
                    // Formata o numero de ponto flutuante removendo zeros desnecessarios
                    formattedValue = String.format(Locale.US, "%.3f", valor)
                                    .replaceAll("(?<=\\d)0*$", ""); // Remove zeros a direita
                }

                formatter.format("%s%n", formattedValue);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            sc.close();
        }
        lerArquivo(n);
    }
}