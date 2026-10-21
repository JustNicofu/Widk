#ifndef wlexer_h
#define wlexer_h

#include "wtoken.h"

typedef struct
{
    char* text;
    int position;
    char current_char;

    int line;
    int column;
} wlexer;

wlexer init_wlexer(char* text);
void advance_wlexer(wlexer* wlexer_object);
wtoken_list tokenize_wlexer(wlexer* wlexer_object);

#endif