#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <sys/time.h>
#define CLEAR "CLS"

unsigned long long current_timestamp() {
    struct timeval tv;
    unsigned long long tim;
    gettimeofday(&tv, NULL);
    tim = 1000000 * tv.tv_sec + tv.tv_usec;
    return tim;
}

void imprimirArray(int *array, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
}

int *criarArray(int tam) {
    int *array = (int *) malloc(sizeof(int) * tam);
    for (int i = 0; i < tam; i++) {
        array[i] = i + 1;
    }
    return array;
}

int *desorganizar(int *array, int tam) {
    time_t tim;
    srand((unsigned) time(&tim));
    for (int i = 0; i < tam; i++) {
        int rand_pos = (int)(((double)rand()/RAND_MAX) * tam);
        int t = array[rand_pos];
        array[rand_pos] = array[i];
        array[i] = t;
    }
    return array;
}

void imprimeMenu() {
    printf("================================================================\n");
    printf("|     Tempo de execucao de diferentes metodos de ordenacao     |\n");
    printf("================================================================\n");
    printf("| Operacoes:                                                   |\n");
    printf("| 1) Insertion Sort                                            |\n");
    printf("| 2) Shell Sort                                                |\n");
    printf("| 3) Bubble Sort                                               |\n");
    printf("| 4) Quick Sort                                                |\n");
    printf("| 5) Merge Sort                                                |\n");
    printf("| 6) Heap Sort                                                 |\n");
    printf("| 7) Imprimir array original                                   |\n");
    printf("| 8) Imprimir array ordenado                                   |\n");
    printf("| 9) Sair                                                      |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("  Pressione a opcao desejada ");
}

void insertionSort(int x[], int tam) {

    unsigned long long t1, t2;
    int i, k, aux;

    t1 = current_timestamp();
    for (k=1; k<tam; k++){
        aux = x[k];
        for (i = k - 1; i >= 0 && aux < x[i]; i--){
            x[i+1] = x[i];
        }
        x[i+1] = aux;
    }
    t2 = current_timestamp();
    printf("\nDuracao em microssegundos insertion sort: %lld\n", t2 - t1);
}

void shellSort(int x[], int tam) {
    int gap, j, k, aux;
    unsigned long long t1, t2;
    t1 = current_timestamp();
    for (gap = tam/2; gap >= 1; gap = gap/2){
        for (j = gap; j<tam; j++){
            aux = x[j];
            for(k=j-gap; k >= 0 && aux < x[k]; k-=gap){
                x[k+gap] = x[k];
            }
            x[k+gap] = aux;
        }
    }
    t2 = current_timestamp();
    printf("\nDuracao em microssegundos shellsort: %lld\n", t2 - t1);
}

void bubbleSort(int v[], int n) {
    int i, j, aux;
    for(j = n - 1; j > 0; j--) {
        for(i = 0; i < j; i++) {
            if(v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
        }
    }
}

void quickSort(int x[], int p, int u) {
    int i, j, pivo, aux;
    i = p;
    j = u;
    pivo = x[(i + j)/2];
    do{
        while(x[i] < pivo && i < u) i++;
        while(x[j] > pivo && j > p) j--;
        if(i <= j){
            aux = x[i];
            x[i] = x[j];
            x[j] = aux;
            i++;
            j--;
        }
    } while(i <= j);
    if(p < j) quickSort(x, p, j);
    if(i < u) quickSort(x, i, u);
}

void merge(int *x, int *temp, int esq, int meio, int dir) {
    int i, esq_fim, tam, tmp_pos;
    esq_fim = meio - 1;
    tmp_pos = esq;
    tam = dir - esq + 1;
    while ((esq <= esq_fim) && (meio <= dir)) { //Junção ordenada em temp
        if (x[esq] <= x[meio]) {                //Se elemento da esquerda menor
            temp[tmp_pos] = x[esq];
            tmp_pos++;
            esq++;
        }
        else {
            temp[tmp_pos] = x[meio];            //Se elemento da direita menor
            tmp_pos++;
            meio++;
        }
    }
    if (esq <= esq_fim) {                       //Sobraram elementos na esquerda
        memcpy(&temp[tmp_pos], &x[esq], (esq_fim - esq + 1)*sizeof(int));
    }
    if (meio <= dir) {                          //Sobraram elementos na direita
        memcpy(&temp[tmp_pos], &x[meio], (dir - meio + 1)*sizeof(int));
    }
    //Copiar elementos de temp para x
    memcpy(&x[dir - tam + 1], &temp[dir - tam + 1], tam*sizeof(int));
}

void mergeSort(int *x, int *temp, int esq, int dir) {
    int meio;
    if (dir > esq) {
        meio = (dir + esq) / 2;
        mergeSort(x, temp, esq, meio);
        mergeSort(x, temp, meio+1, dir);
        merge(x, temp, esq, meio+1, dir);
    }
}

void heapfica(int *x, int n) {
    int i, aux, s, f;
	for (int i = 1; i < n; i++) {
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

void heapsort(int *x, int n) {
	int i, s, f, ival;
    heapfica(x, n);
	for(i = n - 1; i > 0; i--) {
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

int main() {
    int *original, *ordenado, tam, inicio=0, *temp;
    unsigned long long t1,t2;

    printf("Digite um tamanho para o vetor a ser ordenado: ");  //pede o tamanho do array para o usuario
    scanf("%u", &tam);

    original = desorganizar(criarArray(tam), tam);              //cria o array original
    ordenado = (int *) malloc(sizeof(int) * tam);               //aloca memoria para o array ordenado
    memcpy(ordenado, original, sizeof(int) * tam);              //copiar sempre o original para o ordenado, antes de chamar cada metodo de ordenacao



    char opcao = '0';
    while(opcao != '9') {
        system("CLS");
        imprimeMenu();
        opcao = getch();
        switch(opcao) {
            case '1':   memcpy(ordenado, original, sizeof(int) * tam);
                        insertionSort(ordenado, tam);
                        getch();
                        break;

            case '2':   memcpy(ordenado, original, sizeof(int) * tam);
                        shellSort(ordenado, tam);
                        getch();
                        break;

            case '3':   memcpy(ordenado, original, sizeof(int) * tam);
                        t1 = current_timestamp();
                        bubbleSort(ordenado,tam);
                        t2= current_timestamp();
                        printf("\nDuracao em microssegundos Bubble Sort: %lld\n", t2 - t1);
                        getch();
                        break;


            case '4':   memcpy(ordenado, original, sizeof(int) * tam);
                        t1 = current_timestamp();
                        quickSort(ordenado,inicio,tam-1);
                        t2= current_timestamp();
                        printf("\nDuracao em microssegundos Quick Sort: %lld\n", t2 - t1);
                        getch();
                        break;

            case '5':   temp = (int *) malloc(sizeof(int) * tam);                   //aloca memoria para o array temp paara ser utilizado no Merge Sort
                        memcpy(ordenado, original, sizeof(int)*tam);
                        t1 = current_timestamp();
                        mergeSort(ordenado,temp,0,tam-1);
                        t2 = current_timestamp();
                        printf("\nDuracao em microssegundos Merge Sort: %lld\n", t2 - t1);
                        getch();
                        break;

            case '6':   memcpy(ordenado, original, sizeof(int) * tam);
                        t1 = current_timestamp();
                        heapsort(ordenado,tam);
                        t2 = current_timestamp();
                        printf("\nDuracao em microssegundos Merge Sort: %lld\n", t2 - t1);
                        getch();
                        break;

            case '7':   printf("\nVetor original: ");
                        imprimirArray(original,tam);
                        getch();
                        break;

            case '8':   printf("\nVetor ordenado: ");
                        imprimirArray(ordenado,tam);
                        getch();
                        break;

            case '9':   break;
                        break;

            default:    printf("\nOpcao invalida!\n");
                        getch();
                        break;
        }
    }

    return 0;
}
