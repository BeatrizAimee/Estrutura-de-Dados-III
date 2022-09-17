#ifndef __PREENCHE_H__
#define __PREENCHE_H__

#include <stdio.h>
#include "pessoa.h"

void escrever_no_arquivo(FILE*, pessoa);
void preencher_lixo(char*, int);
int printa_registro(pessoa, FILE*);

#endif