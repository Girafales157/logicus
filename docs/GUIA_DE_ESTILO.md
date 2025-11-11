# Guia de Estilo
Este guia serve de referência para o estilo de código adotado nesse projeto, a fim de padronizar o aspecto geral da codebase.

# 1.0 Identação e espaços
- Utilizar identação de quatro caracteres de espaços.
- Exceto ao chamar funções, utilizar espaço em parênteses, chaves iniciais e operadores lógicos.
```c
// ruim
for(int i=0;i<666;++i){
    printf("%d\n", i);
}

// bom
for (int i = 0; i < 666; ++i) {
    printf("%d\n", i);
}
```

# 2.0 Condicionais, funções e laços
- Evitar o uso de condicionais de uma única linha:
```c
// ruim
if (a == b) return true;

// bom
if (a == b) {
    return true;
}
```

# 3.0 Prototipação
- Evitar deixar parametros sem nome, pois isso deixa a definição confusa.
```c
// ruim
int soma(int, int);

// bom
int soma(int n1, int n2);
```

