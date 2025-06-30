
package visao;

import aeds3.ElementoLista;
import aeds3.ListaInvertida;
import entidades.Ator;
import entidades.Elenco;
import entidades.Episodio;
import entidades.Serie;
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
import modelo.ArquivoEpisodios;
import modelo.ArquivoSeries;

public class MenuSeries {
    ListaInvertida lista;
    ArquivoSeries arqSeries = new ArquivoSeries();
    ArquivoEpisodios arqEpisodios = new ArquivoEpisodios();
    private static Scanner console = new Scanner(System.in);
    MenuEpisodios menuEpisodio = new MenuEpisodios();
    MenuAtores menuAtores = new MenuAtores();
    ArquivoElenco arqElenco = new ArquivoElenco();
    ArquivoAtor arqAtores = new ArquivoAtor();

    public MenuSeries() throws Exception {
        arqSeries = new ArquivoSeries();
        arqEpisodios = new ArquivoEpisodios();
        File d = new File("dados");
        if (!d.exists())
            d.mkdir();
        lista = new ListaInvertida(100, "dados/series/dicionario_serie.listainv.db", "dados/series/blocos_serie.listainv.db");
    }

    public void menu() throws Exception {
        int opcao;
        do {
            System.out.println("\n\nPUCFlix 2.0");
            System.out.println("-----------");
            System.out.println("> Início > Séries");
            System.out.println("\n1) Incluir");
            System.out.println("2) Buscar");
            System.out.println("3) Alterar");
            System.out.println("4) Excluir");
            System.out.println("5) Mostrar todos os episódios de uma série");
            System.out.println("6) Mostrar todos os atores de uma série");

            System.out.println("0) Retornar ao menu anterior");

            System.out.print("\nOpção: ");
            try {
                opcao = Integer.valueOf(console.nextLine());
            } catch (NumberFormatException e) {
                opcao = -1;
            }

            switch (opcao) {
                case 1:
                    incluirSerie();
                    break;
                case 2:
                    buscarSerie();
                    break;
                case 3:
                    alterarSerie();
                    break;
                case 4:
                    excluirSerie();
                    break;
                case 5:
                    mostrarEpSerie();
                    break;
                case 6:
                    mostrarAtoresDaSerie();
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Opção inválida!");
                    break;
            }
        } while (opcao != 0);
    }

    public void incluirSerie() {
        System.out.println("\nInclusão de Série");

        String nome, sinopse, streaming, genero, classind;
        int idSerie;
        LocalDate ano = null;
        int anoAtual = LocalDate.now().getYear();

        // Nome
        do {
            System.out.print("Nome da série (min. 4 letras): ");
            nome = console.nextLine();
        } while (nome.length() < 4);

        // Gênero
        do {
            System.out.print("Gênero da série (min. 4 letras): ");
            genero = console.nextLine();
        } while (genero.length() < 4);

        // Classificação indicativa
        do {
            System.out.print("Classificação indicativa da série (min. 2 letras): ");
            classind = console.nextLine();
        } while (classind.length() < 2);

        // Ano de lançamento
        boolean anoValido = false;
        do {
            System.out.print("Ano de lançamento (entre 1900 e " + anoAtual + "): ");
            try {
                int anoDigitado = Integer.parseInt(console.nextLine());
                if (anoDigitado >= 1900 && anoDigitado <= anoAtual) {
                    ano = LocalDate.of(anoDigitado, 1, 1);
                    anoValido = true;
                } else {
                    System.err.println("Ano inválido! Insira um ano entre 1900 e " + anoAtual + ".");
                }
            } catch (NumberFormatException e) {
                System.err.println("Ano inválido! Insira um valor numérico.");
            }
        } while (!anoValido);

        // Sinopse
        do {
            System.out.print("Sinopse (min. 10 letras): ");
            sinopse = console.nextLine();
        } while (sinopse.length() < 10);

        // Streaming
        do {
            System.out.print("Streaming (min. 3 letras): ");
            streaming = console.nextLine();
        } while (streaming.length() < 3);

        System.out.print("\nConfirma a inclusão da série? (S/N) ");
        char resp = console.nextLine().charAt(0);
        if (resp == 'S' || resp == 's') {
            try {
                Serie s = new Serie(nome, ano, sinopse, streaming, genero, classind);
                idSerie = arqSeries.create(s);

                // separar termos em vetor de palvras
                String[] termos = nome.toLowerCase().split("\\W+");

                List<String> termosFiltrados = new ArrayList<>();
                List<Integer> frequencias = new ArrayList<>();

                // filtrar termos que nao sao stopwords e frequencia absoluta
                gerarTermosComFrequencia(termos, termosFiltrados, frequencias);
                // calcular frequencia relativa aos termos
                List<Float> tf = calcularFrequencia(frequencias);
                for (int i = 0; i < termosFiltrados.size(); i++) {
                    String termo = termosFiltrados.get(i);
                    float freqRelativa = tf.get(i);

                    lista.create(termo, new ElementoLista(idSerie, freqRelativa));
                }
                // lista.print();
                lista.incrementaEntidades();
                System.out.println("Série incluída com sucesso.");

                boolean dadosCorretos = false;
                // Atores
                do {
                    System.out.print("Deseja incluir atores? (S/N): ");
                    char resposta = console.nextLine().charAt(0);
                    if (resposta == 'S' || resposta == 's') {
                        int qtd = 0;
                        System.out.print("Quantos atores deseja incluir: ");

                        do {
                            try {
                                qtd = Integer.parseInt(console.nextLine());
                            } catch (NumberFormatException e) {
                                System.err.println("Quantidade inválida!");
                            }
                        } while (qtd <= 0);

                        for (int i = 0; i < qtd; i++) {
                            System.out.println("\tAtor " + i);
                            try {
                                menuAtores.incluirAtores(idSerie);
                            } catch (Exception e) {
                                System.out.println("Erro ao incluir atores: " + e.getMessage());
                            }
                        }
                        dadosCorretos = true;
                    } else if (resposta == 'N' || resposta == 'n') {
                        dadosCorretos = true;
                    } else {
                        System.out.println("Resposta inválida. Digite S ou N.");
                    }
                } while (dadosCorretos == false);
            } catch (Exception e) {
                System.out.println("Erro ao incluir série.");
                e.printStackTrace();
            }
        }
    }

    // Buscar Série pelo nome
    public void buscarSerie() throws Exception {
        System.out.println("\nBusca de Série");

        System.out.print("Nome da Série: ");
        String nome = console.nextLine().toLowerCase();

        String[] termos = nome.split("\\W+");
        List<String> termosFiltrados = new ArrayList<>();
        List<Integer> frequencias = new ArrayList<>();
        // filtrar termos que nao sao stopwords e frequencia absoluta
        gerarTermosComFrequencia(termos, termosFiltrados, frequencias);

        System.out.println();

        try {
            List<Integer> ids = new ArrayList<>();
            List<Float> tfidfs = new ArrayList<>();

            for (String s : termosFiltrados) {
                ElementoLista[] resultados = lista.read(s);
                if (resultados.length == 0) {
                    System.out.println("Nenhuma série encontrada com o nome '" + nome + "'.");
                } else {
                    // calcular idf
                    float idf = calcularIDF(resultados);

                    for (ElementoLista el : resultados) {
                        float tf = el.getFrequencia();
                        float tfidf = tf * idf;

                        int id = el.getId();
                        int index = ids.indexOf(id);

                        if (index != -1) {
                            // Se ja existe, soma
                            tfidfs.set(index, tfidfs.get(index) + tfidf);
                        } else {
                            // Se nao existe, adiciona
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

            // Ordenar os índices de acordo com os tfidfs (ordem decrescente)
            indices.sort((i1, i2) -> Float.compare(tfidfs.get(i2), tfidfs.get(i1)));

            System.out.println("Séries encontradas:");
            for (int i : indices) {
                Serie serie = arqSeries.read(ids.get(i));
                if (serie != null) {
                    mostraSerie(serie);
                    // System.out.printf("TF-IDF Total: %.3f\n\n", tfidfs.get(i));
                }
            }

        } catch (Exception e) {
            System.out.println("Erro ao buscar série.");
        }
    }

    // metodo para escolha da serie
    public Serie buscarIdf(String nome) throws Exception {
        String[] termos = nome.split("\\W+");
        List<String> termosFiltrados = new ArrayList<>();
        List<Integer> frequencias = new ArrayList<>();
        // filtrar termos que nao sao stopwords e frequencia absoluta
        gerarTermosComFrequencia(termos, termosFiltrados, frequencias);

        System.out.println();

        try {
            List<Integer> ids = new ArrayList<>();
            List<Float> tfidfs = new ArrayList<>();

            for (String s : termosFiltrados) {
                ElementoLista[] resultados = lista.read(s);
                if (resultados.length == 0) {
                    System.out.println("Nenhuma série encontrada com o nome '" + nome + "'.");
                } else {
                    // calcular idf
                    float idf = calcularIDF(resultados);

                    for (ElementoLista el : resultados) {
                        float tf = el.getFrequencia();
                        float tfidf = tf * idf;

                        int id = el.getId();
                        int index = ids.indexOf(id);

                        if (index != -1) {
                            // Se ja existe, soma
                            tfidfs.set(index, tfidfs.get(index) + tfidf);
                        } else {
                            // Se nao existe, adiciona
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

            // Ordenar os índices de acordo com os tfidfs (ordem decrescente)
            indices.sort((i1, i2) -> Float.compare(tfidfs.get(i2), tfidfs.get(i1)));

            System.out.println("Séries encontradas:");
            List<Serie> seriesEncontradas = new ArrayList<>();
            int contador = 0;
            for (int i : indices) {
                Serie serie = arqSeries.read(ids.get(i));
                if (serie != null) {
                    System.out.println("\t[" + contador + "]");
                    mostraSerie(serie);
                    seriesEncontradas.add(serie);
                    contador++;
                    // System.out.printf("TF-IDF Total: %.3f\n\n", tfidfs.get(i));
                }
            }
            System.out.print("Digite o número da série a ser atualizada: ");
            int num = console.nextInt();
            console.nextLine();

            if (num < 0 || num >= seriesEncontradas.size()) {
                System.out.println("Número inválido.");
                return null;
            }

            return seriesEncontradas.get(num);

        } catch (Exception e) {
            System.out.println("Erro ao buscar série.");
        }
        return null;
    }

    // Atualizar Série pelo nome
    public void alterarSerie() throws Exception {
        System.out.println("\nAlteração de Série");

        System.out.print("Nome da Série: ");
        String nome = console.nextLine();
        System.out.println();

        try {
            // serie a ser atualizada, com lista invertida
            Serie serie = buscarIdf(nome);

            if (serie != null) {

                // ------------- Dados a serem atualizados ----------------//
                System.out.print("Novo nome (ou Enter para manter): ");
                String novoNome = console.nextLine();
                if (!novoNome.isEmpty()) {
                    serie.setNome(novoNome);
                }

                System.out.print("Novo ano de lançamento (ou Enter para manter): ");
                String ano = console.nextLine();
                if (!ano.isEmpty()) {
                    LocalDate anoS = LocalDate.parse(ano + "-01-01"); // Apenas o ano
                    serie.setAnoLancamento(anoS);
                }

                System.out.print("Nova sinopse (ou Enter para manter): ");
                String novaSinopse = console.nextLine();
                if (!novaSinopse.isEmpty()) {
                    serie.setSinopse(novaSinopse);
                }

                System.out.print("Novo streaming (ou Enter para manter): ");
                String novoStreaming = console.nextLine();
                if (!novoStreaming.isEmpty()) {
                    serie.setStreaming(novoStreaming);
                }

                System.out.print("Novo genero (ou Enter para manter): ");
                String novogenero = console.nextLine();
                if (!novogenero.isEmpty()) {
                    serie.setGenero(novogenero);
                }

                System.out.print("Nova classificação indicada (ou Enter para manter): ");
                String novoclassind = console.nextLine();
                if (!novoclassind.isEmpty()) {
                    serie.setClassIndicativa(novoclassind);
                }

                System.out.print("\nConfirma as alterações? (S/N) ");
                char resp = console.nextLine().charAt(0);

                if (resp == 'S' || resp == 's') {
                    boolean alterado = arqSeries.update(serie);
                    if (alterado) {
                        System.out.println("A Série foi atualizada com sucesso!");
                        // se o nome foi alterado, excluir os termos antigos
                        String[] termosAntigos = nome.toLowerCase().split("\\W+");
                        for (String termo : termosAntigos) {
                            if (lista.delete(termo, serie.getID())) {
                                lista.decrementaEntidades();
                            }
                        }

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
                                        new ElementoLista(serie.getID(), freqRelativa))) {
                                    lista.incrementaEntidades();
                                }
                            }
                        }
                    } else {
                        System.out.println("Erro ao alterar a série.");
                    }
                } else {
                    System.out.println("Alterações canceladas.");
                }
            } else {
                System.out.println("Não foi possível alterar a série");
            }
        } catch (Exception e) {
            System.out.println("Erro ao alterar série.");
        }
    }

    // Excluir Série pelo nome
    public void excluirSerie() throws Exception {
        System.out.println("\nExclusão de Série");

        System.out.print("Nome da Série: ");
        String nome = console.nextLine();
        System.out.println();

        try {
            Serie serie = buscarIdf(nome);

            if (serie != null) {
                System.out.println("Série Encontrada " + serie.getNome());

                // testar se o numero digitado e' valido

                Episodio[] episodios = arqEpisodios.readEpisodiosSerie(serie.getID());
                if (episodios != null) {
                    System.out.print("Essa série possui episódios vinculados, deseja excluir mesmo assim? (S/N) ");
                } else {
                    System.out.print("Tem certeza que deseja excluir essa série? (S/N) ");
                }
                char resposta = console.nextLine().charAt(0);
                if (resposta != 'S' && resposta != 's') {
                    System.out.println("A série não foi excluída.");
                    return;
                }

                boolean excluido = arqSeries.delete(serie.getID());
                if (excluido) {
                    String[] termos = nome.toLowerCase().split("\\W+");
                    List<String> termosFiltrados = new ArrayList<>();
                    List<Integer> frequencias = new ArrayList<>();
                    gerarTermosComFrequencia(termos, termosFiltrados, frequencias);

                    for (String termo : termosFiltrados) {
                        lista.delete(termo, serie.getID());
                    }
                    lista.decrementaEntidades();
                    System.out.println("Série excluída com sucesso.");
                } else {
                    System.out.println("Erro ao excluir a série.");
                }
            }

        } catch (Exception e) {
            System.out.println("Erro ao excluir série.");
        }
    }

    public void mostrarEpSerie() {
        System.out.println("\nBusca de episódio de uma série:");
        System.out.print("De qual série deseja buscar o episódio? (Nome da série): ");

        String nomeSerieVinculada = console.nextLine();
        System.out.println();
        boolean dadosCorretos = false;

        do {
            try {
                Serie serie = buscarIdf(nomeSerieVinculada);

                if (serie != null) {
                    System.out.println("Série Encontrada " + serie.getNome());
                    System.out.println("Séries encontradas:");

                    System.out.println("Episódios da série " + serie.getNome() + ":");
                    Episodio[] episodios = arqEpisodios.readEpisodiosSerie(serie.getID());

                    if (episodios != null && episodios.length > 0) {
                        int temporadaAtual = -1;
                        for (Episodio ep : episodios) {
                            if (ep.getTemporada() != temporadaAtual) {
                                temporadaAtual = ep.getTemporada();
                                System.out.println("\nTemporada " + temporadaAtual + ":");
                            }
                            menuEpisodio.mostraEpisodio(ep);
                        }
                    } else {
                        System.out.println("Nenhum episódio encontrado para esta série.");
                    }
                    dadosCorretos = true;

                } else {
                    System.out.println("Nenhuma série encontrada com esse nome.");
                    dadosCorretos = true;
                }
            } catch (Exception e) {
                System.out.println("Erro ao buscar a série: " + e.getMessage());
                dadosCorretos = true;
            }
        } while (!dadosCorretos);
    }

    public void mostrarAtoresDaSerie() {
        System.out.println("\nBusca de atores de uma série:");
        System.out.print("De qual série deseja buscar os atores? (Nome da série): ");

        String nomeSerieVinculada = console.nextLine();
        System.out.println();
        boolean dadosCorretos = false;

        do {
            try {
                Serie serie = buscarIdf(nomeSerieVinculada);

                if (serie != null) {
                    System.out.println("Série Encontrada " + serie.getNome());
                    System.out.println("\nAtores da série " + serie.getNome() + ":");
                    Ator[] atores = arqAtores.readAtoresDaSerie(serie.getID());

                    if (atores != null && atores.length > 0) {
                        for (Ator at : atores) {
                            System.out.println();
                            mostraAtor(at);

                            Elenco[] elenco = arqElenco.read(at.getID(), serie.getID());
                            if (elenco != null && elenco.length > 0) {
                                System.out.println("Fazendo o papel de: ");
                                for (Elenco el : elenco) {
                                    mostraElenco(el);
                                }
                            }
                        }
                    } else {
                        System.out.println("Nenhum ator encontrado para esta série.");
                    }
                    dadosCorretos = true;

                } else {
                    System.out.println("Nenhum ator encontrada com esse nome.");
                    dadosCorretos = true;
                }
            } catch (Exception e) {
                System.out.println("Erro ao buscar ator de uma série: " + e.getMessage());
                dadosCorretos = true;
            }
        } while (!dadosCorretos);
    }

    // Mostrar Ator
    public void mostraAtor(Ator ator) {
        if (ator != null) {
            System.out.println("----------------------");
            System.out.printf("Nome....: %s%n", ator.getNome());
            System.out.printf("Data de nascimento: %s%n",
                    ator.getDataNasc().format(DateTimeFormatter.ofPattern("dd/MM/yyyy")));
            System.out.printf("Nacionalidade....: %s%n", ator.getNacionalidade());
            System.out.println("----------------------");
        }

    }

    // Mostrar Papel
    public void mostraElenco(Elenco elenco) {
        if (elenco != null) {
            System.out.println("----------------------");
            System.out.printf("Papel.....: %s%n", elenco.getPapel());
            System.out.printf("Com um tempo de tela de: %d%n", elenco.getTempoTela());
            System.out.println("----------------------");
        }

    }

    // Mostrar Série
    public void mostraSerie(Serie serie) {
        try {
            if (serie != null) {
                System.out.println("----------------------");
                System.out.printf("Nome....: %s%n", serie.getNome());
                System.out.printf("Ano lançamento: %d%n", serie.getAnoLancamento().getYear());
                System.out.printf("Sinopse....: %s%n", serie.getSinopse());
                System.out.printf("Streaming.....: %s%n", serie.getStreaming());
                System.out.printf("Gênero.....: %s%n", serie.getGenero());
                System.out.printf("Avaliação Media......: %.2f%n", arqEpisodios.avaliacaoMediaSerie(serie.getID()));

                System.out.printf("Classificação Indicativa.....: %s%n", serie.getClassIndicativa());
                System.out.println("----------------------");
            }
        } catch (Exception e) {
            System.out.println("Erro ao mostrar série: " + e.getMessage());
        }
    }

    // Incluir serie para metodo povoar
    public void incluirSerieAutomaticamente(String nome, String genero, String classind, int anoLancamento,
            String sinopse, String streaming) {
        try {
            LocalDate ano = LocalDate.of(anoLancamento, 1, 1);
            Serie s = new Serie(nome, ano, sinopse, streaming, genero, classind);
            int idSerie = arqSeries.create(s);

            // Separar termos
            String[] termos = nome.toLowerCase().split("\\W+");
            List<String> termosFiltrados = new ArrayList<>();
            List<Integer> frequencias = new ArrayList<>();

            gerarTermosComFrequencia(termos, termosFiltrados, frequencias);
            List<Float> tf = calcularFrequencia(frequencias);

            lista.incrementaEntidades();
            for (int i = 0; i < termosFiltrados.size(); i++) {
                String termo = termosFiltrados.get(i);
                float freqRelativa = tf.get(i);
                lista.create(termo, new ElementoLista(idSerie, freqRelativa));
            }

            System.out.println("Série \"" + nome + "\" incluída automaticamente com sucesso.");

        } catch (Exception e) {
            System.out.println("Erro ao incluir série automaticamente.");
            e.printStackTrace();
        }
    }

    public void povoar() throws Exception {
        incluirSerieAutomaticamente(
            "De Volta aos 15",
            "Comédia/Romance", "14+",
            2022,
            "Após um acidente, uma mulher retorna à sua adolescência e precisa lidar com o passado.",
            "Netflix");

        incluirSerieAutomaticamente(
            "Os Quatro da Candelária",
            "Drama", "16+",
            2019,
            "Quatro amigos enfrentam os desafios da infância nas ruas da Candelária, no Rio de Janeiro.",
            "Globoplay");

        incluirSerieAutomaticamente(
            "O Cangaceiro do Futuro",
            "Ação/Ficção Científica", "16+",
            2023,
            "Um homem do sertão é transportado para o futuro e precisa se adaptar a uma nova realidade.",
            "Amazon Prime");

        incluirSerieAutomaticamente(
            "Onde Está Meu Coração",
            "Drama", "18+",
            2021,
            "Uma médica enfrenta seus próprios conflitos enquanto lida com a vida na periferia de São Paulo.",
            "Globoplay");

        incluirSerieAutomaticamente(
            "Manhãs de Setembro",
            "Drama", "14+",
            2022,
            "Histórias de uma pequena cidade do interior que revelam segredos antigos e conflitos locais.",
            "Globoplay");

        incluirSerieAutomaticamente(
            "Sob Pressão",
            "Drama", "16+",
            2017,
            "O dia a dia de um hospital público do Rio de Janeiro, mostrando os desafios da equipe médica.",
            "GloboPlay");
                
        incluirSerieAutomaticamente(
            "Irmandade",
            "Crime/Drama", "16+",
            2019,
            "Uma advogada descobre que seu irmão está preso e lidera uma facção criminosa, colocando sua moral à prova.",
            "Netflix");

        incluirSerieAutomaticamente(
            "Coisa Mais Linda",
            "Drama/Romance", "14+",
            2019,
            "Nos anos 1950, uma mulher decide abrir um clube de bossa nova no Rio de Janeiro após ser abandonada pelo marido.",
            "Netflix");

        incluirSerieAutomaticamente(
            "Arcanjo Renegado",
            "Ação/Policial", "18+",
            2020,
            "Um sargento do BOPE se envolve em uma trama política e policial enquanto enfrenta o crime organizado.",
            "Globoplay");

        incluirSerieAutomaticamente(
            "3%",
            "Ficção Científica/Drama", "16+",
            2016,
            "Em um futuro distópico, jovens têm uma única chance de passar por um processo seletivo que garante acesso a uma vida melhor.",
            "Netflix");

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
