#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "Node.hpp"

using namespace std;

template <class T>
class LinkedList {
private:
  /* pointer to the first node */
  Node<T>* front;
  /* pointer to the last node */
  Node<T>* back;

  size_t length;

public:
  /*** Do not modify the interface ***/

  LinkedList();
  LinkedList(const LinkedList<T>& ll);
  LinkedList<T>& operator=(const LinkedList<T>& ll);
  ~LinkedList();

  /* returns the first node of the linked list */
  Node<T>& getFront() const;
  /* returns the last node of the linked list */
  Node<T>& getBack() const;
  /* returns the node in given "pos"ition of the linked list */
  Node<T>& getNodeAt(int pos) const;
  /* returns the pointer of the node in given
  "pos"ition of the linked list */
  Node<T>* getNodePtrAt(int pos) const;

  /* inserts a new node containing "data"
  after the node "prev"
  */
  void insert(Node<T>* prev, const T& data);
  /* inserts a new node containing "data"
  at "pos"ition in the linked list
  */
  void insertAt(int pos, const T& data);
  /* erases the given "node" from the linked list */
  void erase(Node<T>* node);
  /* erases the node in given "pos"ition from the linked list */
  void eraseFrom(int pos);
  /* clears the contents of the linked list */
  void clear();

  /* inserts a new node containing "data"
  to the front of the linked list
  */
  void pushFront(const T& data);
  /* inserts a new node containing "data"
  to the back of the linked list
  */
  void pushBack(const T& data);

  /* removes the first node */
  void popFront();
  /* removes the last node */
  void popBack();

  /* returns true if the list is empty, false otherwise */
  bool isEmpty() const;
  /* returns the number of items in the list */
  size_t getSize() const;
  /* prints the contents of the linked list
  one node data per line
  assumes the objects in the node have operator<< overloaded
  */
  void print() const;

  /*** Do not modify the interface ***/
};

/* TO-DO: method implementations here */

template <class T>
LinkedList<T>::LinkedList() {
  front = NULL;
  back = NULL;
  length = 0;
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll) {
     Node<T>* r = &ll.getFront();
    length++;
    Node<T> *newNode = new Node<T>;
    newNode->setData(r->getData());
    newNode->setNext(NULL);
    newNode->setPrev(NULL);
    front = back = newNode;
    //this->pushback(r->getData());
    r = r->getNext();
    while (r) {
        length++;
          newNode = new Node<T>;
        newNode->setData(r->getData());
        newNode->setNext(NULL);
        newNode->setPrev(back);
        back->setNext(newNode);
        back = newNode;
      //pushBack(r->getData());
      r = r->getNext();
    }
  }

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll) {
  if (this != &ll) {
    clear();
    Node<T>* r = &ll.getFront();
    length++;
    Node<T> *newNode = new Node<T>;
    newNode->setData(r->getData());
    newNode->setNext(NULL);
    newNode->setPrev(NULL);
    front = back = newNode;
    //this->pushback(r->getData());
    r = r->getNext();
    while (r) {
        length++;
          newNode = new Node<T>;
        newNode->setData(r->getData());
        newNode->setNext(NULL);
        newNode->setPrev(back);
        back->setNext(newNode);
        back = newNode;
      //pushBack(r->getData());
      r = r->getNext();
    }
  }
  return *this;
  
}

template <class T>
LinkedList<T>::~LinkedList() {
  clear();
  delete front;
  delete back;
}


template <class T>
Node<T>& LinkedList<T>::getFront() const {
  return *front;
}

template <class T>
Node<T>& LinkedList<T>::getBack() const {
  return *back;
}

template <class T>
Node<T>& LinkedList<T>::getNodeAt(int pos) const {
  return *getNodePtrAt(pos);
}

template <class T>
Node<T>* LinkedList<T>::getNodePtrAt(int pos) const {
  Node<T> *getnode = front;
  if(pos < 0 || pos >= length)
    throw out_of_range("invalid index");
  else {
    for (int i = 0; i<pos; i++) {
      getnode = getnode->getNext();
    }
  }
  return getnode;
}

template <class T>
void LinkedList<T>::insert(Node<T>* prev, const T& data) {
  length++;
  if (isEmpty()) {
    Node<T> *newNode = new Node<T>;
    newNode->setPrev(NULL);
    newNode->setNext(NULL);
    newNode->setData(data);
    front = back = newNode;
  }
  else {
    Node<T> *newNode = new Node<T>;
    newNode->setData(data);
    newNode->setPrev(prev);
    newNode->setNext(prev->getNext());
    newNode->getPrev()->setNext(newNode);
    newNode->getNext()->setPrev(newNode);
    if(prev == back){
      back = newNode;
    }
  }
}


template <class T>
void LinkedList<T>::insertAt(int pos, const T& data) {
  if(isEmpty() || pos >= length){
    pushBack(data);
    return;
  }
  else if (pos == 0) {
    pushFront(data);
    return;
  }
  Node<T> *oldNode = getNodePtrAt(pos - 1);
  Node<T> *newNode = new Node<T>;
  newNode->setData(data);
  newNode->setPrev(oldNode);
  newNode->setNext(oldNode->getNext());
  newNode->getPrev()->setNext(newNode);
  newNode->getNext()->setPrev(newNode);
  length++;
}

template <class T>
void LinkedList<T>::erase(Node<T>* node) {
  if( front == node){
    front = node->getNext();
    node->setNext(NULL);
    front->setPrev(NULL);
  }
  if ( back == node){
    back = node -> getPrev();
    node->setPrev(NULL);
    back->setNext(NULL);
  }
  else{
    node->getPrev()->setNext(node->getNext());
    node->getNext()->setPrev(node->getPrev());
  }
  delete node;
  length--;
}

template <class T>
void LinkedList<T>::eraseFrom(int pos) {
  Node<T> *removedNode = getNodePtrAt(pos);
  erase(removedNode);
}

template <class T>
void LinkedList<T>::clear() {
  while (!isEmpty()) {
    length--;
    Node<T> *removedNode = front;
    front = front->getNext();
    if (front)
      front->setPrev(NULL);
    else
      front = back = NULL;
    removedNode->setNext(NULL);
    delete removedNode;
  }
  return;
}

template <class T>
void LinkedList<T>::pushFront(const T& data) {
  length++;
  Node<T> *newNode = new Node<T>;

  if (isEmpty()) {
    newNode->setData(data);
    newNode->setNext(NULL);
    newNode->setPrev(NULL);
    front = back = newNode;
  }
  else {
    newNode->setData(data);
    newNode->setNext(front);
    newNode->setPrev(NULL);
    front->setPrev(newNode);
    front = newNode;
  }
}

template <class T>
void LinkedList<T>::pushBack(const T& data) {
  length++;
  Node<T> *newNode = new Node<T>;

  if (isEmpty()) {
    newNode->setData(data);
    newNode->setNext(NULL);
    newNode->setPrev(NULL);
    front = back = newNode;
  }
  else {
    newNode->setData(data);
    newNode->setNext(NULL);
    newNode->setPrev(back);
    back->setNext(newNode);
    back = newNode;
  }
}

template <class T>
void LinkedList<T>::popFront() {
  if (isEmpty())
    return;
  length--;
  Node<T> *removedNode = front;
  front = front->getNext();
  if (front) {
    front->setPrev(NULL);
    removedNode->setNext(NULL);
  }
  else
    front = back = NULL;
  delete removedNode;
  return;
}

template <class T>
void LinkedList<T>::popBack() {
  if (isEmpty())
    return;
  length--;
  Node<T> *removedNode = back;
  back = back->getPrev();
  if (back) {
    back->setNext(NULL);
    removedNode->setPrev(NULL);
  }
  else
    front = back = NULL;
  delete removedNode;
  return;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
  return (front == NULL && back == NULL);
}

template <class T>
size_t LinkedList<T>::getSize() const {
  return length;
}



template <class T>
void LinkedList<T>::print() const {
  if (isEmpty())
    return;

  Node<T> *head = front;
  while (head) {
    std::cout << head->getData() << endl;
    head = head->getNext();
  }
}



#endif
