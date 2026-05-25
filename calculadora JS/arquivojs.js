const tela = document.getElementById("tela")

function pegarNumero (numero) {
    tela.value += numero
}

function pegarOperacao (operacao) {
    if (tela.value === "") {
        tela.value = 'Digite um número'
        setTimeout(() => {
            tela.value = ""
        }, 2000)
        return
    } else {
        tela.value += operacao
    }
}

function ac () {
    tela.value = ""
}

function organizar () {
    const expressao = tela.value
    let operacao

    if (expressao.includes("+")){
        operacao = "+"
    }

    else if (expressao.includes("-")){
        operacao = "-"
    }

    let partes

    partes = expressao.split(operacao)

    let resultado
    for (let i; i < (partes.length - 1); i++) {
        if (operacao === " +") {
            resultado += partes[i]
        }
    }

    tela.value = resultado
}

function calcular (numeroUm, numeroDois, operacao) {
    let resultado = 0

    switch(operacao) {
        case "+":
            resultado = Number(numeroUm) + Number(numeroDois)
            break
        return resultado
    }


}