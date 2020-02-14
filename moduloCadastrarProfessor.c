#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"moduloGeral.h"
#include "validar.h"
#include<ctype.h>



int ValidarIdProfessor(Professor *listaDeProfessores, int numeroDeProfessoresCadastrados, int id){
  int i, teste = 1;

  for(i=0;i<numeroDeProfessoresCadastrados;i++){
    if(id == listaDeProfessores[i].matricula)
        teste = 2;
  }
  return teste;
}


int CadastrarProfessor(int numeroDeProfessores, int numeroDeProfessoresCadastrados, Professor *listaDeProfessores){
  char cpf[12];
  int valido, id, k;
  int dia, mes, ano;
  int validarDataDeNascimento = 0;
  char letra;

  srand(time(NULL));

    printf("\n================================================================\n");
    
    printf("\nInforme O nome Do Professor:\t");
    
    fgets(listaDeProfessores[numeroDeProfessoresCadastrados].nome,50,stdin);

    do{
      id = ((rand() % 150));
      valido = ValidarIdProfessor(listaDeProfessores, numeroDeProfessoresCadastrados, id);

      if(valido == 2)
        listaDeProfessores[numeroDeProfessoresCadastrados].matricula = id*2;
      else
        listaDeProfessores[numeroDeProfessoresCadastrados].matricula = id;  
           
    }while(valido == 2);
    
  
    while (1){

      printf("Informe o Sexo do Professor Valido (M - F):\t");
      fflush(stdin);
      scanf("%c",&letra);
      letra = toupper(letra);
      listaDeProfessores[numeroDeProfessoresCadastrados].sexo = letra;

      if(letra == 'M' || letra == 'F'){

          break;
      }
    }
    
    
    getchar();
    while(1){
        printf("Informe o CPF do professor:(apenas numeros)\t");
        fflush(stdin);
        scanf("%s",&cpf);

        if(ValidarCPF(cpf)){
            for(k=0;k<12;k++){
                listaDeProfessores[numeroDeProfessoresCadastrados].cpf[k]=cpf[k];
            }
            break;
        }else
            printf("O CPF informado nao eh valido!\t");
    }

    getchar();
    while (1){
      // aqui é validado a data de nascimento
      // a variavel validarDataDeNascimento nasceu como 0 forçando entrar no if de primeira

        if (validarDataDeNascimento == 0){

          printf("Infome a data de nascimento ex: (07 12 1993) com os espacos:\t");
          fflush(stdin);
          scanf("%d %d %d",&dia,&mes,&ano);
          validarDataDeNascimento = ValidarData(dia,mes,ano);

        }
        else{

            listaDeProfessores[numeroDeProfessoresCadastrados].dataNascimento.dia = dia;
            listaDeProfessores[numeroDeProfessoresCadastrados].dataNascimento.mes = mes;
            listaDeProfessores[numeroDeProfessoresCadastrados].dataNascimento.ano = ano;
            break;
        }
    }

    printf("\n================================================================\n");
    getchar();
    return 1;
}

void AtualizarProfessor(Professor *listaDeProfessores, int numeroDeProfessoresCadastrados){
//atualizar o professor
  char cpf[12];
  int i, codProfessor, att=0, id, valido, k;

  printf("Informe a matricula do professor que deseja alterar: ");
  fflush(stdin);
  scanf("%d",&codProfessor);
  getchar();

  for (i = 0; i < numeroDeProfessoresCadastrados; i++){
    if (listaDeProfessores[i].matricula == codProfessor){
      printf("\nInforme o novo nome da professor: ");
      fflush(stdin);
      fgets(listaDeProfessores[i].nome, 50, stdin);


      do{
        printf("\nInforme o novo codigo do professor: ");
        fflush(stdin);
        scanf("%d",&id);
        
        valido = ValidarIdProfessor(listaDeProfessores, numeroDeProfessoresCadastrados, id);

        if(valido == 2)
          printf("Matricula invalida");
        else
          listaDeProfessores[i].matricula = id;
      }while(valido ==2);

      getchar();
      printf("Informe o novo Sexo do Professor:\t");
      fflush(stdin);
      scanf("%c", &listaDeProfessores[i].sexo);

      getchar();
      while(1){
        printf("Informe o novo CPF do professor:(apenas numeros)\t");
        fflush(stdin);
        scanf("%s",cpf);

        if(ValidarCPF(cpf)){
            for(k=0;k<12;k++){
                listaDeProfessores[i].cpf[k]=cpf[k];
            }
            break;
        }else
            printf("O CPF informado nao eh valido!\t");
      }

      getchar();
      printf("Infome a nova data de nascimento ex: (07 12 1993) com os espacos:\t");
      fflush(stdin);
      scanf("%d %d %d", &listaDeProfessores[i].dataNascimento.dia,
            &listaDeProfessores[i].dataNascimento.mes,
            &listaDeProfessores[i].dataNascimento.ano);

      getchar();
      printf("Professor %s atualizado.",listaDeProfessores[i].nome);
      att = 1;
    }
  }
  if(att=0) printf("Professor nao encontrado");
  getchar();
}

int ExcluirProfessor(Professor *listaDeProfessores, int numeroDeProfessoresCadastrados){
  int i, resultado, matricula;

  printf("Informe a matricula do professor para excluir: ");
  scanf("%d",&matricula);
  fflush(stdin);

  for(i=0;i<numeroDeProfessoresCadastrados;i++){
      if(matricula == listaDeProfessores[i].matricula){
        listaDeProfessores[i] = listaDeProfessores[numeroDeProfessoresCadastrados-1];
        printf("Professor excluido");
        resultado =-1;
        return resultado;
      }else{
        printf("Professor nao encontrado");
        return resultado = 0;
      }
  }
}

