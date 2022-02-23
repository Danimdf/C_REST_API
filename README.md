# Processo Seletivo 42 São Paulo: 42Labs


### Qual o uso? 
A Funcionalidade desta API é a de comparação de dados entre cadetes. Ela está vinculada em um Banco de Dados que armazena dados retirados da API oficial da 42 e os apresenta.   

### API 42_Labs
A api 42-Labs permite você saber dados importantes de todos os cadetes . Aqui você encontra dados como:
| `id `        | `Nome`                    |` Login`      | `Email`                      | `Pool_Month`    | `Pool_Year`  | `Wallet`     | `Country` |
| ------------ | ------------------------- | ------------ | --------------------         | --------------- | ------------ |--------------|------------
| Dmonteir     | Daniela Monteiro de Faria | dmonteir     | dmonteir@student.42sp.org.br | March           | 2021         |197           |   Brazil  |


* Número de identificação;
* Nome completo;
* Login da Intra;
* Email;
* Mês da Piscina ou Basecamp;
* Ano da Piscina ou Basecamp;
* Quanto dinheiro possui na carteira da Intra;
* País;

### Como compilar?
A compilação acontece por meio do terminal, se deve usar "make" e depois adicionar o nome do arquivo "./api" e o login do cadete alvo da pesquisa. O login será armazenado como string dentro de uma variável do tipo char *.

### Bibliotecas e implementações
Neste programa se usa a biblioteca Libcurl conhecida como uma biblioteca de transferência de URL gratuita e fácil de usar do lado do cliente. Não há como ter conexão com o servidor por meio da Libcurl. Portanto a conexão com o servidor deve ser feita por outra Biblioteca. Por aqui [LIBCURL](https://curl.se/libcurl/c/), você pode encontrar as funções que usei desta biblioteca.

`MJSON` --> Uma biblioteca de parsear JSON, emitir e de mecanismo JSON-RCP. Usada para adquirir o valor do Token em uma string. Para mais informações sobre: 
[MJSON](https://github.com/cesanta/mjson).

`JSON-C` --> Uma biblioteca de parsing de JSON, bem completa e de fácil utilização, usada durante todo o processo de parseamento de dados. Você encontra as funções e explicações do uso de cada uma aqui: [JSON-C](https://github.com/json-c/json-c#installprereq).

`MySQL` --> É um sistema de gerenciamento de banco de dados, que utiliza a linguagem SQL como interface. Foi a minha escolha pelo fácil manuseio com a linguagem C. Neste documento, se encontra tudo sobre instalação e uso da libmysql com linguagem C: [MySQL](https://zetcode.com/db/mysqlc/)

### Formato de Entrada:

A função principal recebe um máximo de duas strings como entrada, sendo um o executável e o outro o login a se pesquisar. O login será armazenado como string dentro de uma variável do tipo char * que está dentro de uma struct.

### Formato de Resposta:
A resposta vem em JSON.

### Autorização
Se deve ter autorização por meio de Bearer Token para o uso deste programa. 

### Limitação de uso
Este programa está limitado em se conectar com a API oficial da 42, parsear a quantidade de dados específicados mais a cima e em guardá-los dentro de uma banco de dados MySQL. 

### Método HTTP 
Esse programa foi feito para aceitar método do tipo GET. 

### Descrição de erros e retornos 
-No terminal, só se deve usar duas strings para a execução do programa, se acontecer mais que duas ou somente uma, o seguinte erro é mostrado:

 `Error! Add only ./ and user login`
<p>É preciso executar corretamente o programa para que ele funcione.</p>
<p>-Somente é aceito logins válidos para a pesquisa de dados, se caso ocorrer erro de digitação ou uso indevido, um erro é passado.</p>
<p>Significando que durante o request não foi passado um URL válido e por isso no response retornou um erro.</p>

### Funções usadas

`Main()` : Função principal  que executa e direciona a chamada para as outras funções.

`get_Token()` : Função que armazena  o Token em uma váriavel global. Como parâmetro se passa uma struct.

`get_Data()` : Função que usa o processo de armazenar em uma struct todos os dados recebidos de um método GET no endpoint especificado. Como parâmetro se passa uma struct.

`parsing_Data()` : Uma função que lida com separação dos dados necessários. Ela recebe como parâmetro, dois endereços de struct, sendo uma função do tipo void.

`labs_Populate()` : Função que lida com a conecção feita com o banco de dados MySQL, nela deletamos os dados antigos se o id ja existir e adicionamos valores na tabela. 
