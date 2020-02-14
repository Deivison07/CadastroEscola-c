#include<stdio.h>
#include<stdlib.h>
#include"moduloGeral.h"
#include"moduloCadastrarProfessor.h"
#include"moduloCadastrarAluno.h"
#include"moduloCadastrarDisciplinas.h"
#include"moduloInserirExcluirDisciplina.h"
#include"relatorios.h"
#include "validar.h"

int tratamentoAluno(int numeroDeAlunos, int numeroDeAlunosCadastrados, Aluno *listaDeAlunos);
int tratametoProfessor(int numeroDeProfessores, int numeroDeProfessoresCadastrados, Professor *listaDeProfessores);
int tratamentoDisciplinas(int numeroDeDisciplinas, int numeroDeDisciplinasCadastradas, Disciplina *listaDeDisciplinas,Professor *listaDeProfessores, int numeroDeProfessoresCadastrados);

int main(){

    int numeroDeAlunosPorDisciplina;

    int numeroDeAlunos;
    int numeroDeAlunosCadastrados = 0;

    int numeroDeProfessores;
    int numeroDeProfessoresCadastrados = 0;

    int numeroDeDisciplinas;
    int numeroDeDisciplinasCadastradas = 0;

    int opc;

    printf("\n================================================================\n");
    printf("\nInforme o numero de Disciplinas\t");
    fflush(stdin);
    scanf("%d",&numeroDeDisciplinas);
    
    printf("\nInforme o numero de Alunos\t");
    fflush(stdin);;
    scanf("%d",&numeroDeAlunos);

    printf("\nInforme o numero de Alunos por Disciplina Limit:(60)\t");
    fflush(stdin);;
    scanf("%d",&numeroDeAlunosPorDisciplina);

    printf("\nInforme o numero de Professores\t");
    fflush(stdin);
    scanf("%d",&numeroDeProfessores);
    printf("\n================================================================\n");
    Aluno listaDeAlunos[numeroDeAlunos];
    Professor listaDeProfessores[numeroDeProfessores];
    Disciplina listaDeDisciplinas[numeroDeDisciplinas];


    while (1){
        printf("\n================================================================\n");

        printf("Menu Aluno: %d - %d    \t\t(1)\nMenu Professor: %d = %d\t\t(2)\nMenu Disciplina: %d - %d\t\t(3)\nInserir/Excluir Aluno Em Disciplina\t(4)\nRelatorios\t\t\t\t(5)\nSair\t\t\t\t\t(0)\nDigite:\t\t",numeroDeAlunosCadastrados,numeroDeAlunos,
        numeroDeProfessoresCadastrados,numeroDeProfessores,numeroDeDisciplinasCadastradas,numeroDeDisciplinas);
        fflush(stdin);

        scanf("%d",&opc);
        system("cls");

        if(opc==1) numeroDeAlunosCadastrados += tratamentoAluno(numeroDeAlunos,numeroDeAlunosCadastrados,listaDeAlunos);
        if(opc==2) numeroDeProfessoresCadastrados += tratametoProfessor(numeroDeProfessores,numeroDeProfessoresCadastrados,listaDeProfessores);
        if(opc==3) numeroDeDisciplinasCadastradas += tratamentoDisciplinas(numeroDeDisciplinas,numeroDeDisciplinasCadastradas,listaDeDisciplinas,listaDeProfessores,numeroDeProfessoresCadastrados);
        if(opc==4) inserirExcluir(listaDeAlunos,numeroDeAlunosCadastrados,listaDeDisciplinas,numeroDeDisciplinasCadastradas,numeroDeAlunosPorDisciplina); 
        if(opc==5) relatorios(numeroDeAlunosCadastrados,listaDeAlunos,numeroDeProfessoresCadastrados,listaDeProfessores,numeroDeDisciplinasCadastradas,listaDeDisciplinas);
        
        if(opc==0) break;

        if(opc > 5 || opc < 1) printf("Opcao invalida");
    }
return 0; 
}//fim do programa

int tratamentoAluno(int numeroDeAlunos, int numeroDeAlunosCadastrados, Aluno *listaDeAlunos){
    int num, op;
    printf("(1): Cadastrar aluno: \n(2): Atualizar aluno: \n(3): Excluir aluno: \n");
    fflush(stdin);
    scanf("%d",&op);
    
    
    switch(op){
        case  1:
                getchar();
            if (numeroDeAlunos > numeroDeAlunosCadastrados){
                num = CadastrarAluno(numeroDeAlunos, numeroDeAlunosCadastrados, listaDeAlunos);
                return num;
            }else{
                printf("NUMERO DE ALUNOS ATINGIU O LIMITE\n");
                return 0;
            }
            break;
        case 2:
                getchar();
            if(numeroDeAlunosCadastrados!=0){
                AtualizarAluno(listaDeAlunos, numeroDeAlunosCadastrados); 
                return 0;
            }else{
                printf("NAO EXISTEM ALUNOS CADASTRADOS\n");
                return 0;
            }
        break;

        case 3:
            if(numeroDeAlunosCadastrados!=0){
                num = ExcluirAluno(listaDeAlunos, numeroDeAlunosCadastrados);
                return num;
            }else{
                printf("NAO EXISTEM ALUNOS CADASTRADOS\n");
                return 0;
            }
        break;  

        default: printf("Opcao invalida!");
        return 0; 
        break;
    }
}

int tratametoProfessor(int numeroDeProfessores, int numeroDeProfessoresCadastrados, Professor *listaDeProfessores){
    int num, op;

    printf("(1): Cadastrar professor: \n(2): Atualizar professor: \n(3): Excluir professor:\n");
    fflush(stdin);
    scanf("%d",&op);
    
    switch(op){
        case 1:
            getchar();
            if (numeroDeProfessores>numeroDeProfessoresCadastrados){
                num = CadastrarProfessor(numeroDeProfessores,numeroDeProfessoresCadastrados,listaDeProfessores);
                return num;
            }else{
                printf("NUMERO DE PROFESSORES ATINGIU O LIMITE\n");    
                return 0;
            }
        break;
        case 2:
            getchar();
            if(numeroDeProfessoresCadastrados!=0){
                AtualizarProfessor(listaDeProfessores, numeroDeProfessoresCadastrados);
            }else{
                printf("NAO EXISTEM PROFESSORES CADASTRADOS\n");
                return 0;
            }
        break;
        case 3:
            if(numeroDeProfessoresCadastrados!=0){
                num = ExcluirProfessor(listaDeProfessores, numeroDeProfessoresCadastrados);
                return num;
            }else{
                printf("NAO EXISTEM PROFESSORES CADASTRADOS\n");
                return 0;
            }
        break;

        default: printf("Opcao invalida!");
        return 0;
        break;
    }
}

int tratamentoDisciplinas(int numeroDeDisciplinas, int numeroDeDisciplinasCadastradas, Disciplina *listaDeDisciplinas,Professor *listaDeProfessores,int numeroDeProfessoresCadastrados){

    int num = 0, op;

    printf("(1): Cadastrar Disciplina: \n(2): Atualizar Disciplina: \n(3): Excluir Disciplina: ");
    fflush(stdin);
    scanf("%d",&op);
    

    switch (op){
        case 1:
            getchar();
            if ((numeroDeDisciplinas>numeroDeDisciplinasCadastradas) && (numeroDeProfessoresCadastrados>0)){
                num = CadastrarDisciplinas(numeroDeDisciplinas,numeroDeDisciplinasCadastradas,listaDeDisciplinas,listaDeProfessores,numeroDeProfessoresCadastrados);
                return num;
            }else{
                printf("NUMERO DE DISCIPLINAS ATINGIU O LIMITE \nOU AINDA NAO FOI CADASTRADO NENHUM PROFESSOR");
                return 0;
            }
        break;
        case 2:
            getchar();
            if(numeroDeDisciplinasCadastradas!=0){
                AtualizarDisciplina(listaDeDisciplinas, numeroDeDisciplinasCadastradas);
            }else{
                printf("NAO EXISTE DISCIPLINAS CADASTRADAS\n");
                return 0;
            }
        break;
        case 3:
            if(numeroDeDisciplinasCadastradas!=0){
                num = ExcluirDisciplina(listaDeDisciplinas, numeroDeDisciplinasCadastradas);
                return num;
            }else{
                printf("NAO EXISTEM DISCIPLINAS CADASTRADOS\n");
                return 0;
            }
        break;
        default: printf("Opcao invalida!");
        return 0;
        break;
    }
}




