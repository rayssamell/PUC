public class Fila2 {
    private Celula primeiro;
    private Celula ultimo;

    public Fila2(){
        primeiro = new Celula();
        ultimo = primeiro;
    }

    public void inserir(int x){
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }

    public int remover() throws Exception{
        if(primeiro == ultimo) throw new Exception("FILA VAZIA");

        int elemento = primeiro.prox.elemento;

        Celula tmp = primeiro.prox;
        primeiro.prox = tmp.prox;
        tmp.prox = null;
        tmp = null;
        return elemento;
    }

    public int getSoma(){
        int soma = 0;
        for(Celula i=primeiro.prox; i != null; i=i.prox){
            soma += i.elemento;
        }
        return soma;
    }

    public void mostrar(){
        System.out.print("[");
        for(Celula i=primeiro.prox; i != null; i=i.prox){
            System.out.println(i.elemento + " ");
        }
        System.out.println("]");
    }

    public int somaRec(){
        return somaRec(primeiro.prox);
    }

    public int somaRec(Celula i){
        int soma = 0;
        if(i != null){
            soma += i.elemento + somaRec(i.prox);
        }
        return soma;
    }

    public int getMaior(){
        int maior = 0;
        for(Celula i=primeiro.prox; i!=null; i=i.prox){
            maior = i.elemento;
            if(maior < i.prox.elemento){
                maior = i.prox.elemento;
            }
        }
        return maior;
    }
}
