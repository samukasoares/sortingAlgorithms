package algoritmosordenacao;

import java.util.Scanner;

public class AlgoritmosOrdenacao {

    public static void main(String[] args) {
        int tam;
        int original[], ordenado[], temp[];
        long t1, t2;

        Scanner leitura = new Scanner(System.in);
        System.out.print("Digite um tamanho para o vetor a ser ordenado: ");  //pede o tamanho do array para o usuario
        tam = leitura.nextInt();

        original = desorganizar(criarArray(tam));              //cria o array original
        ordenado = new int[tam];
        System.arraycopy(original, 0, ordenado, 0, original.length);

        int opcao = 0;
        while (opcao != 9) {
            imprimeMenu();
            opcao = leitura.nextInt();
            switch (opcao) {
                case 1:
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    insertionSort(ordenado);
                    break;

                case 2:
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    shellSort(ordenado);
                    break;

                case 3:
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    t1 = System.currentTimeMillis();
                    bubbleSort(ordenado, original.length);
                    t2 = System.currentTimeMillis();
                    System.out.println("Duracao em milisegundos Bubble Sort: " + (t2 - t1));
                    break;

                case 4:
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    t1 = System.currentTimeMillis();
                    quickSort(ordenado, 0, original.length);
                    t2 = System.currentTimeMillis();
                    System.out.println("Duracao em milisegundos Quick Sort: " + (t2 - t1));
                    break;

                case 5:
                    temp = new int[ordenado.length];
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    t1 = System.currentTimeMillis();
                    mergeSort(ordenado, temp, 0, ordenado.length-1);
                    t2 = System.currentTimeMillis();
                    System.out.println("Duracao em milisegundos Merge Sort: " + (t2 - t1));
                    break;

                case 6:
                    System.arraycopy(original, 0, ordenado, 0, original.length);
                    t1 = System.currentTimeMillis();
                    heapsort(ordenado);
                    t2 = System.currentTimeMillis();
                    System.out.println("Duracao em milisegundos Heap Sort: " + (t2 - t1));

                case 7:
                    System.out.print("Vetor original: ");
                    imprimirArray(original);
                    break;

                case 8:
                    System.out.println("Vetor ordenado: ");
                    imprimirArray(ordenado);
                    break;
                case 9:
                    break;

                default:
                    System.out.print("Opcao invalida!");
                    break;
            }
        }
    }

    public static void imprimirArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + "\t");
        }
    }

    public static int[] criarArray(int tam) {
        int array[] = new int[tam];

        for (int i = 0; i < tam; i++) {
            array[i] = i + 1;
        }
        return array;
    }

    public static int[] desorganizar(int array[]) {

        for (int i = 0; i < array.length; i++) {
            int rand_pos = (int) (Math.random() * ((array.length - 1) + 1));
            int t = array[rand_pos];
            array[rand_pos] = array[i];
            array[i] = t;
        }
        return array;
    }

    public static void imprimeMenu() {
        System.out.println("================================================================\n");
        System.out.println("|     Tempo de execucao de diferentes metodos de ordenacao     |\n");
        System.out.println("================================================================\n");
        System.out.println("| Operacoes:                                                   |\n");
        System.out.println("| 1) Insertion Sort                                            |\n");
        System.out.println("| 2) Shell Sort                                                |\n");
        System.out.println("| 3) Bubble Sort                                               |\n");
        System.out.println("| 4) Quick Sort                                                |\n");
        System.out.println("| 5) Merge Sort                                                |\n");
        System.out.println("| 6) Heap Sort                                                 |\n");
        System.out.println("| 7) Imprimir array original                                   |\n");
        System.out.println("| 8) Imprimir array ordenado                                   |\n");
        System.out.println("| 9) Sair                                                      |\n");
        System.out.println("+--------------------------------------------------------------+\n");
        System.out.println("  Pressione a opcao desejada ");
    }

    public static void insertionSort(int x[]) {

        long t1 = System.currentTimeMillis();
        int i, k, aux;
        for (k = 1; k < x.length; k++) {
            aux = x[k];
            for (i = k - 1; i >= 0 && aux < x[i]; i--) {
                x[i + 1] = x[i];
            }
            x[i + 1] = aux;
        }
        long t2 = System.currentTimeMillis();
        long t = t2 - t1;
        System.out.println("Duracao em milisegundos insertion sort:" + t);
    }

    public static void shellSort(int x[]) {
        long t1 = System.currentTimeMillis();
        int gap, j, k, aux;

        for (gap = x.length / 2; gap >= 1; gap = gap / 2) {
            for (j = gap; j < x.length; j++) {
                aux = x[j];
                for (k = j - gap; k >= 0 && aux < x[k]; k -= gap) {
                    x[k + gap] = x[k];
                }
                x[k + gap] = aux;
            }
        }
        long t2 = System.currentTimeMillis();
        System.out.println("Duracao em milisegundos shellsort: " + (t2 - t1));
    }

    public static void bubbleSort(int v[], int n) {
        int i, j, aux;
        for (j = n - 1; j > 0; j--) {
            for (i = 0; i < j; i++) {
                if (v[i] > v[i + 1]) {
                    aux = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = aux;
                }
            }
        }
    }

    public static void quickSort(int x[], int p, int u) {
        int i, j, pivo, aux;
        i = p;
        j = u;
        pivo = x[(i + j) / 2];
        do {
            while (x[i] < pivo && i < u) {
                i++;
            }
            while (x[j] > pivo && j > p) {
                j--;
            }
            if (i <= j) {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
                i++;
                j--;
            }
        } while (i <= j);
        if (p < j) {
            quickSort(x, p, j);
        }
        if (i < u) {
            quickSort(x, i, u);
        }
    }

    public static void merge(int x[], int temp[], int esq, int meio, int dir) {
        int esq_fim, tam, tmp_pos;
        esq_fim = meio - 1;
        tmp_pos = esq;
        tam = dir - esq + 1;
        while ((esq <= esq_fim) && (meio <= dir)) { //Junção ordenada em temp
            if (x[esq] <= x[meio]) {                //Se elemento da esquerda menor
                temp[tmp_pos] = x[esq];
                tmp_pos++;
                esq++;
            } else {
                temp[tmp_pos] = x[meio];            //Se elemento da direita menor
                tmp_pos++;
                meio++;
            }
        }
        if (esq <= esq_fim) {                       //Sobraram elementos na esquerda
            System.arraycopy(x, esq, temp, tmp_pos, esq_fim - esq + 1);
        }
        if (meio <= dir) {                          //Sobraram elementos na direita
            System.arraycopy(x, meio, temp, tmp_pos, dir - meio + 1);
        }
            System.arraycopy(temp, dir - tam + 1, x, dir - tam + 1, tam);
    }

    public static void mergeSort(int x[], int temp[], int esq, int dir) {
        int meio;
        if (dir > esq) {
            meio = (dir + esq) / 2;
            mergeSort(x, temp, esq, meio);
            mergeSort(x, temp, meio + 1, dir);
            merge(x, temp, esq, meio + 1, dir);
        }
    }

    public static void heapfica(int[] x, int n) {
        int i, aux, s, f;
        for (i = 1; i < n; i++) {
            aux = x[i];
            s = i;
            f = (s - 1) / 2;
            while (s > 0 && x[f] < aux) {
                x[s] = x[f];
                s = f;
                f = (s - 1) / 2;
            }
            x[s] = aux;
        }
    }

    public static void heapsort(int[] x) {
        int i, s, f, ival;
        heapfica(x, x.length);
        for (i = x.length - 1; i > 0; i--) {
            //Copia-se x[i] - última posição
            ival = x[i];
            //Insere x[0] (raiz, maior valor) no final
            x[i] = x[0];
            //Ajusta o heap novamente
            f = 0;
            if (i == 1) {
                s = -1;
            } else {
                s = 1;
            }
            if (i > 2 && x[2] > x[1]) {
                s = 2;
            }
            while (s >= 0 && ival < x[s]) {
                x[f] = x[s];
                f = s;
                s = 2 * f + 1;
                if (s + 1 <= i - 1 && x[s] < x[s + 1]) {
                    s = s + 1;
                }
                if (s > i - 1) {
                    s = -1;
                }
            }
            x[f] = ival;
        }
    }
}
