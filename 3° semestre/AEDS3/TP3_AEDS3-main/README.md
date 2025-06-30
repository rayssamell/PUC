# TP2_AEDS3 💻

## 👨‍🎓 Alunos integrantes da equipe

* Davi Cândido de Almeida
* Letícia da Silva Rocha
* Rayssa Mell de Souza Silva

## 👨‍🏫 Professor responsável

* Marcos André Silveira Kutova
 
## 🎯 O que o trabalho faz?

Este projeto é uma aplicação desenvolvida em Java chamada PUCFlix 2.0, que simula um sistema de gerenciamento de séries e episódios. A aplicação permite realizar operações de cadastro, leitura, atualização e remoção (CRUD) de registros, utilizando arquivos binários para armazenar os dados de forma persistente. Para otimizar as buscas e garantir eficiência no acesso às informações, o sistema implementa estruturas de dados avançadas como Hash Extensível, Árvore B+ e lista invertida, que são utilizadas para indexar os registros por diferentes chaves, como identificadores e nomes, e buscar por nomes ordenados pela frequência, o sistema possui também relacionamentos 1:N e N:N. O programa possui uma interface interativa por meio de menus no terminal, permitindo ao usuário navegar entre as opções de gerenciamento de séries e episódios, além de oferecer uma função para popular o sistema com dados de exemplo para testes.

## Classes criadas e os seus métodos principais.


```java
└── 📁Project
   └── 📁aeds3
   	└── Arquivo.java //(Métodos: read, create, delete, update, addDeleted, getDeleted)
   	└── ArvoreBMais.java //(Métodos: empty, read, create, delete, update, print)
        └── ListaInvertida.java //(Métodos: create, read, delete, numeroEntidades, incrementaEntidades, decrementaEntidades)
        └── ElementoLista //(Métodos: toByteArray, fromByteArray, create, test, read, update, delete, last, list, empty, full, toString, next, setNext, size)
   	└── Pagina.java //(Métodos: toByteArray, fromByteArray)
   	└── EntidadeArquivo.java //(Interface: setID, getID, toByteArray, fromByteArray)
   	└── HashExtensivel.java //(Métodos: toByteArray, fromByteArray, create, read, update, delete, empty, full, print, atualizaEndereco)
   	└── ParIDEndereco.java //(Métodos: getId, getEndereco, hashCode, size, toString, toByteArray, fromByteArray)
   	└── ParIdId.java //(Métodos: getId_agregado, clone, size, compareTo, toString, toByteArray, fromByteArray)
   	└── RegistroArvoreBMais.java  //(Métodos: size, toByteArray, fromByteArray, compareTo, clone)
   	└── RegistroHashExtensivel.java  //(Métodos: hashCode, size, toByteArray, fromByteArray)
   └── 📁dados
	└── 📁ator
            └── ator.db
            └── indiceAtor.db
            └── indiceDireito.c.db
            └── indiceDireito.d.db
            └── blocos_ator.listainv.db
            └── blocos_serie.listainv.db
	    └── dicionario_ator.listainv.db
	    └── dicionario_serie.listainv.db
	    └── blocos_episodio.listainv.db
	    └── dicionario_episodio.listainv.db
   	└── 📁episodio
       	   └── episodio.db
       	   └── indiceDireito.c.db
       	   └── indiceDireito.d.db
       	   └── indiceIdEpisodios_IdSerie.db
       	   └── indiceNomeEpisodios.db
   	└── 📁series
           └── indiceDireito.c.db
       	   └── indiceDireito.d.db
       	   └── indiceNomeSerie.d.db
       	   └── series.db
   └── 📁entidades
	└── Ator.java // (Métodos: Ator, getID, setID, getNome, setNome, getDataNasc, setDataNasc, getNacionalidade, toByteArray, fromByteArray, toString, equals, compareTo)
   	└── Episodio.java //(Métodos: getID, setID, getID_serie, setID_serie, getNome, setNome, getTemporada, setTemporada, getDataLancamento, setDataLancamento, getDuracaoMinutos, setDuracaoMinutos, getAvaliacao, setAvaliacao, isEspecial, setEspecial, getDescricao, setDescricao, toByteArray, fromByteArray, toString, equals, compareTo)
   	└── Serie.java //(Métodos: getID, setID, getNome, setNome, getAnoLancamento, setAnoLancamento, getSinopse, setSinopse, getStreaming, setStreaming, getGenero, setGenero, getClassIndicativa, toByteArray, fromByteArray, toString, equals, compareTo)
   └── 📁modelo
	└── ArquivoAtor.java // (Métodos: ArquivoAtor, create, readNome, readAtoresDaSerie, readSerieDoAtor, delete, delete, update, atorExiste)
	└── ArquivoElenco.java //ArquivoElenco, readElencoPorAtor, read, readElencoPorSerie, delete, deleteAtorElenco, update)
   	└── ArquivoEpisodios.java //(Métodos: create, readNomeEpisodio, readNomeEpisodioPorSerie, readEpisodiosSerie, delete, deleteEpisodioSerie, update, avaliacaoMediaSerie)
   	└── ArquivoSeries.java //(Métodos: create, readNome, delete, update, serieExiste)
   	└── ParAtorId.java //(Métodos: ParAtorId, getNome, getId, clone, size, compareTo, toString, toByteArray, fromByteAray, transforma)
   	└── ParTituloId.java //(Métodos: getTitulo, getId, clone, size, compareTo, toString, toByteArray, fromByteArray, transforma)
   └── 📁visao
   	└── MenuEpisodios.java //(Métodos: menu, incluirEpisodio, buscarEpisodio, excluirEpisodio, alterarEpisodio, mostraEpisodio, mostraSerie, povoar)
        └── MenuAtores.java //(Métodos: MenuAtores, menu, incluirAtores, buscarAtor, excluirAtor, mostrarAtoresDaSerie, mostraAtor, mostraElenco, mostraSerie, povoar)
        └── MenuSeries.java //(Métodos: menu, incluirSerie, buscarSerie, alterarSerie, excluirSerie, mostrarEpSerie, mostraSerie, povoar)
   └── Principal.java //(Método: main)
   └── stopwords.txt
```


## Relato de experiências:

```
Todos os requisitos foram implementados ?  
 - Sim

Houve alguma operação mais difícil? 
 - Sim, o cálculo da lista invertida 

Vocês enfrentaram algum desafio na implementação? 
 - Sim, a utilização da lista invertida em si foi um grande desafio. Como por exemplo, adaptar totalmente o que haviamos feito para a lista invertida. 

Os resultados foram alcançados? 
 - Sim
```


### Checklist :

```
O índice invertido com os termos dos títulos das séries foi criado usando a classe ListaInvertida?
sim
O índice invertido com os termos dos títulos dos episódios foi criado usando a classe ListaInvertida?
sim
O índice invertido com os termos dos nomes dos atores foi criado usando a classe ListaInvertida?
sim
É possível buscar séries por palavras usando o índice invertido?
sim
É possível buscar episódios por palavras usando o índice invertido?
sim
É possível buscar atores por palavras usando o índice invertido?
sim
O trabalho está completo?
sim
O trabalho é original e não a cópia de um trabalho de um colega?
sim


```



## 📄 Licença
Este projeto está licenciado sob a **MIT License** - veja o arquivo [LICENSE](LICENSE) para mais detalhes.


