#include <stdio.h>
#include "../include/cdictlib.h"


int main(void)
{
    link *a = create_link("test", 2);
    set_value(a, "test", 5);
    
    link *p = a;
    while (p != NULL)
    {
        printf("%d = %s\n", p->value, p->key);
        p = p->next;
    }
    

    return 0;
}
