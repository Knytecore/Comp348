    #include <stdio.h>


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



    list initializeLinkedList(){
        //struct _listnode test = NULL; doesn't work bc NULL is a pointer whose value is set to 0. Must set null to a pointer.
        struct _listnode* node = NULL;
        list l = node;
        return l;
    }

    list addToLinkedList(element *a, list b){
        struct _listnode node = {.el = *a, .next = b}; //set element (value) to param a and next to list b, which is a pointer to the first node of the list (head)
        list l = &node;
        return l;
    }

    void printLinkedList(list l){
        struct _listnode *node = &(*l); // Set node pointer to address of first node in the list (head) - a is passed by value but does't matter here
        if(node == NULL){
            printf("The list is empty.");
        }else{


            while((node) != NULL){
                printf("next is not null");
                element el = (*node).el;
                element b = {.type=ATOM,.a='d'}; //Without this, strange behaviour
                printf("Type: %s",eltypeString[el.type]);
                printf("Value: %c",el.a);
                node = (*node).next;

            }

            if(node == NULL){
            printf("Node is null");
        }

        }
    }



    element car(element e){

    }



    list append(list l1, list l2){

    }

    int main(){
        printf("hello");
        list LinkedList = initializeLinkedList();
        printLinkedList(LinkedList);
        element el = {.type=ATOM,.a='e'};
        LinkedList = addToLinkedList(&el,&LinkedList);
        printLinkedList(LinkedList);


    }

