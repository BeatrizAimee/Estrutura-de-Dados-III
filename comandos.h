#ifndef __COMANDOS_H__
#define __COMANDOS_H__

#include <stdio.h>
#include "abertura_e_leitura_de_arquivos.h"
#include "preenche_e_printa_arquivo.h"
#include "funções_fornecidas.h"
#include "pessoa.h"

//define tamanho fixo para um registro em bytes
#define TAMANHO_DO_REGISTRO 238

void comando_insere_pessoa(char*);
void comando_printa_registros(char*);
void comando_printa_RRN(char*);

#endif