import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

public class Estiagem {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int cont = 1;
        Residencia res = new Residencia();

        int n = sc.nextInt();
        while(n != 0){
            for(int i=0; i < n; i++){
                int quant = sc.nextInt();
                int consumo = sc.nextInt();
                res.setQuant(quant);
                res.setConsumo(consumo);
            }
            System.out.println("Cidade# " + cont + ":");
            res.calcular();
            if(cont < n-1){
                System.out.println();
                System.out.println();
            }
            cont++;
            n = sc.nextInt();
        }
        sc.close();
    }    
}

class Residencia {
    private ArrayList<Integer> quant; //quantidade de pessoas
    private ArrayList<Integer> consumo; //consumo total

    public Residencia(){
        quant = new ArrayList<>();
        consumo = new ArrayList<>();
    }

    public void setQuant(int quant){
        this.quant.add(quant);
    }

    public void setConsumo(int consumo){
        this.consumo.add(consumo);
    }

    public void swap(ArrayList<Integer> list, int i, int j) {
        int tmp = list.get(i);
        list.set(i, list.get(j));
        list.set(j, tmp);
    }

    public void quicksort(){
        quicksort(0, consumo.size()-1);
    }
    public void quicksort(int esq, int dir){
        int i = esq, j = dir;
        int pivo = consumo.get((esq+dir)/2);

        while(i <= j){
            while(consumo.get(i) < pivo) i++;
            while(consumo.get(j) > pivo) j--;
            if(i <= j){
                swap(consumo, i, j);
                swap(quant, i, j);
                i++;
                j--;
            }
        }
        if (esq < j)  quicksort(esq, j);
        if (i < dir)  quicksort(i, dir);
    }

    public void ordenar() {
        // Consolidar duplicatas após ordenação
        for (int i = 0; i < consumo.size() - 1; i++) {
            if (consumo.get(i).equals(consumo.get(i + 1))) {
                // Somar quantidades de duplicatas
                quant.set(i, quant.get(i) + quant.get(i + 1));
                
                // Remover o próximo elemento (duplicado)
                consumo.remove(i + 1);
                quant.remove(i + 1);
            
                i--;
            }
        }
    }

    public double truncarParaDuasCasas(double valor) {
        return Math.floor(valor * 100) / 100.0;
    }

    public void calcular(){
        int soma = 0;
        int p = 0;
        for(int i=0; i < consumo.size(); i++){
            soma += consumo.get(i);
            p += quant.get(i);
            int pessoa = consumo.get(i) / quant.get(i);
            consumo.set(i, pessoa);
        }
        ordenar();
        quicksort();
        double consumoP = (double)soma / (double)p;

        for(int i=0; i < consumo.size(); i++){
            System.out.print(quant.get(i) + "-" + consumo.get(i));
            if(i < consumo.size() - 1){
                System.out.print(" ");
            }
        }
        System.out.println();
        System.out.printf(Locale.US, "Consumo medio: %.2f m3.", truncarParaDuasCasas(consumoP));
        
        quant.clear();
        consumo.clear();
    }
}