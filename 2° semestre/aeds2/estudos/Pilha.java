public class Pilha {
    private Celula topo;

    //Construtor
    public Pilha(){
        topo = null;
    }

    //Inserir: primeiro que entra ultimo que sai
    public void inserir(int x){
        Celula tmp = new Celula(x); //nova celula com o elemento
        tmp.prox = topo;
        topo = tmp;
        tmp = null;
    }

    //Remover: remover topo
    public int remover() throws Exception{
        if(topo == null) throw new Exception("ERRO"); //pilha vazia

        int elemento = topo.elemento; //elemento a ser removido
        Celula tmp = topo; //guarda o topo no tmp
        topo = topo.prox; //atualiza o topo
        tmp.prox = null; //libera referencia
        tmp = null; //libera referencia
        return elemento;
    }

    //Mostrar elementos da Pilha
    public void mostrar(){
        System.out.print("[");
        for(Celula i=topo; i!=null; i=i.prox){
            System.out.print(i.elemento + " ");
        }
        System.out.println("]");
    }

    //Somar valores da pilha: iterativo
    public int getSomaInterativo(){
        int soma = 0;
        for(Celula i=topo; i != null; i = i.prox){
            soma += i.elemento;
        }
        return soma;
    }

    //Somar valores da pilha: recursivo
    public int getSomaRec(){
        return getSomaRec(topo);
    }

    public int getSomaRec(Celula i){
        int soma = 0;
        //caso base
        if(i != null){
            soma += i.elemento + getSomaRec(i.prox);
        }
        return soma;
    }

    //Função para buscar maior valor
    public int getMaior(){
        int maior = topo.elemento;
        for(Celula i=topo.prox; i!=null; i=i.prox){
            if(i.elemento > maior){
                maior = i.elemento;
            }
        }
        return maior;
    }

    //Mostrar Recursivo
    public void mostraPilha() {
		mostraPilha(topo);
	}

	private void mostraPilha(Celula i) {
		if (i != null) {
			mostraPilha(i.prox);
			System.out.println("" + i.elemento);
		}
	}
}

