package visao;

import aeds3.ElementoLista;
import aeds3.ListaInvertida;
import entidades.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import modelo.ArquivoAtor;
import modelo.ArquivoElenco;
import modelo.ArquivoSeries;

public class MenuAtores {
     ListaInvertida lista;

    ArquivoAtor arqAtores = new ArquivoAtor();
    ArquivoElenco arqElenco = new ArquivoElenco();
    
    ArquivoSeries arqSeries = new ArquivoSeries();

    private static Scanner console = new Scanner(System.in);

    public MenuAtores() throws Exception {
        arqSeries = new ArquivoSeries();
        arqAtores = new ArquivoAtor();
          File d = new File("dados");
        if (!d.exists())
            d.mkdir();
        lista = new ListaInvertida(100, "dados/ator/dicionario_ator.listainv.db", "dados/ator/blocos_ator.listainv.db");
    }

  public void menu() throws Exception {
    int opcao;
    do {
        System.out.println("\n\nPUCFlix 2.0");
        System.out.println("-----------");
        System.out.println("> Início > Atores");
        System.out.println("1) Buscar");
        System.out.println("2) Alterar");
        System.out.println("3) Excluir");
        System.out.println("4) Mostrar todos as series de um ator");
        System.out.println("0) Retornar ao menu anterior");

        System.out.print("\nOpção: ");
        try {
            opcao = Integer.valueOf(console.nextLine());
        } catch (NumberFormatException e) {
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                buscarAtor();
                break;
            case 2:
                alterarAtor();
                break;
            case 3:
                excluirAtor();
                break;
            case 4:
                mostrarSeriesDoAtores();
                break;
            case 0:
                break;
            default:
                System.out.println("Opção inválida!");
                break;
        }
    } while (opcao != 0);
}


    public void incluirAtores(int idSerie) throws Exception {
        System.out.println("\nInclusão de Atores");
        System.out.println();
        boolean dadosCorretos = false;

        String nome = "", nacionalidade = "", papel = "";
        int tempoTela = 0;


        LocalDate dataNasc = LocalDate.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

        // Nome
        do {
            System.out.print("Nome do Ator (min. 2 letras): ");
            nome = console.nextLine();
        } while (nome.length() < 2);

        // Nacionalidade
        do {
            System.out.print("Nacionalidade do Ator (min. 2 letras): ");
            nacionalidade = console.nextLine();
        } while (nacionalidade.length() < 2);

        dadosCorretos = false;
        do {
            System.out.print("Data de nascimento (DD/MM/AAAA): ");
            String dataStr = console.nextLine();
            try {
                dataNasc = LocalDate.parse(dataStr, formatter);
                dadosCorretos = true;
            } catch (Exception e) {
                System.err.println("Data inválida! Use o formato DD/MM/AAAA.");
            }
        } while(!dadosCorretos);

        // Papel
        do {
            System.out.print("Qual papel do Ator na Serie (min. 2 letras): ");
            papel = console.nextLine();
        } while (nome.length() < 2);

        // Tempo de tela
        dadosCorretos = false;
        do {
            System.out.print("Qual o tempo de tela do ator na serie em Minutos (0-999): ");
            if (console.hasNextInt()) {
                tempoTela = console.nextInt();
                dadosCorretos = true;
            }
            console.nextLine();
        } while(!dadosCorretos);
        

        System.out.print("\nConfirma a inclusão do Ator na série? (S/N) ");
        char resp = console.nextLine().charAt(0);
        if (resp == 'S' || resp == 's') {
           
       try {
    Ator at = new Ator(nome, dataNasc, nacionalidade);
    int idAtor = arqAtores.create(at);

    Elenco elenco = new Elenco(papel, tempoTela, idSerie, idAtor);
    int idElenco = arqElenco.create(elenco);

    // Processar termos do nome do ator
    String[] termosNome = nome.toLowerCase().split("\\W+");
    List<String> termosFiltradosNome = new ArrayList<>();
    List<Integer> frequenciasNome = new ArrayList<>();

    gerarTermosComFrequencia(termosNome, termosFiltradosNome, frequenciasNome);
    List<Float> tfNome = calcularFrequencia(frequenciasNome);

    for (int i = 0; i < termosFiltradosNome.size(); i++) {
        String termo = termosFiltradosNome.get(i);
        float freqRelativa = tfNome.get(i);
        lista.incrementaEntidades();
        lista.create(termo, new ElementoLista(idAtor, freqRelativa));
    }

    // Processar termos do papel do elenco
    String[] termosPapel = papel.toLowerCase().split("\\W+");
    List<String> termosFiltradosPapel = new ArrayList<>();
    List<Integer> frequenciasPapel = new ArrayList<>();

    gerarTermosComFrequencia(termosPapel, termosFiltradosPapel, frequenciasPapel);
    List<Float> tfPapel = calcularFrequencia(frequenciasPapel);

    for (int i = 0; i < termosFiltradosPapel.size(); i++) {
        String termo = termosFiltradosPapel.get(i);
        float freqRelativa = tfPapel.get(i);
        lista.incrementaEntidades();
        lista.create(termo, new ElementoLista(idAtor, freqRelativa));
    }

        System.out.println("Ator incluído com sucesso.");
    } catch (Exception e) {
        System.out.println("Erro ao incluir Ator. " + e.getMessage());
    }

        }
    }


    public void createAtores(int Idserie, String nome, LocalDate dataNasc, String nacionalidade) throws Exception 
    {
     
       try {
    Ator at = new Ator(nome, dataNasc, nacionalidade);
    int idAtor = arqAtores.create(at);

    // Processar termos do nome do ator
    String[] termosNome = nome.toLowerCase().split("\\W+");
    List<String> termosFiltradosNome = new ArrayList<>();
    List<Integer> frequenciasNome = new ArrayList<>();

    gerarTermosComFrequencia(termosNome, termosFiltradosNome, frequenciasNome);
    List<Float> tfNome = calcularFrequencia(frequenciasNome);

    for (int i = 0; i < termosFiltradosNome.size(); i++) {
        String termo = termosFiltradosNome.get(i);
        float freqRelativa = tfNome.get(i);
        lista.incrementaEntidades();
        lista.create(termo, new ElementoLista(idAtor, freqRelativa));
    }

    } catch (Exception e) {
        System.out.println("Erro ao incluir Ator. " + e.getMessage());
    }

     }
    
      public void createElenco(String papel, int tempoTela, int idSerie, int idAtor) throws Exception {
     
          try {

    // Processar termos do papel do elenco
    String[] termosPapel = papel.toLowerCase().split("\\W+");
    List<String> termosFiltradosPapel = new ArrayList<>();
    List<Integer> frequenciasPapel = new ArrayList<>();

    gerarTermosComFrequencia(termosPapel, termosFiltradosPapel, frequenciasPapel);
    List<Float> tfPapel = calcularFrequencia(frequenciasPapel);

    for (int i = 0; i < termosFiltradosPapel.size(); i++) {
        String termo = termosFiltradosPapel.get(i);
        float freqRelativa = tfPapel.get(i);
        lista.incrementaEntidades();
        lista.create(termo, new ElementoLista(idAtor, freqRelativa));
    }

        System.out.println("Ator incluído com sucesso.");
    
          }
        catch (Exception e) {
        System.out.println("Erro ao incluir Ator. " + e.getMessage());
    }

     }
    



    public void buscarAtor() throws IOException {
    System.out.println("\nBusca de Atores");

    System.out.print("Nome do Ator: ");
    String nome = console.nextLine().toLowerCase();

    String[] termos = nome.split("\\W+");
    List<String> termosFiltrados = new ArrayList<>();
    List<Integer> frequencias = new ArrayList<>();

    // Filtrar termos que não são stopwords e calcular frequência absoluta
    gerarTermosComFrequencia(termos, termosFiltrados, frequencias);

    System.out.println();

    try {
        List<Integer> ids = new ArrayList<>();
        List<Float> tfidfs = new ArrayList<>();

        for (String s : termosFiltrados) {
            ElementoLista[] resultados = lista.read(s);
            if (resultados.length == 0) {
                System.out.println("Nenhum ator encontrado com o termo '" + s + "'.");
            } else {
                // Calcular IDF
                float idf = calcularIDF(resultados);

                for (ElementoLista el : resultados) {
                    float tf = el.getFrequencia();
                    float tfidf = tf * idf;

                    int id = el.getId();
                    int index = ids.indexOf(id);

                    if (index != -1) {
                        // Se já existe, soma
                        tfidfs.set(index, tfidfs.get(index) + tfidf);
                    } else {
                        // Se não existe, adiciona
                        ids.add(id);
                        tfidfs.add(tfidf);
                    }
                }
            }
        }

        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < ids.size(); i++) {
            indices.add(i);
        }

        // Ordenar os índices de acordo com os TF-IDFs (ordem decrescente)
        indices.sort((i1, i2) -> Float.compare(tfidfs.get(i2), tfidfs.get(i1)));

        System.out.println("Atores encontrados:");
        for (int i : indices) {
            Ator ator = arqAtores.read(ids.get(i));
            if (ator != null) {
                mostraAtor(ator);
                
            }
        }

    } catch (Exception e) {
        System.out.println("Erro ao buscar ator: " + e.getMessage());
    }
}

public Ator buscarIdfAtor(String nome) throws Exception {
    String[] termos = nome.toLowerCase().split("\\W+");
    List<String> termosFiltrados = new ArrayList<>();
    List<Integer> frequencias = new ArrayList<>();

    // Gera termos filtrados e frequência absoluta
    gerarTermosComFrequencia(termos, termosFiltrados, frequencias);

    if (termosFiltrados.isEmpty()) {
        System.out.println("Nenhum termo relevante encontrado.");
        return null;
    }

    List<Integer> ids = new ArrayList<>();
    List<Float> tfidfs = new ArrayList<>();

    for (String termo : termosFiltrados) {
        ElementoLista[] resultados = lista.read(termo);

        if (resultados.length == 0) {
            System.out.println("Nenhum ator encontrado com o termo: " + termo);
            continue;
        }

        float idf = calcularIDF(resultados);

        for (ElementoLista el : resultados) {
            float tf = el.getFrequencia();
            float tfidf = tf * idf;
            int id = el.getId();

            int idx = ids.indexOf(id);
            if (idx != -1) {
                tfidfs.set(idx, tfidfs.get(idx) + tfidf);
            } else {
                ids.add(id);
                tfidfs.add(tfidf);
            }
        }
    }

    if (ids.isEmpty()) {
        System.out.println("Nenhum ator corresponde aos termos fornecidos.");
        return null;
    }

    // Ordena os índices pelo maior TF-IDF
    List<Integer> indices = new ArrayList<>();
    for (int i = 0; i < ids.size(); i++) {
        indices.add(i);
    }
    indices.sort((i1, i2) -> Float.compare(tfidfs.get(i2), tfidfs.get(i1)));

    System.out.println("Atores encontrados:");
    for (int i : indices) {
        Ator ator = arqAtores.read(ids.get(i));
        if (ator != null) {
            mostraAtor(ator);
        }
    }

    // Retorna o ator mais relevante
    return arqAtores.read(ids.get(indices.get(0)));
}

public void alterarAtor() throws Exception {
    System.out.println("\nAlteração de Ator");

    System.out.print("Nome do Ator: ");
    String nome = console.nextLine();
    System.out.println();
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

    try {
        // buscar o ator mais relevante com lista invertida e TF-IDF
        System.out.println(nome);
        Ator ator = buscarIdfAtor(nome);  


        if (ator != null) {
            System.out.println("Ator Encontrado: " + ator.getNome());

            // ------------- Dados a serem atualizados ----------------//
            System.out.print("Novo nome (ou Enter para manter): ");
            String novoNome = console.nextLine();
            if (!novoNome.isEmpty()) {
                ator.setNome(novoNome);
            }

            do {
                System.out.print("Nova data de nascimento (DD/MM/AAAA) (ou Enter para manter): ");
                String novaData = console.nextLine();
                if (novaData.isEmpty()) {
                    break;
                }
                try {
                    ator.setDataNasc(LocalDate.parse(novaData, formatter));
                    break;
                } catch (Exception e) {
                    System.err.println("Data inválida! Use o formato DD/MM/AAAA.");
                }
            } while (true);

            System.out.print("Nova nacionalidade (ou Enter para manter): ");
            String novaNacionalidade = console.nextLine();
            if (!novaNacionalidade.isEmpty()) {
                ator.setNacionalidade(novaNacionalidade);
            }

            System.out.print("\nConfirma as alterações? (S/N) ");
            char resp = console.nextLine().charAt(0);

            if (resp == 'S' || resp == 's') {
                boolean alterado = arqAtores.update(ator);
                if (alterado) {
                    System.out.println("O Ator foi atualizado com sucesso!");

                    // se o nome foi alterado, atualiza a lista invertida
                    if (!novoNome.isEmpty() && !nome.equals(novoNome)) {
                        // atualizar termos
                        String[] novosTermos = novoNome.toLowerCase().split("\\W+");
                        List<String> termosFiltrados = new ArrayList<>();
                        List<Integer> frequencias = new ArrayList<>();

                        gerarTermosComFrequencia(novosTermos, termosFiltrados, frequencias);
                        List<Float> tf = calcularFrequencia(frequencias);

                        for (int i = 0; i < termosFiltrados.size(); i++) {
                            float freqRelativa = tf.get(i);

                            if (lista.update(termosFiltrados.get(i),
                                    new ElementoLista(ator.getID(), freqRelativa))) {
                                lista.incrementaEntidades();
                            }
                        }
                    }
                } else {
                    System.out.println("Erro ao alterar o Ator.");
                }
            } else {
                System.out.println("Alterações canceladas.");
            }
        } else {
            System.out.println("Não foi possível alterar o Ator.");
        }
    } catch (Exception e) {
        System.out.println("Erro ao alterar Ator: " + e.getMessage());
    }
}


 // Excluir Ator pelo nome
public void excluirAtor() throws Exception {
    System.out.println("\nExclusão de Ator");

    System.out.print("Nome do Ator: ");
    String nome = console.nextLine();
    System.out.println();

    try {
        String[] termos = nome.toLowerCase().split("\\W+");
        List<String> termosFiltrados = new ArrayList<>();
        List<Integer> frequencias = new ArrayList<>();

        gerarTermosComFrequencia(termos, termosFiltrados, frequencias);

        List<Integer> ids = new ArrayList<>();
        List<Float> tfidfs = new ArrayList<>();

        for (String termo : termosFiltrados) {
            ElementoLista[] resultados = lista.read(termo);

            if (resultados.length == 0) continue;

            float idf = calcularIDF(resultados);

            for (ElementoLista el : resultados) {
                float tf = el.getFrequencia();
                float tfidf = tf * idf;
                int id = el.getId();

                int idx = ids.indexOf(id);
                if (idx != -1) {
                    tfidfs.set(idx, tfidfs.get(idx) + tfidf);
                } else {
                    ids.add(id);
                    tfidfs.add(tfidf);
                }
            }
        }

        if (ids.isEmpty()) {
            System.out.println("Nenhum ator encontrado.");
            return;
        }

        // Ordenar por TF-IDF
        List<Integer> indices = new ArrayList<>();
        for (int i = 0; i < ids.size(); i++) indices.add(i);
        indices.sort((i1, i2) -> Float.compare(tfidfs.get(i2), tfidfs.get(i1)));

        // Criar array de atores ordenado por relevância
        Ator[] atores = new Ator[indices.size()];
        for (int i = 0; i < indices.size(); i++) {
            int pos = indices.get(i);
            atores[i] = arqAtores.read(ids.get(pos));
        }

        // Exibir lista
        System.out.println("Atores encontrados:");
        for (int i = 0; i < atores.length; i++) {
            if (atores[i] != null) {
                System.out.print("[" + i + "] ");
                mostraAtor(atores[i]);
            }
        }

        System.out.println("Digite o numero do autor que você deseja excluir");
    
        int escolha = console.nextInt();
        console.nextLine(); // limpa buffer

        if (escolha < 0 || escolha >= atores.length || atores[escolha] == null) {
            System.err.println("Número inválido!");
            return;
        }

        Ator ator = atores[escolha];

        System.out.print("Tem certeza que deseja excluir esse ator? (S/N) ");
        String confirm = console.nextLine().trim();
        if (!confirm.equalsIgnoreCase("S")) {
            System.out.println("Exclusão cancelada.");
            return;
        }

        if (arqAtores.delete(ator.getID())) {
            String[] termosAtor = ator.getNome().toLowerCase().split("\\W+");
            List<String> termosRemover = new ArrayList<>();
            List<Integer> freqs = new ArrayList<>();
            gerarTermosComFrequencia(termosAtor, termosRemover, freqs);

            for (String termo : termosRemover) {
                lista.delete(termo, ator.getID());
                lista.decrementaEntidades();
            }

            System.out.println("Ator excluído com sucesso.");
        } else {
            System.out.println("Erro ao excluir o ator.");
        }

    } catch (Exception e) {
        System.out.println("Erro ao excluir ator: " + e.getMessage());
    }
}



    public void mostrarSeriesDoAtores(){
        System.out.println("\nBusca de Series de um ator:");
        System.out.print("De qual ator deseja buscar as Series? (Nome do ator): ");
        
        String nomeAtorVinculado = console.nextLine();
        System.out.println();
        boolean dadosCorretos = false;
        
        do {
            try {
                Ator[] atores = arqAtores.readNome(nomeAtorVinculado);
                
                if (atores != null && atores.length > 0) {
                    System.out.println("Séries encontradas:");
                    for (int i = 0; i < atores.length; i++) {
                        System.out.print("[" + i + "] ");
                        mostraAtor(atores[i]);
                    }
                    
                    System.out.print("\nDigite o número do ator escolhida: ");
                    if (console.hasNextInt()) {
                        int num = console.nextInt();
                        console.nextLine(); // Limpar buffer
                        
                        if (num < 0 || num >= atores.length || atores[num] == null) {
                            System.err.println("Número inválido!");
                        } else {
                            System.out.println("\nSeries do ator " + atores[num].getNome() + ":");
                            Serie[] series = arqAtores.readSerieDoAtor(atores[num].getID());
                            
                            if (series != null && series.length > 0) {
                                for (Serie se : series) {
                                    System.out.println();
                                    mostraSerie(se);

                                    Elenco[] elenco = arqElenco.read(atores[num].getID(), se.getID());
                                    if (elenco != null && elenco.length > 0) {
                                        System.out.println("Fazendo o papel de: ");
                                        for(Elenco el : elenco) {
                                            mostraElenco(el);
                                        }
                                    }
                                }
                            } else {
                                System.out.println("Nenhum série encontrado para esta ator.");
                            }
                            dadosCorretos = true;
                        }
                    } else {
                        System.err.println("Entrada inválida! Digite um número válido.");
                        console.nextLine(); // Limpar buffer
                    }
                } else {
                    System.out.println("Nenhum série encontrada para esse ator.");
                    dadosCorretos = true;
                }
            } catch (Exception e) {
                System.out.println("Erro ao buscar séries de um ator: " + e.getMessage());
                dadosCorretos = true;
            }
        } while (!dadosCorretos);
    }


    //Mostrar Ator
    public void mostraAtor(Ator ator) {
        if (ator != null) {
            System.out.println("----------------------");
            System.out.printf("Nome....: %s%n", ator.getNome());
            System.out.printf("Data de nascimento: %s%n", ator.getDataNasc().format(DateTimeFormatter.ofPattern("dd/MM/yyyy")));
            System.out.printf("Nacionalidade....: %s%n", ator.getNacionalidade());
            System.out.println("----------------------");
        }

    }

    //Mostrar Papel
    public void mostraElenco(Elenco elenco) {
        if (elenco != null) {
            System.out.println("----------------------");
            System.out.printf("Papel.....: %s%n", elenco.getPapel());
            System.out.printf("Com um tempo de tela de: %d%n", elenco.getTempoTela());
            System.out.println("----------------------");
        }

    }

    //Mostrar Série
    public void mostraSerie(Serie serie) {
        if (serie != null) {
            System.out.println("----------------------");
            System.out.printf("Nome....: %s%n", serie.getNome());
            System.out.printf("Ano lançamento: %d%n", serie.getAnoLancamento().getYear());
            System.out.printf("Sinopse....: %s%n", serie.getSinopse());
            System.out.printf("Streaming.....: %s%n", serie.getStreaming());
            System.out.printf("Gênero.....: %s%n", serie.getGenero());
            System.out.printf("Classificação Indicativa.....: %s%n", serie.getClassIndicativa());
            System.out.println("----------------------");
        }
    }


    public void povoar() throws Exception {

        // Cadastrando atores
        int IdAtor1 = arqAtores.create(new Ator("Bryan Cranston", LocalDate.of(1956, 3, 7), "Americano"));
        int IdAtor2 = arqAtores.create(new Ator("Aaron Paul", LocalDate.of(1979, 8, 27), "Americano"));
        int IdAtor3 = arqAtores.create(new Ator("Millie Bobby Brown", LocalDate.of(2004, 2, 19), "Britânica"));
        int IdAtor4 = arqAtores.create(new Ator("David Harbour", LocalDate.of(1975, 4, 10), "Americano"));
        int IdAtor5 = arqAtores.create(new Ator("Emilia Clarke", LocalDate.of(1986, 10, 23), "Britânica"));
        int IdAtor6 = arqAtores.create(new Ator("Kit Harington", LocalDate.of(1986, 12, 26), "Britânico"));
        int IdAtor7 = arqAtores.create(new Ator("Henry Cavill", LocalDate.of(1983, 5, 5), "Britânico"));
        int IdAtor8 = arqAtores.create(new Ator("Anya Chalotra", LocalDate.of(1996, 7, 21), "Britânica"));
        int IdAtor9 = arqAtores.create(new Ator("Louis Hofmann", LocalDate.of(1997, 6, 3), "Alemão"));
        int IdAtor10 = arqAtores.create(new Ator("Lisa Vicari", LocalDate.of(1997, 2, 11), "Alemã"));
        int IdAtor11 = arqAtores.create(new Ator("Karl Urban", LocalDate.of(1972, 6, 7), "Neozelandês"));
        int IdAtor12 = arqAtores.create(new Ator("Jack Quaid", LocalDate.of(1992, 4, 24), "Americano"));
        int IdAtor13 = arqAtores.create(new Ator("Cillian Murphy", LocalDate.of(1976, 5, 25), "Irlandês"));
        int IdAtor14 = arqAtores.create(new Ator("Paul Anderson", LocalDate.of(1978, 11, 12), "Britânico"));
        int IdAtor15 = arqAtores.create(new Ator("Pedro Pascal", LocalDate.of(1975, 4, 2), "Chileno-Americano"));
        int IdAtor16 = arqAtores.create(new Ator("Emily Swallow", LocalDate.of(1979, 12, 18), "Americana"));
        int IdAtor17 = arqAtores.create(new Ator("Matt Smith", LocalDate.of(1982, 10, 28), "Britânico"));
        int IdAtor18 = arqAtores.create(new Ator("Emma D'Arcy", LocalDate.of(1992, 6, 27), "Britânica"));
        int IdAtor19 = arqAtores.create(new Ator("Tom Hiddleston", LocalDate.of(1981, 2, 9), "Britânico"));
        int IdAtor20 = arqAtores.create(new Ator("Sophia Di Martino", LocalDate.of(1983, 11, 15), "Britânica"));

        //colocar atores na lista invertida
          createAtores(1,"Bryan Cranston", LocalDate.of(1956, 3, 7), "Americano");
         createAtores(1,"Aaron Paul", LocalDate.of(1979, 8, 27), "Americano");
         createAtores(2,"Millie Bobby Brown", LocalDate.of(2004, 2, 19), "Britânica");
         createAtores(2,"David Harbour", LocalDate.of(1975, 4, 10), "Americano");
         createAtores(3,"Emilia Clarke", LocalDate.of(1986, 10, 23), "Britânica");
         createAtores(3,"Kit Harington", LocalDate.of(1986, 12, 26), "Britânico");
         createAtores(4,"Henry Cavill", LocalDate.of(1983, 5, 5), "Britânico");
        createAtores(4,"Anya Chalotra", LocalDate.of(1996, 7, 21), "Britânica");
         createAtores(5,"Louis Hofmann", LocalDate.of(1997, 6, 3), "Alemão");
         createAtores(5,"Lisa Vicari", LocalDate.of(1997, 2, 11), "Alemã");
        createAtores(6,"Karl Urban", LocalDate.of(1972, 6, 7), "Neozelandês");
       createAtores(6,"Jack Quaid", LocalDate.of(1992, 4, 24), "Americano");
        createAtores(7,"Cillian Murphy", LocalDate.of(1976, 5, 25), "Irlandês");
         createAtores(7,"Paul Anderson", LocalDate.of(1978, 11, 12), "Britânico");
        createAtores(8,"Pedro Pascal", LocalDate.of(1975, 4, 2), "Chileno-Americano");
         createAtores(8,"Emily Swallow", LocalDate.of(1979, 12, 18), "Americana");
       createAtores(9,"Matt Smith", LocalDate.of(1982, 10, 28), "Britânico");
        createAtores(9,"Emma D'Arcy", LocalDate.of(1992, 6, 27), "Britânica");
         createAtores(10,"Tom Hiddleston", LocalDate.of(1981, 2, 9), "Britânico");
        createAtores(10,"Sophia Di Martino", LocalDate.of(1983, 11, 15), "Britânica");

        // Cadastrando elencos (referenciando apenas séries de ID 1 a 10)
        arqElenco.create(new Elenco("Walter White", 95, 1, IdAtor1));
        arqElenco.create(new Elenco("Jesse Pinkman", 92, 1, IdAtor2));

        arqElenco.create(new Elenco("Eleven", 88, 2, IdAtor3));
        arqElenco.create(new Elenco("Jim Hopper", 85, 2, IdAtor4));

        arqElenco.create(new Elenco("Daenerys Targaryen", 84, 3, IdAtor5));
        arqElenco.create(new Elenco("Jon Snow", 86, 3, IdAtor6));

        arqElenco.create(new Elenco("Geralt de Rívia", 91, 4, IdAtor7));
        arqElenco.create(new Elenco("Yennefer", 82, 4, IdAtor8));

        arqElenco.create(new Elenco("Jonas Kahnwald", 80, 5, IdAtor9));
        arqElenco.create(new Elenco("Martha Nielsen", 78, 5, IdAtor10));

        arqElenco.create(new Elenco("Billy Butcher", 86, 6, IdAtor11));
        arqElenco.create(new Elenco("Hughie Campbell", 83, 6, IdAtor12));

        arqElenco.create(new Elenco("Thomas Shelby", 93, 7, IdAtor13));
        arqElenco.create(new Elenco("Arthur Shelby", 81, 7, IdAtor14));

        arqElenco.create(new Elenco("Din Djarin (Mando)", 89, 8, IdAtor15));
        arqElenco.create(new Elenco("The Armorer", 75, 8, IdAtor16));

        arqElenco.create(new Elenco("Daemon Targaryen", 79, 9, IdAtor17));
        arqElenco.create(new Elenco("Rhaenyra Targaryen", 82, 9, IdAtor18));

        arqElenco.create(new Elenco("Loki", 92, 10, IdAtor19));
        arqElenco.create(new Elenco("Sylvie", 87, 10, IdAtor20));

        
        //colocar elenco na lista invertida 
         createElenco("Walter White", 95, 1, IdAtor1);
        createElenco("Jesse Pinkman", 92, 1, IdAtor2);

        createElenco("Eleven", 88, 2, IdAtor3);
        createElenco("Jim Hopper", 85, 2, IdAtor4);

        createElenco("Daenerys Targaryen", 84, 3, IdAtor5);
        createElenco("Jon Snow", 86, 3, IdAtor6);

        createElenco("Geralt de Rívia", 91, 4, IdAtor7);
        createElenco("Yennefer", 82, 4, IdAtor8);

        createElenco("Jonas Kahnwald", 80, 5, IdAtor9);
        createElenco("Martha Nielsen", 78, 5, IdAtor10);

        createElenco("Billy Butcher", 86, 6, IdAtor11);
        createElenco("Hughie Campbell", 83, 6, IdAtor12);

        createElenco("Thomas Shelby", 93, 7, IdAtor13);
        createElenco("Arthur Shelby", 81, 7, IdAtor14);

        createElenco("Din Djarin (Mando)", 89, 8, IdAtor15);
        createElenco("The Armorer", 75, 8, IdAtor16);

        createElenco("Daemon Targaryen", 79, 9, IdAtor17);
        createElenco("Rhaenyra Targaryen", 82, 9, IdAtor18);

        createElenco("Loki", 92, 10, IdAtor19);
        createElenco("Sylvie", 87, 10, IdAtor20);


    }

      // Metodo para carregar stopords do arquivo
    public static List<String> carregarStopwords(String caminhoArquivo) throws IOException {
        List<String> stopwords = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))) {
            String linha;
            while ((linha = br.readLine()) != null) {
                stopwords.add(linha.trim().toLowerCase());
            }
        }
        return stopwords;
    }

    // Metodo para filtrar termos e frequencia
    public static void gerarTermosComFrequencia(String[] termos, List<String> termosFiltrados,
            List<Integer> frequencias) throws IOException {
        // arquivo de stopwords
        List<String> stopwords = carregarStopwords("stopwords.txt");
        // percorre cada termo
        for (String termo : termos) {
            // se nao for stopword
            if (!stopwords.contains(termo)) {
                int index = termosFiltrados.indexOf(termo);
                // Verifica se o termo ja esta na lista termosFiltrados
                if (index == -1) {
                    // se nao tiver adiciona e a frequencia
                    termosFiltrados.add(termo);
                    frequencias.add(1);
                } else {
                    // Se ja estiver, incrementa a frequencia
                    frequencias.set(index, frequencias.get(index) + 1);
                }
            }
        }
    }

    // Metodo para calcular frequencia TF
    public static List<Float> calcularFrequencia(List<Integer> frequencias) {
        List<Float> tf = new ArrayList<>();
        int total = 0;

        for (int freq : frequencias) {
            total += freq;
        }

        for (int freq : frequencias) {
            tf.add((float) freq / total);
        }

        return tf;
    }

    // Metodo para calcular idF
    public float calcularIDF(ElementoLista[] elementos) throws Exception {
        // quantidade de termos
        int total = lista.numeroEntidades();
        if (elementos == null)
            return 0;
        // quantidade de elementos para um termo especifico
        int docFreq = elementos.length;
        return (float) (Math.log((float) total / docFreq) + 1);
    }
}
