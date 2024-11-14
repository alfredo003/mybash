#include "mybash.h"


int execute_command(char *input) {
 
    char *args[64];
    int i = 0;
    char *token = strtok(input, " ");
    
    while (token != NULL && i < 63) {  // Limite para evitar estouro
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;  // Último elemento precisa ser NULL para execve

    // Verificar se o comando é um caminho absoluto ou relativo
    if (strchr(args[0], '/') != NULL) {
        // Tentar executar diretamente o comando se é um caminho
        if (execve(args[0], args, NULL) == -1) {
            perror("Command execution failed");
            return -1;
        }
    } else {
        // Se não for um caminho, buscar no PATH
        char *path = getenv("PATH");
        if (path == NULL) {
            fprintf(stderr, "PATH not set\n");
            return -1;
        }

        char *directory = strtok(path, ":");
        while (directory != NULL) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", directory, args[0]);
            
            // Verificar se o caminho construído é executável
            if (access(full_path, X_OK) == 0) {
                execve(full_path, args, NULL);  // Executa o comando encontrado
                perror("Command execution failed");
                return -1;
            }
            directory = strtok(NULL, ":");
        }
    }

    fprintf(stderr, "Command not found\n");
    return -1;
}
int main(void)
{
	char *input;
	while(1)
	{
		input = readline("my_shell > ");
		if(input[0] != '\0')
			execute_command(input);
		if(input == NULL)
			break;
		free(input);
			
	}
	return (0);
}
