print('''
      A senha deve conter:
        Mínimo de 8 dígitos.
        2 Caracteres especiais. (Exemplo: '?', '!',...)
        Ao menos uma letra (Exemplo: M/m)
        Números
      ''')
password = input('      Digite sua senha: ')

def validador(senha):
    s = True
    senhas_obvias = {
            '123456', 'password', '123456789', 'qwerty',
            'abc123', '111111', '123123', 'admin',
            'letmein', '1234'
        }

    caracteres_especiais = set('!@#$%^&*()-_=+[]{}|\\;:\'",.<>?/`~')

    if senha in senhas_obvias or len(senha) < 8:
        s = False
        return 'Senha curta ou inválida'

    contador = 0
    contador_de_letras = 0
    for i in senha:
        if i in caracteres_especiais:
            contador += 1
        if i.isalpha():
            contador_de_letras += 1
    
    if contador < 2:
        s = False
        return 'Faltam caracteres especiais'
    
    if contador_de_letras < 2:
        s = False
        return 'Faltam letras'
    
    if s == True:
        return s


def tentativas(senha):
    i = 0
    while i < 3:
        tentativa = input('Digite a senha para entrar: ')
        if senha == tentativa:
            return 'Passou'
        else:
            print('Senha errada! Tente novamente.')
        i += 1
    return 'Bloqueado'

def barreira(senha):
    resultado = validador(senha)
    
    if resultado == True:
        return tentativas(senha)
    else:
        return resultado

print(barreira(password))
