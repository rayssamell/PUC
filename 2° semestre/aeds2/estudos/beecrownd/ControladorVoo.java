import java.util.ArrayList;
import java.util.Scanner;

public class ControladorVoo {
    private ArrayList<String> norte;
    private ArrayList<String> sul;
    private ArrayList<String> leste;
    private ArrayList<String> oeste;
    
    public ControladorVoo(){
        norte = new ArrayList<>();
        sul = new ArrayList<>();
        leste = new ArrayList<>();
        oeste = new ArrayList<>();
    }

    public void setNorte(String[] norte){
        for (String entry : norte) {
            this.norte.add(entry);
        }
    }

    public void setSul(String[] sul){
        for (String entry : sul) {
            this.sul.add(entry);
        }
    }

    public void setLeste(String[] line) {
        for (String entry : line) {
            this.leste.add(entry);
        }
    }

    public void setOeste(String[] oeste){
        for (String entry : oeste) {
            this.oeste.add(entry);
        }
    }

    public ArrayList<String> getNorte(){
        return norte;
    }
    public ArrayList<String> getSul(){
        return sul;
    }
    public ArrayList<String> getLeste(){
        return leste;
    }
    public ArrayList<String> getOeste(){
        return oeste;
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Fila fila = new Fila();
        ControladorVoo cv = new ControladorVoo();

        String p = sc.nextLine();
        String[] line = null;

        int i = 0;
        while (!p.equals("0")){ 
            line[i] = p;
            i++;
            p = sc.nextLine();
        }

       

        sc.close(); 
    }


}

class Celula{
    public int elemento;
    public Celula prox;

    public Celula(){
        this(0);
    }
    public Celula(int elemento){
        this.elemento = elemento;
        this.prox = null;
    }
}

class Fila{
    private Celula primeiro;
    private Celula ultimo;

    public Fila(){
        primeiro = new Celula();
        ultimo = primeiro;
    }

    public void inserir(int x){
        Celula tmp = new Celula(x);
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;
        if(primeiro == ultimo){
            ultimo = tmp;
        }
        tmp.prox = null;
        tmp = null;
    }
}