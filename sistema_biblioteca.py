livros = []
comentarios = []

def cadastrar():
    titulo = input('digite o titulo')
    autor = input('digite o autor')

    
    livro = {
        'titulo' : titulo,
        'autor' : autor,
    }

    livros.append(livro)
    print('livro cadastrado!')

def pesquisar(lista, nome):
    encontrado = False

    for i in lista:
        if nome.lower() in i['titulo'].lower():
            print(f"Livro encontrado: {i['titulo']} - {i['autor']}")
            encontrado = True

    if not encontrado:
        print('não existe')
    
def catalogo(lista):
    for livro in lista:
        print(f'titulo: {livro['titulo']} | autor: {livro['autor']}')

def notas(user, xyz):
    usuario = {
        'leitor': user,
        'comentario' : xyz
    }
    comentarios.append(usuario)

def ver_notas(lista):
    for i in lista:
        print(i.items())

def escolha():
    while True:
        escolha = int(input('''
            menu 
            1 - cadastrar livro
            2 - pesquisar livro
            3 - ver catalogo
            4 - comentarios/ reviews
            5 - sair
        '''))

        if escolha == 1:
            cadastrar()
        elif escolha == 2:
            titulo = input('digite o titulo do livro: ')
            pesquisar(livros, titulo)
        elif escolha == 3:
            catalogo(livros)
        elif escolha == 4:
            qual = int(input('''
    1 - comentar
    2 - ver comentarios
'''))
            if qual == 1:
                nome = input('leitor: ')
                comentario = input('comentario: ')
                notas(nome, comentario)
            elif qual == 2:
                ver_notas(comentarios)
        elif escolha == 5:
            print('volte sempre!')
            break
    
escolha()
