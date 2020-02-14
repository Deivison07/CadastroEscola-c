#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"moduloGeral.h"

int CadastrarDisciplinas(int numeroDeDisciplinas, int numeroDeDisciplinasCadastradas, Disciplina *listaDeDisciplinas, Professor *listaDeProfessores, int numeroDeProfessoresCadastrados){
    srand(time(NULL));
    int i = 0;
    int prof;
    printf("\n================================================================\n");

    printf("\nInforme O Nome Da Disciplina:\t");
    fflush(stdin);
    fgets(listaDeDisciplinas[numeroDeDisciplinasCadastradas].nome,50,stdin);
    

    listaDeDisciplinas[numeroDeDisciplinasCadastradas].codigo = ((rand() % 150)); // ta dando ao id um numero random

    
    printf("Informe O Semestre da Disciplina:\t");
    fflush(stdin);
    scanf("%d",&listaDeDisciplinas[numeroDeDisciplinasCadastradas].semestre);

    getchar();
    printf("Informe o indice do Professor Da materia:\n");
    for (i=0;i<numeroDeProfessoresCadastrados;i++){
        printf("(%d) ---------> %s\n",i,listaDeProfessores[i].nome);
    }
    fflush(stdin);
    scanf("%d",&prof);
    listaDeDisciplinas[numeroDeDisciplinasCadastradas].docente = listaDeProfessores[prof];


    return 1;
}

void AtualizarDisciplina(Disciplina *listaDeDisciplinas, int numeroDeDisciplinas){
//atualizar a disciplina
 int codDisciplina, i, att=0;
    
    printf("Informe o codigo da disciplina que deseja atualizar: ");
    scanf("%d",&codDisciplina);
    getchar();

    for(i=0;i<numeroDeDisciplinas;i++){
        if(listaDeDisciplinas[i].codigo == codDisciplina){
            printf("\nInforme o novo nome da disciplina: ");
            fflush(stdin);
            fgets(listaDeDisciplinas[i].nome, 50, stdin);

            printf("\nInforme o novo codigo da disciplina: ");
            fflush(stdin);
            scanf("%d",&codDisciplina);
            getchar();

            printf("\nInforme o novo semestre: ");
            fflush(stdin);
            scanf("%d",&listaDeDisciplinas[i].semestre);
            getchar();

            printf("Atualizado");
            att=1;
        }
    }
    if(att!=1) printf("Disciplina nao encontrada"); 
}

int ExcluirDisciplina(Aluno *listaDeDisciplinas, int numeroDeDisciplinas){
  int i, resultado, matricula;

  printf("Informe o codigo da disciplina para excluir: ");
  scanf("%d",&matricula);
  fflush(stdin);

  for(i=0;i<numeroDeDisciplinas;i++){
      if(matricula == listaDeDisciplinas[i].matricula){
        listaDeDisciplinas[i] = listaDeDisciplinas[numeroDeDisciplinas-1];
        printf("Disciplina excluida");
        resultado =-1;
        return resultado;
      }else{
        printf("Disciplina nao encontrada");
        return resultado = 0;
      }
  }
}