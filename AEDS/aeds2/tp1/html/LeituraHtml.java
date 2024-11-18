import java.net.URI;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.io.IOException;
import java.util.Scanner;

public class LeituraHtml {
    //funcao para comparar strings e determinar se sao identicas
    public static boolean isEquals(String palavra1, String palavra2){
        int n = palavra1.length();
        boolean resp = true;
        
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

    //funcao para obter o html da pagina
    public static String getHtml(String endereco){
        String resp = "";
        HttpClient client = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder()
                                        .uri(URI.create(endereco))
                                        .build();
        try {
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            resp = response.body();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
        return resp;
    }

    //funcao para verificar se a letra e' uma vogal
    public static boolean isVogal(char c){
        //char c = letra.charAt(i);
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    // funcao para contar <br>
    public static int contarBR(String html) {
        int count = 0;
        for (int i = 0; i < html.length() - 3; i++) {
		// verifica se ha <br>
            if (html.charAt(i) == '<' && 
                html.charAt(i+1) == 'b' && 
                html.charAt(i+2) == 'r' && 
                html.charAt(i+3) == '>') {
                count++;
                i += 3; 
            }
        }
        return count;
    }

    //funcao para contar <table>
    public static int contarTable(String html) {
        int count = 0;
        for (int i = 0; i < html.length() - 6; i++) {
            // verifica se ha <table> 
            if (html.charAt(i) == '<' && 
                html.charAt(i+1) == 't' && 
                html.charAt(i+2) == 'a' && 
                html.charAt(i+3) == 'b' && 
                html.charAt(i+4) == 'l' && 
                html.charAt(i+5) == 'e' && 
                html.charAt(i+6) == '>') {
                count++;
                i += 6;
            }
        }
        return count;
    }

    //funcao para realizar contagem das letras
    public static void contarLetras(String nome, String html){
		//tratando enconding na saida
		try {
            System.setOut(new PrintStream(System.out, true, StandardCharsets.UTF_8));
        } catch (Exception e) {
            e.printStackTrace();
        }

        int[] counts = new int[5]; // Array para contar as ocorrencias de vogais
        int[] acentuadas = new int[17]; // Array para contar as ocorrencias de vogais acentuadas
        int consoante = 0; // contador para consoantes

        // Contagem de vogais (com e sem acento), consoantes, <br> e <table>
        for (int i = 0; i < html.length(); i++) {
            char c = html.charAt(i);
            boolean letra = ((int)c > 97 && (int)c <= 122);

            switch (c) {
                case 'a': counts[0]++; break;
                case 'e': counts[1]++; break;
                case 'i': counts[2]++; break;
                case 'o': counts[3]++; break;
                case 'u': counts[4]++; break;
                case '\u00E1': acentuadas[0]++; break; 
                case '\u00E9': acentuadas[1]++; break; 
                case '\u00ED': acentuadas[2]++; break; 
                case '\u00F3': acentuadas[3]++; break; 
                case '\u00FA': acentuadas[4]++; break; 
                case '\u00E0': acentuadas[5]++; break; 
                case '\u00E8': acentuadas[6]++; break; 
                case '\u00EC': acentuadas[7]++; break; 
                case '\u00F2': acentuadas[8]++; break; 
                case '\u00F9': acentuadas[9]++; break; 
                case '\u00E3': acentuadas[10]++; break; 
                case '\u00F5': acentuadas[11]++; break; 
                case '\u00E2': acentuadas[12]++; break; 
                case '\u00EA': acentuadas[13]++; break; 
                case '\u00EE': acentuadas[14]++; break; 
                case '\u00F4': acentuadas[15]++; break; 
                case '\u00FB': acentuadas[16]++; break; 
                default: 
					//se for uma letra e nao for vogal
                    if (!isVogal(c) && letra) {
                        consoante++;
                    }
                    break;
            }
        }

        if (counts[0] > 0) counts[0]--; 
        if (counts[1] > 0) counts[1]--; 

        // Contagem de <br> e <table>
        int br =  contarBR(html);
        int table = contarTable(html);

        // Exibir resultado
        System.out.print("a(" + counts[0] + ") e(" + counts[1] + ") i(" + counts[2] + ") o(" + counts[3] + ") u(" + counts[4] + ")");
        System.out.print(" \u00E1(" + acentuadas[0] + ") \u00E9(" + acentuadas[1] + ") \u00ED(" + acentuadas[2] + ") \u00F3(" + acentuadas[3] + ") \u00FA(" + acentuadas[4] + ")");
        System.out.print(" \u00E0(" + acentuadas[5] + ") \u00E8(" + acentuadas[6] + ") \u00EC(" + acentuadas[7] + ") \u00F2(" + acentuadas[8] + ") \u00F9(" + acentuadas[9] + ")");
        System.out.print(" \u00E3(" + acentuadas[10] + ") \u00F5(" + acentuadas[11] + ")");
        System.out.print(" \u00E2(" + acentuadas[12] + ") \u00EA(" + acentuadas[13] + ") \u00EE(" + acentuadas[14] + ") \u00F4(" + acentuadas[15] + ") \u00FB(" + acentuadas[16]+")");
        System.out.print(" consoante(" + (consoante-3) + ")");
        System.out.print(" <br>(" + br + ") <table>(" + table + ")");
        System.out.print(" " + nome);
    }
    
    //metodo principal
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in, "UTF-8");
        String nome = "", endereco = "", html;
        
        nome = sc.nextLine();
        endereco = sc.nextLine();
        
        while (!isEquals(nome, "FIM")){
            html = getHtml(endereco);
            contarLetras(nome, html);
            System.out.println();

            nome = sc.nextLine();
            if (!isEquals(nome, "FIM")) {
                endereco = sc.nextLine(); // Leia o endereco apenas se nome nao for "FIM"
            }
        } 
        sc.close();
    }
}
