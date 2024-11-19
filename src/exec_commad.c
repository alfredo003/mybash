#include <mybash.h> 
int execute_command(char *input)
{
    char *args[64];
	extern	char **environ;
    int i = 0;
    char **token = ft_split(input, ' ');  
    if (token == NULL)
    {
        perror("Error splitting input\n");
        return -1;
    }

    while (token[i] != NULL && i < 63)
    {
        args[i] = token[i];
        i++;
    }
    args[i] = NULL;

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Fork failed");
        free(token);
        return -1;
    }

    if (pid == 0)
    {
		if (ft_strchr(args[0], '/'))
		{
		    if (execve(args[0], args, environ) == -1)
		    {
				perror("Command execution failed");
				exit(EXIT_FAILURE);
		    }
		}
		else
		{
		    char *path = getenv("PATH");
		    if (path == NULL)
		    {
				perror("PATH not set\n");
				exit(EXIT_FAILURE);
		    }

		    char *path_copy = ft_strdup(path);
		    if (path_copy == NULL)
		    {
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
		    }

		    char *directory;
		    char *save_ptr;
		    directory = strtok_r(path_copy, ":", &save_ptr);

		    while (directory != NULL)
		    {
				char full_path[1024];
				snprintf(full_path, sizeof(full_path), "%s/%s", directory, args[0]);

				if (access(full_path, X_OK) == 0)
				{
					execve(full_path, args, environ);
					perror("Command execution failed");
					free(path_copy);
					exit(EXIT_FAILURE);
				}
				directory = strtok_r(NULL, ":", &save_ptr);
		    }

		    printf("Command not found: %s\n", args[0]);
		    free(path_copy);
		    exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
		    fprintf(stderr, "Child process exited with error code %d\n", WEXITSTATUS(status));
		}
	}

	free(token);
	return 0;
}



