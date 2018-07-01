
#include "crip.cpp"

int main(int argc, char* argv[]) {

	struct sockaddr_in socketservidor;
	socketservidor.sin_family = AF_INET;
	socketservidor.sin_addr.s_addr = INADDR_ANY;
	socketservidor.sin_port = htons(8080);

	char *buffer;

	buffer = (char*)malloc(sizeof(char)*1000);

	int servidor = socket(AF_INET, SOCK_STREAM, 0);

	int activado = 1;
	setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));

	if (bind(servidor, (struct sockaddr*)&socketservidor, sizeof(socketservidor)) != 0) {
		perror("Falha bind");
		return 1;
	}

	printf("\n\t   Aguardando conexao......  \n");
	listen(servidor, 100);

	//------------------------------

	struct sockaddr_in clientesock;
	unsigned int tam;
	int cliente = accept(servidor, (struct sockaddr*) &clientesock, &tam);

	printf("\n\t Conexao recebida de [%d]\n", cliente);
	send(cliente, "Ola cliente!", 13, 0);
	send(cliente, ":)\n", 4, 0);

	//------------------------------

	printf("\n\n");
	while (1) {

		int bytesRecibidos = recv(cliente, buffer, 1001, 0);
		if (bytesRecibidos <= 0) {
			perror("Desconectado");
			return 1;
		}
		fflush(stdin);
		printf("\tRecebido Codificado: [ %s ]\n\n", buffer);
	
		buffer[bytesRecibidos] = '\0';

		
		char* textoclaro = descript(buffer, (char*)KEY);
		int tam = strlen(textoclaro);

		printf("\tRecebido %d bytes mensagem => ", tam-1);
		printf("Decodificado:  [");

		for (int i = 0; i < static_cast<int>(strlen(textoclaro))-1; i++){
			printf("%c", textoclaro[i]);
		}

		printf("] \n\n");
	}

	free(buffer);

	return 0;
}
