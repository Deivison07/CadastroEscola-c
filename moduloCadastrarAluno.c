#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "moduloGeral.h"
#include "validar.h"
#include<ctype.h>


int ValidarIdAluno(Aluno *listaDeAlunos, int numeroDeAlunosCadastrados, int id){
  int i, teste = 1;
  for(i=0;i<numeroDeAlunosCadastrados;i++){
    if(id == listaDeAlunos[i].matricula)
      teste = 2;
  }
  return teste;
}


int CadastrarAluno(int numeroDeAlunos, int numeroDeAlunosCadastrados, Aluno *listaDeAlunos){
//Cadastra o aluno gerando um id automático com o rand, deveria criar um verificador de ids para saber se aquele id pode ser inserido...
  char cpf[12];
  int valido, id, i;
  int dia, mes, ano;
  int validarDataDeNascimento = 0;

  char letra;

  srand(time(NULL));

    printf("\n================================================================\n");

    printf("\nInforme O nome Do Aluno:\t");
    fflush(stdin);
    fgets(listaDeAlunos[numeroDeAlunosCadastrados].nome,50,stdin);


    do{
      id = ((rand() % 150));
      valido = ValidarIdAluno(listaDeAlunos, numeroDeAlunosCadastrados, id);

      if(valido == 2)
        listaDeAlunos[numeroDeAlunosCadastrados].matricula = id*2;
      else
        listaDeAlunos[numeroDeAlunosCadastrados].matricula = id;  
           
    }while(valido == 2);
    
    while (1){

      printf("Informe o Sexo do Aluno Valido (M - F):\t");
      fflush(stdin);
      scanf("%c",&letra);
      letra = toupper(letra);
      listaDeAlunos[numeroDeAlunosCadastrados].sexo = letra;

      if(letra == 'M' || letra == 'F' ){
          break;
      }

    }
      getchar();
     while(1){
        printf("Informe o CPF do Aluno:(apenas numeros)\t");
        fflush(stdin);
        scanf("%s",&cpf);

        if(ValidarCPF(cpf)){
            for(i=0;i<12;i++){
                listaDeAlunos[numeroDeAlunosCadastrados].cpf[i]=cpf[i];
            }
            break;
        }else
            printf("O CPF informado nao eh valido!\t");
    }
    getchar();
    while (1)
    {
      // aqui é validado a data de nascimento
      // a variavel validarDataDeNascimento nasceu como 0 forçando entrar no if de primeira    
      if (validarDataDeNascimento == 0){

          printf("Infome a data de nascimento VALIDA ex: (07 12 1993) com os espacos:\t");
          fflush(stdin);
          scanf("%d %d %d",&dia, &mes,&ano);
          validarDataDeNascimento = ValidarData(dia,mes,ano);
      }
      else{

          listaDeAlunos[numeroDeAlunosCadastrados].dataNascimento.dia = dia;
          listaDeAlunos[numeroDeAlunosCadastrados].dataNascimento.mes = mes;
          listaDeAlunos[numeroDeAlunosCadastrados].dataNascimento.ano = ano;
          break;
      }
    }

    printf("\n================================================================\n");
    
    return 1;
}

void AtualizarAluno(Aluno *listaDeAlunos, int numeroDeAlunosCadastrados){
//Atualizar o aluno a partir do numero de matricula
  char cpf[12];
  int codAluno, i, att=0, valido, id, k;

  printf("Informe a matricula do aluno que deseja atualizar: ");
  fflush(stdin);
  scanf("%d",&codAluno);
  getchar();

  for (i = 0; i < numeroDeAlunosCadastrados; i++){
    if (listaDeAlunos[i].matricula == codAluno){
      printf("\nInforme o novo nome do aluno: ");
      fflush(stdin);
      fgets(listaDeAlunos[i].nome, 50, stdin);
     
        do{
          printf("\nInforme o novo codigo do aluno: ");
          fflush(stdin);
          scanf("%d",&id);
          
          valido = ValidarIdAluno(listaDeAlunos, numeroDeAlunosCadastrados, id);

          if(valido == 2)
            printf("Matricula invalida");
          else
            listaDeAlunos[i].matricula = id;
        }while(valido ==2 );

          getchar();
          printf("Informe o novo sexo do Aluno:\t");
          fflush(stdin);
          scanf("%c", &listaDeAlunos[i].sexo);
        
          getchar();
          while(1){
                printf("Informe o CPF do Aluno:(apenas numeros)\t");
                fflush(stdin);
                scanf("%s",cpf);

                if(ValidarCPF(cpf)){
                    for(k=0;k<12;k++){
                        listaDeAlunos[i].cpf[k]=cpf[k];
                    }
                    break;
                }else
                    printf("O CPF informado nao eh valido!\t");
          }

          getchar();
          printf("Infome a nova data de nascimento ex: (07 12 1993) com os espacos:\t");
          fflush(stdin);
          scanf("%d %d %d", &listaDeAlunos[i].dataNascimento.dia,
                &listaDeAlunos[i].dataNascimento.mes,
                &listaDeAlunos[i].dataNascimento.ano);

          printf("Aluno %s atualizado.", listaDeAlunos[i].nome);
          att =1;
          getchar();
    }
  }
  if(att==0) printf("Aluno nao encontrado");
}

int ExcluirAluno(Aluno *listaDeAlunos, int numeroDeAlunosCadastrados){
  int i, resultado, matricula;

  printf("Informe a matricula do aluno para excluir: ");
  scanf("%d",&matricula);
  fflush(stdin);

  for(i=0;i<numeroDeAlunosCadastrados;i++){
      if(matricula == listaDeAlunos[i].matricula){
        listaDeAlunos[i] = listaDeAlunos[numeroDeAlunosCadastrados-1];
        printf("Aluno excluido");
        resultado =-1;
        return resultado;
      }else{
        printf("Aluno nao encontrado");
        return resultado = 0;
      }
  }
}



int validarDataDeNascimento(int dia,int mes,int ano){





}

