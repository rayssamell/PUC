import java.util.Scanner;
import java.util.ArrayList; 

public class Etiquetas {
    private ArrayList<String> idioma ;
    private ArrayList<String> frase ;

    public Etiquetas(){
        idioma = new ArrayList<>();
        frase = new ArrayList<>();
    }
    public Etiquetas(String idioma, String frase){
        this.idioma.add(idioma);
        this.frase.add(frase);
    }

    public void setIdioma(String idioma){
        this.idioma.add(idioma);
    }
    public int getIdioma(String id){
        int indice = -1;
        for(int i=0; i < idioma.size(); i++){
            if(idioma.get(i).equals(id)){
                indice = i;
            }
        }
        return indice;
    }

    public void setFrase(String frase){
        this.frase.add(frase);
    }
    public String getFrase(int i){
        return frase.get(i);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Etiquetas noel = new Etiquetas();

        int n = sc.nextInt();
        sc.nextLine();
        for(int i=0; i < n; i++){
            String idioma = sc.nextLine();
            String frase = sc.nextLine();
            noel.setIdioma(idioma);
            noel.setFrase(frase);
        }

        int m = sc.nextInt();
        sc.nextLine();

        for(int i=0; i < m; i++){
            String nome = sc.nextLine();
            String idioma = sc.nextLine();
            
            int indice = noel.getIdioma(idioma);
            String frase = noel.getFrase(indice);

            System.out.println(nome);
            System.out.println(frase);
            System.out.println();
        }

        sc.close();
    }
}
