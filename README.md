
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

Java possui uma função nativa:
```
System.getCurrentTimeMillis();
```


```
unsigned long long current_timestamp() {
    struct timeval tv;
    unsigned long long tim;
    gettimeofday(&tv, NULL);
    tim = 1000000 * tv.tv_sec + tv.tv_usec;
    return tim;
}
```
