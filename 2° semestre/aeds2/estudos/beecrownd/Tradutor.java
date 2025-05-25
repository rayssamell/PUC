import java.util.Scanner;

public class Tradutor {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        Idioma idioma = new Idioma();
        while (sc.hasNext()) {
            String line = sc.nextLine();
            System.out.println();
            idioma.buscar(line);
        }
    
        sc.close();
    }
}

class Idioma {
    private String[] idioma;
    private String[] mensagem;

    public Idioma(){
        idioma = new String[24];
        mensagem = new String[24];
        inserir();
    }

    public void inserir(){
        idioma[0] = "brasil";
        mensagem[0] = "Feliz Natal!";
        idioma[1] = "alemanha";
        mensagem[1] = "Frohliche Weihnachten!";
        idioma[2] = "austria";
        mensagem[2] = "Frohe Weihnacht!";
        idioma[3] = "coreia";
        mensagem[3] = "Chuk Sung Tan!";
        idioma[4] = "espanha";
        mensagem[4] = "Feliz Navidad!";
        idioma[5] = "grecia";
        mensagem[5] = "Kala Christougena!";
        idioma[6] = "estados-unidos";
        mensagem[6] = "Merry Christmas!";
        idioma[7] = "inglaterra";
        mensagem[7] = "Merry Christmas!";
        idioma[8] = "australia";
        mensagem[8] = "Merry Christmas!";
        idioma[9] = "portugal";
        mensagem[9] = "Feliz Natal!";
        idioma[10] = "suecia";
        mensagem[10] = "God Jul!";
        idioma[11] = "turquia";
        mensagem[11] = "Mutlu Noeller";
        idioma[12] = "argentina";
        mensagem[12] = "Feliz Navidad!";
        idioma[13] = "chile";
        mensagem[13] = "Feliz Navidad!";
        idioma[14] = "mexico";
        mensagem[14] = "Feliz Navidad!";
        idioma[15] = "antardida";
        mensagem[15] = "Merry Christmas!";
        idioma[16] = "canada";
        mensagem[16] = "Merry Christmas!";
        idioma[17] = "irlanda";
        mensagem[17] = "Nollaig Shona Dhuit!";
        idioma[18] = "belgica";
        mensagem[18] = "Zalig Kerstfeest!";
        idioma[19] = "italia";
        mensagem[19] = "Buon Natale!";
        idioma[20] = "libia";
        mensagem[20] = "Buon Natale!";
        idioma[21] = "siria";
        mensagem[21] = "Milad Mubarak!";
        idioma[22] = "marrocos";
        mensagem[22] = "Milad Mubarak!";
        idioma[23] = "japao";
        mensagem[23] = "Merii Kurisumasu!";
    }

    public void buscar(String idioma){
        boolean achou = false;
        for(int i=0; i < this.idioma.length; i++){
            if(idioma.equals(this.idioma[i])){
                System.out.print(mensagem[i]);
                achou = true;
                i = this.idioma.length;
            }
        }
        if(!achou){
            System.out.print("--- NOT FOUND ---");
        }
    }
}
