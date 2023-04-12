//gcc 7.4.0

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>


struct vector{
    void * data;
    size_t size; // size of each unit
    int index; // used for push pop operartions
    int current_index;
    void * pop_buffer; // this the buffer for poping
    int (*construct)(struct vector * self,size_t size);
    int (*destruct)(struct vector * self);
    void (*push)(struct vector * self,void * item);
    void * (*pop)(struct vector * self);
    void * (*get)(struct vector * self,int index);
};


#define vector_create(name) struct vector name ; \
                    name.construct=&construct;  \
                    name.push=&push;  \
                    name.pop=&pop;    \
                    name.get = &get; \
                    name.destruct = &destruct;


int destruct(struct vector * self);
int construct(struct vector * self,size_t size);

void * get(struct vector * self,int index);
void push(struct vector * self,void * item);
void * pop(struct vector * self);
