#include "wtoken.h"
#include "wlexer.h"

int main()
{
    wlexer wlexer_object = init_wlexer("hello world!");
    wtoken_list tokenize_result = tokenize_wlexer(&wlexer_object);
    
    return 0;
}