#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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


// a small example
int main(void)
{
    srand(time(NULL));

    link *a = create_link("test", 2);
    set_value(a, "test", 5);

    link_add(a, "first", rand() % 100 + 1);
    link_add(a, "second", rand() % 100 + 1);
    link_add(a, "third", rand() % 100 + 1);

    printf("\n---%d---\n", get_value(a, "third"));

    remove_value(a, "third");
    
    print_all(a);
    free_all(&a);

    
    link *alphabet = create_link((char[2]) {'A', '\0'}, 65); 

    for (int i = 66; i <= 90; i++)
    {

        link_add(alphabet, (char[2]) {i, '\0'}, i);
    }
    

    print_all(alphabet);
    free_all(&alphabet);

    return 0;
}
