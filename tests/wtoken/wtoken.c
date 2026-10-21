#include "wtoken.h"

int main()
{
    wtoken_list wtoken_list_object = init_wtoken_list();
    
    wtoken wtoken_object1 = init_wtoken("+", SUM);
    wtoken wtoken_object2 = init_wtoken("-", SUB);
    wtoken wtoken_object3 = init_wtoken("*", MUL);
    wtoken wtoken_object4 = init_wtoken("/", DIV);

    insert_wtoken_to_list(&wtoken_list_object, &wtoken_object1);
    insert_wtoken_to_list(&wtoken_list_object, &wtoken_object2);
    insert_wtoken_to_list(&wtoken_list_object, &wtoken_object3);
    insert_wtoken_to_list(&wtoken_list_object, &wtoken_object4);

    print_wtoken_list(&wtoken_list_object);
    return 0;
}