import java.util.ArrayList;
import java.util.Scanner;

public class Van {
    public ArrayList<Alunos> lista;

    public Van(){
        lista = new ArrayList<>();
    }

    public void sort(){
        quicksort(0, lista.size()-1);
    }

    public void swap(int i, int j){
        Alunos tmp = lista.get(i);
        lista.set(i, lista.get(j));
        lista.set(j, tmp);
    }

    public void quicksort(int esq, int dir) {
        int i = esq, j = dir;
        int pivoD = lista.get((esq+dir)/2).getDistancia();
        String pivoR = lista.get((esq+dir)/2).getRegiao();
        String pivoName = lista.get((esq+dir)/2).getNome();

        while(i <= j){
            while(lista.get(i).getDistancia() < pivoD || 
            (pivoD == lista.get(i).getDistancia() && lista.get(i).getRegiao().compareTo(pivoR) < 0) || 
            (pivoD == lista.get(i).getDistancia() && lista.get(i).getNome().compareTo(pivoName) < 0)) i++;
            while(lista.get(j).getDistancia() > pivoD || 
            (pivoD == lista.get(j).getDistancia() && lista.get(j).getRegiao().compareTo(pivoR) > 0) || 
            (pivoD == lista.get(j).getDistancia() && lista.get(j).getNome().compareTo(pivoName) > 0)) j--;

            if(i <= j){
                swap(i, j);
                i++;
                j--;
            }
        }
        if (esq < j) quicksort(esq, j);
        if (i < dir) quicksort(i, dir);
    }

    public void mostrar(){
        for(int i=0; i < lista.size(); i++){
            System.out.println(lista.get(i).getNome());
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Van van = new Van();

        while (sc.hasNext()) {
            for(int i=0; i < n; i++){
                Alunos al = new Alunos();

                String nome = sc.next();
                al.setNome(nome);
                String regiao = sc.next();
                al.setRegiao(regiao);
                int distancia = sc.nextInt();
                al.setDistancia(distancia);

                van.lista.add(al);
            }
        }
        van.sort();
        van.mostrar();

        sc.close();
    }
}

class Alunos {
    private String nome;
    private String regiao;
    private int distancia;

    public Alunos(){
        nome = "";
        regiao = "";
        distancia = 0;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setRegiao(String regiao){
        this.regiao = regiao;
    }

    public void setDistancia(int d){
        this.distancia = d;
    }

    public String getNome(){
        return nome;
    }

    public String getRegiao(){
        return regiao;
    }

    public int getDistancia(){
        return distancia;
    }
}
