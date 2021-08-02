#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "stack.h"

struct _s_stack{
    stack_elem e;
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
    stack a = s;
    if(!stack_is_empty(s)){
        count++;
        while(a->next != NULL){
            a = a->next;
            count++;
        }
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
        int n = stack_size(s);

        r = calloc(n, sizeof(stack_elem));

        stack a = s;
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


 
