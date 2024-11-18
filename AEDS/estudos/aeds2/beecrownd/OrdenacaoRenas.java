import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class OrdenacaoRenas {
    public List<Renas> renas;

    public OrdenacaoRenas(int n){
        renas = new ArrayList<>(n);
    }

    public void swap(int i, int j){
        Renas tmp = renas.get(i);
        renas.set(i, renas.get(j));
        renas.set(j, tmp);
    }

    public void ordenacaoPeso(){
        for(int i=0; i < renas.size()-1; i++){
            for(int j=0; j < renas.size()-i-1; j++){
                double rena1 = renas.get(j).getPeso();
                double rena2 = renas.get(j+1).getPeso();
                if(rena1 == rena2){
                    if(renas.get(j).getIdade() == renas.get(j+1).getIdade()){
                        if(renas.get(j).getAltura() == renas.get(j+1).getAltura()){
                            if (renas.get(j).getNome().compareTo(renas.get(j + 1).getNome()) > 0) {
                                swap(j, j+1);
                            }
                        } else if(renas.get(j).getAltura() > renas.get(j+1).getAltura()){
                            swap(j, j+1);
                        }
                    } else if(renas.get(j).getIdade() > renas.get(j+1).getIdade()){
                        swap(j, j+1);
                    } 
                } else {
                    if(rena1 < rena2){
                        swap(j+1, j);
                    }
                }
            }
        }
    }

    public void mostrar(int m){
        System.out.println("CENARIO {1}");
        for(int i=0; i < m; i++){
            System.out.println(i + " - " + renas.get(i).getNome());
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        int n = sc.nextInt();
        int m = sc.nextInt();

        OrdenacaoRenas oR = new OrdenacaoRenas(n);
        String[] partes = new String[4];
        for(int i=0; i < t; i++){
            for(int j=0; j < n; j++){
                Renas rena = new Renas();
                
                partes[0] = sc.next();
                rena.setNome(partes[0]); 
        
                partes[1] = sc.next();
                rena.setPeso(Double.parseDouble(partes[1]));

                partes[2] = sc.next();
                rena.setIdade(Integer.parseInt(partes[2]));

                partes[3] = sc.next();
                rena.setAltura(Double.parseDouble(partes[3]));

                oR.renas.add(rena);
            }
        }
        oR.ordenacaoPeso();
        oR.mostrar(m);
        sc.close();
    }
}

class Renas {
    private String nome;
    private double peso;
    private int idade;
    private double altura;

    public Renas(){
        nome = "";
        peso = 0.0;
        idade = 0;
        altura = 0.0;
    }

    public String getNome(){
        return nome;
    }
    public double getPeso(){
        return peso;
    }
    public int getIdade(){
        return idade;
    }
    public double getAltura(){
        return altura;
    }
    public void setNome(String nome){
        this.nome = nome;
    }
    public void setIdade(int idade){
        this.idade = idade;
    }
    public void setPeso(double peso){
        this.peso = peso;
    }
    public void setAltura(double altura){
        this.altura = altura;
    }
}