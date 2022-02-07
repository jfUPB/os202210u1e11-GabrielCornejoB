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
    /*
    if(this->isEmpty == '1'){
        Event *ans = NULL;
        return ans;
    }*/
    if(this->isEmpty == '0'){
        Event *tmp = this->head; 
    do{
        if(strcmp(name, tmp->eventName) == 0){
            return tmp;
        }
        tmp = tmp->next;
    }
    while(tmp != NULL); 
    return NULL;
    }  
}

void AddEvent(EventList *this, Event *event)
{
    this->head = event;
    this->last = event;
    this->isEmpty = '0';
    /*
    if(this->isEmpty == '1'){
        this->head = &event;
        this->last = &event;
    }
    else{
        /*Event *bool = SearchEvent(&this, event->eventName);
        if(bool == NULL){
            this->last->next = event;
            this->last = event;
        }
        this->last->next = event;
        this->last = event;
    }*/
}

void RemoveEvent(EventList *this, char *name)
{
    if(this->isEmpty != '1'){
        Event *bool = SearchEvent(this, name);
        if(bool != NULL){
            //Si es el primer elemento de la lista
            if(strcmp(this->head->eventName,bool->eventName) == 0){
                this->head = this->head->next;
            }
            //Si es el ultimo
            else if(strcmp(this->last->eventName,bool->eventName) == 0){
                this->last = NULL;
                //Falta poner que el next del penultimo sea null tambien
            }
            //free(bool);
        }
    }
}

void ListEvents(EventList *this)
{
    if(this->isEmpty == '1'){
        printf("empty\n");
    }
    else{
        Event *tmp = this->head;
        do{
            printf("%s\n",tmp->eventName);
            tmp = tmp->next;
        }
        while(tmp != NULL);
        
    }
}
