# TP01-PAA
<div>
  <h1>Executar o programa:</h1>

  <p>Pode-se executar de 2 formas, lendo o arquivo como parâmetro ou durante a execução do programa </p>
  <p>
    1) Execute: 
    
     gcc main.c ./src/backtracking.c ./src/lerArquivo.c ./src/matriz.c ./src/pilha.c -o main.exe -Wall -lm 

  </p>
  <p>
    2) Se quiser ler como parâmetro rode: ./main nomeArquivo
    
    ./main.exe entrada

   </p>
   <p>
    =>Sem parâmetro:
    
    ./main 
   </p>
</div>
<div>
<h1>Pastas e arquivosTeste</h1>
<p> <h3>./arquivosTeste</h3> Nessa pasta se encontra os arquivosTeste .txt para leitura.</p>
<p> <h3>./geradorArquivosTeste</h3> Nessa pasta se encontra um programa responsavel por gerar arquivos de teste e salva-los direto na pasta ./arquivosTeste. 
<p>
    Para isso é preciso executá-lo de dentro da pasta usando: 
    
    gcc gerador.c fazenda.c -o gerarTeste.exe 

  </p>
  <p>
  
    ./gerarTeste.exe

   </p>
   <p>
    ou 
    
    make

   </p>
 </p>
<p> <h3>./src</h3> Nessa pasta se encontra os arquivosTeste .c e .h para a execução do programa</p>
<p> <h3> main.c </h3> Nesse arquivo se encontra o menu principal do programa. Nele há um switch em loop enquanto o usuário desejar continuar executando a aplicação. Além disso, na main há a chamada da função lerArquivoPrincipal, no caso, o nome do arquivo pode ser digitado pelo usuário ou lido por parâmetro pelo terminal.</p>
<p> <h3>lerarquivosTeste.c</h3> Nesse arquivo há a leitura de arquivosTeste e também a inicalização da matriz!</p>
<p>A leitura acontece da seguinte forma: primeiramente, o arquivo que o usuário quiser será lido e, após isso, os valores das linhas e colunas da futura matriz será armazenado. Também, a variável "cadaLinha" consegue ler cada linha do arquivo e, em seguida, é separado individualmente cada valor dessa variável e inserido em "cadaNumero", dessa forma, é possível inserir na matriz cada um desses valores</p>
<p> <h3>matriz.c</h3> Nesse arquivo separado serve para manipular melhor a matriz, como inicializar, printar, inserir valores e liberar a matriz.</p>
</div>
