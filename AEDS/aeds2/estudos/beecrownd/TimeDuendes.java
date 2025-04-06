import java.util.Scanner;

public class TimeDuendes {
    private String nome;
    private int idade;
    private int tam;

    public TimeDuendes(int tam){
        this.tam = tam;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public String getNome(){
        return nome;
    }

    public void setIdade(int idade){
        this.idade = idade;
    }

    public int getIdade(){
        return idade;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();

        TimeDuendes tm = new TimeDuendes(n);

        for(int i=0; i < n; i++){
            String nome = sc.next();
            int idade = sc.nextInt();

            tm.setNome(nome);
            tm.setIdade(idade);
        }


        sc.close();
    }
}