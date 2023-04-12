#include "vector.h"

int destruct(struct vector * self){
    free(self->data);
    free(self->pop_buffer);
    return 0;
}
int construct(struct vector * self,size_t size){
    self->index = 0;
    self->size = size;
    self->data = malloc(size);
    self->pop_buffer = malloc(size);
    return 0;
}



void * get(struct vector * self,int index){
    return (((char*)self->data)+(index*self->size)); 
}


void push(struct vector * self,void * item){
    memcpy(((char*)self->data)+(self->index*self->size),item,self->size);
    self->data = realloc(self->data,(++self->index)*self->size);
}



void * pop(struct vector * self){
    memcpy(self->pop_buffer,((char*)self->data)+((self->index*self->size)-self->size),self->size);

    self->data = realloc(self->data,(--self->index)*self->size);
    return self->pop_buffer;
}


