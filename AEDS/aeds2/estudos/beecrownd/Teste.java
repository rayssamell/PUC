import java.util.Scanner;

public class Teste {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        for(int i=1; i <=n; i++){
            Arvore tree = new Arvore();
            int m = sc.nextInt();
            System.out.println("Case " + i + ":");
            for(int j=0; j < m; j++){
                int valor = sc.nextInt();
                tree.inserir(valor);
            }
            tree.preOrdem();
            tree.central();
            tree.posOrdem();
    
            if(i < n){
                System.out.println();
            }
            
        }

        sc.close();
    }   
}

class Arvore {
    private No raiz;

    public Arvore(){
        raiz = null;
    }

    public void inserir(int x) throws Exception{
        raiz = inserir(x, raiz);
    }

    public No inserir(int x, No i) throws Exception{
        if(i == null){
            i = new No(x);
        } if(i.elemento > x){
            i.esq = inserir(x, i.esq);
        } else if(i.elemento < x){
            i.dir = inserir(x, i.dir);
        }
        return i;
    }

    public void preOrdem(){
        System.out.print("Pre.:");
        preOrdem(raiz);
        System.out.println();
    }

    public void preOrdem(No i){
        if(i != null){
            System.out.print(" " + i.elemento);
            preOrdem(i.esq);
            preOrdem(i.dir);
        }
    }

    public void central(){
        System.out.print("In..:");
        central(raiz);
        System.out.println();
    }

    public void central(No i){
        if(i != null){
            central(i.esq);
            System.out.print(" " + i.elemento);
            central(i.dir);
        }
    }

    public void posOrdem(){
        System.out.print("Post:");
        posOrdem(raiz);
        System.out.println();
    }

    public void posOrdem(No i){
        if(i != null){
            posOrdem(i.esq);
            posOrdem(i.dir);
            System.out.print(" " + i.elemento);
        }
    }
}

class No {
    public int elemento;
    public No esq, dir;

    public No(){
        this(0);
    }

    public No(int elemento){
        this.elemento = elemento;
        esq = dir = null;
    }
}