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

// problem in IEEE 754 
// float-pointer


// a small example
int main(void)
{
    srand(time(NULL));

    link *a = create_link("test", (void *)2);
    set_value(a, "test", (void *)5);

    link_add(a, "first", (void *)(rand() % 100 + 1) );
    double double_val = 3.3;
    link_add(a, "second", (void *)&double_val );

    printf("double_val = %f\n", (get_value(a, "second")));

    link_add(a, "third", (void *)(rand() % 100 + 1) );

    printf("\n---%d---\n", get_value(a, "third"));

    remove_value(a, "test");
    
    print_all(a);
    free_all(&a);

    
    // link *alphabet = create_link((char[2]) {'A', '\0'}, (void *)65); 

    // for (int i = 66; i <= 90; i++)
    // {
    //     link_add(alphabet, (char[2]) {i, '\0'}, (void *)i);
    // }
    
    // remove_value(alphabet, "A");

    // print_all(alphabet);
    // free_all(&alphabet);

    return 0;
}
