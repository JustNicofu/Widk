#include <stdlib.h>
#include <stdio.h>
#include "wtoken.h"

wtoken init_wtoken(char* value, wtoken_type type)
{
    wtoken new_wtoken;
    new_wtoken.value = value;
    new_wtoken.type = type;

    return new_wtoken;
}

void print_wtoken(wtoken* wtoken_object)
{
    const char* type_repr = wtoken_type_string_repr[wtoken_object->type];
    printf("token(value=%s, type=%s)", wtoken_object->value, type_repr);
}

wtoken_list init_wtoken_list()
{
    wtoken_list new_wtoken_list;
    new_wtoken_list.capacity = 2;
    new_wtoken_list.length = 0;

    size_t malloc_size = new_wtoken_list.capacity * sizeof(wtoken);
    new_wtoken_list.wtokens = malloc(malloc_size);

    return new_wtoken_list;

}

void insert_wtoken_to_list(wtoken_list* wtoken_list_object, wtoken* wtoken_object)
{
    if (wtoken_list_object->length >= wtoken_list_object->capacity)
    {
        size_t new_capacity = wtoken_list_object->capacity * 2;

        if (wtoken_list_object->capacity == 0)
        {
            new_capacity = 2;
        }

        wtoken* new_wtokens = realloc(wtoken_list_object->wtokens, new_capacity * sizeof(wtoken));

        if (new_wtokens == NULL)
        {
            return;
        }

        wtoken_list_object->capacity = new_capacity;
        wtoken_list_object->wtokens = new_wtokens;
    }

    wtoken_list_object->wtokens[wtoken_list_object->length] = *wtoken_object;
    wtoken_list_object->length++;

}

void print_wtoken_list(wtoken_list* wtoken_list_object)
{
    printf("wtoken_list(capacity=%d, length=%d):\n", wtoken_list_object->capacity, wtoken_list_object->length);
    if (wtoken_list_object->wtokens == NULL)
    {
        return;
    }

    for (size_t i = 0; i < wtoken_list_object->length; i++)
    {
        print_wtoken(&wtoken_list_object->wtokens[i]);
        printf("\n");
    }
    
}
