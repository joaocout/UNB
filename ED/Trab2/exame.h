#ifndef __EXAME_H__
#define __EXAME_H__

#include "eds.h"

void start();

Ninja* escolherninja(t_lista* list);

void torneio(t_node* root, Ninja* personagem, int etapa);

void randvet(int* vet, int range);

void historico();


#endif