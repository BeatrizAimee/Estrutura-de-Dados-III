#include <stdio.h>
#include "comandos.h"

int main(){

    char nome_do_arquivo[15];
    int comando = 0;

    scanf("%d", &comando);
    scanf("%s", nome_do_arquivo);

    if(comando == 1){
        comando_insere_pessoa(nome_do_arquivo);
    }
    else if(comando == 2){
        comando_printa_registros(nome_do_arquivo);
    }
    else if(comando == 3){
        comando_printa_RRN(nome_do_arquivo);
    }

    return 0;
}