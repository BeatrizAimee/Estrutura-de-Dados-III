#include "comandos.h"

void comando_insere_pessoa(char* nome_do_arquivo){

    FILE* arquivo;
    pessoa humano;
    int numero_de_registros = 0;

    scanf("%d", &numero_de_registros);

    arquivo = abrir_escrita(nome_do_arquivo);
    
    int i = 0;

    while(i < numero_de_registros){
        humano = ler_dados(humano);//preenche a struct com os dados lidos

        preencher_lixo(humano.nome, 51);//preenche com lixo as strings
        preencher_lixo(humano.sobrenome, 51);
        preencher_lixo(humano.email, 81);
        preencher_lixo(humano.nacionalidade, 51);
    
        escrever_no_arquivo(arquivo, humano);
        i++;
    }

    fclose(arquivo);
    binarioNaTela(nome_do_arquivo); 
}

void comando_printa_registros(char* nome_do_arquivo){

    FILE* arquivo;
    pessoa humano;

    arquivo = abrir_leitura(nome_do_arquivo);

    //enquanto fread do printa_registro não retornar a flag que o arquivo acabou, continua printando
    while(printa_registro(humano, arquivo) != 0);
    
    fclose(arquivo);
}

void comando_printa_RRN(char* nome_do_arquivo){

    FILE* arquivo;
    pessoa humano;
    int RRN, byte_offset;
    int temp;

    if(abrir_leitura(nome_do_arquivo) == 0){
        return;
    }
    else{

        arquivo = abrir_leitura(nome_do_arquivo);
        scanf("%d", &RRN);//pega o RRN
        byte_offset = RRN*TAMANHO_DO_REGISTRO;

        fseek(arquivo, byte_offset, SEEK_SET);

        //se o RRN é válido, printa o registro 
        if(printa_registro(humano, arquivo) == 0){
            printf("Não foi possível ler o arquivo\n");
            return;
        }  
    }
    
    fclose(arquivo);
}