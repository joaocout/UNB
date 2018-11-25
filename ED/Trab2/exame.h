/**
@file exame.h
@brief Arquivo de header/declaração das funcções implementadas no arquivo exame.c
\par
Contém declarações de funcções que tratam da execução do torneio em si, utilizando as estruturas e funções dos arquivos
eds.c e eds.h.
**/

#ifndef __EXAME_H__
#define __EXAME_H__

#include "eds.h"

void start();

Ninja* escolherninja(t_lista* list);

void torneio(t_node* root, Ninja* personagem, int etapa);

void randvet(int* vet, int range);

void historico();


#endif