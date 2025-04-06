import java.util.Scanner;

public class Percurso {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        sc.nextLine();
        for(int i=1; i <= n; i++){
            System.out.println("Case " + i + ":");
            
            int c = sc.nextInt();
            Arvore arvore = new Arvore();
            
            for(int j=0; j < c; j++){
                int v = sc.nextInt();
                arvore.inserir(v);
            }
            arvore.mostrarPorNivel();

            if(i < n){
                System.out.println();
            }
        }
        
        sc.close();
    }
}

class Arvore {
    private No raiz;
    private int tam;

    String resp = "";

    public Arvore(){
        raiz = null;
        tam = 0;
    }

    public void inserir(int elemento) throws Exception{
        raiz = inserir(elemento, raiz);
        tam++;
    }

    private No inserir(int elemento, No i) throws Exception{
        if(i == null){
            i = new No(elemento);
        } else if(elemento < i.elemento){
            i.esq = inserir(elemento, i.esq);
        } else if(elemento > i.elemento){
            i.dir = inserir(elemento, i.dir);
        } else {
            throw new Exception("Erro");
        }
        return i;
    }

    public void mostrarPorNivel() {
        int altura = tam;
        for (int i = 0; i <= altura; i++) {
            mostrar(raiz, i);
        }
        System.out.println(resp.trim()); 
    }

    public void mostrar(No i, int n) {
        if(i != null){
            // Se chegamos ao nível desejado, mostramos o elemento
            if (n == 0) {
                resp += i.elemento + " ";
            } else {
                // Recorre para os níveis inferiores
                mostrar(i.esq, n- 1);
                mostrar(i.dir, n - 1);
            }
        }
    }
}

class No {
    public int elemento;
    public No esq;
    public No dir;

    public No(){
        this(0);
    }

    public No(int elemento){
        this.elemento = elemento;
        dir = esq = null;
    }
}