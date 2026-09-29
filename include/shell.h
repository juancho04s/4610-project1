#pragma once

#include "lexer.h"

void print_prompt(void);
void expand_environment_variables(tokenlist *tokens);
void expand_tilde(tokenlist *tokens);
