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
const element NIL = { .type=LIST, .l=NULL }; 



static const char *eltypeString[] = {
    "ATOM","LIST"
};


void print(element e);
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
        printf("Returned NIL. Not a list.");
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
            if((node ->el).type == LIST){
                printf("Node was returned with count of %d, its list value is ",count);
                print(node->el);
            }else{
                printf("Node was returned with count of %d, its atom value is %c\n",count,(node->el).a);
            }
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
        printf("(");
        struct  _listnode *node = e.l;
        while(node != NULL){
            print(node->el);
            node = node -> next;
        }   
        printf(")");

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

    struct  _listnode *last;
    last = malloc(sizeof(struct _listnode));
    last =  NULL;

    list newlist;
    newlist = malloc(sizeof(list));
    element newElement = {.type=LIST,.l = l};
    newlist -> el = newElement;
    newlist -> next = last;

    struct  _listnode *newnode;
    newnode = malloc(sizeof(struct _listnode));
    newnode -> el = e;
    newnode -> next = newlist;


    return newnode;

}

list append(list l1, list l2){
    list pointer = l1;
    while((l1 -> next) != NULL){
        l1 = l1 -> next;
    }
    
    l1 -> next = l2;
    return pointer; 
    
}

int main(){
    //B-C list
    struct  _listnode *last;
    last = malloc(sizeof(struct _listnode)); //malloc returns a pointer
    last -> next =  NULL;
    last -> el = NIL;

    struct _listnode *new;
    new = malloc(sizeof(struct _listnode));
    element newEl = {.type=ATOM,.a='c'};
    new -> el = newEl;
    new -> next = last;



    struct _listnode *new2;
    new2 = malloc(sizeof(struct _listnode));
    element newE2 = {.type=ATOM,.a='b'};
    new2 -> el = newE2;
    new2 -> next = new;



    //Main linkedlist
    struct  _listnode *last2;
    last2 = malloc(sizeof(struct _listnode)); //malloc returns a pointer
    last2 -> next =  NULL;
    last2 -> el = NIL;

    struct _listnode *new3;
    new3 = malloc(sizeof(struct _listnode));
    element newEl3 = {.type=ATOM,.a='e'};
    new3 -> el = newEl3;
    new3 -> next = last2;


    struct _listnode *new4;
    new4 = malloc(sizeof(struct _listnode));
    element newEl4 = {.type=ATOM,.a='d'};
    new4 -> el = newEl4;
    new4 -> next = new3;

    struct _listnode *new5;
    new5 = malloc(sizeof(struct _listnode));
    element newEl5 = {.type=LIST,.l=new2};
    new5 -> el = newEl5;
    new5 -> next = new4;





    struct _listnode *head;
    head = malloc(sizeof(struct _listnode));
    element headEL = {.type=ATOM,.a='a'};
    head -> el = headEL;
    head -> next = new5;


    element linkedList = {.type=LIST,.l=head};




    printf("------------------------------------------------------------------------------\n");
    printf("Printing the LinkedList: \n");

    print(linkedList);

    printf("\n------------------------------------------------------------------------------\n");
    printf("Calling car() to get head of linkedList: \n");
    element returnedHead = car(linkedList);
    printf("Returned head element atom is %c\n", returnedHead.a);
    printf("\n\n");

    printf("\n------------------------------------------------------------------------------\n");
    printf("Calling car() of car(linkedlist) to get head of linkedList: \n");
    element returnedHead2 = car(returnedHead);
    printf("\n\n");

    printf("\n------------------------------------------------------------------------------\n");
    printf("Calling cdr() to get head of linkedList: \n");
    list returnedtail = cdr(linkedList);
    printf("\n\n");


    printf("\n------------------------------------------------------------------------------\n");
    printf("List will be freed and program will terminate.\n");
    lfreer(new2);
    lfreer(head);


   
}

