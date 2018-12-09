//
// Created by Ryan King on 12/9/18.
//

#include "SongLinked.h"

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

void SongLinked::addAlphabetical(Song* songToAdd){
    if(currItemCount == 0) {
        insertAt(songToAdd, 0);
    }
    else{
        for(int x=0; x<currItemCount; x++){
            if (songToAdd->getTitle().compare(array[x]->getTitle())<0){
                insertAt(songToAdd,x);
            }
        }
    }
    currItemCount++;
}
//Possibly get rid of this function below
//_______________________REVISIT THIS!!!!!_________________________________________________________

void SongLinked::addSong(Song* songToAdd){
    addAlphabetical(songToAdd);
}


std::string SongLinked::toString(){
    if (currItemCount < 1) {
        return "{}";
    }
    std::string text = "{";
    LinkedNode* nextptr = front;
    for (int x = 0; x <= currItemCount - 1; x++) {
        text += std::to_string(nextptr->getItem());
        if (x < currItemCount - 1) {
            text += ", ";
        }
        nextptr=nextptr->getNext();
    }
    // nextptr= nullptr;
    text += "}";
    // std::cout<<text<<std::endl;
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






















/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
//O(1) always the same thing because the linkedlist has an end value
void SongLinked::insertAtEnd(int itemToAdd){
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

//O(n) gets bigger as the size of the list gets bigger
int SongLinked::getValueAt(int index){
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





//FIX THIS !!!!!!!!!!!

//O(n) it is proportional to the size of the LinkedList
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

    if (artistExists==true){
        return artist;
    }
    else{
        return "{}";
    }
}





/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
//O(1) pretty consistent because we know where the front is
void SongLinked::insertAtFront(int itemToAdd){
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


/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
//O(1) it is the same every time because we have the end location
int SongLinked::removeValueAtEnd(){
    if (isEmpty()){
        throw std::out_of_range("LinkedList is Empty");
    }
    else if(front==end||currItemCount<=1){
        int returnitem = end->getItem();
        delete front;
        front= nullptr;
        end= nullptr;
        currItemCount-=1;
        return returnitem;
    }
    else{
        int returnitem = end->getItem();
        LinkedNode* nextptr = front;
        for(int i=0; i<currItemCount-2;i++){
            nextptr=nextptr->getNext();
        }
        delete end;
        currItemCount-=1;
        end=nextptr;
        end->setNext(nullptr);
        //std::cout<< end->getItem() << " "<<currItemCount<< nextptr<< " "<<nextptr->getNext()<< std::endl;
        return returnitem;
    }
}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
//O(1) it is the same every time because we have the front location
int SongLinked::removeValueAtFront(){
    if (isEmpty()){
        throw std::out_of_range("LinkedList is Empty");
    }
    else {
        int returnItem = front->getItem();
        LinkedNode* nextptr = front->getNext();
        delete front;
        front=nextptr;
        currItemCount-=1;
        return returnItem;
    }
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
//O(n) - because there's only one loop
int SongLinked::removeValueAt(int index){
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

        int returnItem =next->getNext()->getItem();

        LinkedNode *deleteNode = next->getNext();
        next->setNext(next->getNext()->getNext());
        delete deleteNode;
        currItemCount-=1;
        return returnItem;
    }
}
