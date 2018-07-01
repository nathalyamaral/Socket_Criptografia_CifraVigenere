#include "crip.h"


int modulo(int a, int b){
	int resultado = ((a % b + b) % b);
	printf("resultado do modulo = %d\n", resultado);
	return resultado;
}

char muda(char* str){ /* metodo muda letras de minusculo para maisculo */
	int i;
	for( i = 0; i < str[i];i++){
       if((str[i] >= 'a') && (str[i] <= 'z')){
           return 'A' + (str[i] - 'a');
       }
       if((str[i] >= 'A') && (str[i] <= 'Z')){
           return 'a' + (str[i] - 'A');
       }
       return str[i];
	}
	return *str;
}

bool verificar_letra(char *text){ /* meotod verifica se é uma letra do alfabeto */
	int j;
	bool returns = NULL;
	for( j = 0; j < text[j] ; j++){
		if(text[j] == '\0' || text[j] == ' '){
			returns = false;
			return false;
		}
		else if((text[j] >= 'A' || text[j] <= 'Z') && (text[j] >= 'a' || text[j] <= 'z')){
			returns = true;
			return true;

		}else{
			returns = false;
			return false;
		}
	}
	return returns;
}



char* critografar(char* palavra, char* chave, bool cript){
	char* palavra_saida;
	char troca;
	int tamanha_chave = strlen(chave);
	int i;
	bool verifica;
	int  chave_index,cont_char = 0,k;
	int tamanha_entrada = strlen(palavra);
	
	
	palavra_saida = (char*)malloc(tamanha_chave + 1);
	

	for ( i = 0; i < tamanha_entrada; ++i){
		if (verificar_letra(&palavra[i]) == true){

			verifica = isupper(palavra[i]); /* se e maisculo */
			if(verifica){
				troca = 'A';
			}
			else{
				troca = 'a';		
			}
			printf("Valor de troca na execucao nº%d vez valor=%c\n\n", i,troca);
			chave_index = (i - cont_char) % tamanha_chave;
			printf("Valor de chave_index na execucao nº%d vez valor=%d\n\n", i,chave_index);
			if(verifica){
				k = muda(&chave[chave_index]);
			}
			else{
				k = muda(&chave[chave_index]) - troca;
			}

			k = cript ? k : -k; /* AQUI ESCOLHE SE VAI SOMAR OU SUBTRAIR */
			printf("Formula: palavra=%c     k=%d    - troca=%d ), 26)   + troca=%d\n", palavra[i], k, troca, troca);
			char ch = (char)((modulo(((palavra[i] + k) - troca), 26)) + troca);
			printf("\nvalor de (ch) na  execucao nº%d vez valor= %c\n\n", i,ch);
			palavra_saida[i] = ch;

		}else{

			palavra_saida[i] = palavra[i];
			++cont_char;
		}
	}

	palavra_saida[tamanha_entrada] = '\0';
	return palavra_saida;
}

char* cript(char* palavra, char* chave){
	return critografar(palavra, chave, true);
}

char* descript(char* palavra, char* chave){
	return critografar(palavra, chave, false);
}



