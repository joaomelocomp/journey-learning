#include <stdio.h>
#include <stdlib.h>

typedef struct Mesas {
    int numeroMesa;
    int totalPedido;
    struct Mesas *pms; 
} Mesas;

typedef struct Pedidos {
    char codigoPedido[6];
    int quantidadePedido;
    struct Pedidos *pps;
} Pedidos;

typedef struct {
    char 
} Pratos;