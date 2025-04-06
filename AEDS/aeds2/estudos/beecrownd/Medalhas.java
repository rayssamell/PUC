import java.util.Scanner;

public class Medalhas {
    private Quadro[] medalhas;
    private int n;

    public Medalhas(int n){
        medalhas = new Quadro[n];
        this.n = 0;
    }

    public void inserir(Quadro quadro){
        medalhas[n] = quadro;
        n++; 
    }

    public void sort() {
        mergesort(0, n-1);
    }

    private void mergesort(int esq, int dir) {
        if (esq < dir){
            int meio = (esq + dir) / 2;
            mergesort(esq, meio);
            mergesort(meio + 1, dir);
            intercalar(esq, meio, dir);
        }
    }

    //Algoritmo que intercala os elementos entre as posicoes esq e dir
    public void intercalar(int esq, int meio, int dir){
        int n1, n2;

        //Definir tamanho dos dois subarrays
        n1 = meio-esq+1;
        n2 = dir - meio;

        Quadro[] a1 = new Quadro[n1 + 1];
        Quadro[] a2 = new Quadro[n2 + 1];

        //Inicializar primeiro subarray
        for (int i = 0; i < n1; i++) {
            a1[i] = medalhas[esq+i];
        }

        //Inicializar segundo subarray
        for (int j = 0; j < n2; j++) {
            a2[j] = medalhas[meio + 1 + j];
        }
    
        a1 = new Quadro[n1 + 1];
        a2 = new Quadro[n2 + 1];

        int i = 0, j = 0;
        for (int k = esq; k <= dir; k++) {

            // Verifica se todos os elementos foram copiados
            if (i >= a1.length) {
                medalhas[k] = a2[j++];  
            } else if (j >= a2.length) { 
                medalhas[k] = a1[i++];
            } else {
                Quadro quadroA1 = a1[i];
                Quadro quadroA2 = a2[j];

                // Verifica se a1[i] ou a2[j] sao nulos
                if (quadroA1 == null) {
                    medalhas[k] = quadroA2;
                    j++;
                } else if (quadroA2 == null) {
                    medalhas[k] = quadroA1;
                    i++;
                } else {
                    // se primeiro antecede o segundo
                    if (quadroA1.ouro > quadroA2.ouro) {
                        medalhas[k] = quadroA1;
                        i++;
                    } else if (quadroA1.ouro < quadroA2.ouro) {
                        medalhas[k] = quadroA2;
                        j++;
                    } else {
                        if (quadroA1.prata < quadroA2.prata) {
                            medalhas[k] = quadroA1;
                            i++;
                        } else if (quadroA1.prata > quadroA2.prata) {
                            medalhas[k] = quadroA2;
                            j++;
                        } else {
                            if (quadroA1.bronze < quadroA2.bronze) {
                                medalhas[k] = quadroA1;
                                i++;
                            } else if (quadroA1.bronze > quadroA2.bronze) {
                                medalhas[k] = quadroA2;
                                j++;
                            } else {
                                int compare = quadroA1.pais.compareTo(quadroA2.pais);
                                if(compare < 0){
                                    medalhas[k] = quadroA1;
                                    i++;
                                } else if(compare > 0){
                                    medalhas[k] = quadroA2;
                                    j++;
                                }
                            }
                        }
                    }
                }
            }
        }        
    }

    public void mostrar(){
        for(int i=0; i < n; i++){
            System.out.print(medalhas[i].pais + " " + medalhas[i].ouro + " " + medalhas[i].prata + " " + medalhas[i].bronze);
            System.out.println();
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Medalhas medalha = new Medalhas(n);
        for(int i=0; i<n; i++){
            Quadro q = new Quadro();

            q.pais = sc.next();
            q.ouro = sc.nextInt();
            q.prata = sc.nextInt();
            q.bronze = sc.nextInt();

            medalha.inserir(q);
        }
        medalha.sort();
        medalha.mostrar();

        sc.close();
    }    
}

class Quadro {
    public String pais;
    public int ouro;
    public int prata;
    public int bronze;

    public Quadro(){
        pais = "";
        ouro = 0;
        prata = 0;
        bronze = 0;
    }
}