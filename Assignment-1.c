#include <stdio.h>
#include <stdlib.h>


typedef enum { ATOM, LIST } eltype;
typedef char atom;
struct _listnode; //Define _listnode identifier within struct namespace. Need _listnode in front. (typedef struct _listnode _listnode would allow you to call w/out _listnode in front)
typedef struct { //Define anonymous struct, define that as type of element, and add alias "element" in global namespace (struct not require in front)
    eltype type;
    union { //Union stores diff data type in same memory location (either atom or _listnode, don't need two memory locations)
    atom a;
    struct _listnode* l;
    };
} element;

typedef struct _listnode { //Contains element (atom or listnode and type) and next node.
    element el;
    struct _listnode* next;
} * list; //Declares list as a pointer to a _listnode
const element NIL = { .type=LIST, .l=NULL }; //Last element of linked list



static const char *eltypeString[] = {
    "ATOM","LIST"
};



list LinkedList; //Global variable

element aasel(atom a){
    struct  _listnode *pointer = LinkedList;
    while(pointer != NULL){
        
        element el = pointer -> el;
        if(a == el.a){
            printf("Corresponding atom found and returned.\n");
            return el;
        }

        pointer = pointer->next;

    }

    printf("Atom value not found.\n");



    
}

element lasel(list l){
    struct  _listnode *pointer = LinkedList;
    while(pointer != NULL){
        
        element el = pointer -> el;

        if(l == el.l){
            printf("Corresponding list found and returned.\n");
            return el;
        }
        pointer = pointer->next;


    }
    printf("List not found.\n");

}

element car(element e){
    if(e.type != LIST){
        return NIL;
    }else{
        struct  _listnode *node = e.l;
        return node -> el;
    }
}

list cdr(element e){
    if(e.type != LIST){
        printf("Null returned because not a list\n");
        return NULL;
    }else{
        int count = 1;
        struct  _listnode *node = e.l;
        while((node -> next) != NULL){
            count++;
            node = node -> next;
        }
        if(count == 0 || count == 1){
            printf("Null returned with count of %d\n", count);
            return NULL;
        }else{
            printf("Node was returned with count of %d, its atom value is %c\n",count,(node->el).a);
            return node;
        }
    }

}

list cdrdr(element e){
    printf("Running cdr for first time... \n");
    list a = cdr(e);
    printf("Running cdr for second time... \n");
    return cdr(a->el);
}

void print(element e){
    if(e.type == LIST && e.l == NULL){
        printf("NIL");
    }else if(e.type == LIST){
        printf("\"");
        struct  _listnode *node = e.l;
        while(node != NULL){
            print(node->el);
            node = node -> next;

        }
        printf("\"");

    }else if(e.type == ATOM){
        printf(" %c ",e.a);

    }

}

void lfreer(list l){ 
    struct _listnode *pointer;

   while (l != NULL)
    {
       pointer = l;
       l = l->next;
       free(pointer);

    }
}

list cons(element e, list l){


    list newlist;
    newlist = malloc(sizeof(list));
    newlist = l;

    struct  _listnode *newnode;
    newnode = malloc(sizeof(struct _listnode));
    newnode -> el = e;
    newnode -> next = newlist;



}

int main(){
    struct  _listnode *last;
    last = malloc(sizeof(struct _listnode));
    last =  NULL;

    struct _listnode *new;
    new = malloc(sizeof(struct _listnode));
    element newEl = {.type=ATOM,.a='e'};
    new -> el = newEl;
    new -> next = last;

    struct _listnode *new2;
    new2 = malloc(sizeof(struct _listnode));
    element newE2 = {.type=ATOM,.a='c'};
    new2 -> el = newE2;
    new2 -> next = new;

    struct _listnode *new3;
    new3 = malloc(sizeof(struct _listnode));
    element newE3 = {.type=LIST,.l= new2};
    new3 -> el = newE3;
    new3 -> next = new2;

    LinkedList = new3;

    element el = (LinkedList -> next) ->el;



    element returnedHead = car(newE3);
    printf("Returned head element atom is %c\n", returnedHead.a);

    list returnedTail = cdr(newE3);

    printf("\n\n");
    printf("Running cdrdr with element of type list containing \" c e \"...\n\n");
    list returnedCdrdr = cdrdr(newE3);
    



    

    printf("%c", el.a); //Prints correct value (c)
    lfreer(LinkedList); 
    el = (LinkedList -> next) ->el;
    printf("%c", el.a); //Value freed
}

