//
// Created by Ryan King on 12/09/18.
//
#include "LinkedNode.h"
#include "Playlist.h"

LinkedNode::LinkedNode(Song* item){
    this->item = item;
    next = nullptr;
}

LinkedNode::LinkedNode(const LinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}
Song* LinkedNode::getItem(){
    return item;
}

LinkedNode* LinkedNode::getNext(){
    return next;
}
void LinkedNode::setItem(Song* newItem){
    item = newItem;
}

void LinkedNode::setNext(LinkedNode* newNext){
    next = newNext;
}
