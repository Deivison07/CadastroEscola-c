typedef struct amd{
    int ano;
    int mes;
    int dia;
} Data;

typedef struct cadastroAluno{ 
    char nome[50];
    int matricula;
    char sexo;
    char cpf[12];
    Data dataNascimento;
} Aluno;

typedef struct cadastroProfessor{
    char nome[50];
    int matricula;
    char sexo;
    char cpf[12];
    Data dataNascimento;
} Professor;

typedef struct disciplina{
    char nome[50];
    int codigo;
    int semestre;
    int alunosDaMateria;
    Professor docente;
    Aluno discentes[60];
} Disciplina;


