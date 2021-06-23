
### Algoritmos de ordenação em Java e C

---

Durante a matéria de Estrutura de Dados no terceiro semestre da faculdade, estruturamos 6 diferentes algoritmos de ordenação para comparar seus tempos de execução.

- Insertion Sort
- Shell Sort
- Bubble Sort
- Quick Sort
- Merge Sort
- Heap Sort

---

### Tempo de execução

Java possui uma função nativa que retorna os milissegundos entre o tempo atual e meia noite do dia 01/01/1970. Portanto, para medir o tempo de execução de cada algoritmo, foi necessário criar duas variáveis com essa função e fazer a diferença entre elas.
```
t1 = System.currentTimeMillis();
t2 = System.currentTimeMillis();
System.out.println("Duracao em millissegundos: " + (t2 - t1));

```

Como C não possui uma função pronta igual a de Java, estruturamo uma que tem praticamente o mesmo efeito
```
unsigned long long current_timestamp() {
    struct timeval tv;
    unsigned long long tim;
    gettimeofday(&tv, NULL);
    tim = 1000000 * tv.tv_sec + tv.tv_usec;
    return tim;
}
```
