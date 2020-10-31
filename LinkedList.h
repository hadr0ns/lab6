#pragma once
#include <string>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>
class LinkedList: public LinkedListInterface<T>
{

public:

	LinkedList(void) {};
	~LinkedList(void) {};

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value){
		if (head != NULL) {
			if (find(value)){
				return;
			}
		}
		Node* toAdd = new Node();
		toAdd->data = value;
		toAdd->next = NULL;
		if (head == NULL){
			head = toAdd;
			head->data = toAdd->data;
			head->next = NULL;
			//delete toAdd;
			return;
		} else {
			Node* temp = head;
			head = toAdd;
			head->data = toAdd->data;
			head->next = temp;
		}
	};

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value){
		if (find(value)){
			return;
		}
		Node* temp;
		if (head == NULL){
			insertHead(value);
			return;
		}
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		Node* toAdd = new Node();
		toAdd->data = value;
		toAdd->next = NULL;
		temp->next = toAdd;

	};

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode){
		if (head == NULL){
			return;
		} else if (find(value)){
			return;
		} else if (!find(insertionNode)){
			return;
		} else {
			Node* temp = head;
			while (temp->data != insertionNode){
				temp = temp->next;
			}
			Node* after = temp->next;
			Node* toAdd = new Node();
			toAdd->data = value;
			toAdd->next = after;
			temp->next = toAdd;

		}
	};

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value){
		if (head == NULL) {
			return;
		}
		if (!find(value)) {
			return;
		}
		Node* temp = head;
		if (temp->data == value){
			head = temp->next;
			delete temp;
			return;
		}
		while (temp->next->data != value){
			temp = temp->next;
		}
		Node* previous = temp;
		temp = temp->next;
		Node* after = temp->next;
		previous->next = after;
		delete temp;
	};

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear(){
		if (head != NULL){
			while (head !=NULL){
				Node* temp = head;
				head = head->next;
				remove(temp->data);
			}
		}
	};

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index){
		if (head !=NULL){
			int trackIndex=0;
			Node* track = head;
			while (track->next !=NULL){
				if (trackIndex == index){
					return track->data;
				} else {
					track = track->next;
					trackIndex++;
				}
			}
			if (trackIndex == index) {
				return track->data;
			} else {
				throw out_of_range("");
			}
		} else {
			throw out_of_range("");
		}
	};

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size(){
		if (head==NULL){
			return 0;
		} else {
			int track = 0;
			Node* temp;
			temp = head;
			track = 1;
			while (temp->next != NULL){
				temp = temp->next;
				track++;
			}
			return track;
		}
	};

	/*
	toString

	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString(){
		if (head !=NULL){
			string list;
			Node* temp = head;
			while (temp->next != NULL){
				string temporary;
				stringstream ss;
				ss << temp->data;
				ss >> temporary;
				list = list + temporary + " ";
				//cout << list<< endl;
				temp = temp->next;
			}
			stringstream ss2;
			ss2 << temp->data;
			string temp2;
			ss2 >> temp2;
			list += temp2;
			return list;

		} else {
			return "";
		}
	};

	bool find(T value){
		if (head !=NULL){
			Node* temp = head;
			while (temp != NULL){
				if (temp->data == value){
					return true;
				}
				temp = temp->next;
			}
			return false;
		} else {
			return false;
		}
	};

private:
	struct Node{
		T data;
		Node* next;
	};
	Node* head;

};
