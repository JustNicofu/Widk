#ifndef wtoken_h
#define wtoken_h

typedef enum
{
    SUM,
    SUB,
    MUL,
    DIV
} wtoken_type;

static const char* wtoken_type_string_repr[] = {
    [SUM] = "SUM",
    [SUB] = "SUB",
    [MUL] = "MUL",
    [DIV] = "DIV"
};

typedef struct
{
    char* value;
    wtoken_type type;
} wtoken;

wtoken init_wtoken(char* value, wtoken_type type);
void print_wtoken(wtoken* wtoken_object);

typedef struct
{
    wtoken* wtokens;
    int capacity;
    int length;
} wtoken_list;

wtoken_list init_wtoken_list();
void insert_wtoken_to_list(wtoken_list* wtoken_list_object, wtoken* wtoken_object);
void print_wtoken_list(wtoken_list* wtoken_list_object);

#endif