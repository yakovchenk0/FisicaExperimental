#include <stdio.h>
#include <math.h> 

float somatorio(float dados[], int tam){

	int i;
	float aux = 0;
	
	for(i = 0; i < tam; i++)
		aux += dados[i];

	return aux;
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
	
	//Cálculo do Coeficiente
	
	coeficienteLinear = (SOMA_Y*SOMA_XX - SOMA_X*SOMA_XY) / (tam*SOMA_XX - SOMA_X*SOMA_X);
	
	return coeficienteLinear;
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
	
	//Cálculo Coeficiente Linear
	
	coeficienteAngular = (tam*SOMA_XY - SOMA_X*SOMA_Y) / (tam*SOMA_XX - SOMA_X*SOMA_X);
	
	return coeficienteAngular;
}

float errorExperimentalTeoria(float x[], float y[], float teoria[], int tam){

	float coeficienteAngular, coeficienteLinear;
	float error[tam];
	float ERROR = 0;
	int i;
	
	coeficienteAngular = calculoCoeficienteAngular(x,y,tam);
	coeficienteLinear = calculoCoeficienteLinear(x,y,tam);
	
	for(i = 0; i < tam; i++){
		error[i] = teoria[i] - (coeficienteAngular*x[i] + coeficienteLinear);
	}
	
	for(i = 0; i < tam; i++)
		ERROR += error[i]*error[i];
	
	ERROR = ERROR/(tam-2);
	
	return ERROR;
}

float errorLinear(float x[], float y[], float teoria[], int tam){

	float SOMA_X, SOMA_XX, aux[tam];
	float ERROR, ERROR_LINEAR;
	int i;
	
	SOMA_X = somatorio(x, tam);
	
	for(i = 0; i < tam; i++)	//Preparar o vetor da soma dos quadrados
		aux[i] = x[i]*x[i];
	
	SOMA_XX = somatorio(aux, tam);
	
	ERROR = errorExperimentalTeoria(x,y,teoria,tam);

	ERROR_LINEAR = sqrt((ERROR*SOMA_XX) / (tam*SOMA_XX - SOMA_X*SOMA_X));
	
	return ERROR_LINEAR;
}

float errorAngular(float x[], float y[], float teoria[], int tam){

	float SOMA_X, SOMA_XX, aux[tam];
	float ERROR, ERROR_ANGULAR;
	int i;
	
	SOMA_X = somatorio(x, tam);
	
	for(i = 0; i < tam; i++)	//Preparar o vetor da soma dos quadrados
		aux[i] = x[i]*x[i];
	
	SOMA_XX = somatorio(aux, tam);
	
	ERROR = errorExperimentalTeoria(x,y,teoria,tam);
	
	ERROR_ANGULAR = sqrt((ERROR*tam) / (tam*SOMA_XX - SOMA_X*SOMA_X));
	
	return ERROR_ANGULAR;
}
