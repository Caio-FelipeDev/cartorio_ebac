#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings 

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema
{
	//in�cio: cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final: cria��o de vari�veis/strings
	
		printf("Digite seu CPF: "); //coletaando dados dos usu�rios
		scanf("%s", cpf); // %s refere-se a strings
		
		strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
		
		FILE *file; //cria o arquivo; "w" significa "escrever"
		file = fopen(arquivo, "w"); //cria o arquivo
		fprintf(file, cpf); //salva o valor da vari�vel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
	
		printf("Digite seu nome: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);

		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite seu sobrenome: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite seu cargo: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		system("pause");
}
int consulta()
{
	char cpf[40];
	char nome[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF que quer consultar ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	system("cls");
	
	if(file == NULL)
	{
		
		printf("CPF inv�lido. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{	
		printf("Informa��es do usu�rio:	");
		printf("%s", conteudo);
		printf("\n\n");
	}
		system("pause");
	
		
		
}
int deletar()			
{
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	system("cls");
	
	if(file == NULL)
	{
		printf("CPF deletado ou n�o existe no sistema. \n");
		system("pause");
	}

}

int main()
{
	int opcao=0;
	
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	while(1)
	{
	
		system("cls");
	
		printf("\tCart�rio da EBAC\n\n");// in�cio do menu
		printf("Escolha uma das op��es abaixo:\n\n");
		printf("\t 1 - Cadastrar nome\n");
		printf("\t 2 - Consultar nome\n");
		printf("\t 3 - Deletar nome\n");
		printf("\t 4 - Encerrar o programa\n\n");
		printf("Digite a op��o desejada: ");//fim do menu

		scanf("%d", &opcao);//inicio da sele��o 
	
		system("cls"); //respons�el por limpar a tela
		
		switch(opcao)
		{
			case 1: 
			registro();// chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
		    deletar();
			break;	
			
			case 4:
			printf("Sistema finalizado. \n");
			return 0;
			break;
			
			default:
			printf("Op��o inv�lida! Tente novamente.\n");//fim da sele��o
			system("pause");
			break;	
	    }
	}
}
