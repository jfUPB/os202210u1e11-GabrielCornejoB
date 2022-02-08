#include "event.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{
    Event *event = malloc(sizeof(Event));
    char aux[sizeof(name)];
    if(strlen(name) > 15){
        char fixed[15];
        for (int i = 0; i < 15; i++){
            fixed[i] = name[i];
        }     
        sscanf(fixed, "%s", event->eventName);
    }
    else{
        sscanf(name, "%s", event->eventName);    
    }  
    event->next = NULL;
    return event;
}

void DestroyEvent(Event *this)
{
    free(this);
}
