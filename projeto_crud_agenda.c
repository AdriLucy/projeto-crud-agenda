#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
struct ficha{
	char nome[40];
	char telefone[15];
	char email[40];
	char endereco[100];
	char datanascimento[15];
};
void leia(char string[ ], int tam)
{
	fgets(string, tam, stdin);
	string[strlen(string)-1] = '\0';
};


int leiaNum()
{   
    char aux[100];
    fgets(aux, 100, stdin);
    return atoi(aux);
};
void Iniciar(void)
{
    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    printf("\n-- Cadastro de agenda de amigos --");
    printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    
};
int procurar(struct ficha agenda[], int num_fichas)
{
    char procurado[40];
    int acertou = 0;
    printf("\nEntre com o nome procurado:");
    leia(procurado,40);
	int i;
    for(i=0; i<num_fichas; i++)
	{
	   if(strstr(agenda[i].nome, procurado) != NULL)
		{
		    printf("\nA pessoa procurada é %s?\n0 - Não\n1 - Sim\n",agenda[i].nome);
            acertou = leiaNum();
		    if(acertou == 1) return i;
        }
    }
    
    return -1;
};
void mostrarDados(struct ficha agenda[],int i)
{
    printf("\nAbaixo, os dados de %s"
        "\nTelefone: %s"
        "\nEmail: %s"
        "\nEndereco: %s"
        "\nData de nascimento: %s\n"
        ,agenda[i].nome
        ,agenda[i].telefone
        ,agenda[i].email
        ,agenda[i].endereco
        ,agenda[i].datanascimento);
};


int main()
{
	Iniciar();
	
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0"; 
        setlocale(LC_ALL, "Portuguese");
	while(opcao[0] != '6')
	{
		printf("\nEntre com a opção desejada:\n");
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Alterar informações:");
		printf("\n5) Excluir por nome:");
		printf("\n6) Sair\n\n");
		leia(opcao,5);
		//fgets(opcao,5,stdin);
		if(opcao[0] == '1') //inserir
		{
			printf("\nEntre com um nome:");
			leia(agenda[proxima].nome,40);
			printf("Entre com um telefone:");
			leia(agenda[proxima].telefone,15);
			printf("Entre com um e-mail:");
			leia(agenda[proxima].email,40);
			printf("Entre com um endereco:");
			leia(agenda[proxima].endereco,100);
			printf("Entre com a data de nascimento:");
			leia(agenda[proxima].datanascimento,15);
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2') //procurar
		{
			int i;
			i = procurar(agenda,fichas_existentes);
			if(i>=0) mostrarDados(agenda,i); else printf("Pessoa não encontrada");
		}
		if(opcao[0] == '3') //listar tudo
		{
			printf("\n");
			int i;
			if(fichas_existentes == 0) printf("A base de dados está vazia!\n");
			for(i=0; i<fichas_existentes; i++)
			{
                mostrarDados(agenda,i);
			}
		}
		if(opcao[0] == '4') //alterar	
		{
		    int i;
			char alterar[10]="0";
			char dadoAlterado[100];
				printf("\nEntre com a opção que deseja alterar: \n");
        		printf("\n1) Telefone:");
        		printf("\n2) E-mail:");
        		printf("\n3) Endereco:");
        		printf("\n4) Data de nascimento:");
        		printf("\n5) Sair: \n\n");
        		leia(alterar,10);
        		
			while(alterar[0] != '5')
			{


			    i = procurar(agenda,fichas_existentes);
			    if(i<0) 
			    {
			    printf("Pessoa não encontrada");
			    break;
			    }
        		printf("\nDigite a informação que substituirá: ");
        		leia(dadoAlterado,100);
			    if(alterar[0]=='1') strcpy(agenda[i].telefone, dadoAlterado);
			    if(alterar[0]=='2') strcpy(agenda[i].email, dadoAlterado);
			    if(alterar[0]=='3') strcpy(agenda[i].endereco, dadoAlterado);
			    if(alterar[0]=='4') strcpy(agenda[i].datanascimento, dadoAlterado);
			    printf("\Dado alterado!\n");
			    break;
			}
			
	    }
		if(opcao[0] == '5') //excluir	
		{
		    int i;
			i = procurar(agenda,fichas_existentes);
			if(i >= 0)
			{
		        printf("\n\n%s foi removido(a)\n", agenda[i].nome);
		        int j;
		        agenda[i] = agenda[fichas_existentes-1];
		        fichas_existentes--;
		        proxima--;
		        //break;
			}
		    else
	        {
		        printf("\nPessoa não encontrada\n");
		    }
	    }
	}
	return 0;
}
