#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_DO_REGISTRO 238

typedef struct{

    char nome[51];
    char sobrenome[51];
    char email[81];
    char nacionalidade[51];
    int idade;

}pessoa;

//abre um arquivo a partir de dado nome e verifica se obteve sucesso
FILE* abrir_arquivo(char* nome_do_arquivo, char* modo){
    FILE *arquivo;//declara o arquivo
    arquivo = fopen(nome_do_arquivo, modo);//abre no modo desejado

    if(arquivo == NULL){//verifica a existência do arquivo
        printf("Falha no processamento do arquivo\n");
        return 0;
    }

    return arquivo;
}

//recebe uma struct humano e coloca nos campos o lido do teclado
pessoa ler_dados(pessoa humano){

    readline(humano.nome);
    readline(humano.sobrenome);
    readline(humano.email);
    readline(humano.nacionalidade);
    scanf("%d", &humano.idade);

    return humano;
}

void readline(char* string){//coloca na string o lido do teclado
    char c = 0;

    do{
        c = (char) getchar();

    } while(c == '\n' || c == '\r');

    int i = 0;

    do{
        string[i] = c;
        i++;
        c = getchar();
    } while(c != '\n' && c != '\r');

    string[i]  = '\0';
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

    while(i < tamanho_do_campo){//enquanto for menor que o tamanho do campo
        campo[i] = '$';//por lixo
        i++;
    }
}

//escreve os dados da struct no arquivo
void escrever_no_arquivo(FILE* arquivo, pessoa humano){
    
    fwrite(humano.nome, sizeof(char), 51, arquivo);
    fwrite(humano.sobrenome, sizeof(char), 51, arquivo);
    fwrite(humano.email, sizeof(char), 81, arquivo);
    fwrite(humano.nacionalidade, sizeof(char), 51, arquivo);
    fwrite(&humano.idade, sizeof(int), 1, arquivo);
}

void binarioNaTela(char *nomeArquivoBinario) { /* Você não precisa entender o código dessa função. */

	/* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
	*  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

	unsigned long i, cs;
	unsigned char *mb;
	size_t fl;
	FILE *fs;
	if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
		fprintf(stderr, "ERRO AO ESCREVER O BINARIO NA TELA (função binarioNaTela): não foi possível abrir o arquivo que me passou para leitura. Ele existe e você tá passando o nome certo? Você lembrou de fechar ele com fclose depois de usar?\n");
		return;
	}
	fseek(fs, 0, SEEK_END);
	fl = ftell(fs);
	fseek(fs, 0, SEEK_SET);
	mb = (unsigned char *) malloc(fl);
	fread(mb, 1, fl, fs);

	cs = 0;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	printf("%lf\n", (cs / (double) 100));
	free(mb);
	fclose(fs);
}

void faz_comando1(int numero_de_registros, char* nome_do_arquivo, char* modo){

    FILE* arquivo;
    pessoa humano;

    arquivo = abrir_arquivo(nome_do_arquivo, modo);
    
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

void faz_comando2(char* nome_do_arquivo, char* modo){

    FILE* arquivo;
    arquivo = abrir_arquivo(nome_do_arquivo, modo);

    pessoa humano;

    while(fread(humano.nome, sizeof(char)*51, 1, arquivo) != 0) {

        printf("Firstname: %s\n", humano.nome);

        fread(humano.sobrenome, sizeof(char)*51, 1, arquivo);
        printf("Lastname: %s\n", humano.sobrenome);

        fread(humano.email, sizeof(char)*81, 1, arquivo);
        printf("Email: %s\n", humano.email);

        fread(humano.nacionalidade, sizeof(char)*51, 1, arquivo);
        printf("Nationality: %s\n", humano.nacionalidade);

        fread(&humano.idade, sizeof(int), 1, arquivo);
        printf("Age: %d\n\n", humano.idade);
    }
    fclose(arquivo);
}


//realiza o comando 3
void faz_comando3(char* nome_do_arquivo, char* modo){

    FILE* arquivo;
    pessoa humano;
    int RRN, byte_offset, temp;

    if(abrir_arquivo(nome_do_arquivo, modo) == 0){
        return;
    }
    else{

        arquivo = abrir_arquivo(nome_do_arquivo, modo);
        scanf("%d", &RRN);//pega o RRN
        byte_offset = RRN*TAMANHO_DO_REGISTRO;

        if(fread(temp, sizeof(char), 1, arquivo) == 0){
            printf("Não foi possível ler o arquivo\n");
            return;
        }

        fseek(arquivo, byte_offset, SEEK_SET);

        fread(humano.nome, sizeof(char)*51, 1, arquivo);
        printf("Firstname: %s\n", humano.nome);

        fread(humano.sobrenome, sizeof(char)*51, 1, arquivo);
        printf("Lastname: %s\n", humano.sobrenome);

        fread(humano.email, sizeof(char)*81, 1, arquivo);
        printf("Email: %s\n", humano.email);

        fread(humano.nacionalidade, sizeof(char)*51, 1, arquivo);
        printf("Nationality: %s\n", humano.nacionalidade);

        fread(&humano.idade, sizeof(int), 1, arquivo);
        printf("Age: %d\n\n", humano.idade);
    }
}


int main(){

    char* nome_do_arquivo;
    char* entrada;
    int comando;
    //int numero_de_registros_do_arquivo;
    FILE* arquivo;

    entrada = malloc(50*sizeof(char));//aloca espaço para entrada e nome do arquivo
    nome_do_arquivo = malloc(15*sizeof(char));

    readline(entrada);//pega a primeira linha da entrada (numero do comando e nome do arquivo)

    sscanf(entrada, "%d %s", &comando, nome_do_arquivo);//separa o numero da string

    if(comando == 1){
        int numero_de_registros;
        scanf("%d", &numero_de_registros);//pega numero de registros

        faz_comando1(numero_de_registros, nome_do_arquivo, "wb");
    }
    else if(comando == 2){
        faz_comando2(nome_do_arquivo, "rb")
    }
    else if(comando == 3){
        faz_comando3(nome_do_arquivo, "rb");
    }

    return 0;
}