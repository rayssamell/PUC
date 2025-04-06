import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Quest {
    public List<Elfos> list;

    public Quest(int n){
        list = new ArrayList<>(n);
    }

    public void sort() {
        mergesort(0, list.size()-1);
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

        List<Elfos> a1 = new ArrayList<>(n1 + 1);
        List<Elfos> a2 = new ArrayList<>(n2 + 1);

        //Inicializar primeiro subarray
        for (int i = 0; i < n1; i++) {
            a1.add(list.get(esq + i));
        
        }

        //Inicializar segundo subarray
        for (int j = 0; j < n2; j++) {
            a2.add(list.get(meio + 1 + j));
        
        }
    
        a1.add(null);
        a2.add(null);

        int i = 0, j = 0;
        for (int k = esq; k <= dir; k++) {

            // Verifica se todos os elementos foram copiados
            if (i >= a1.size()) {  
                list.set(k, a2.get(j++));
            
            } else if (j >= a2.size()) { 
                list.set(k, a1.get(i++));
            
            } else {
                Elfos elfosA1 = a1.get(i);
                Elfos elfosA2 = a2.get(j);

                // Verifica se a1[i] ou a2[j] sao nulos
                if (elfosA1 == null) {
                    list.set(k, elfosA2); // Se a1[i] nulo, usa a2[j]
                    j++;
                } else if (elfosA2 == null) {
                    list.set(k, elfosA1); // Se a2[j] nulo, usa a1[i]
                    i++;
                } else {
                    // se primeiro antecede o segundo
                    if (elfosA1.getPeso() > elfosA2.getPeso()) {
                        list.set(k, elfosA1);
                        i++;
                    } else if (elfosA1.getPeso() < elfosA2.getPeso()) {
                        list.set(k, elfosA2);
                        j++;
                    } else {
                        if (elfosA1.getIdade() < elfosA2.getIdade()) {
                            list.set(k, elfosA1);
                            i++;
                        } else if (elfosA1.getIdade() > elfosA2.getIdade()) {
                            list.set(k, elfosA2);
                            j++;
                        } else {
                            int compare = elfosA1.getNome().compareTo(elfosA2.getNome());
                            if(compare < 0){
                                list.set(k, elfosA1);
                                i++;
                            } else if(compare > 0){
                                list.set(k, elfosA2);
                                j++;
                            }
                        }
                    }
                }
            }
        }        
    }

    public void mostrar(int m){
        int j = 1;
        for(int i=0; i < m; i++, j++){
            System.out.println(j + " - " + list.get(i).getNome());
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        sc.nextLine();

        int x = 1;
        for(int i=0; i < t; i++){
            int n = sc.nextInt();
            int m = sc.nextInt();   
            sc.nextLine();

            Quest list = new Quest(n);
            String[] partes = new String[4];

            for(int j=0; j < n; j++){
                Elfos elfos = new Elfos();

                partes[0] = sc.next();
                elfos.setName(partes[0]);

                partes[1] = sc.next();
                elfos.setPeso(Integer.parseInt(partes[1]));
                
                partes[2] = sc.next();
                elfos.setIdade(Integer.parseInt(partes[2]));
               
                partes[3] = sc.next();
                elfos.setAltura(Double.parseDouble(partes[3]));

                list.list.add(elfos);
            }
            list.sort();
            
            System.out.println("CENARIO {" + x + "}");
            x++;
            list.mostrar(m);

        }

        sc.close();
    }
}

class Elfos {
    private String nome;
    private int peso;
    private int idade;
    private double altura;

    public Elfos(){
        nome = "";
        peso = 0;
        idade = 0;
        altura = 0.0;
    }

    public void setName(String nome){
        this.nome = nome;
    }

    public void setPeso(int peso){
        this.peso = peso;
    }

    public void setIdade(int idade){
        this.idade = idade;
    }

    public void setAltura(double altura){
        this.altura = altura;
    }

    public String getNome(){
        return nome;
    }

    public int getPeso(){
        return peso;
    }

    public int getIdade(){
        return idade;
    }

    public double getAltura(){
        return altura;
    }
}