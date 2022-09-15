#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define um tipo pessoa
typedef struct{

    char* nome;
    char* sobrenome;
    char* email;
    char* nacionalidade;
    int idade;

}pessoa;

//abre um arquivo a partir de dado nome e verifica se obteve sucesso
FILE* abrir_arquivo(char* nome_do_arquivo, char* modo){
    FILE *arquivo;//declara o arquivo
    arquivo = fopen(nome_do_arquivo, modo);//abre no modo desejado

    if(arquivo == NULL){//verifica a existência do arquivo
        printf("Falha no processamento do arquivo\n");
        return;
    }

    return arquivo;
}

//recebe o nome do arquivo
char* recebe_nome(){
    char** nome_do_arquivo;
    scanf("%ms", &nome_do_arquivo);
    
    return nome_do_arquivo;
}

//aloca espaço para os campos do registro
void aloca_pessoa(pessoa* humano){

    humano->nome = malloc(sizeof(char)*51);
    humano->sobrenome = malloc(sizeof(char)*51);
    humano->email = malloc(sizeof(char)*81);
    humano->nacionalidade = malloc(sizeof(char)*51);
    humano->idade = malloc(sizeof(int));

}

int main(){

    FILE* arquivo;

    int num_registros = 0;

    scanf("%d", &num_registros);

    arquivo = fopen("saida.bin", "wb");

    pessoa humano;

    humano.nome = malloc(sizeof(char)*51);
    humano.sobrenome = malloc(sizeof(char)*51);
    humano.email = malloc(sizeof(char)*81);
    humano.nacionalidade = malloc(sizeof(char)*51);
    humano.idade = malloc(sizeof(int));

    scanf("%d", &humano.idade);
    scanf("%s", humano.nome);
    scanf("%s", humano.sobrenome);
    scanf("%s", humano.email);
    scanf("%s", humano.nacionalidade);


    fwrite(humano.idade, sizeof(int), 1, arquivo);

    //loop

    fclose(arquivo);

    



    return 0;
}
