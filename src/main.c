#include "fila.h"
#include "pilha.h"

int main()
{
    int tam = 0, i = 0, j = 0, metodo=0;
    int **matriz;

    FILE *arquivo;

    arquivo = fopen("matriz.txt", "r");

    if (arquivo == NULL)
    {
        printf("\nArquivo inválido.\n");
        return 0;
    }

    fscanf(arquivo, "%d", &tam);

    matriz = (int **)malloc(sizeof(int *) * tam);
    for (i = 0; i < tam; i++)
    {
        matriz[i] = (int *)malloc(sizeof(int) * tam);
    }

    for(i=0;i<tam; i++){
        for(j=0; j<tam; j++){
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    printf("\nA matriz gerada foi: \n");
    ImprimirMatriz(tam, matriz);
    fscanf(arquivo, "%d", &metodo);
    
    if(metodo == 0){
        DFS(matriz, tam);
        printf("\nCaminho percorrido: \n");
        ImprimirMatriz(tam, matriz);
    }
    else if(metodo == 1){
        BFS(matriz, tam);
    }
    else{
        printf("\nMetodo nao reconhecido. Tente valores entre '0' e '1'.");
    }

    fclose(arquivo);



    return 0;
}