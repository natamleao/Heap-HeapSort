# Heap e *Heap Sort* com Medição de Tempo

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Data Structure](https://img.shields.io/badge/data_structure-heap-yellow)
![Algorithm](https://img.shields.io/badge/algorithm-heap_sort-lightgrey)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Visão geral

Este projeto implementa uma **Heap (*Max-Heap*)** em C, juntamente com o algoritmo ***Heap Sort***.

Também inclui um módulo para **medição de tempo de execução** utilizando `clock_gettime`, permitindo observar o comportamento real do algoritmo.

A ideia não é só implementar — é medir e entender o custo.

---

## Funcionalidades

* Criação de *heap* dinâmica
* Construção da *heap* (*heap build*)
* Reorganização com *heapify down*
* Ordenação com *Heap Sort*
* Impressão da estrutura
* Medição de tempo de execução
* Liberação de memória

---

## Estrutura da *heap*

A *heap* é representada como um *array*:

```
Índice:   0    1    2    3    4    5
Valor:   [90, 70, 50, 30, 20, 10]
```

Relações:

```
pai(i) = (i - 1) / 2
esq(i) = 2*i + 1
dir(i) = 2*i + 2
```

---

## Estrutura principal

```c
struct _heap{
    float *_data;
    int _size;
    int _virtualSize;
};
```

* `_data` → armazena os elementos
* `_size` → tamanho atual da estrutura
* `_virtualSize` → controla a parte ativa durante o *Heap Sort*

---

## Operações principais

### Construção da *heap*

```c
heapBuild(heap);
```

Transforma um *array* arbitrário em uma *heap* válida.

---

### Reorganização (*heapify down*)

```c
heapifyDown(heap, index);
```

Garante a propriedade de *heap* ao descer um elemento.

---

## *Heap Sort*

```c
void heapSort(Heap *heap);
```

Etapas:

1. Construir a *heap*
2. Trocar a raiz com o último elemento
3. Reduzir o tamanho ativo
4. Aplicar *heapify down*

Complexidade:

* Tempo: `O(n log n)`
* Espaço: `O(1)` (*in-place*)

---

## Medição de tempo

O projeto utiliza `clock_gettime` com `CLOCK_MONOTONIC`, evitando interferência do sistema.

```c
double executionTime = executionTimeCalculate(heapSortWrapper, heap);
executionTimePrint(executionTime);
```

Exemplo:

```
Tempo de execução: 0 H : 0 M : 0 S : 120 ms
```

---

## Estrutura do projeto

```
Heap-HeapSort/
│
├── app/             # Arquivo principal da aplicação (main)
├── bin/             # Executável gerado
├── include/         # Arquivos de cabeçalho (.h)
├── build/           # Arquivos objeto (.o)
├── src/             # Código-fonte da aplicação (.c)
├── lib/             # Biblioteca estática
│
├── Makefile         # Regras de compilação
├── README.md        # Documentação 
└── LICENSE          # Licença
```

---

> [!IMPORTANT]
>
> ## Requisitos
>
> * **GCC ou Clang**
> * **GNU Make**
> * Sistema **Linux ou macOS**

---

## Instalação

```bash
git clone git@github.com:natamleao/Heap-HeapSort.git
cd Heap-HeapSort
```

---

## Compilação

```bash
make
```

---

## Execução

```bash
make run
```

---

## Limpeza

```bash
make clean
make cleanapp
```

---

> [!WARNING]
>
> ## Licença
>
> Este projeto está sob a **Licença MIT**.

---

## Autor

**Natam Leão Ferreira**

Conclusão: **2026**

---
