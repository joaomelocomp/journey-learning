const tela = document.getElementById("tela")

function pegarNumero (numero) {
    tela.value += numero
}

function ac () {
    tela.value = null
}

function operacoes (numeroUm, numeroDois) {
    let resultado = 0
    switch(opcao) {
        case 1:
        resultado = numeroUm / numeroDois
    }


}