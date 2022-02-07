#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->isEmpty = '1';                       //1 = Yes, 0 = No
    eventList->head = NULL;
    eventList->last = NULL;
    return eventList;
}

void DestroyEventList(EventList *this)
{


    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *tmp = this->head; 
    for (int i = 0; i < sizeof(this); i++){
        if(strcmp(name, tmp->eventName)){return tmp;}
        tmp = tmp->next;
    }   
    return NULL;
}

void AddEvent(EventList *this, Event *event)
{
    Event *bool = SearchEvent(this, event);
    if(bool == NULL){
        
    }
}

void RemoveEvent(EventList *this, char *name)
{
}

void ListEvents(EventList *this)
{
    // imprime esto si la lista está vacía
    printf("empty\n");
}
