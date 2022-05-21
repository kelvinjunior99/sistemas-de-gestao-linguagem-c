#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define MAX_ALUNOS 100
#define MAX_NOTAS 100

typedef struct{
	char nome[40];	
	int classe;
    char curso[20];
	 
	 int ativo;
	}Aluno;
 Aluno alunos[MAX_ALUNOS];
 
 typedef struct{
 	 char nome[40];
	 float nota[3];
	 int ativo;
 }Nota;
 Nota notas[MAX_NOTAS];
 
 void menu();

 void lista_aluno();
 void lista_nota();
 
 void adicionar_aluno();
 void adicionar_nota();
 
 void remover_aluno();
 void remover_nota();
 
 void pesquisar();
 void reprovados();
 void aprovados();
 void quadro_honra();
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
	printf("\n      ---------------------------------MENU------------------------------");
	printf("\n \n      1-ADICIONAR ALUNO        2-CADASTRAR NOTA      3- ALUNOS APROVADOS       ");
	printf(" \n \n      4-LISTA DE ALUNOS        5-PESQUISAR ALUNO     6-EXCLUIR NOTA    7-EXCLUIR ALUNO ");
	printf("\n \n      8-ALUNOS REPROVADO       9-LISTA DE NOTA        10-SOBRE       0-SAIR ");
	printf("\t       \n\n      : ");
	scanf("%d", &op);
	getchar();
	switch(op){
		
		case 1: 
		  adicionar_aluno();
		 break;
		
		case 2: 
		 adicionar_nota();
		 break;
		
 	 	 case 3:
		 aprovados();
		 break;
	 	  
	 	 case 4:
	 	 	lista_aluno();
	 	 	break;
 	 	 
 	 	 case 5:
	 	 	pesquisar();
	 	 	break;
	 	 
	  	  case 6: 
	 	 	remover_nota();
	 	 	break;
	 	 
	 	 case 7: 
	 	 	remover_aluno();
	 	 	break;
	 	 
		case 8: 
	 	 	reprovados();
	 	 	break;	
	 	 
	 	 case 9: 
	 	 	lista_nota();
	 	 	break;
		  case 10:
		  	sobre();
			  break;	
	  }
		
		getchar();
}while(op!=0);

}
 void lista_aluno(){
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
			printf("\nNome:  %s"  ,alunos[i].nome);
			printf("\nClasse: %d  ",alunos[i].classe);
			printf("\nCurso: %s  ",alunos[i].curso);
			
			printf("\n____________________");	
		}
			
	}
		getchar();
}
 void adicionar_aluno(){
	system("cls");
	char url[]="Lista.txt";
	char nome[40];
	int classe;
	char curso[20];

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
		fprintf(arq,"\n_____________________");
		fprintf(arq,"\nNome: %s ", nome);
		
		fflush(stdin);
		printf("\n Digite a classe: ");
		scanf("%d", &classe);
		fprintf(arq,"\nClasse: %d", classe);
		

		fflush(stdin);
		printf("\n Digite curso: ");
		fgets(curso,sizeof(curso),stdin);
		fprintf(arq,"\nCurso: %s", curso);
		

		for(int i=0; i<MAX_ALUNOS; ++i)
		{
			if(alunos[i].ativo==0)
			{
				
				 strcpy(alunos[i].nome, nome);
				 alunos[i].classe = classe;	
				
				strcpy(alunos[i].curso, curso);  
				//alunos[i].curso;
				//alunos[i].turno;
			   
				alunos[i].ativo=1;
				break;
			}
		}
		printf("\n1 - Continuar \n 0 - Sair \n: ");
		scanf("%d", &op);	
	}while(op!=0);
		}
}

 void remover_aluno(){
 	int matricula;
 	lista_aluno();
 	printf("\n Digite a matricula do aluno a ser removido: ");
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
			printf("\nCurso: %s  ",alunos[i].curso);
			
			printf("\n___________________________");
			}
				
		}
		printf("\n Digite 0 para sair \n 1 para continuar ");
		scanf("%d", &op);
		getchar();		 
	 }while(op!=0);
}
void lista_nota(){
	system("cls");
	float media;
		setlocale(LC_ALL,"Portuguese");
		printf("\n_________________");
		printf("\n LISTA DE NOTAS ");
		printf("\n-----------------");
			
		for(int i=0; i<MAX_NOTAS; ++i)
		{
			if(notas[i].ativo==1)
			{	
			printf("\n\n Id: %d", i+1);	
			printf("\n Nome:  %s"  ,notas[i].nome);
			printf("\n Nota 1: %0.1f",notas[i].nota[0]);
		    printf("\n Nota 2: %0.1f",notas[i].nota[1]);
			printf("\n Nota 3: %0.1f",notas[i].nota[2]);
			printf("\n Media: %0.1f  ",media);
			
			printf("\n____________________");	
		}
			
	}
		getchar();
}
void adicionar_nota(){
	system("cls");
	
	setlocale(LC_ALL,"PORTUGUESSE");
	char url[]="Notas.txt";
 	char nome[40];
 	float nota[3];
 	float media;
 	int op;
 	
 	FILE*arq;
	arq = fopen(url, "a+");
	if(arq == NULL){
		printf("\n Erro ao abrir arquivo");
	}
	else {
 	do{
 		system("cls");
 		printf("\n_________________");
		printf("\n ADICIONAR NOTA ");
		printf("\n-----------------");
 		printf("\n Digite nome do aluno para pesquisar: ");
	    fgets(nome,sizeof(nome),stdin);
	    
	    fprintf(arq,"\nNOTAS DOS ALUNO   ");
		fprintf(arq,"\nNome: %s ", nome);
		
		for(int i=0; i<MAX_ALUNOS; ++i)
		{
			if(strstr(alunos[i].nome,nome)!=NULL)
			{

            printf("\n Matricula: %d", i+1);	
 		    printf("\n Nome:  %s"  ,alunos[i].nome);
			printf("\n Classe: %d  ",alunos[i].classe);
			printf("\n Curso: %s  ",alunos[i].curso);
			printf("\n_______________________________");
			
			printf("\n Nota 1: ");
			scanf("%f", &nota[0]);
			fprintf(arq,"\nNota 1: %0.1f ",nota[0]);
			fflush(stdin);
			if(nota[0] >=21 || nota[0] <= 0){
				MessageBox(NULL,"Nota digitado é maior que 20 ou menor que 0 \n Erro ao cadastrar Nota,"," mensagem de alerta ", 0);
				printf("\n Erro ");
				break;
			}
			
            printf("\n Nota 2: ");
			scanf("%f", &nota[1]);
			fprintf(arq,"\nNota 2: %0.1f ",nota[1]);
			fflush(stdin);
			if(nota[1] >=21 || nota[1] <= 0){
				MessageBox(NULL,"Nota digitado é maior que 20 ou menor que 0 \n Erro ao cadastrar Nota,"," mensagem de alerta ", 0);
				printf("\n Erro ");
				break;
			}
			
            printf("\n Nota 3: ");
			scanf("%f", &nota[2]);
			fprintf(arq,"\nNota 3: %0.1f ",nota[2]);
			fflush(stdin);
			if(nota[2] >=21 || nota[2] <= 0){
				MessageBox(NULL,"Nota digitado é maior que 20 ou menor que 0 \n Erro ao cadastrar Nota,"," mensagem de alerta ", 0);
				printf("\n Erro ");
				break;
			}

			media = 0;
			media = nota[0] + nota[1] + nota[2];
			media = media / 3;  
			if(media>=10.0){
				printf("\n Aprovado MEDIA %0.lf", media);
				fprintf(arq,"\nAprovado MEDIA %0.lf", media);
				fprintf(arq,"\n____________________");
			}
			else {
				printf("\n Reprovado MEDIA %0.lf", media);
				fprintf(arq,"\nReprovado MEDIA %0.lf", media);
				fprintf(arq,"\n_____________________");
			}
			
			for(int i=0; i<MAX_NOTAS; ++i)
   		   	{
			if(notas[i].ativo==0)
			{
				
                strcpy(notas[i].nome, nome);  
				//alunos[i].curso;
				//calunos[i].turno;
				notas[i].nota[0] = nota[0];
				notas[i].nota[1] = nota[1];
				notas[i].nota[2] = nota[2];
				notas[i].ativo=1;
				break;
			}
			}
			}
				
		}
		printf("\n\n Digite 0 para sair \n 1 para continuar  \n: ");
		scanf("%d", &op);
		getchar();		 
	 }while(op!=0);
	 
	 	
	 }

}

void remover_nota(){
	int matricula;
 	lista_nota();
 	printf("\n Digite numero de Nota para removido: ");
	 scanf("%d", &matricula);
	 --matricula;
	 notas[matricula].ativo=0;
	 printf("\n Nota foi excluido com sucesso ");
		getchar();
}

void aprovados(){
	
	system("cls");
 	   float media;
		setlocale(LC_ALL,"Portuguese");
		printf("\n_________________");
		printf("\n LISTA DE ALUNOS APROVADOS ");
		printf("\n-----------------");
		for(int i=0; i<MAX_NOTAS; ++i)
		{
			if(notas[i].ativo==1)
			{
			
            media = (notas[i].nota[0] + notas[i].nota[1] + notas[i].nota[2])/3;
			
			if(media >= 10.0){
			printf("\n Id: %d", i+1);	
			printf("\n Nome:  %s"  ,notas[i].nome);
			printf("\n Nota 1: %0.1f",notas[i].nota[0]);
		    printf("\n Nota 2: %0.1f",notas[i].nota[1]);
			printf("\n Nota 3: %0.1f",notas[i].nota[2]);
			system("color f1");
			printf("\n Media: %0.1f  ",media);	
			printf("\n______________________");
			}				
		}
			
	}
		getchar();
}

void reprovados(){
	
	system("cls");
	    float media;
		setlocale(LC_ALL,"Portuguese");
		printf("\n_________________");
		printf("\n LISTA DE ALUNOS REPROVADO ");
		printf("\n-----------------");
		for(int i=0; i<MAX_NOTAS; ++i)
		{
			if(notas[i].ativo==1)
			{
				
			media = (notas[i].nota[0] + notas[i].nota[1] + notas[i].nota[2])/3;
			
			if(media <=10){
			printf("\n Id: %d", i+1);	
			printf("\n Nome:  %s"  ,notas[i].nome);
			printf("\n Nota 1: %0.1f",notas[i].nota[0]);
		    printf("\n Nota 2: %0.1f",notas[i].nota[1]);
			printf("\n Nota 3: %0.1f",notas[i].nota[2]);
			system("color f4");
			printf("\n Media: %0.1f  ",media);	
			printf("\n______________________");
			}				
		}
			
	}
		getchar();
}

void sobre(){
	system("cls");
	setlocale(LC_ALL,"Portuguese");
	system("color f3");
	printf("\n________________________________________________________________________________");
	 printf("\n \t                           SOBRE ");
	 printf("\n________________________________________________________________________________");
	 printf("\n \n \n Versao: 2.0  \n Programador: Kelvin Junior(KatNick)");
	 
	 printf("\n \n \n COMENTARIO DO PROGRAMADOR: ");
	 printf("\n Depois de ficar anos sem mexer com a linguagem C,");
	 printf("\n lembrei que precisava alterar ou criar uma nova versão para o SG escolar ");
	 printf("\n adicionando novas funções, talvez essa versão seja melhor que a primeira. ");
	 printf("\n Desta vez agredeço a Deus Todo Poderoso.");
	 
	 printf("\n \n \n CONTACTO: ");
     printf("\n Email: kelvinjunior592@gmail.com");
     printf("\n WhatsApp: 949772030");
	 printf("\n Linkedin: www.linkedin.com/in/kelvinjunior-9bb7501b9");
	 printf("\n GitHub:  https://github.com/kelvinjunior99/");
	 	 
	 printf("\n\n Ano: 2022");
	 
	 	 	
	getchar();
}
