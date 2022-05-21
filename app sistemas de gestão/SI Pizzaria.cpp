#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FUNCIO 60
#define MAX_CLIENTE 60
#define MAX_PRODUTO 60
#define MAX_RELATORIO 60
typedef struct{
	char nome[50];	
	char morada[20];
	int tel;  
	char cargo[10];
	 int ativo;
	}Funcionario;
	Funcionario funcios[MAX_FUNCIO];
	
typedef struct{
	char nome[50];	
	char morada[20];
	int tel;  
	int ativo;
	}Cliente;
	Cliente clientes[MAX_CLIENTE];
	
typedef struct{
	char nome[50];
	int preco;	
	int quant; 
	 int ativo;
	}Produto;
	Produto produtos[MAX_PRODUTO];
	
typedef struct {
	char nomeCli[20];
	char moradaCli[20];
	int qua;
	int valor;
	}Relatorio;
	Relatorio relato[MAX_RELATORIO];

	
 void menu();
 void listaF();
 void listaP();
 void addFUN();
 void addCLI();
 void addPRO();
 void removerF();
 void removerP();
 void pagar();
 
	 
int main()
{
	menu();	
	return 0;
}

void menu(){
	int senha;
	system("color a0");
		
	printf("\n Digite senha [FUNCIONARIO | ADMINISTRADOR] \n: ");
	scanf("%d", &senha);
	
	getchar();
	if(senha==1234){
	 
	int op;
	do{
		system("cls");
		system("color f9");
	printf("[administrador]");
	printf("\n      -------------------------------MENU--------------------------------");	
	printf("\n\n   1-ADICIONAR FUNCIONARIO    2-ADICIONAR PRODUTO    3-LISTA DE FUNCIONARIO");
	printf("\n    \n            4-LISTA DE PRODUTO     6-ELIMINAR FUNCIONARIO        0-LOGIN  ");
	printf("\n \n                     7-ELIMINAR PRODUTO           8-SAIR ");
	printf("\n : ");
	scanf("%d", &op);
	getchar();
	switch(op){
		
		case 1:
			addFUN();
			break; 

		case 2:
			addPRO();
			break;
		
		case 3: 
			listaF();
			break;
		
		case 4: 
			listaP();
			break;
		
		case 6:
			removerF();
			break;
		
		case 7:
			removerP();
			break;
		case 8:
			exit(1);	
			break;	
	}
	
	getchar();
   }while(op!=0);{
       system("cls");
	   menu();
   }	
}
 
   if(senha==9876){
   	system("cls");
   	system("color f9");
   		int op;
        
           do{
           	
           	for(int i=0; i<MAX_FUNCIO; ++i){
		
			if(funcios[i].ativo==1)
			{
				
         printf("\n Nome:  %s ",funcios[i].nome);	
		}
}
system("cls");
	   printf("\n \n              ---------------------MENU------------------------- ");
	   printf("\n \n            1-LISTA DE PRODUTO     2-FATURA    3-SAIR    0-Login ");
	   printf("\n    \n         : ");
	   scanf("%d", &op);
	   switch(op){
		   
		   case 1:
		   	listaP();
		   	break;
		   
	   	   case 2:
		   	pagar();
		   	break;
		   
		   case 3:
		   	exit(1);
		   	break;		   
		   
      }
		getchar();	  
 	 }while(op!=0);{
 	 	system("cls");
		  menu();
	  }
}
 
 	 else{
	 system("cls");	 
	 printf("\n Senha invalida ");
	 menu();
	}
				
}		

void pagar(){
	//arquivo
	
	
	int op;
	char nome[20];
	int ativo;
	//dados cliente
	char nomeCli[20];
	char moradaCli[20];
	int qua;
	int valor, s;
	
	char url[]="Relatorio.txt";
      FILE*arq;
	arq = fopen(url, "a");
	if(arq == NULL){
		printf("\n Erro ao abrir arquivo");
	} else {
		
				do{
			getchar();
			system("cls");
			printf("\n-------------FATURA----------------");
           printf("\n Produto: ");
	    fgets(nome,sizeof(nome),stdin);
		for(int i=0; i<MAX_PRODUTO; ++i)
		{
			if(strstr(produtos[i].nome,nome)!=NULL)
			{
			   	
            printf("\n id: %d ", i+1);
			
				
    		printf("\n Produto: %s ",produtos[i].nome);
    		
    		
    		printf("\n Preco: %d ",produtos[i].preco);
    		
			
				fflush(stdin);
				printf("\n Cliente: ");
				fgets(nomeCli,sizeof(nomeCli),stdin);
				
				
				fflush(stdin);
				printf("\n Morada: ");
				fgets(moradaCli,sizeof(moradaCli),stdin);
				
				
				fflush(stdin);			
				printf("\n Quantidade: ");
				scanf("%d", &qua);
				
				
				
				fflush(stdin);
				printf("\n Dinheiro Pago(real):  ");
				scanf("%d", &valor);
				
				
				s = (produtos[i].preco * qua);
				
				// Relatorio
				system("cls");
				
fprintf(arq," \n --------RELATORIO DA FATURA--------   \n");
				
				fprintf(arq,"\n Numero do produto: %d ", i+1);
				
				printf("\n Cliente: %s ", nomeCli);
				fprintf(arq,"\n Cliente: %s ", nomeCli);
				
				printf("\n Morada: %s ", moradaCli);
				fprintf(arq,"\n Morada: %s ", moradaCli);
				
				
				printf("\n Comprou: %s", nome);
				fprintf(arq,"\n Comprou: %s",nome);
				
				fprintf(arq,"\n Preco do Produto: %d ",produtos[i].preco);
				
				printf("\n Quant: %d ",qua);
				fprintf(arq,"\n Quant: %d ",qua);
				
				printf("\n Total: %d",s);
				fprintf(arq,"\n Total: %d ",s);
				
				printf("\n Valor pago: %d real", valor);
				fprintf(arq,"\n Dinheiro pago: %d real",valor);
				
      fprintf(arq,"\n ______________________________________ \n ");
							
			break;
			
	 }
					
		}
		getchar();
		printf("\n \nDesejas continuar [0-Sair | 1-Cont ] \n: ");
		scanf("%d", &op);
	
		
		
		
	}while(op!=0);{
		system("cls");
        	}
     }
		
   }

void addFUN(){
	system("cls");
	char nome[50];	
	char morada[20];
	int tel; 
	char cargo[10];
	 int ativo;
	 int op;
	 
	 do{
	 printf("\n---------------ADICIONAR FUNCIONARIO-----------------");

	 	 fflush(stdin);
		printf("\n Digite nome: ");
		fgets(nome,sizeof(nome),stdin);
		
		fflush(stdin);
		printf("\n Digite morada: ");
		fgets(morada,sizeof(morada),stdin);
		
		 fflush(stdin);
		printf("\n Digite NumeroTEl: ");
		scanf("%d", &tel);
		
		fflush(stdin);
		printf("\n Cargo: ");
		fgets(cargo,sizeof(cargo),stdin);
		
		 
		 	for(int i=0; i<MAX_FUNCIO; ++i)
		{
			if(funcios[i].ativo==0)
			{
				
				 strcpy(funcios[i].nome,nome);
                 strcpy(funcios[i].morada,morada); 
				 funcios[i].tel = tel;
				 strcpy(funcios[i].cargo,cargo);
				
				funcios[i].ativo=1;
				break;
			}
		}
		getchar();
		printf("\n Desejas continuar [0-Sair | 1-Cont ] \n: ");
		scanf("%d", &op);
	}while(op!=0);{
		system("cls");
	}
}

void addPRO(){
	system("cls");
	   char nome[50];
	   int preco;	
	   int quant; 
	 int ativo;
	 int op;
	 
	 do{
	 printf("\n---------------ADICIONAR PRODUTO-----------------");

	 	fflush(stdin);
		printf("\n Digite nome: ");
		fgets(nome,sizeof(nome),stdin);
		
		fflush(stdin);
		printf("\n Preço: ");
		scanf("%d", &preco);
		
		printf("\n Quantidade: ");
		scanf("%d", &quant);
		 
		 	for(int i=0; i<MAX_PRODUTO; ++i)
	      	{
			if(produtos[i].ativo==0)
			{
				
				 strcpy(produtos[i].nome,nome);
				 produtos[i].preco = preco;
                 produtos[i].quant = quant;
				
				produtos[i].ativo=1;
				break;
			}
		}
		
			
	  printf("\n Desejas continuar: [0-Sair | 1-Cont] \n: ");
	  scanf("%d", &op);
	  getchar();
	  system("cls");
	}while(op!=0);
}

void listaF(){
		system("cls");
		printf("\n_______________________");
		printf("\n LISTA DE FUNCIONARIO ");
		printf("\n-----------------------");
		for(int i=0; i<MAX_FUNCIO; ++i)
		{
			if(funcios[i].ativo==1)
			{
			
			printf("\n id: %d", i+1);	
			printf("\n Nome:  %s ",funcios[i].nome);
			printf("\n Morada: %s ",funcios[i].morada);
			printf("\n Tel:  %1d ",funcios[i].tel);
			printf("\n Cargo:  %s ",funcios[i].cargo);
			printf("\n________________________________________ ");
			printf("");	
		}
			
	}
		getchar();
}
void listaP(){
		system("cls");
		printf("\n__________________");
		printf("\n LISTA DE PRODUTO ");
		printf("\n------------------");
		for(int i=0; i<MAX_PRODUTO; ++i)
		{
			if(produtos[i].ativo==1)
			{
			
			printf("\n id: %d", i+1);	
			printf("\n Nome:  %s ",produtos[i].nome);
			printf("\n Preço: %1d",produtos[i].preco);
			printf("\n Quantidade: %d ",produtos[i].quant);
			
			printf("\n________________________________________ ");	
		}
			
	}
		getchar();
}
 void removerF(){
 	int id;
 	int op;
 	do{
    listaF();
 	printf("\n Digite id do Funcionario a ser removido: ");
	 scanf("%d", &id);
	 --id;
	 funcios[id].ativo=0;
	 printf("\n Funcionario foi excluido com sucesso ");
		getchar();	
       printf("\n Desejas continuar [0-Sair | 1-Cont] \n : ");
	   scanf("%d", &op); 
	 }while(op!=0);
 getchar();
}

 void removerP(){
 	int id;
 	int op;
 	do{
    listaP();
 	printf("\n Digite id do Produto a ser removido: ");
	 scanf("%d", &id);
	 --id;
	 produtos[id].ativo=0;
	 printf("\n Produto foi excluido com sucesso ");
		getchar();	
       printf("\n Desejas continuar [0-Sair | 1-Cont] \n : ");
	   scanf("%d", &op); 
	 }while(op!=0);
 getchar();
}
