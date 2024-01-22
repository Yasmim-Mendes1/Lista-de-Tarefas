//Yasmim Mendes - UEMG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100

struct Tarefa {
  char descricao[100];
  int concluida;
};

void adicionarTarefa(struct Tarefa tarefas[], int *nTarefas, const char *descricao){
  if (*nTarefas < MAX_TAREFAS){
    struct Tarefa novaTarefa;
    strcpy(novaTarefa.descricao, descricao);
    novaTarefa.concluida = 0;
    tarefas[*nTarefas] = novaTarefa;
    (*nTarefas)++;
    printf ("Nova tarefa adicionada com sucesso!\n");
  }
  else {
    printf ("Número máximo de tarefas atingido!\nNão foi possível adicionar a tarefa\n");
  }
}

void concluirTarefa(struct Tarefa tarefas[], int nTarefas, int indice){
  if (indice > 0 && indice <= nTarefas){
    tarefas[indice - 1].concluida = 1;
    printf ("Tarefa marcada como concluída!\n");
  }
  else {
    printf ("Índice inválido!\nNão foi possível marcar como concluída.\n");
  }
}

void listaTarefas(struct Tarefa tarefas[], int nTarefas){
  if (nTarefas > 0){
    printf ("\nLista de tarefas:\n");

    for (int i = 0; i < nTarefas; i++){
      printf ("%d. [%s] %s\n", i + 1, tarefas[i].concluida ? "x" : " ", tarefas[i].descricao);
    }
  }
  else {
    printf ("Lista de tarefas vazia!\n");
  }
}

void removerTarefa (struct Tarefa tarefas[], int *nTarefas, int indice){
  if (*nTarefas > 0 && indice > 0 && indice <= *nTarefas){
    for (int i = indice - 1; i < *nTarefas - 1; i++){
      tarefas[i] = tarefas [i + 1];
    }
    (*nTarefas)--;
    printf ("Tarefa excluída com sucesso!\n");
  }
  else {
    printf ("Índice inválido!\nNão foi possível excluir a tarefa.\n");
  }
}

int main (){
  struct Tarefa tarefas[MAX_TAREFAS];
  int nTarefas = 0;
  int escolha, indice;
  char descricao[100];

  do {
    printf ("\n\n---------Menu:---------\n");
    printf ("1. Adicionar tarefa;\n");
    printf ("2. Exibir lista de tarefas;\n");
    printf ("3. Marcar como concluída;\n");
    printf ("4. Remover tarefa;\n");
    printf ("5. Sair.\n");

    printf ("\nEscolha uma opção: ");
    scanf ("%d", &escolha);

    switch (escolha){
      case 1:
        printf ("Informe a descrição da tarefa: ");
        scanf (" %[^\n]", descricao);
        adicionarTarefa(tarefas, &nTarefas, descricao);
        break;

      case 2:
        listaTarefas(tarefas, nTarefas);
        break;

      case 3:
        printf ("Informe o índice da tarefa concluída: ");
        scanf ("%d", &indice);
        concluirTarefa(tarefas, nTarefas, indice);
        break;

      case 4:
        printf ("Informe o índice da tarefa a ser removida: ");
        scanf ("%d", &indice);
        removerTarefa(tarefas, &nTarefas, indice);
        break;
      
      case 5:
        printf ("Saindo do programa... Até logo!\n");
        break;
      
      default: 
        printf ("Opção inválida! Tente novamente.\n");
    }
  } while (escolha != 5);

  return 0;
}
