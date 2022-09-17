CC = gcc
MAIN = main.c
AUXFILES = preenche_e_printa_arquivo.c funções_fornecidas.c comandos.c abertura_e_leitura_de_arquivos.c 
EXECNAME = main

all:
	${CC} -o ${EXECNAME} ${AUXFILES} ${MAIN}

run:
	./${EXECNAME}