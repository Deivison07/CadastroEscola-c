#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"moduloGeral.h"
#include<ctype.h>

struct tm *data_atual; //-> O tipo de struct tm ta definido nas libs do C e pode ser acessada a partir de sua chamada
                        //Para utilizar os membros de sua função é um pouco diferente do comum





void ListarAlunos(int numeroDeAlunosCadastrados, Aluno *listaDeAlunos){
//Lista todos os alunos
    int i;
    printf("LISTA DE TODOS OS ALUNOS:\n");
    if(numeroDeAlunosCadastrados>0){
        for(i = 0; i<numeroDeAlunosCadastrados;i++){
            printf("%d %s\n",listaDeAlunos[i].matricula,listaDeAlunos[i].nome);
        }
    }else{
        printf("Nenhum Aluno Cadastrado!\n\n");
    }
}

void ListarProfessores(int numeroDeProfessoresCadastrados, Professor *listaProfessores){
//Lista todos os professores
    int i;
    printf("LISTA DE TODOS OS PROFESSORES:\n");
    if(numeroDeProfessoresCadastrados>0){
        for(i = 0; i<numeroDeProfessoresCadastrados;i++){
            printf("%d\t%s\n",listaProfessores[i].matricula,listaProfessores[i].nome);
        }
    }
    else{
        printf("Nenhum Professor Cadastrado!\n\n");
    }   
}

void ListarDisciplinas(int numeroDeDisciplinasCadastradas, Disciplina *listaDisciplinas){
//Lista todas as disciplinas
    if (numeroDeDisciplinasCadastradas>0){
        int i=0;

        for(i=0;i<numeroDeDisciplinasCadastradas;i++){
            printf("\n====================================================\n");
            printf("Nome: %s",listaDisciplinas[i].nome);
            printf("Semestre: %d\n",listaDisciplinas[i].semestre);
            printf("Professor: %s",listaDisciplinas[i].docente.nome);
            printf("Codigo: %d\n",listaDisciplinas[i].codigo);
            printf("Numero de alunos na materia: %d\n",listaDisciplinas[i].alunosDaMateria);
            printf("\n====================================================\n");
        }      
    }else{
        printf("NAO HA DISCIPLIINAS PARA LISTAR!\n");
    }
}

void ListarDisciplinas2(int numeroDeDisciplinasCadastradas, Disciplina *listaDisciplinas){
//Lista a disciplina escolhida pelo usuario de forma detalhada, mostrando os alunos que fazem parte dela
    if (numeroDeDisciplinasCadastradas>0){
        int i=0;
        int decisao;
        printf("Informe o indice da Disciplica a ser listada:\n");

        for(i=0;i<numeroDeDisciplinasCadastradas;i++){

            printf("(%d) ----> %s",i,listaDisciplinas[i].nome);

        }
        scanf("%d",&decisao);

        printf("\n====================================================\n");

        printf("Nome: %s",listaDisciplinas[decisao].nome);
        printf("Semestre: %d\n",listaDisciplinas[decisao].semestre);
        printf("Professor: %s",listaDisciplinas[decisao].docente.nome);
        printf("Codigo: %d\n",listaDisciplinas[decisao].codigo);
        printf("Numero de alunos na materia: %d\n",listaDisciplinas[decisao].alunosDaMateria);
        
        printf("LISTA DE ALUNOS:\n");
        
        for(i=0;i<listaDisciplinas[decisao].alunosDaMateria;i++){

            printf("%s",listaDisciplinas[decisao].discentes[i].nome);
        }

        printf("\n====================================================\n");    
    }
    else{
        printf("NAO HA DISCIPLIINAS PARA LISTAR!\n");
    }
}

void ListarAlunosSexo(int numeroDeAlunosCadastrados, Aluno *listaDeAlunos){
//Lista os alunos a partir do sexo definido pelo usuario
    int i;
    char sexo;

    printf("informe o sexo que deseja listar:");
    scanf("%c",&sexo);
    sexo = getchar();
    sexo = toupper(sexo);
    printf("Lista dos alunos do sexo: %c\n",sexo);

    for(i=0;i<numeroDeAlunosCadastrados;i++){
        if(listaDeAlunos[i].sexo == sexo){
            printf("%s\t%d\n",listaDeAlunos[i].nome, listaDeAlunos[i].matricula);
        }
    }
}

void ListarProfessoresSexo(int numeroDeProfessoresCadastrados, Professor *listaDeProfessores){
//Lista os professores a partir do sexo definido pelo usuario
    int i;
    char sexo;

    printf("informe o sexo que deseja listar:");
    scanf("%c",&sexo);
    sexo = getchar();
    sexo = toupper(sexo);
    printf("Lista dos professores do sexo: %c\n",sexo);
    for(i=0;i<numeroDeProfessoresCadastrados;i++){
        if(listaDeProfessores[i].sexo == sexo){
            printf("%s\t%d\n",listaDeProfessores[i].nome, listaDeProfessores[i].matricula);
        }
    }
}
void ListarAlunosNascimento(int numeroDeAlunosCadastrados,Aluno *listaDeAlunos){
//Lista os alunos por ordem de nascimento
    int menor,i,j,k;
    Aluno troca;

    //selectionSort
    for(i=0;i<numeroDeAlunosCadastrados-1;i++){
        menor=i;
        for (j=i+1;j<numeroDeAlunosCadastrados;j++){
            if(listaDeAlunos[j].dataNascimento.ano<listaDeAlunos[menor].dataNascimento.ano)
                menor=j;
            else if ((listaDeAlunos[j].dataNascimento.ano==listaDeAlunos[menor].dataNascimento.ano) && (listaDeAlunos[j].dataNascimento.mes<listaDeAlunos[menor].dataNascimento.mes))
                menor=j;
            else if ((listaDeAlunos[j].dataNascimento.ano==listaDeAlunos[menor].dataNascimento.ano)
                     && (listaDeAlunos[j].dataNascimento.mes==listaDeAlunos[menor].dataNascimento.mes)
                     &&(listaDeAlunos[j].dataNascimento.dia<listaDeAlunos[menor].dataNascimento.dia))
                menor=j;
        }
        if (menor!=i){
            for(k=0;k<12;k++)
                troca.cpf[k]=listaDeAlunos[i].cpf[k];
                troca.dataNascimento.ano=listaDeAlunos[i].dataNascimento.ano;
                troca.dataNascimento.dia=listaDeAlunos[i].dataNascimento.dia;
                troca.dataNascimento.mes=listaDeAlunos[i].dataNascimento.mes;
                troca.matricula=listaDeAlunos[i].matricula;
                strcpy(troca.nome,listaDeAlunos[i].nome);
                troca.sexo=listaDeAlunos[i].sexo;

            for(k=0;k<12;k++)
                listaDeAlunos[i].cpf[k]=listaDeAlunos[menor].cpf[k];
                listaDeAlunos[i].dataNascimento.ano=listaDeAlunos[menor].dataNascimento.ano;
                listaDeAlunos[i].dataNascimento.dia=listaDeAlunos[menor].dataNascimento.dia;
                listaDeAlunos[i].dataNascimento.mes=listaDeAlunos[menor].dataNascimento.mes;
                listaDeAlunos[i].matricula=listaDeAlunos[menor].matricula;
                strcpy(listaDeAlunos[i].nome,listaDeAlunos[menor].nome);
                listaDeAlunos[i].sexo=listaDeAlunos[menor].sexo;

            for(k=0;k<12;k++)
                listaDeAlunos[menor].cpf[k]=troca.cpf[k];
                listaDeAlunos[menor].dataNascimento.ano=troca.dataNascimento.ano;
                listaDeAlunos[menor].dataNascimento.dia=troca.dataNascimento.dia;
                listaDeAlunos[menor].dataNascimento.mes=troca.dataNascimento.mes;
                listaDeAlunos[menor].matricula=troca.matricula;
                strcpy(listaDeAlunos[menor].nome,troca.nome);
                listaDeAlunos[menor].sexo=troca.sexo;
        }
    }
    //impressao
    for(i=0;i<numeroDeAlunosCadastrados;i++)
        printf("/n%i - %i/%i/%i - %s (%i)",i+1,
               listaDeAlunos[i].dataNascimento.dia,
               listaDeAlunos[i].dataNascimento.mes,
               listaDeAlunos[i].dataNascimento.ano,
               listaDeAlunos[i].nome,
               listaDeAlunos[i].matricula);
}

void ListarProfessoresNascimento(int numeroDeProfessoresCadastrados,Professor *listaDeProfessores){
//Lista professores por ordem de nascimento 
    int menor,i,j,k;
    Professor troca;

    //selectionSort
    for(i=0;i<numeroDeProfessoresCadastrados-1;i++){
        menor=i;
        for (j=i+1;j<numeroDeProfessoresCadastrados;j++){
            if(listaDeProfessores[j].dataNascimento.ano<listaDeProfessores[menor].dataNascimento.ano)
                menor=j;
            else if ((listaDeProfessores[j].dataNascimento.ano==listaDeProfessores[menor].dataNascimento.ano) && (listaDeProfessores[j].dataNascimento.mes<listaDeProfessores[menor].dataNascimento.mes))
                menor=j;
            else if ((listaDeProfessores[j].dataNascimento.ano==listaDeProfessores[menor].dataNascimento.ano)
                     && (listaDeProfessores[j].dataNascimento.mes==listaDeProfessores[menor].dataNascimento.mes)
                     &&(listaDeProfessores[j].dataNascimento.dia<listaDeProfessores[menor].dataNascimento.dia))
                menor=j;
        }
        if (menor!=i){
           for(k=0;k<12;k++)
                troca.cpf[k]=listaDeProfessores[i].cpf[k];
                troca.dataNascimento.ano=listaDeProfessores[i].dataNascimento.ano;
                troca.dataNascimento.dia=listaDeProfessores[i].dataNascimento.dia;
                troca.dataNascimento.mes=listaDeProfessores[i].dataNascimento.mes;
                troca.matricula=listaDeProfessores[i].matricula;
                strcpy(troca.nome,listaDeProfessores[i].nome);
                troca.sexo=listaDeProfessores[i].sexo;

            for(k=0;k<12;k++)
                listaDeProfessores[i].cpf[k]=listaDeProfessores[menor].cpf[k];
                listaDeProfessores[i].dataNascimento.ano=listaDeProfessores[menor].dataNascimento.ano;
                listaDeProfessores[i].dataNascimento.dia=listaDeProfessores[menor].dataNascimento.dia;
                listaDeProfessores[i].dataNascimento.mes=listaDeProfessores[menor].dataNascimento.mes;
                listaDeProfessores[i].matricula=listaDeProfessores[menor].matricula;
                strcpy(listaDeProfessores[i].nome,listaDeProfessores[menor].nome);
                listaDeProfessores[i].sexo=listaDeProfessores[menor].sexo;

            for(k=0;k<12;k++)
                listaDeProfessores[menor].cpf[k]=troca.cpf[k];
                listaDeProfessores[menor].dataNascimento.ano=troca.dataNascimento.ano;
                listaDeProfessores[menor].dataNascimento.dia=troca.dataNascimento.dia;
                listaDeProfessores[menor].dataNascimento.mes=troca.dataNascimento.mes;
                listaDeProfessores[menor].matricula=troca.matricula;
                strcpy(listaDeProfessores[menor].nome,troca.nome);
                listaDeProfessores[menor].sexo=troca.sexo;
        }
    }
    //impressao
    for(i=0;i<numeroDeProfessoresCadastrados;i++)
        printf("/n%i - %i/%i/%i - %s (%i)",i+1,
               listaDeProfessores[i].dataNascimento.dia,
               listaDeProfessores[i].dataNascimento.mes,
               listaDeProfessores[i].dataNascimento.ano,
               listaDeProfessores[i].nome,
               listaDeProfessores[i].matricula);

}

void ListarAlunosOrdemAlfabetica(int numeroDeAlunosCadastrados, Aluno *listaDeAlunos){
//Ordena o array de alunos por ordem alfabética e lista
    int i, j, k, pos;
    Aluno troca, menor, trocadentro;

    for(i=0;i<numeroDeAlunosCadastrados-1;i++){
        menor = listaDeAlunos[i];
        for(k=i+1;k<numeroDeAlunosCadastrados;k++){
            for(j=0;j<10;j++){
                if(listaDeAlunos[k].nome[j] < menor.nome[j]){
                    menor = listaDeAlunos[k];
                    pos = k;
                    trocadentro = listaDeAlunos[i];
                    listaDeAlunos[i] = menor;
                    listaDeAlunos[k] = trocadentro;
                    break;
                }else if(strcmp(menor.nome, listaDeAlunos[k].nome)==1){
                    break;
                }else{
                    break;
                }
            }
        }
        //listaDeAlunos[pos] = trocadentro;
    }

    for(i=0;i<numeroDeAlunosCadastrados;i++){
        printf("\n%s\t%d\n", listaDeAlunos[i].nome, listaDeAlunos[i].matricula);
    }
}

void ListarProfessoresOrdemAlfabetica(int numeroDeProfessoresCadastrados, Professor *listaDeProfessores){
//Organiza o array de professores e coloca em ordem alfabética
 int i, j, k, pos;
    Professor troca, menor, trocadentro;

    for(i=0;i<numeroDeProfessoresCadastrados-1;i++){
        menor = listaDeProfessores[i];
        for(k=i+1;k<numeroDeProfessoresCadastrados;k++){
            for(j=0;j<10;j++){
                if(listaDeProfessores[k].nome[j] < menor.nome[j]){
                    menor = listaDeProfessores[k];
                    pos = k;
                    trocadentro = listaDeProfessores[i];
                    listaDeProfessores[i] = menor;
                    listaDeProfessores[k] = trocadentro;
                    break;
                }else if(strcmp(menor.nome, listaDeProfessores[k].nome)==1){
                    break;
                }else{
                    break;
                }
            }
        }
        //listaDeProfessores[pos] = trocadentro;
    }

    for(i=0;i<numeroDeProfessoresCadastrados;i++){
        printf("\n%s\t%d\n", listaDeProfessores[i].nome, listaDeProfessores[i].matricula);
    }
}

void ListarAniversariantesdoMes(int numeroDeAlunosCadastrados, Aluno *listaDeAlunos, int numeroDeProfessoresCadastrados, Professor *listaProfessores){
//Lista os aniversariantes a partir de busca do  mês atual do computador e uma busca na lista de alunos e professores
    int mes, i;
    time_t segundos; //time_t é um tipo usado para representar o tempo do calendário
    time(&segundos); //time é uma função do include time.h
    data_atual = localtime(&segundos);
    //a nível de curiosidade -> é um operador em c que permite acessar alguns membros da struct tm 
    mes = data_atual->tm_mon+1;
    
    printf("Aniversariantes do mes\n");
    printf("Alunos:\n");
    for(i=0;i<numeroDeAlunosCadastrados;i++)
        if(mes == listaDeAlunos[i].dataNascimento.mes)
            printf("%s %d\n",listaDeAlunos[i].nome, listaDeAlunos[i].matricula);
    
    printf("\nProfessores:\n");
    for(i=0;i<numeroDeProfessoresCadastrados;i++)
        if(mes == listaProfessores[i].dataNascimento.mes)
            printf("%s %d\n",listaProfessores[i].nome, listaProfessores[i].matricula);
}

void ListarPessoasAPartirdeString(int numeroDeAlunosCadastrados, Aluno *listaDeAlunos, int numeroDeProfessoresCadastrados, Professor *listaProfessores){
//busca pessoas a partir de uma string inserida pelo usuário
    int sl, cont=0, i, k, j; //sl > para pegar o tamanho da string que vem do usuário
    char busca[50];

    getchar();
    printf("Informe no minimo 3 letras para buscar a pessoa: ");
    fflush(stdin);
    fgets(busca, 50, stdin);

    sl = strlen(busca)-1;

    if(sl>=3){
        for(i=0; i<numeroDeAlunosCadastrados;i++){
            for(k=0;k<sl-1;k++){
                for(j=0;j<50;j++){
                    if(busca[k] == listaDeAlunos[i].nome[j]){
                        if(busca[k+1]==listaDeAlunos[i].nome[j+1] && busca[k+2] == listaDeAlunos[i].nome[j+2]){    
                            cont=3;
                            break;
                        }
                    }
                }
                if(cont==3) break;
            }
            if(cont == 3){
                printf("%s\n",listaDeAlunos[i].nome);
            }
            cont=0;
        }

        for(i=0;i<numeroDeProfessoresCadastrados;i++){
            for(k=0;k<sl-1;k++){
                for(j=0;j<50;j++){
                    if(busca[k] == listaProfessores[i].nome[j]){
                        if(busca[k+1]==listaProfessores[i].nome[j+1] && busca[k+2] == listaProfessores[i].nome[j+2]){    
                            cont=3;
                            break;
                        }
                    }
                }
                if(cont==3) break;
            }
            if(cont == 3){
                printf("%s\n",listaProfessores[i].nome);
            }
            cont=0;
        }
    }
}