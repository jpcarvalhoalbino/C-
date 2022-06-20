#include<stdio.h>
#include<math.h>
#include <locale.h>
#include <cstdlib>

float raizCubica (float num){
	float raiz;
	raiz = pow(num, 1.0/3.0);
	return raiz;
}

float areaTrapezio(float basema, float baseme, float h){
	float area;
	area = ((basema + baseme)/2.0) * h;
	return area;
}

float volCilindro (float r, float h){
	float vol;
	vol = (pow(r,2))* h;
	return vol;
}

float areaEsfera(float r){
	float area;
	area = 4*pow(r,2);
	return area;
}

float volEsfera(float r){
	float vol;
	vol = (4*pow(r,3))/3;
	return vol;
}

void sair(){
	exit(0);
}

int menu(){
	int op;
	
	puts("1 - Raiz c�bica");
	puts("2 - �rea do Trap�zio");
	puts("3 - Volume do Cilindro");
	puts("4 - �rea da Esfera");
	puts("5 - Volume da Esfera");
	puts("6 - Sair");
	puts(" ");
	printf("entre com uma op��o: ");
	scanf("%d", &op);
	return op;
}

main(){
	int opcao;
	float pv, sv, tv;
	float result;
	setlocale(LC_ALL, "Portuguese");
	
	opcao = menu();
	switch(opcao){
		case 1:
			printf("entre com um n�mero: ");
			scanf("%f", &pv);
			result = raizCubica(pv);
			printf("A raiz c�bica ser� %f", result);
		break;
		case 2:
			printf("entre com a  base maior do trap�zio: ");
			do{
				scanf("%f", &pv);
				if(pv<=0){
				printf("valor invalido! entre com um valor maior que zero:");
				
				}
			}while(pv<=0);
			
			printf("entre com a  base menor do trap�zio: ");
			do{
			
			scanf("%f", &sv);
			if(sv<=0){
				printf("valor invalido! entre com um valor maior que zero");
			}
			}while(sv<=0);
			
			do{
				if(sv>pv){
					printf("resultado invalido!base menor maior que a base maior:");
				}
			}while(sv>pv);
			
			printf("entre com a altura do trap�zio ");
			do{
		
			scanf("%f", &tv);
			if(tv<=0){
				printf("valor invalido! entre com um valor maior que zero");
			}
			
			}while(tv<=0);
			result = areaTrapezio(pv, sv, tv);
			printf("A �rea do trap�zio ser� %f", result);
		break;
		case 3:
			printf("entre com o raio do cil�ndro: ");
			do{
			
			scanf("%f", &pv);
			if(pv<=0){
			printf("valor invalido! entre com um numero maior que zero:");
			}
			}while(pv<=0);
			
			printf("entre com a altura do cil�ndro: ");
			do{
			
			scanf("%f", &sv);
			if(sv<=0){
				printf("valor invalido! entre com um numero maior que zero");
			}
			}while(sv<=0);
			result = volCilindro(pv, sv);
			printf("O volume do cil�ndro ser� %fpi", result);
		break;
		case 4:
			printf("entre com o raio da esfera: ");
			do{
			
			scanf("%f", &pv);
			if(pv<=0){
				printf("valor invalido! entre com um numero maior que zero:");
			}
			}while(pv<=0);
			result = areaEsfera(pv);
			printf("A �rea da esfera ser� %fpi", result);
		break;
		case 5:
			printf("entre com o raio da esfera: ");
			do{
		
			scanf("%f", &pv);
			if (pv<=0){
				printf("valor invalido! entre com um numero maiorque zero:");
			}
			}while(pv<=0);
			result = volEsfera(pv);
			printf("O volume da esfera ser� %fpi", result);
		break;

	}

	
}

