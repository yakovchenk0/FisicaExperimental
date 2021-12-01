#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "minimosquadrados.h"

#define GRAVIDADE 9.81
#define kPA 101.325

void main(){

	FILE *dados, *referencia;
	
	float *x, *y, *teoria, DeltaAltura = 0.2;
	float coeficienteAngular, coeficienteLinear, erroAngular, erroLinear;
	float densidade;
	int i, tam=0;

	char c;
	
	//Identificação dos dados
	dados = fopen("dados.dat", "r+");
	referencia = fopen("teoria.dat", "w");
	
	for (c = getc(dados); c != EOF; c = getc(dados))
		if (c == '\n')
			tam++;
			
	rewind(dados);
	
	//Malloc 
	x = (float *)malloc(tam*sizeof(float));
	y = (float *)malloc(tam*sizeof(float));
	teoria = (float *)malloc(tam*sizeof(float));
	
	
	//Passagem dos dados 
	for(i = 0; i < tam; i++)
		fscanf(dados, "%f\t%f\n", (x+i), (y+i));
	
	fclose(dados);
	
	//Coeficientes do Minimos Quadrados
	coeficienteAngular = calculoCoeficienteAngular(x,y,tam);
	coeficienteLinear = calculoCoeficienteLinear(x,y,tam);
	
	//Calculo da Densidade com base no desenvolvido no primeiro relatorio
	densidade = coeficienteAngular/GRAVIDADE;
		
	// Cálculo Teorico
	for(i = 0; i < tam; i++){
		*(teoria+i) = kPA + i*densidade*GRAVIDADE*DeltaAltura;
		fprintf(referencia, "%f\t%f\n", i*0.2, *(teoria+i));
	}
	fclose(referencia);
		
	//Erro do Minimos Quadrados
	erroAngular = errorAngular(x,y,teoria,tam);
	erroLinear = errorLinear(x,y,teoria,tam);
	
	printf("--- RESULTADOS --- \n\tCoeficiente Angular: %f\n\tCoeficiente Linear: %f\n\tErro Angular: %f\n\tErro LInear: %f\n\tDensidade: %f\n", coeficienteAngular, coeficienteLinear, erroAngular, erroLinear, densidade);
	
}
