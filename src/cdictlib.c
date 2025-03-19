#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cdictlib.h"


link *create_link(char *add_key, void *add_value)
{
    if (add_key == NULL)
        return NULL;


    link *new_link = (link *)malloc(sizeof(link));
    if (new_link == NULL)
        return NULL;

    new_link->key = (char *)malloc(strlen(add_key) + 1);
    if (new_link->key == NULL)
        return NULL;

    strcpy(new_link->key, add_key);
    new_link->value = add_value;
    new_link->next = NULL;


    return new_link;
}


void link_add(link *obj, char *add_key, void *add_value) 
{
    if (add_key == NULL)
        return;


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
    if (new_link == NULL)
        return;

    p = obj;
    while (p->next != NULL) 
    {
        p = p->next;
    }
    p->next = new_link;
}


void set_value(link *obj, char *add_key, void *add_value)
{
    if (add_key == NULL)
        return;
    

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


void *get_value(link *obj, char *add_key)
{
    if (add_key == NULL)
        return 0;

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


void free_all(link **obj)
{
    if (obj == NULL)
        return;

    link *current = *obj;

    while (current != NULL)
    {
        link *next = current->next; 
        free(current->key);
        free(current);
        current = next;
    }
    
    *obj = NULL;
}


void remove_value(link *obj, char *add_key)
{
    if (add_key == NULL)
        return;

    if (obj != NULL && strcmp(obj->key, add_key) == 0)
    {
        puts("yeeep");
    }
    

    link *p = obj;
    while (p != NULL)
    {
        link *removing = p->next;
        if (removing != NULL && strcmp(removing->key, add_key) == 0)
        {
            link *temp = removing->next;
            if (temp != NULL)
            {
                free(removing->key);
                free(removing);

                p->next = temp;
            }
            else if (temp == NULL)
            {
                free(removing->key);
                free(removing);

                p->next = NULL;
            }
            
            
            return;
        }
        p = p->next;
    }
    
}