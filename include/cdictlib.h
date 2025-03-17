#ifndef CDICTLIB_H
#define CDICTLIB_H


typedef struct link link;

struct link 
{
    char *key;
    int value;
    struct link *next;
};


link *create_link(char *add_key, int add_value);
void link_add(link *obj, char *add_key, int add_value);
void set_value(link *obj, char *add_key, int add_value);
int get_value(link *obj, char *add_key);
void free_all(link **obj);
void remove_value(link *obj, char *add_key);

#endif
