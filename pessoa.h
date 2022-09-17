#ifndef __PESSOA_H__
#define __PESSOA_H__


//definição de uma struct pessoa e seus campos
typedef struct{

    char nome[51];
    char sobrenome[51];
    char email[81];
    char nacionalidade[51];
    int idade;

}pessoa;

void comando_insere_pessoa(char*);
void comando_printa_registros(char*);
void comando_printa_RRN(char*);

#endif