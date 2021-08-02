#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"

struct _s_stack{
    stack_elem e;
    stack_elem pos;
    stack next;
};

stack stack_empty(){
    stack new = NULL;
    return new;
}

stack stack_push(stack s, stack_elem e){
    
    stack new_e = malloc(sizeof(struct _s_stack));
    new_e->e = e;
    new_e->next = s;
    if(!stack_is_empty(s)){
        new_e->pos = s->pos+1;
    }else{
        new_e->pos = 0;
    }
    s = new_e;

    return s;
}

stack stack_pop(stack s){
    
    if(!stack_is_empty(s)){
        stack a = s;
        s = s->next;
        free(a);
    }

    return s;
}

unsigned int stack_size(stack s){

    unsigned int count = 0u;

    if(!stack_is_empty(s)){
        count = s->pos+1;
    }

    return count;
}

stack_elem stack_top(stack s){
    
    assert(!stack_is_empty(s));

    return s->e;
}

bool stack_is_empty(stack s){
    
    return s == NULL;
}

stack_elem *stack_to_array(stack s){

    stack_elem *r = NULL;

    if(!stack_is_empty(s)){
        r = calloc(stack_size(s), sizeof(stack_elem));

        stack a = s;
         int n = stack_size(s);
        for(int i = n-1; i > -1; --i){
            r[i] = stack_top(a);
            a = a->next;
        }
    }

    return r;
}

stack stack_destroy(stack s){
    
    while(!stack_is_empty(s)){
        s = stack_pop(s);
    }

    return s;
}


 
