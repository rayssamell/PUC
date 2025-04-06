import java.util.Scanner;

public class InfixaPosfixa {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Pilha p1 = new Pilha();
        Pilha p2 = new Pilha();
        String s = "";
        int n = sc.nextInt();
        sc.nextLine();

        for(int i=0; i < n; i++){
            String line = sc.nextLine();
            String[] partes = line.split("");
            if(partes[i].equals("+") || partes[i].equals("-") || partes[i].equals("*") || partes[i].equals("^") || partes[i].equals("/")){
                p1.empilhar(line);
            } else if(partes[i].equals("(")){
                
            }
        }
        sc.close();
    }
}

class Pilha {
    public Celula topo;

    public Pilha(){
        topo = null;
    }

    public void empilhar(String elemento){
        Celula tmp = new Celula(elemento);
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
    }

    public String desempilhar(){
        Celula tmp = topo;
        String elemento = tmp.elemento;
        topo = topo.prox;
        tmp.prox = tmp = null;

        return elemento;
    }
}

class Celula {
    public String elemento;
    public Celula prox;

    public Celula(String elemento){
        this.elemento = elemento;
        prox = null;
    }
    public Celula(){
        this(null);
    }
}