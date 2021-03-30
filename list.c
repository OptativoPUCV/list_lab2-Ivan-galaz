#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List *list = (List*)malloc(sizeof(List));//reservamos memoria para la lista 
  list->head = NULL; 
  list->tail = NULL;
  list->current = NULL;
  
  return list;
} 

void * firstList(List * list) 
{
  if (list == NULL ) return NULL;//si no encontramos una lista retornamos NULL
  if (list->head == NULL) return NULL; //si no hay dato en la cabeza retornamos NULL

  list->current = list->head;   //el current apunta a la cabeza
  return (void*)list->current->data; //retornamos el primer nodo (head)
}

void * nextList(List * list) 
{
  if (list == NULL ) return NULL;//si no encontramos una lista retornamos NULL
  if (list->current == NULL) return NULL;
  if (list->current->next == NULL ) return NULL;

  list->current = list->current->next;
  return (void*)list->current->data;
}

void * lastList(List * list)
{
  if (list == NULL ) return NULL;//si no encontramos una lista retornamos NULL
  if (list->head == NULL) return NULL;

  list->current = list->tail;
  return (void*)list->current->data;
}

void * prevList(List * list) 
{
  if (list == NULL ) return NULL;//si no encontramos una lista retornamos NULL
  if (list->head == NULL) return NULL; 
  if (list->current == NULL) return NULL;
  if (list->current->prev == NULL ) return NULL;

  list->current = list->current->prev;
  return (void*)list->current->data;
}

void pushFront(List * list, const void * data) 
{
  if (list)     //debe existir una lista para realizar esta función
  {
    Node * node = createNode(data);
    if (list->head == NULL)  //si no hay un dato en la cabeza
    { 
      list->head = node;
      list->tail = node;
    }else                    //si hay un dato en la cabeza lo cambiamos por el node y
    {                        //cambiamos los nodos a los que apunta
      node->next = list->head;   
      list->head->prev = node;
      list->head = node;
    }
  }
}
  
void pushBack(List * list, const void * data) 
{
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) 
{
  if (list){    //debe existir una lista para realizar esta función
    Node * node = createNode(data);
    if (list->head == NULL)       //si no hay un dato en la cabeza
    { 
      list->head = node;
      list->tail = node;
    }else{
      if(list->current->next != NULL) //si el current está entre medio
      {
        node->next = list->current->next;
        node->prev = list->current;
        list->current->next = node;
        list->current->next->prev = node;
      }else 
      {             //si nos encontramos en el último nodo
        list->tail = node;
        list->current->next = node;
        list->current->next->prev = list->current;
      }
    }
  } 
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if (list == NULL) return NULL;    //debe existir una lista para realizar esta función
  if (list->head == NULL) return NULL;
  if (list->current == NULL) return NULL;






  
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}