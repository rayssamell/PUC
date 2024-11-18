import java.util.Scanner;

public class BalancoParenteses {
    //funcao para verificar se as pelavras sao iguais
    public static boolean isEquals(String palavra1, String palavra2){
        int n = palavra1.length();
        boolean resp = true;
        // comparar tamanho das palavras 1 e 2
        if(n != palavra2.length()){
            resp = false;
        } else {
            for(int i = 0; i < n; i++){
                if(palavra1.charAt(i) != palavra2.charAt(i)){
                    resp = false;
                    i = n;
                 }
            }
        }
        return (resp);
    }

    //funcao para verificar se os parentes () estao corretos
    public static void isCorrectParenteses(String expressao){
        int cont = 0;
        boolean aberto = false; 

        for (int i = 0; i < expressao.length(); i++) {
            char c = expressao.charAt(i);
            if (c == '(') {
               cont++;
               aberto = true;
            } else if(c == ')' && aberto){
                cont--;
            } 
        }
        if(cont % 2 == 0) System.out.println("correto");
        else System.out.println("incorreto");
    }

    //metodo principal
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String expressao = sc.nextLine();

        while(!isEquals(expressao, "FIM")){
            isCorrectParenteses(expressao);
            expressao = sc.nextLine();
        }

        sc.close();
    }
}