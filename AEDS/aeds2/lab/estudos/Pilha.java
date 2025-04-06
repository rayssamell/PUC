public class Pilha {
    private Lista l;
    private int[] array; // Array que armazenara os elementos da pilha
    private int n;       // Contador de elementos na pilha

    public Pilha(){
        this(6);
        
    }
    public Pilha(int tamanho) {
        array = new int[tamanho]; 
        n = 0; 
        l = new Lista(); 
    }
    public static void main(String[] args){
        System.out.println("==== LISTA LINEAR ====");
        Pilha p = new Pilha(6);
        int x1, x2, x3;
        
        p.l.inserirFim(7);
        p.l.inserirFim(9);
        p.l.inserirFim(15);
        p.l.mostrar();
        x1 = p.l.removerFim();
        p.l.inserirFim(2);
        p.l.inserirFim(21);
        p.l.mostrar();
        p.l.inserirFim(3);
        x2 = p.l.removerFim();
        x3 = p.l.removerFim();
        System.out.print(x1 + ", " + x2 + ", " + x3);
        p.l.mostrar();
    }
}