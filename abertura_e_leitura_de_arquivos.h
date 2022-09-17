#ifndef __ABERTURA_H__
#define __ABERTURA_H__

#include <stdio.h>
#include "pessoa.h"
#include "funções_fornecidas.h"

FILE* abrir_leitura(char*);
FILE* abrir_escrita(char*);
pessoa ler_dados(pessoa);

#endif