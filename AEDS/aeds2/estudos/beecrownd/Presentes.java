import java.util.Locale;
import java.util.Scanner;

public class Presentes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.useLocale(Locale.US);

        int n = sc.nextInt();
        sc.nextLine(); // Consumir quebra de linha pendente

        for (int i = 0; i < n; i++) {
            if (sc.hasNextInt()) {
                int t = sc.nextInt(); // Número de itens a inserir
                sc.nextLine(); // Consumir quebra de linha

                Trenos trenos = new Trenos();

                // Inserindo os itens
                for (int j = 0; j < t; j++) {
                    String nome = sc.nextLine();
                    double peso = sc.nextDouble();
                    sc.nextLine(); // Consumir quebra de linha
                    trenos.inserir(nome, peso);
                }

                double m = 0.0;
                if (sc.hasNextDouble()) {
                    m = sc.nextDouble(); // Capacidade máxima de um trenó
                    sc.nextLine(); // Consumir quebra de linha
                }

                double total = 0.0;
                String p = sc.nextLine(); // Nome do presente
                while (!p.equals("0")) {
                    int quantidade = sc.nextInt();
                    sc.nextLine(); // Consumir quebra de linha
                    total += trenos.presentes(p, quantidade);
                    p = sc.nextLine(); // Ler próximo presente
                }

                // Exibir resultado
                System.out.println("Peso total: " + total + " kg");
                System.out.println("Número de trenós: " + (int) Math.ceil(total / m));
            }
        }
        sc.close();
    }
}

class Trenos {
    private String[] nome;
    private Double[] peso;
    int t;

    public Trenos(){
        nome = new String[30];
        peso = new Double[30];
        t = 0;
    }

    public void inserir(String nome, double peso){
        this.nome[t] = nome;
        this.peso[t] = peso;
        t++;
    }

    public double presentes(String p, int quant){
        boolean resp = false;
        double total = 0.0;
        for(int i=0; i < t; i++){
            if(nome[i].equals(p) && !resp){
                total = peso[i] * quant;
                resp = true;
            }
        }
        
        return total;
    }
}