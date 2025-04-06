public class Fila {
    private int[] array;
    private int n;
    private Lista l;

    public Fila(){
        this(6);
    }
    public Fila(int tamanho){
        array = new int[tamanho];
        n = 0;
        l = new Lista();
    }
     public static void main(String[] args){
        System.out.println("==== LISTA LINEAR ====");
        Fila f = new Fila(6);
        int x1, x2, x3;
        
        f.l.inserirFim(7);
        f.l.inserirFim(9);
        f.l.inserirFim(15);
        f.l.mostrar();
        x1 = f.l.removerInicio();
        f.l.inserirFim(2);
        f.l.inserirFim(21);
        f.l.mostrar();
        f.l.inserirFim(3);
        x2 = f.l.removerInicio();
        x3 = f.l.removerInicio();
        System.out.print(x1 + ", " + x2 + ", " + x3);
        f.l.mostrar();
    }
}