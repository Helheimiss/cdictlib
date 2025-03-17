#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cdictlib.h"


link *create_link(char *add_key, int add_value)
{
    link *new_link = (link *)malloc(sizeof(link));

    new_link->key = (char *)malloc(strlen(add_key) + 1);
    strcpy(new_link->key, add_key);
    new_link->value = add_value;
    new_link->next = NULL;

    return new_link;
}


void link_add(link *obj, char *add_key, int add_value) {
    link *p = obj;
    while (p != NULL) 
    {
        if (strcmp(p->key, add_key) == 0)
        {
            return;
        }
        p = p->next;
    }
    
    link *new_link = create_link(add_key, add_value);
    p = obj;
    while (p->next != NULL) 
    {
        p = p->next;
    }
    p->next = new_link;
}


void set_value(link *obj, char *add_key, int add_value)
{
    link *p = obj;
    while (p != NULL)
    {
        if (strcmp(p->key, add_key) == 0)
        {
            p->value = add_value;
            return;
        }
        p = p->next;
    }

}


int get_value(link *obj, char *add_key)
{
    link *p = obj;
    while (p != NULL)
    {
        if (strcmp(p->key, add_key) == 0)
        {
            return p->value;
        }
        p = p->next;
    }


    return 0;
}