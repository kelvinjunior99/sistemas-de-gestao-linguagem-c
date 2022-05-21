#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define MAX_ALUNOS 50

void date(){
	time_t rawtime;
	struct tm *timeinfo;
	
	time(&rawtime);
	timeinfo = localtime (&rawtime);
	
	printf("hora e data: %s \n", asctime(timeinfo));
}
typedef struct{
	char nome[50];	
	int classe;
	int sala;
    char curso[20];
    char turno[20];
    int data[3];
	 
	 int ativo;
	}Aluno;
 Aluno alunos[MAX_ALUNOS];
 void menu();
 void pagar();
 void lista();
 void adicionar();
 void remover();
 void pesquisar();
 void sobre();
 int main()
 {
 	
		menu();
		return 0;			
}

void menu(){
	
	int op;
	do{	
	  system("cls");
	  system("title Sistema de Gestão Escolar");
	  setlocale(LC_ALL,"Portuguese");
	  system("color f1");
	printf("\n         -----------------------------------------------------------------");
	printf("\n	|                 MULTI-APRENDIZAGEM COLÉMA                       |");
	printf("\n        |                                                                 |");
	printf("\n	|_________________________________________________________________|");
	printf("\n	| 1-FAZER PAGAMENTO       2-LISTA        3-ADICIONAR ALUNO        |");
	printf("\n 	|                                                                 |    ");
	printf("\n        |                                                                 |");
	printf("             | 4-REMOVER ALUNO    5-PESQUISAR ALUNO   6-SOBRE SISTEMA   0-SAIR |");
	printf("\n	|_________________________________________________________________|");
	printf("\t       \n        : ");
	scanf("%d", &op);
	getchar();
	switch(op){
		
		case 1: 
		 pagar();
		 break;
		
		case 2: 
		 lista();
		 break;
		
 	 	 case 3:
		 adicionar();
		 break;
	 	  
	 	 case 4:
	 	 	remover();
	 	 	break;
 	 	 
 	 	 case 5:
	 	 	pesquisar();
	 	 	break;
	 	 
	  	  case 6: 
	 	 	sobre();
	 	 	break;
		}
		
		getchar();
}while(op!=0);

}
 void lista(){
		system("cls");
		setlocale(LC_ALL,"Portuguese");
		printf("\n_________________");
		printf("\n LISTA DE ALUNOS ");
		printf("\n-----------------");
		for(int i=0; i<MAX_ALUNOS; ++i)
		{
			if(alunos[i].ativo==1)
			{
			
			printf("\nMatricula: %d", i+1);	
			printf("\n\nNome:  %s"  ,alunos[i].nome);
			printf("\nClasse: %d  ",alunos[i].classe);
			printf("\nSala:  %d   ",alunos[i].sala);
			printf("\nCurso: %s  ",alunos[i].curso);
			printf("\nTurno: %s",alunos[i].turno);
		    printf("\nDia:  %d   ",alunos[i].data[0]);
			printf("\nMês:   %d   ",alunos[i].data[1]);
			printf("\nAno:  %d  "   ,alunos[i].data[2]);
			
			printf("\n________________________________________");	
		}
			
	}
		getchar();
}
 void adicionar(){
	system("cls");
	char url[]="Lista.txt";
	char nome[50];
	int classe;
    int sala;
	char curso[20];
	char turno[20];
	int data[3];
	 int op;
	 FILE*arq;
	arq = fopen(url, "a+");
	if(arq == NULL){
		printf("\n Erro ao abrir arquivo");
	}
	else {
		
	
	 do{
	 	printf("\n_________________");
		printf("\n ADICIONAR ALUNO ");
		printf("\n-----------------");
		
	 	fflush(stdin);
		printf("\n Digite nome: ");
		fgets(nome,sizeof(nome),stdin);
		fprintf(arq,"DADOS DO ALUNO   ");
		fprintf(arq,"\n________________________  ");
		fprintf(arq,"\nNome: %s ", nome);
		
		fflush(stdin);
		printf("\n Digite a classe: ");
		scanf("%d", &classe);
		fprintf(arq,"\nClasse: %d", classe);
		
		fflush(stdin);
		printf("\n Digite a sala: ");
		scanf("%d", &sala);
		fprintf(arq,"\nSala: %d", sala);
		
		fflush(stdin);
		printf("\n Digite curso: ");
		//scanf("%s", &curso);
		 //gets(curso);
		fgets(curso,sizeof(curso),stdin);
		fprintf(arq,"\nCurso: %s", curso);
		
		printf("\n Turno: ");
		fgets(turno,sizeof(turno),stdin);
		fprintf(arq,"Turno: %s\n", turno);
		
           fflush(stdin);
		  printf("\nDia:  ");
		  scanf("%d", &data[0]);
		  
		  fflush(stdin);
		  printf("\nMês: ");
		  scanf("%d", &data[1]);
		  
		  fflush(stdin);
		  printf("\nAno: ");
     	  scanf("%d", &data[2]);
     	  fflush(stdin);

		for(int i=0; i<MAX_ALUNOS; ++i)
		{
			if(alunos[i].ativo==0)
			{
				
				 strcpy(alunos[i].nome, nome);
				 alunos[i].classe = classe;	
				
				alunos[i].sala = sala;
				strcpy(alunos[i].curso, curso); 
				 strcpy(alunos[i].turno, turno); 
				//alunos[i].curso;
				//alunos[i].turno;
				alunos[i].data[0] = data[0];
				alunos[i].data[1] = data[1];
				alunos[i].data[2] = data[2];
			   
				alunos[i].ativo=1;
				break;
			}
		}
		printf("\n1 - Continuar \n 0 - Sair \n: ");
		scanf("%d", &op);	
	}while(op!=0);
		}
}

 void remover(){
 	int matricula;
 	lista();
 	printf("\n Digite a numero de matricula do aluno a ser removido: ");
	 scanf("%d", &matricula);
	 --matricula;
	 alunos[matricula].ativo=0;
	 printf("\n Aluno foi excluido com sucesso ");
		getchar();
}

 void pesquisar(){
 	system("cls");
 	setlocale(LC_ALL,"Portuguesse");
 	char nome[50];
 	int op;
 	do{
 		system("cls");
 		printf("\n_________________");
		printf("\n PESQUISAR ALUNO ");
		printf("\n-----------------");
 		printf("\n Digite nome para pesquisar: ");
	    fgets(nome,sizeof(nome),stdin);
		for(int i=0; i<MAX_ALUNOS; ++i)
		{
			if(strstr(alunos[i].nome,nome)!=NULL)
			{
            printf("\nMatricula: %d", i+1);	
    		printf("\n\nNome:  %s"  ,alunos[i].nome);
			printf("\nClasse: %d  ",alunos[i].classe);
			printf("\nSala:  %d   ",alunos[i].sala);
			printf("\nCurso: %s  ",alunos[i].curso);
			printf("\nTurno: %s",alunos[i].turno);
		    printf("\nDia:  %d   ",alunos[i].data[0]);
			printf("\nMês:   %d   ",alunos[i].data[1]);
			printf("\nAno:  %d  "   ,alunos[i].data[2]);
			
			printf("\n____________________________________");
			}
		
		}
		printf("\n Digite 0 para sair \n 1 para continuar ");
		scanf("%d", &op);
		getchar();		 
	 }while(op!=0);
}
void pagar(){
	system("cls");
	setlocale(LC_ALL,"Portuguese");
  char nome[50];
  char mes[20];
  float quant;
  float din, soma;
 	int op;
 	do{
 		system("cls");
 		printf("\n_________________");
		printf("\n FAZER PAGAMENTO  ");
		printf("\n-----------------");
 		printf("\nDigite nome para pesquisar: ");
        fgets(nome,sizeof(nome),stdin);
 		fflush(stdin);
 		
        printf("\nValor:  ");
 		scanf("%f", &din);
 		fflush(stdin);
 		
 		printf("\nQuantidade de meses: ");
 		scanf("%f", &quant);
 		fflush(stdin);
 		
 		printf("\nMes a ser pago: ");
 		gets(mes);
 		fflush(stdin);
 		
 		soma = (din * quant);
	    
		for(int i=0; i<MAX_ALUNOS; ++i)
		{
			if(strstr(alunos[i].nome,nome)!=NULL)
			{
            //printf("\nMatricula: %d", i+1);	
			//printf("\n\nNome:  %s"  ,alunos[i].nome);
			//printf("\nClasse: %d  ",alunos[i].classe);
			//printf("\nSala:  %d   ",alunos[i].sala);
		    //printf("\nCurso: %s  ",alunos[i].curso);
			//printf("\nTurno: %s ",alunos[i].turno);
		    //printf("\nData:  %d   ",alunos[i].data[0]);
			//printf("\nMês:   %d   ",alunos[i].data[1]);
			//printf("\nAno:  %d  "   ,alunos[i].data[2]);
		    //printf("\n_________________________________");
		    
   		 
	system("cls");
	system("color b0"); 
	printf("\nCOMPLEXO ESCOLAR  MULTI-APRENDIZAGEM ");
	printf("\nENSINO PRIMARIO Iª E II CICLO E MEDIO ");
	printf("\n-------------------------------------------------------------------------------");
	printf("\n ___________________________________");
	printf("\n|RECIBO ORIGINAL> Nª do aluno: %d    |",i+1);
	printf("\n|___________________________________|"); 
	printf("\n ____________________________"); 
	printf("\n|Nome:%s                             | ",alunos[i].nome);printf(" Descricao");
	printf("\n|____________________________|");   printf("    Qtd:%1.f ",quant);
	printf("\n|Clase:%d                     |", alunos[i].classe); printf("    Mes:%s ",mes);
	printf("\n|____________________________|");	 printf("    Valor:%2.fkz ",din);
	printf("\n|Sala:%d                      |",alunos[i].sala);printf("    Total:%2.fkz",soma);
	printf("\n|____________________________|");printf("\n|Curso:%s",alunos[i].curso);
printf("|Turno:%s   ",alunos[i].turno);
  date();
  break;      	
			}
				
		}
		printf("\n Digite 0 para sair \n 1 para continuar ");
		scanf("%d", &op);
		getchar();		 
	 }while(op!=0);

	
}
void sobre(){
	system("cls");
	setlocale(LC_ALL,"Portuguese");
	system("color f3");
	setlocale(LC_ALL,"Portugues");
	printf("\n________________________________________________________________________________");
	 printf("\n \t                           SOBRE ");
	 printf("\n________________________________________________________________________________");
	 printf("\n \t   SI esta composto 6 op \n  \t   As primeiras opção faz parte de funcionamento");
     printf("do SI. \n \t   Os dados sao armazenados em formato de arquivo de texto.");
	 printf("\n \n \n Versao: 1.0  \n Programador: Kelvin Junior(KatNick)");
	 
	 printf("\n \n \n COMENTARIO DO PROGRAMADOR: ");
	 printf("\n Nao foi facil terminar este projeto, foi uma longa batalha");
	 printf("\n agredeco todos que me ajudaram durante este pequeno projeto");
	 printf("\n principalmento o meu professor que me fez conhecer esta ");
	 printf("\n bela linguagem, obrigado.");
	 
	 printf("\n \n \n CONTACTO: ");
     printf("\n Email: kelvinjunior592@gmail.com");
     printf("\n WhatsApp: 949772030");
	 printf("\n Linkedin: www.linkedin.com/in/kelvinjunior-9bb7501b9");
	 printf("\n GitHub:  https://github.com/kelvinjunior99/");
	 	 
	 printf("\n\n Ano: 2018-2019");
	 
	 	 	
	getchar();
}