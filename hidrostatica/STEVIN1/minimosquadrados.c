#include <stdio.h>

float somatorio(float dados[], int tam){

	int i;
	float aux = 0;
	
	for(i = 0; i < tam; i++)
		aux += dados[i];

	return aux;
}

float calculoCoeficienteAngular(float x[], float y[], int tam){

	float SOMA_Y, SOMA_X, SOMA_XY, SOMA_XX;
	float aux[tam];
	float coeficienteAngular;
	int i;
	
	//Elementos do quociente
	
	SOMA_Y = somatorio(y,tam);
	SOMA_X = somatorio(x, tam);
	
	for(i = 0; i < tam; i++)	//Preparar o vetor da multiplicação dos dados
		aux[i] = x[i]*y[i];
	
	SOMA_XY = somatorio(aux,tam);
	
	for(i = 0; i < tam; i++)	//Preparar o vetor da soma dos quadrados
		aux[i] = x[i]*x[i];
	
	SOMA_XX = somatorio(aux,tam);
	
	//Cálculo do Coeficiente
	
	coeficienteAngular = (SOMA_Y*SOMA_XX - SOMA_X*SOMA_XY) / (tam*SOMA_XX - SOMA_X*SOMA_X);
	
	return coeficienteAngular;
}

float calculoCoeficienteLinear(float x[], float y[], int tam){

	float SOMA_Y, SOMA_X, SOMA_XY, SOMA_XX;
	float aux[tam];
	float coeficienteLinear;
	int i;
	
	//Elementos do quociente
	
	SOMA_Y = somatorio(y,tam);
	SOMA_X = somatorio(x, tam);
	
	for(i = 0; i < tam; i++)	//Preparar o vetor da multiplicação dos dados
		aux[i] = x[i]*y[i];
	
	SOMA_XY = somatorio(aux,tam);
	
	for(i = 0; i < tam; i++)	//Preparar o vetor da soma dos quadrados
		aux[i] = x[i]*x[i];
	
	SOMA_XX = somatorio(aux,tam);
	
	//Cálculo Coeficiente Linear
	
	coeficienteLinear = (tam*SOMA_XY - SOMA_X*SOMA_Y) / (tam*SOMA_XX - SOMA_X*SOMA_X);

void main(){

	
}
