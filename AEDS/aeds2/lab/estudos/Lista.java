import java.io.IOException;

public class Lista {
    //atributos
    private int[] array;
    private int n; //tamanho
    //construtor 
    public Lista(){
        this(6);
    }
    public Lista(int tamanho){
        array = new int[tamanho];
        n = 0;
    }
    //inserir no inicio
    public void inserirInicio(int valor){
        if(n >= array.length)
            System.out.println("Erro");
        for(int i=n; i > 0; i--){
            array[i] = array[i-1];
        }
        array[0] = valor;
        n++; 
    }
    //inserir no fim
    public void inserirFim(int valor){
        if(n >= array.length)
            System.out.println("Erro");
        array[n++] = valor;
    }
    //inserir em posicao
    public void inserir(int valor, int pos){
        if(n >= array.length || pos < 0 || pos > n)
            System.out.println("Erro");

        for(int i=n; i > pos; i--){
            array[i] = array[i-1];
        }
        array[pos] = valor;
        n++;
    }
    //remover no inicio
    public int removerInicio(){
        if(n == 0)
            System.out.println("Erro");

        int resp = array[0];
        n--;
        for(int i=0; i < n; i++){
            array[i] = array[i+1];
        }
        return resp;
    }
    //remover no fim
    public int removerFim(){
        if(n == 0)
            System.out.println("Erro");
        
        return array[--n];
    }
    //remover em posicao
    public int remover(int pos){
        if(n == 0 || pos < 0 || pos > n)
            System.out.println("Erro");
        
        int resp = array[pos];
        n--;
        for(int i=pos; i < n; i++){
            array[i] = array[i+1];
        }
        return resp;
    }
    //mostrar arranjo
    public void mostrar(){
        System.out.print("[ ");
        for (int i = 0; i < n; i++){
            System.out.print(array[i] + " ");
        }
        System.out.println(" ]");
    }
    //metodo principal
    public static void main(String[] args){
        System.out.println("==== LISTA LINEAR ====");
        Lista lista = new Lista(6);
        int x1, x2, x3;
        lista.inserirInicio(1);
        lista.inserirFim(7);
        lista.inserirFim(9);
        lista.inserirInicio(3);
        lista.inserir(8, 3);
        lista.inserir(4, 2);
        lista.mostrar();
        x1 = lista.removerInicio();
        x2 = lista.removerFim();
        x3 = lista.remover(2);
        System.out.print(x1 + ", " + x2 + ", " + x3);
        lista.mostrar();
    }
}