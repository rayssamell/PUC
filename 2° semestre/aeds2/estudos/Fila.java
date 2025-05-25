public class Fila {
    private Celula primeiro;
    private Celula ultimo;

    //Construtor
    public Fila(){
        primeiro = new Celula(); //celula cabeca
        ultimo = primeiro;
    }

    //Inserir elemento: primeiro que entra primeiro que sai
    public void inserir(int x){
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }

    //Remover elemento
    public int remover() throws Exception{
        if(primeiro == ultimo) throw new Exception("ERRO"); //fila vazia
        Celula tmp = primeiro.prox;
        int elemento = tmp.elemento;
        primeiro.prox = tmp.prox;
        tmp.prox = null;
        tmp = null;

        return elemento;
    }

    public void mostrar(){
        System.out.print("[");
        for(Celula i =primeiro.prox; i != null; i=i.prox){
            System.out.print(i.elemento + " ");
        }
        System.out.println("]");
    }

   
}
