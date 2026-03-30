# Heap e HeapSort em C com Medição de Tempo

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Data Structure](https://img.shields.io/badge/data_structure-heap-yellow)
![Algorithm](https://img.shields.io/badge/algorithm-heapsort-lightgrey)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Visão geral

Este projeto implementa uma **Heap (Max-Heap)** em C, juntamente com o algoritmo **HeapSort**.

Também inclui um módulo simples para **medição de tempo de execução** utilizando `clock_gettime`, permitindo avaliar o desempenho do algoritmo.

---

## Funcionalidades

- Criação de heap a partir de array  
- Inserção de elementos  
- Remoção do elemento máximo  
- Construção de heap (heapify)  
- Ordenação com HeapSort  
- Impressão da estrutura  
- Medição de tempo de execução  
- Liberação de memória  

---

## Estrutura da Heap

A heap é representada como um array:

```

Índice:   0    1    2    3    4    5
Valor:   [90, 70, 50, 30, 20, 10]

```

Relações:

```

pai(i) = (i - 1) / 2
esq(i) = 2*i + 1
dir(i) = 2*i + 2

````

---

## Estrutura principal

```c
struct _structureHeap{
    float *_data;
    int _size;
    int _virtualSize;
    int _capacity;
};
````

* `_data`: array da heap
* `_size`: quantidade de elementos válidos
* `_virtualSize`: usado no HeapSort para controlar a parte ativa
* `_capacity`: capacidade máxima

---

## Operações principais

### Construção da heap

```c
heapBuildFromArray(heap);
```

Transforma um array arbitrário em uma heap válida.

---

### Inserção

```c
heapInsertKey(heap, key);
```

Mantém a propriedade de heap via **HeapifyUp**.

---

### Remoção do máximo

```c
heapExtractMax(heap);
```

Remove o elemento da raiz e reorganiza a estrutura.

---

## HeapSort

```c
void heapSort(Heap *heap);
```

Etapas:

1. Construção da heap
2. Troca da raiz com o último elemento
3. Redução do tamanho virtual
4. Reorganização com HeapifyDown

Complexidade: 

* Tempo: `O(n log n)`
* Espaço: `O(1)`

---

## Medição de tempo

O projeto utiliza `clock_gettime` com `CLOCK_MONOTONIC`, evitando interferência de ajustes no relógio do sistema.

```c
double executionTime = executionTimeCalculate(heapSortWrapper, heap);
executionTimePrint(executionTime);
```

Exemplo de saída:

```
Tempo de execução: 0 H : 0 M : 0 S : 12 ms
```

---

## Estrutura do projeto

```
Heap-HeapSort/
│
├── app/             # Arquivo principal da aplicação (main)
├── bin/             # Executáveis gerados
├── include/         # Arquivos de cabeçalho (.h)
├── build/           # Arquivos objeto (.o)
├── src/             # Código-fonte da aplicação (.c)
├── lib/             # Biblioteca estática
│
├── Makefile         # Regras de compilação
├── README.md        # Documentação do projeto
└── LICENSE          # Licença do projeto
```

---
> [!IMPORTANT]
> ## Requisitos
>
> Para compilar e executar o projeto é necessário:
>
> * **GCC ou Clang**
> * **GNU Make**
> * Sistema **Linux ou macOS**

---

## Instalação

Clone o repositório:

```bash
git clone git@github.com:natamleao/Heap-HeapSort.git
cd Heap-HeapSort
```
---

## Compilação

Compile o projeto com:

```bash
make
```

---

## Execução

Execute o programa com:

```bash
make run
```

---

## Limpeza do projeto

Remover arquivos compilados:

```bash
make clean
make cleanapp
```

---

> [!WARNING]
> ## Licença
>
> Este projeto está licenciado sob a **Licença MIT**.

---

## Autor

**Natam Leão Ferreira**

Conclusão: **2026**

---
