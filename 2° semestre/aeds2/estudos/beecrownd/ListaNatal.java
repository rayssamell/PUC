import java.util.Locale;
import java.util.Scanner;

public class ListaNatal {
    public Presente[] presente;

    public ListaNatal(int n){
        presente = new Presente[n];
    }

    public void swap(int i, int j){
        Presente tmp = presente[i];
        presente[i] = presente[j];
        presente[j] = tmp; 
    }
    
    public void ordenar(){
        for(int i=0; i < presente.length-1; i++){
            for(int j=0; j < presente.length-i-1; j++){
                if(presente[j].prioridade == presente[j+1].prioridade){
                    if(presente[j].valor > presente[j+1].valor){
                        swap(j, j+1);
                    }
                } else if(presente[j].prioridade < presente[j+1].prioridade){
                    swap(j, j+1);
                }
            }
        }
    }

    public void mostrar(){
        for(int i=0; i < presente.length;i++){
            System.out.print(presente[i].nome + " ");
            System.out.printf(Locale.US, "- R$%.2f %n", presente[i].valor);
        }
        System.out.println();
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String nome = sc.next(); // Lê o nome
            if (sc.hasNextInt()) {
                int n = sc.nextInt(); // Lê o número de produtos
                sc.nextLine();        // Consome o caractere de nova linha pendente
                ListaNatal lista = new ListaNatal(n);
                for (int i = 0; i < n; i++) {
                    Presente presente = new Presente();
                    if (sc.hasNextLine()) {
                        String produto = sc.nextLine(); // Lê cada produto
                        presente.nome = produto;
            
                        String entrada = sc.nextLine(); 
                        String[] valores = entrada.split(" ");
                        presente.valor = Double.parseDouble(valores[0]);
                        presente.prioridade = Integer.parseInt(valores[1]); 
                    }
                    lista.presente[i] = presente;
                }
                System.out.println("Lista de " + nome);
                lista.ordenar();
                lista.mostrar();
                
            }
        }


        sc.close();
    }
}

class Presente {
    public String nome;
    public double valor;
    public int prioridade;

    public Presente(){
        nome = " ";
        valor = 0.0;
        prioridade = 0; 
    }
}