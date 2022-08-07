#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tamanho 20 //Definindo tamanho padrao para o struct
#include <Windows.h> //Incluso para utilizar a fun��o SLEEP ao pesquisAr o CPF (UTILIZADO NO DEV-C++)

	//Criando a STRUCT que ser� usada para os cadastros
	struct vacina{
		
		int codigo;
		char nome[100];
		char cpf[14];
		char vacina[50];
		char data[10];
		int lote;
		
	};
		
	//Criando uma fun��o que repete/imprime caracteres na tela
	void repetir(int n, char c){
		int i;
		for(i = 1; i <= n; i++){
			printf("%c",c);
		}
	};
	
	//Criando layout para a tela principal de MENU
	void layBemVindo(){
		repetir(50,'=');
		repetir(1,'\n');
		repetir(8,' ');
		printf("Bem-Vindo Ao Sistema de Vacina��o");
		repetir(8,' ');
		repetir(1,'\n');
		repetir(50,'=');
		repetir(2,'\n');		
	};
	
	//Criando layout para a tela de BUSCA POR CPF
	void layBuscaCPF(){
		repetir(50,'=');
		repetir(1,'\n');
		repetir(18,' ');
		printf("Busca por CPF");
		repetir(18,' ');
		repetir(1,'\n');
		repetir(50,'=');
		repetir(1,'\n');
	};
	
	//Criando layou para a tela de VACINAS CADASTRADAS
	void layVacinasCadastradas(){
		repetir(50,'=');
		repetir(1,'\n');
		repetir(15,' ');
		printf("Vacinas Cadastradas");
		repetir(15,' ');
		repetir(1,'\n');
		repetir(50,'=');
		repetir(1,'\n');		
	};
	
	//Criando layout para a tela de CADASTRO DE VACINAS
	void layCadastroVacina(){
		repetir(50,'=');
		repetir(1,'\n');
		repetir(15,' ');
		printf("Cadastro de Vacina");
		repetir(16,' ');
		repetir(1,'\n');
		repetir(50,'=');
		repetir(1,'\n');
	};

void main() {
	
	setlocale(LC_ALL, "Portuguese");
	
	//Declarando as variaveis necess�rias
	int contador = 0;
	struct vacina cadastro[tamanho];
	int opcao = 0;
	
	//Criando o WHILE que, enquanto n�o for digitado a opcao 4 (SAIR), o loop permanecer� 
	while(opcao != 4){
		
		//Exibindo o layout do menu principal
		system("cls");
		layBemVindo();
		
		//Criando o menu com as opcoes de 1 a 4 e recebendo a escolha
		printf("Selecione uma das op��es: \n\n");
		printf("1 - Cadastrar Vacina \n2 - Listar Aplica��es \n3 - Consultar por CPF \n4 - Sair \n\n");
		printf("Digite sua op��o: ");
		scanf("%d", &opcao);
		fflush(stdin);
		
		//Fluxo caso o usuario digite 1, para cadastrar novas vacina��es
		if(opcao == 1){			
			
			//Verificando se o usuario est� tentando cadastrar mais vacinacoes do que a struct comporta
			//A STRUCT foi criada por padrao para 20 posicoes		
			system("cls");
			if(contador >= tamanho){
				layCadastroVacina();
				printf("Voc� chegou ao limite de cadastros permitidos. \n\nPara novos, reinicie a aplica��o!");
				repetir(1,'\n');
				repetir(50,'=');
				repetir(2,'\n');
				system("pause");
			}//Caso ainda n�o tenha atingido o limite, vai para a tela solicitando as informa��es
			else{			
				&cadastro[contador].codigo;
				layCadastroVacina();
				fflush(stdin);							
				printf("\nDigite o nome para o cadastro %d: \n",contador+1);
				fflush(stdin);
				scanf("%s", cadastro[contador].nome);
				fflush(stdin);
				printf("\nDigite o CPF para o cadastro %d: \n", contador+1);
				fflush(stdin);
				scanf("%s", cadastro[contador].cpf);
				fflush(stdin);
				printf("\nDigite qual a vacina para o cadastro %d: \n", contador+1);
				fflush(stdin);
				scanf("%s", cadastro[contador].vacina);
				fflush(stdin);
				printf("\nDigite a data para o cadastro %d: \n", contador+1);
				fflush(stdin);
				scanf("%s", cadastro[contador].data);
				fflush(stdin);
				printf("\nDigite o lote para o cadastro %d: \n", contador+1);
				fflush(stdin);
				scanf("%d", &cadastro[contador].lote);
				fflush(stdin);
				contador++;
				fflush(stdin);
				repetir(50,'=');
				repetir(1,'\n');
				repetir(15,' ');
				printf("Cadastro Realizado!");
				repetir(15,' ');
				repetir(1,'\n');
				repetir(50,'=');
				repetir(2,'\n');
				system("pause");
			}
		}
		//Fluxo caso o usuario digite 2, ixibindo todos os cadastros realizados
		if(opcao == 2){			
			system("cls");
			//Vai validar se j� houve algum cadastro feito, atraves da variavel contador, caso ainda n�o, vai informar e pedir para voltar ao menu e cadastrar
			if(contador == 0){				
				layVacinasCadastradas();
				printf("N�o foi cadastrada nenhuma vacina��o. \n\nVolte ao menu e realize um cadastro!");
				repetir(1,'\n');
				repetir(50,'=');
				repetir(2,'\n');
				system("pause");					
			}//Caso j� tenha sido realizado algum cadastro (contador > 0), vai percorrer a struct e imprimir todos cadastros
			else{				
				int i;
				layVacinasCadastradas();
				for(i = 0; i < contador; i++){				
					printf("Codigo: %d", i+1);
					printf("\nNome: %s", cadastro[i].nome);
					printf("\nCPF: %s", cadastro[i].cpf);
					printf("\nVacina: %s", cadastro[i].vacina);
					printf("\nData: %s", cadastro[i].data);
					printf("\nLote: %d", cadastro[i].lote);
					repetir(1,'\n');
					repetir(50,'=');
					repetir(1,'\n');
				}
				repetir(1,'\n');
				system("pause");
			}
		}
		//Fluxo caso o usuario digite 3, realizando busca por um CPF
		if(opcao == 3){
			system("cls");
			//Vai validar se j� houve algum cadastro feito, atraves da variavel contador, 
			//caso ainda n�o, vai informar e pedir para voltar ao menu e cadastrar
			if(contador == 0){				
				layBuscaCPF();
				printf("N�o foi cadastrada nenhuma vacina��o. \n\nVolte ao menu e realize um cadastro!");
				repetir(1,'\n');
				repetir(50,'=');
				repetir(2,'\n');
				system("pause");			
			}//Caso j� tenha sido realizado algum cadastro (contador > 0), solicitar qual CPF deseja buscar
			else{
				char busca[14];
				layBuscaCPF();
				printf("\nInforme qual CPF deseja pesquisar: ");
				gets(busca);//Armazenando o CPF digitado
				//Criando as variaveis que ser�o usadas dentro do FOR e outras estruturas para a busca				
				int i;
				int encontrou = 99;
				int indice;
				//Aqui atraves do for vai percorrer o CPFs armazenados e caso localize, vai alterar a variavel encontrou, 
				//armazenar em qual indice foi localizado, e dar um break para sair do la�o sem a necessidade de perconrrer os demais indices
				for(i = 0; i < contador; i++){
					if(strcmp(cadastro[i].cpf,busca) == 0){
						encontrou = 0;
						indice = i;
						break;
					}
				}
				//Mensagem informando que estamos buscando o CPF na base
				system("cls");
				layBuscaCPF();
				printf("Estamos buscando o CPF informado .");
				Sleep(1200);
				printf(" .");
				Sleep(1200);
				printf(" .");
				repetir(1,'\n');	
				
				//Caso tenha encontrado o CPF na base, pela variavel encontrou = 0,
				//Vai mostrar a mensagem informando que foi localizado e que est� carregando as informa��es
				if(encontrou == 0){
					system("cls");
					layBuscaCPF();
					printf("CPF localizado! \nEstamos carregando as informa��es .");
					Sleep(1200);
					printf(" .");
					Sleep(1200);
					printf(" .");
					repetir(1,'\n');
					//Vai carregar as informa��es do CPF localizado utilizando o indice armazendo no FOR anterior
					system("cls");
					layBuscaCPF();
					printf("Codigo: %d", i+1);
					printf("\nNome: %s", cadastro[indice].nome);
					printf("\nCPF: %s", cadastro[indice].cpf);
					printf("\nVacina: %s", cadastro[indice].vacina);
					printf("\nData: %s", cadastro[indice].data);
					printf("\nLote: %d", cadastro[indice].lote);
					repetir(1,'\n');
					repetir(50,'=');
					repetir(1,'\n');
					system("pause");									
				}//Caso n�o tenha encontrado o CPF, informar� que n�o foi localizado
				else{
					system("cls");
					layBuscaCPF();
					printf("CPF n�o localizado!");
					repetir(1,'\n');
					repetir(50,'=');
					repetir(1,'\n');
					system("pause");
				}			
			}
		}
		//Caso o usuario digite 4, sai do while, encerrando a aplicacao
		if(opcao == 4){
			break;
		}		
	}
	//Mensangem de volte sempre ao sair da aplica��o
	system("cls");
	repetir(50,'=');
	repetir(1,'\n');
	repetir(18,' ');
	printf("Volte Sempre!");
	repetir(18,' ');
	repetir(1,'\n');
	repetir(50,'=');
}
