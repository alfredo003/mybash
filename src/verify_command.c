#include <mybash.h> 

void verify_command(char *input)
{
	char **token;
	
	token = ft_split(input,' ');
	
	if(!ft_strncmp(token[0],"echo",5))
	{
		printf("Exists!\n");
	}else if (!ft_strncmp(token[0],"cd",5))
	{
		printf("Exists!\n");
	}else if (!ft_strncmp(token[0],"pwd",5))
	{
		printf("Exists!\n");
	}else if (!ft_strncmp(token[0],"export",5))
	{
		printf("Exists!\n");
	}else if (!ft_strncmp(token[0],"unset",5))
	{
		printf("Exists!\n");
	}else if (!ft_strncmp(token[0],"env",5))
	{
		printf("Exists!\n");
	}else if (!ft_strncmp(token[0],"exit",5))
	{
		printf("Exists!\n");
	}
	else
	{
		execute_command(input);
	}
}
