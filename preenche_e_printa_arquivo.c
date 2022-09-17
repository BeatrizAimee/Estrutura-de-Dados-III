#include "preenche_e_printa_arquivo.h"


//escreve os dados da struct no arquivo
void escrever_no_arquivo(FILE* arquivo, pessoa humano){
    
    fwrite(humano.nome, sizeof(char), 51, arquivo);
    fwrite(humano.sobrenome, sizeof(char), 51, arquivo);
    fwrite(humano.email, sizeof(char), 81, arquivo);
    fwrite(humano.nacionalidade, sizeof(char), 51, arquivo);
    fwrite(&(humano.idade), sizeof(int), 1, arquivo);
}



//preenche as strings com $ após o \0
void preencher_lixo(char* campo, int tamanho_do_campo){

    int i = 0;

    while(campo[i] != '\0'){//enquanto o caracter da string for diferente de \0
        i++;//anda pra frente na string
    }
    i++;//pega o caracter após o \0

    if((i-1) >= tamanho_do_campo){//checa se precisa por lixo
        return;//se não precisar, sai da função
    }

    while(i < tamanho_do_campo){//enquanto contador for menor que o tamanho do campo
        campo[i] = '$';//por lixo
        i++;
    }
}


int printa_registro(pessoa humano, FILE* arquivo){

    //se o arquivo não está no final, printa o registro
    if(fread(humano.nome, sizeof(char)*51, 1, arquivo) != 0){
        
        printf("Firstname: %s\n", humano.nome);

        fread(humano.sobrenome, sizeof(char)*51, 1, arquivo);
        printf("Lastname: %s\n", humano.sobrenome);

        fread(humano.email, sizeof(char)*81, 1, arquivo);
        printf("Email: %s\n", humano.email);

        fread(humano.nacionalidade, sizeof(char)*51, 1, arquivo);
        printf("Nationality: %s\n", humano.nacionalidade);

        fread(&(humano.idade), sizeof(int), 1, arquivo);
        printf("Age: %d\n\n", humano.idade);
    }
    //se o arquivo chega no final, retorna a flag de parada
    else{
        return 0;
    }
}