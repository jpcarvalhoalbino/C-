#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<conio.h>
int inse;
int i, inserircont, removercont, listacont, fechar;
const int limite=500;
char lista [30];
char listaaux;

typedef struct{ 
char nome [30];
int telefone ;
char email[50];
}Cliente;

Cliente cliente[300];

void inclusao(){
	FILE*listan;
	listan=fopen("teste.txt", "r");
	int quantidade,i=0;
	do{
		printf("digite quantos clientes você deseja inserir/n");
		scanf("%i", &quantidade);
		if(quantidade<=0){
			printf("valor invalido/n");
		}
		
	} 
	while(quantidade <=0);
	
	
	
	listan =fopen("teste.txt","a");
	for(i=0;i<quantidade;i++){
		printf ("digite o nome do %i cliente/n",i+1);
		scanf("%s%*c",& cliente[i].nome );
		printf ("digite o telefone do %i cliente/n",i+1);
		scanf("%i%*c",& cliente[i].telefone);
		printf ("digite o email do %i cliente/n",i+1);
		scanf("%s%*c",& cliente[i].email );
		inse=fprintf(listan, "%s\n%d\n%s\n",cliente[i].nome,cliente[i].telefone,cliente[i].email);
	} 
	fechar=fclose(listan);

	
}

void listagem(){
	printf("Você quer imprimir todos os cadastros? \n s - Sim \n n - Não\n");
	int confl;
	
	do{
		char sairliste;
		scanf(" %c", & sairliste);
		int indexagem=0;
		if(sairliste=='s'){
			char nome [50],email[50],listaaux;
			int telefone;
			FILE*listan;
			listan=fopen("teste.txt","r");
			if(listan==NULL){
				printf("esta lista não existe");
				printf("precione qualquer tecla");
				getch();		
			} 
			else{
				listaaux=fscanf(listan,"%s %d %s",&nome,&telefone,&email);
				while(listaaux!=EOF){
				indexagem+=1;
				printf("nome do %i cliente %s\n",indexagem,nome);
				printf("telefone do %i cliente %i\n",indexagem,telefone);
				printf("email do %i cliente %s\n",indexagem,email);
				printf ("precione pra continuar imprimindo\n");
				getch();
				listaaux=fscanf(listan,"%s %d %s",&nome,&telefone,&email);
				}
				printf("foram imprimidos todos os itens\n");
				fechar=fclose(listan);
				confl=0;
			}
		
		}
		else if(sairliste =='n'){
			char nome [50],email[50],listaaux;
			int telefone;
			FILE*listan;
			listan=fopen("teste.txt","r");
			listaaux=fscanf(listan,"%s %d %s",&nome,&telefone,&email);
			printf("posição do contato\n");
			int positivo=0;
			indexagem=0; 
			scanf("%d", &positivo);
			while(listaaux != EOF) {
              
              if(indexagem == positivo) {
                printf("\nNome do %d cliente:%s\n", indexagem + 1, nome);
                printf("\nTelefone do %d cliente:%d\n", indexagem + 1, telefone);
                printf("\nEmail do %d cliente:%s\n\n", indexagem + 1, email);
              }
              indexagem+=1;
              listaaux = fscanf(listan,"%s %d %s",&nome, &telefone, &email);

          }
			confl = 0;
         fechar = fclose(listan);
		}
		else{
			printf("digite s-sim ou n-não");
			scanf(" %c",&sairliste);
			confl=500;
		}
		
		
		
		
		
		
		
		
	}while (confl!=0);

	
	
	
}

void remover() {
	int rem;
	FILE *listan;
	listan = fopen("teste.txt", "r");
	if(listan == NULL) {
		printf("A lista não existe!\nPressione alguma tecla para continuar.\n\n");
		getch();
	}
	else {
		fechar = fclose(listan);
		rem = remove("teste.txt");
		printf("Lista removida!\n");
	}
}



main(){
	setlocale(LC_ALL,"portuguese");
	char sair='n';
	
	printf("Agenda/n");
	int opicao;
	printf("digite uma das numerações a seguir\n");
	do{
		
		printf("inclusão de registro - 1\n");
		printf("listagem de cadastro - 2\n");
		printf("remover arquivo - 3\n");
		printf("sair - 4\n");
		
		scanf ("%i", &opicao);
		
		switch (opicao) {
			case 1:
				inclusao();
				break;
			case 2:
				listagem();
				break;
			case 3:
				remover();
				break;
			case 4:
				sair = 'y';
				break;
			default:
				printf("escolha uma das opições acima\n");
				break;
		}	
	}while (sair=='n');
	
	
	printf("criado por joão pedro carvalho albino");
	return 0;
	
	
	
	
	
}
