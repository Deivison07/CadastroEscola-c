#include<stdio.h>
#include<stdlib.h>
#include"moduloGeral.h"
#include"listar.h"


void relatorios(int numeroDeAlunosCadastrados, Aluno *listaDeAlunos, int numeroDeProfessoresCadastrados, Professor *listaDeProfessores, int numeroDeDisciplinasCadastradas, Disciplina *listaDeDisciplinas){

    while (1){
        int decisao;
        printf("==================================================\n");
        printf("Listar Alunos\t\t\t(0)\nListar Professores\t\t(1)\nListar Disciplinas\t\t(2)\nListar Disciplinas (Com Alunos) (3)\nListar alunos por sexo \t\t (4)\nOrdenar alunos por nome \t\t (5)\nListar professores por sexo \t\t (6)\nOrdenar professores por nome \t\t (7)\nListar aniversariantes do mes \t\t (8)\nBuscar \t\t (9)\nSair\t\t\t\t(10)\n");
        scanf("%d",&decisao);
        printf("==================================================\n");
        
        if (decisao == 0) ListarAlunos(numeroDeAlunosCadastrados,listaDeAlunos);
        if (decisao == 1) ListarProfessores(numeroDeProfessoresCadastrados,listaDeProfessores);
        if (decisao == 2) ListarDisciplinas(numeroDeDisciplinasCadastradas,listaDeDisciplinas);
        if (decisao == 3) ListarDisciplinas2(numeroDeDisciplinasCadastradas,listaDeDisciplinas);
        if (decisao == 4) ListarAlunosSexo(numeroDeAlunosCadastrados, listaDeAlunos);
        if (decisao == 5) ListarAlunosOrdemAlfabetica(numeroDeAlunosCadastrados, listaDeAlunos);
        if (decisao == 6) ListarProfessoresSexo(numeroDeProfessoresCadastrados, listaDeProfessores);
        if (decisao == 7) ListarProfessoresOrdemAlfabetica(numeroDeProfessoresCadastrados, listaDeProfessores);
        if (decisao == 8) ListarAniversariantesdoMes(numeroDeAlunosCadastrados, listaDeAlunos, numeroDeProfessoresCadastrados, listaDeProfessores);
        if (decisao == 9) ListarPessoasAPartirdeString(numeroDeAlunosCadastrados, listaDeAlunos, numeroDeProfessoresCadastrados, listaDeProfessores);
        if (decisao == 10) break; 
        if(decisao > 10 || decisao < 0) printf("Valor inválido");
    }
    





}