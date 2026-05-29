function somar(a, b) {
    return a + b;
}
function subtrair(a, b) {
    return a - b;
}
function multiplicar(a, b) {
    return a * b;
}
function dividir(a, b) {
    return a / b;
}

let a = parseInt(prompt("Numero 1: "));
let b = parseInt(prompt("Numero 2: "));

console.log('1 - Somar')
console.log('2 - Subtrair')
console.log('3 - Multiplicar')
console.log('4 - Dividir')

let opcao = parseInt(prompt("Escolha uma opção (1-4): "));

switch(opcao) {
    case 1:
        alert(`Resultado: ${somar(a, b)}`);
        break;
    case 2:
        alert(`Resultado: ${subtrair(a, b)}`);
        break;
    case 3:
        alert(`Resultado: ${multiplicar(a, b)}`);
        break;
    case 4:
        alert(`Resultado: ${dividir(a, b)}`);
        break;
    default:
        alert("Opção inválida!");
}