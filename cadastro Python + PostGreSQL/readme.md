Sistema de Cadastro de Usuários

Aplicação desktop desenvolvida em Python com interface gráfica para cadastro, consulta e visualização de usuários utilizando banco de dados PostgreSQL.

Funcionalidades

Cadastro de usuários com validação de dados  
Busca de usuário por e-mail  
Exibição de usuários cadastrados recentemente  
Navegação entre telas (cadastro e consulta)  
Feedback visual para sucesso/erro  

Tecnologias utilizadas

Python
CustomTkinter
PostgreSQL
psycopg2

---

 Estrutura do projeto


/projeto
│
├── front.py # Interface gráfica (frontend)
└── backend.py # Conexão com PostgreSQL + validação de informações

---

Como executar o projeto

### 1. Clone o repositório
```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio
2. Instale as dependências
pip install customtkinter psycopg2-binary
3. Configure o PostgreSQL

Crie o banco de dados:

CREATE DATABASE cadastro_db;

Crie a tabela:

CREATE TABLE usuarios (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100),
    sobrenome VARCHAR(100),
    email VARCHAR(150),
    telefone VARCHAR(20),
    endereco TEXT
);
4. Configure a conexão

No arquivo database.py, altere:

host="localhost"
database="cadastro_db"
user="seu_usuario"
password="sua_senha"
5. Execute o sistema
python main.py
 Interface
```
O sistema possui duas telas principais:

Tela de cadastro de usuários
Tela de busca e listagem de usuários
 Aprendizados

Este projeto aborda conceitos importantes como:

Organização de código em camadas
Integração com banco de dados
Manipulação de interface gráfica
Estruturação de aplicações reais
###
Desenvolvido por João Gabriel Melo
Estudante de Ciência da Computação
