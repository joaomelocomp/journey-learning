class tarefa:
    def __init__(self, id, texto):
        self.id = id
        self.tarefa = texto

def limpar():
    with open('tarefas.txt', 'w', encoding='utf-8') as arquivo:
        arquivo.write('### Lista de Tarefas ###\n')

def escrever():
    with open('tarefas.txt', 'a+', encoding='utf-8') as arquivo:
        arquivo.seek(0)
        numero = arquivo.readlines()

        if len(numero) == 1:
            id_tarefa = 1
        else:
            id_tarefa = len(numero)
        descricao_tarefa = input("O que vamos fazer? ")

        arquivo.write(f'{id_tarefa} - {descricao_tarefa}\n')

def ler():
    with open('tarefas.txt', 'r', encoding='utf-8') as arquivo:
        conteudo = arquivo.read()

    print(conteudo)

escrever()