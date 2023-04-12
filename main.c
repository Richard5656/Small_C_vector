#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


int main(void)
{
    vector_create(vector)
    vector.construct(&vector,4);
   
   
    int s = 89;
    vector.push(&vector,&s);
   
    s = 879;
    vector.push(&vector,&s);
   
   
   
    printf("%d\n",*((int*)vector.pop(&vector)));

    s = 83;
    vector.push(&vector,&s);
       
    printf("%d\n",*((int*)vector.get(&vector,1)));
   
   
    vector.destruct(&vector);
    return 0;
}