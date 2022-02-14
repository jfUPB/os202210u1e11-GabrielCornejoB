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
    Event *tmp = this->head;
    if(tmp != NULL){
        do{
        char *name = tmp->eventName;
        tmp = tmp->next;
        RemoveEvent(this, name);
        }
        while(tmp != NULL);
    }
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    if(this->isEmpty == '1'){
        return NULL;
    }  
    else{    
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
    if(this->isEmpty == '1'){
        this->head = event;
        this->last = event;
        this->isEmpty = '0';
    }
    else{
        Event *bool = SearchEvent(this, event->eventName);
        if(bool == NULL){
            this->last->next = event;
            this->last = event;
        }  
        else{
            DestroyEvent(event);
        }
    }
}

void RemoveEvent(EventList *this, char *name)
{
    if(this->isEmpty == '0'){
        Event *bool = SearchEvent(this, name);
        if(bool != NULL){
            //Si es el primer elemento de la lista
            if(strcmp(this->head->eventName,bool->eventName) == 0){
                if(bool->next == NULL){
                    this->isEmpty = '1';
                }
                this->head = this->head->next;
                DestroyEvent(bool);
            }
            else{
                Event *tmp = this->head;
                do{
                    if(strcmp(tmp->next->eventName, bool->eventName) == 0){
                        //Si queremos borrar el ultimo
                        if(tmp->next->next == NULL){
                            tmp->next = NULL;
                            this->last = tmp;
                            DestroyEvent(bool);
                            break;
                        }
                        //Si queremos borrar uno en medio de la lista
                        tmp->next = bool->next;
                        DestroyEvent(bool);
                        break;
                    }
                    tmp = tmp->next;
                }
                while(tmp != NULL);
            } 
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
