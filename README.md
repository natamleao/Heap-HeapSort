# Heap e HeapSort em C com Medição de Tempo

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Data Structure](https://img.shields.io/badge/data_structure-heap-yellow)
![Algorithm](https://img.shields.io/badge/algorithm-heapsort-lightgrey)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Sobre o projeto

> [!NOTE]
> Este projeto implementa uma **estrutura Heap (Max-Heap)** em C, juntamente com o algoritmo **HeapSort**, incluindo também um módulo para **medição precisa de tempo de execução**.

---

## Tecnologias utilizadas

* **C (C11)**
* **POSIX (`clock_gettime`)**
* **GNU Make**

---

## Conceitos aplicados

Esse projeto é praticamente um checklist de fundamentos bem feitos:

* Alocação dinâmica (`malloc`, `calloc`, `free`)
* Manipulação de ponteiros
* Estrutura **Heap (Max-Heap)**
* Recursão (`HeapifyUp` e `HeapifyDown`)
* Ordenação com **HeapSort**
* Controle de tamanho lógico vs virtual
* Medição de tempo com alta precisão
* Modularização (`.h` / `.c`)

---

## Estrutura da Heap

A heap é representada como array:

```
Índice:   0    1    2    3    4    5
Valor:   [90, 70, 50, 30, 20, 10]
```

Relações:

```
pai(i)     = (i - 1) / 2
esq(i)     = 2*i + 1
dir(i)     = 2*i + 2
```

---

## Estrutura principal

```c
struct _structureHeap{
    float *_data;
    int _size;
    int _virtualSize;
    int _capacity;
};
```

### Significado:

* `_data` → array da heap
* `_size` → tamanho real
* `_virtualSize` → usado no HeapSort (controle da parte ativa)
* `_capacity` → capacidade máxima

---

## Funcionalidades

### Criar heap

```c
HeapCreateStructureHeap(array, size, capacity);
```

---

### Inserção

```c
HeapInsertKey(heap, key);
```

Mantém a propriedade de heap via **HeapifyUp**.

---

### Remover máximo

```c
HeapExtractMax(heap);
```

Remove o maior elemento (raiz).

---

### Construir heap

```c
HeapBuildFromArray(heap);
```

Transforma um array qualquer em heap válida.

---

### Impressão

```c
HeapPrint(heap);
```

---

### Destruição

```c
HeapDestroy(heap);
```

Libera toda a memória.

---

## HeapSort

```c
void HeapSort(StructureHeap *heap);
```

### Como funciona:

1. Constrói a heap
2. Troca raiz com último elemento
3. Reduz tamanho virtual
4. Reorganiza com HeapifyDown

Complexidade:

* **Tempo:** `O(n log n)`
* **Espaço:** `O(1)` (in-place)

---

## Medição de tempo

O projeto usa `clock_gettime` com `CLOCK_MONOTONIC`, que é confiável e não sofre com mudanças do sistema.

### Uso:

```c
double tempo = calculateTime(func, heap);
calculateTimePrintTime(tempo);
```

### Exemplo de saída:

```
Tempo de execução: 0 H : 0 M : 0 S : 12 ms
```

---

## Estrutura do projeto

```
Heap-Project/
│
├── include/        # Headers (.h)
├── src/            # Implementações (.c)
├── obj/            # Arquivos objeto
├── bin/            # Executáveis
│
├── Makefile
├── README.md
└── LICENSE
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
git clone git@github.com:natamleao/Hash-Table.git
cd Hash-Table
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