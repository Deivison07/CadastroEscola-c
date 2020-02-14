#include<stdio.h>
#include<stdlib.h>
#include "moduloGeral.h"

void inserirExcluir(Aluno *listaDeAlunos,int numeroDeAlunosCadastrados,Disciplina *listaDeDisciplinas,int numeroDeDisciplinasCadastradas,int numeroDeAlunosPorDisciplina){

    int materia;
    int aluno;
    int descisao;
    int i;
    int alunoExcluir;

    Disciplina auxiliar;

    if (numeroDeDisciplinasCadastradas>0 && numeroDeAlunosCadastrados>0){

        for(i=0; i<numeroDeDisciplinasCadastradas; i++){

            printf("(%d) -------> %s",i,listaDeDisciplinas[i].nome);

        }

        fflush(stdin);
        printf("\nInforme de qual materia Inserir - Excluir:\t");
        scanf("%d",&materia);

        fflush(stdin);
        printf("Inserir\t(1)\nExcluir(2):\t");
        scanf("%d",&descisao);


        if (descisao==1){

            if (numeroDeAlunosPorDisciplina>listaDeDisciplinas[materia].alunosDaMateria){

                for (i = 0; i < numeroDeAlunosCadastrados; i++){
                    
                    printf("(%d) -----> %s\n",i,listaDeAlunos[i].nome);
                }

                printf("Informe o Aluno a ser Cadastrado na Materia\n");
                fflush(stdin);
                scanf("%d",&aluno);

                listaDeDisciplinas[materia].discentes[listaDeDisciplinas[materia].alunosDaMateria] = listaDeAlunos[aluno];
                listaDeDisciplinas[materia].alunosDaMateria += 1;
        
            }

            else{
                printf("Limite de alunos por Disciplina Atingido");
            }

        }

        if (descisao==2){

            for(i = 0 ; i<listaDeDisciplinas[materia].alunosDaMateria;i++){

                printf("(%d) ----> %s\n",i,listaDeDisciplinas[materia].discentes[i].nome);
            }
            printf("Informe o Aluno que sera Excluido:");
            fflush(stdin);
            scanf("%d",&alunoExcluir);

            auxiliar.discentes[0] = listaDeDisciplinas[materia].discentes[alunoExcluir];

            for(i = alunoExcluir;i<listaDeDisciplinas[materia].alunosDaMateria;i++){

                listaDeDisciplinas[materia].discentes[i] =  listaDeDisciplinas[materia].discentes[i+1];
            }

            listaDeDisciplinas[materia].discentes[listaDeDisciplinas[materia].alunosDaMateria] = auxiliar.discentes[0];
            listaDeDisciplinas[materia].alunosDaMateria -=1;
            

        }//descisão 2
    }
    else{
        printf("NAO HA DISCIPLINA OU ALUNO CADASTRADOS");

    }
    
}
