#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    stack new = NULL;
    return new;
}

stack stack_push(stack s, stack_elem e){
    if(stack_is_empty(s)){
        s = malloc(sizeof(struct _s_stack));
        s->elems = calloc(1, sizeof(stack_elem));//malloc(1*sizeof(stack_elem))
        s->size = 0;
        s->capacity = 1;
    }

    if(s->size == s->capacity){
        s->elems = realloc(s->elems, (2*s->capacity)*sizeof(stack_elem));
        s->capacity = 2*s->capacity;
    }
    s->elems[s->size] = e;
    s->size++;

    return s;
}

stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    s->size--;

    return s;
}

unsigned int stack_size(stack s){
    return s->size;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elems[s->size-1];
}

bool stack_is_empty(stack s){
    return s == NULL;
}

stack_elem *stack_to_array(stack s){
    unsigned int length = stack_size(s);
    stack_elem *r = calloc(length, sizeof(stack_elem));
    for(unsigned int i = 0; i < length; i++){
        r[i] = s->elems[i];
    }
    return r;
}

stack stack_destroy(stack s){
    free(s->elems);
    free(s);
    s = NULL;
    return s;
}

