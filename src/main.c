#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/cdictlib.h"


void print_all(link *a)
{
    link *p = a;
    while (p != NULL)
    {
        printf("key: %s\nvalue: %d\n\n",  p->key, p->value);
        p = p->next;
    }

}


int main(void)
{
    srand(time(NULL));

    link *a = create_link("test", 2);
    set_value(a, "test", 5);

    link_add(a, "first", rand() % 100 + 1);
    link_add(a, "second", rand() % 100 + 1);
    link_add(a, "third", rand() % 100 + 1);
    
    free_all(&a);
    print_all(a);

    return 0;
}
