//
// Created by Ryan King on 12/09/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Song.h"
#include "Playlist.h"



class LinkedNode {

private:
    Playlist* item;
    LinkedNode* next;

public:
    LinkedNode(Playlist* item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    Playlist* getItem();
    LinkedNode* getNext();
    void setItem(Playlist* newItem);
    void setNext(LinkedNode* newNext);
};


#endif //LINKEDNODE_H
