#include "lexer.h"
#include "shell.h"

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    while (1)
    {
        print_prompt();

        char *input = get_input();

        if (feof(stdin) && input[0] == '\0')
        {
            free(input);
            printf("\n");
            break;
        }

        tokenlist *tokens = get_tokens(input);

        expand_environment_variables(tokens);
        expand_tilde(tokens);

        free(input);
        free_tokens(tokens);
    }

    return 0;
}
