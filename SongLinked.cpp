//
// Created by Ryan King on 12/9/18.
//

#include "SongLinked.h"
#include "LinkedNode.h"
#include "Playlist.h"


SongLinked::SongLinked(){
    front = nullptr;
    end = nullptr;
    currItemCount=0;
}

//Destructor
SongLinked::~SongLinked(){
    LinkedNode *next = front;
    LinkedNode *after = front;
    while(next!= nullptr){
        after=next->getNext();
        delete next;
        next=after;
    }
}

void SongLinked::insertAt(Song* itemToAdd, int index){
    if(index<0||index>currItemCount){
        throw std::out_of_range("Index is invalid");
    }

    //linked node to be templated
    LinkedNode* adder = new LinkedNode(itemToAdd);
    if(front== nullptr){
        front = adder;
        end = adder;
        front->setNext(nullptr);
        currItemCount+=1;
    }
    else if(index==0){
        insertAtFront(itemToAdd);
        delete adder;
    }
    else if(index==currItemCount){
        insertAtEnd(itemToAdd);
        delete adder;
    }
    else {
        LinkedNode *next = front;
        for (int x = 0; x < index-1; x++) {
            next = next->getNext();
        }
        adder->setNext(next->getNext());
        next->setNext(adder);
        currItemCount+=1;
    }
}

void SongLinked::insertAtFront(Song* itemToAdd){
    LinkedNode* next = new LinkedNode(itemToAdd);
    if(front== nullptr){
        front = next;
        end = next;
        front->setNext(nullptr);
        currItemCount+=1;
    }
    else {
        next->setNext(front);
        front = next;
        currItemCount+=1;
    }
}

void SongLinked::insertAtEnd(Song* itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    //if front is nullptr, end should be nullptr too
    if (isEmpty()||front == nullptr){
        newNode->setNext(nullptr);
        front = newNode;
        end = newNode;
        currItemCount+=1;
    }
    else {
        end->setNext(newNode);
        end = newNode;
        end->setNext(nullptr);
        currItemCount+=1;
    }
}

Song* SongLinked::removeValueAtEnd(){
    if (isEmpty()){
        throw std::out_of_range("LinkedList is Empty");
    }
    else if(front==end||currItemCount<=1){
        Song* returnitem = end->getItem();
        delete front;
        front= nullptr;
        end= nullptr;
        currItemCount-=1;
        return returnitem;
    }
    else{
        Song* returnitem = end->getItem();
        LinkedNode* nextptr = front;
        for(int i=0; i<currItemCount-2;i++){
            nextptr=nextptr->getNext();
        }
        delete end;
        currItemCount-=1;
        end=nextptr;
        end->setNext(nullptr);
        return returnitem;
    }
}

void SongLinked::addSong(Song* songToAdd){
    insertAtEnd(songToAdd);
}

Song* SongLinked::findSong(std::string title, std::string artist){
    LinkedNode* count=front;
    for(int i = 0; i < currItemCount; i++){
        if(title == count->getItem()->getTitle() && artist == count->getItem()->getArtist()){
            return count->getItem();
        }
        count=count->getNext();

    }
    if(front== nullptr){
        throw std::invalid_argument("Could not find the given song");
    }
    return nullptr;
}

void SongLinked::removeSong(std::string title, std::string artist){
    LinkedNode*  count=front;
    for(int i = 0; i < currItemCount; i++){
        if(title == count->getItem()->getTitle() && artist == count->getItem()->getArtist()){
            removeValueAt(i);
        }
        count=count->getNext();

    }
    if(front== nullptr){
        throw std::invalid_argument("Could not find the given song");
    }
}

std::string SongLinked::toString(){
    if (currItemCount < 1) {
        return "{}";
    }
    std::string text = "";
    LinkedNode* nextptr = front;
    for (int x = 0; x <= currItemCount - 1; x++) {
        text += (nextptr->getItem()->getInfo() + "\n");
        nextptr=nextptr->getNext();
    }
    return text;
}

bool SongLinked::isEmpty(){
    return currItemCount == 0;
}

int SongLinked::itemCount(){
    return currItemCount;
}

void SongLinked::clearList(){
    if(currItemCount>0){
        while(!isEmpty()){
            this->removeValueAtEnd();
        }
    }
}

Song* SongLinked::getValueAt(int index){
    if(index>=currItemCount||front== nullptr||index<0){
        throw std::out_of_range("Index is invalid");
    }
    LinkedNode* nextptr = front;
    if (index==0){
        return nextptr->getItem();
    }
    for (int i=0; i<index; i++){
        nextptr=nextptr->getNext();
    }
    return nextptr->getItem();
}

std::string SongLinked::findArtist(std::string artist){
    LinkedNode*  count=front;
    bool artistExists=false;
    std::string artists = "{";
    for(int x=0;x<currItemCount;x++){
        if(count->getItem()->getArtist()==artist){
            artistExists=true;
            artists += ", ";
            artists += count->getItem()->getTitle();
        }
        count=count->getNext();
    }
    artists += "}";

    if (artistExists){
        return artist;
    }
    else{
        return "{}";
    }
}

Song* SongLinked::removeValueAtFront(){
    if (isEmpty()){
        throw std::out_of_range("LinkedList is Empty");
    }
    else {
        Song* returnItem = front->getItem();
        LinkedNode* nextptr = front->getNext();
        delete front;
        front=nextptr;
        currItemCount-=1;
        return returnItem;
    }
}

Song* SongLinked::removeValueAt(int index){
    if(index>=currItemCount){
        throw std::out_of_range("Index is invalid");
    }
    if(index==0){
        return removeValueAtFront();
    } else if (index==currItemCount-1){
        return removeValueAtEnd();
    }
    else {
        LinkedNode *next = front;

        for (int x = 0; x < index-1; x++) {
            next = next->getNext();
        }

        Song* returnItem =next->getNext()->getItem();

        LinkedNode *deleteNode = next->getNext();
        next->setNext(next->getNext()->getNext());
        delete deleteNode;
        currItemCount-=1;
        return returnItem;
    }
}

float SongLinked::calcDuration(){
    float duration;
    LinkedNode* count = front;
    for(int i = 0; i < currItemCount; i++){
        duration += count->getItem()->getDuration();
        count=count->getNext();
    }
    return duration;
}
