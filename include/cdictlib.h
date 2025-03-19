#ifndef CDICTLIB_H
#define CDICTLIB_H


typedef struct link link;

struct link 
{
    char *key;
    void *value;
    struct link *next;
};


link *create_link(char *add_key, void *add_value);
void link_add(link *obj, char *add_key, void *add_value);
void set_value(link *obj, char *add_key, void *add_value);
void *get_value(link *obj, char *add_key);
void free_all(link **obj);
void remove_value(link *obj, char *add_key);

#endif
