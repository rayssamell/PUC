public class Pilha2 {
    private Celula topo;

    public Pilha2(){
        topo = null;
    }

    public void inserir(int x){
        Celula tmp = new Celula(x);
        tmp.prox = topo;
        topo = tmp;
        tmp.prox = null;
        tmp = null;      
    }

    public int remover() throws Exception{
        if(topo == null) throw new Exception("PILHA VAZIA");

        int elemento = topo.elemento;
        Celula tmp = topo;
        topo = tmp.prox;
        tmp.prox = null;
        tmp = null;

        return elemento;
    }

    public int getSoma(){
        int soma = 0;

        for(Celula i=topo; i!= null; i=i.prox){
            soma += i.elemento;
        }
        return soma;
    }

    public int somaRec(){
        return somaRec(topo);
    }

    public int somaRec(Celula i){
        int soma = 0;

        if(i != null){
            soma += i.elemento + somaRec(i.prox);
        }
        return soma;
    }

    public void mostrar(){
        System.out.print("[");
        for(Celula i=topo; i!= null; i=i.prox){
            System.out.print(i.elemento + " ");
        }
        System.out.print("]");
    }

    public int getMaior(){
        int maior = topo.elemento;
        for(Celula i=topo.prox; i!=null; i=i.prox){
            if(i.elemento > maior){
                maior = i.elemento;
            }
        }
        return maior;
    }
}
