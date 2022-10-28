# TP01-PAA
<div>
  <h1 >Executar o programa:</h1>
  <p>Pode-se executar de 2 formas, lendo o arquivo como parâmetro ou durante a execução do programa </p>
  <p>
    1) Execute: 
    
    gcc main.c ./executaveis/lerArquivo.c ./executaveis/matriz.c -o main -Wall 
  </p>
  <p>
    2) Se quiser ler como parâmetro rode: ./main nomeArquivo
    
    ./main entrada
   </p>
   <p>
    =>Sem parâmetro:
    
    ./main 
   </p>
</div>
<div>
<h1>Pastas e Arquivos</h1>
<p> <h3>./arquivos</h3> Nessa pasta se encontra os arquivos .txt para leitura.</p>
<p> <h3>./executaveis</h3> Nessa pasta se encontra os arquivos .c e .h para a execução do programa</p>
<p> <h3> main.c </h3> Nesse se encontra o menu principal do programa. Nele há um switch em loop enquanto o usuário desejar continuar executando a aplicação. Além disso, na main há a chamada da função lerArquivoPrincipal, no caso, o nome do arquivo pode ser digitado pelo usuário ou lido por parâmetro pelo terminal.</p>
<p> <h3>lerArquivos.c</h3> Nesse arquivo há a leitura de arquivos e também a inicalização da matriz!</p>
<p>A leitura acontece da seguinte forma: primeiramente, o arquivo que o usuário quiser será lido e, após isso, os valores das linhas e colunas da futura matriz será armazenado. Também, a variável "cadaLinha" consegue ler cada linha do arquivo e, em seguida, é separado individualmente cada valor dessa variável e inserido em "cadaNumero", dessa forma, é possível inserir na matriz cada um desses valores</p>
<p> <h3>matriz.c</h3> Nesse arquivo separado serve para manipular melhor a matriz, como printar e inserir valores. Entretanto, vale ressaltar que a função inicializaMatriz ainda não está sendo utilizada, pois está tendo problemas.</p>
</div>
