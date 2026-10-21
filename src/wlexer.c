#include <stdio.h>
#include <string.h>
#include "wlexer.h"

wlexer init_wlexer(char* text)
{
    wlexer new_wlexer;
    new_wlexer.text = text;
    new_wlexer.position = 0;
    new_wlexer.current_char = new_wlexer.text[new_wlexer.position];

    new_wlexer.line = 0;
    new_wlexer.column = 1;

    return new_wlexer;
}

void advance_wlexer(wlexer* wlexer_object)
{
    wlexer_object->position++;

    if (wlexer_object->position <= strlen(wlexer_object->text))
    {
        wlexer_object->current_char = wlexer_object->text[wlexer_object->position];
    }
    else
    {
        wlexer_object->current_char = '\0';
    }
}

wtoken_list tokenize_wlexer(wlexer* wlexer_object)
{
    wtoken_list result;

    while (wlexer_object->current_char != '\0')
    {
        printf("%c", wlexer_object->current_char);
        advance_wlexer(wlexer_object);

        // @todo: do the tokenize_wlexer function       
    }

    return result;
}
