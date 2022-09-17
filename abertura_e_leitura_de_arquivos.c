#include "abertura_e_leitura_de_arquivos.h"

//abre um arquivo a partir de dado nome para leitura e verifica se obteve sucesso
FILE* abrir_leitura(char* nome_do_arquivo){
    FILE* arquivo;

    arquivo = fopen(nome_do_arquivo, "rb");

    if(arquivo == NULL){
        printf("Falha no processamento do arquivo \n");
        return 0;
    }

    return arquivo;
}

//abre um arquivo a partir de dado nome para escrita e verifica se obteve sucesso
FILE* abrir_escrita(char* nome_do_arquivo){
    FILE* arquivo;

    arquivo = fopen(nome_do_arquivo, "wb");

    if(arquivo == NULL){
        printf("Falha no processamento do arquivo \n");
        return 0;
    }

    return arquivo;
}

//recebe uma struct humano e coloca em seus campos o lido do teclado
pessoa ler_dados(pessoa humano){

    readline(humano.nome);
    readline(humano.sobrenome);
    readline(humano.email);
    readline(humano.nacionalidade);
    scanf("%d", &(humano.idade));

    return humano;
}