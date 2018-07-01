#ifndef __CRIP_h
#define __CRIP_h

#include <stdint.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#define KEY "W#Z"


using namespace std;

/* Funcao de codificacao e decodifica o texto */
char* critografar(char* palavra, char* chave, bool cript);

/* Funcao tira modulo de entre dois valores */
int modulo(int a, int b);

/*funcao altera caracteres minusculos para maisculos, e minusculos para maisculos*/
char muda(char* str);

/* funcao verifica se a letra esta no alfabeto */
bool verificar_letra(char *text);

/*funcao chama metodo para criptografar */
char* cript(char* palavra, char* chave);

/*funcao chama metodo para descriptografar */
char* descript(char* palavra, char* chave);


#endif
