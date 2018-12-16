//
// Created by Ryan King on 12/09/18.
//
#include "LinkedNode.h"
#include "Playlist.h"

LinkedNode::LinkedNode(Playlist* item){
    this->item = item;
    next = nullptr;
}

LinkedNode::LinkedNode(const LinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}
Playlist* LinkedNode::getItem(){
    return item;
}

LinkedNode* LinkedNode::getNext(){
    return next;
}
void LinkedNode::setItem(Playlist* newItem){
    item = newItem;
}

void LinkedNode::setNext(LinkedNode* newNext){
    next = newNext;
}
