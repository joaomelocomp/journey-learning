Sistema simples em C para cadastrar e listar usuários usando arquivo.

Funcionalidades:

* Cadastrar usuário (id, nome, idade)
* Listar usuários salvos

Os dados são armazenados no arquivo "dados.bin".

Como usar:

1. Compilar:
   gcc cadastro.c -o cadastro

2. Executar:
   ./cadastro

Observações:

* O nome é limitado a 9 caracteres
* Para apagar os dados, delete o arquivo dados.bin com rm dados.bin no terminal

Objetivo:
Praticar uso de struct e manipulação de arquivos em C
