#include <mybash.h> 

int main(void) {
    char *input;

    while (1) {
        input = readline("\033[0;31mmybash\033[0m$ ");
        if (input == NULL) { 
            break;
        }
        if (input[0] != '\0') {
            add_history(input);
            verify_command(input);
        }
        free(input);
    }

    return 0;
}

