// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	myData = data;
	next = 0;
	prev = 0;
  return;
}

char Node::GetData() {
  return myData;
}

Node* Node::GetPreviousNode() {
  return prev;
}

Node* Node::GetNextNode() {
  return next;
}

Node* Node::InsertPreviousNode(char data) {
	Node* oldPrev = prev;
	prev = new Node(data);
	prev->next = this;
	if (oldPrev != 0) {
		prev->prev = oldPrev;
		oldPrev->next = prev;
	}
  return prev;
}

Node* Node::InsertNextNode(char data) {
	Node* oldNext = next;
	next = new Node(data);
	next->prev = this;
	if (oldNext != 0) {
		next->next = oldNext;
		oldNext->prev = next;
	}
  return next;
}

bool Node::ErasePreviousNode() {
	if (prev == 0) {
		return false;
	}
	Node* secondPrev = prev->prev;
	delete prev;
	if (secondPrev == 0) {
		prev = 0;
	} else {
		prev = secondPrev;
		secondPrev->next = this;
	}
  return true;
}

bool Node::EraseNextNode() {
	if (next == 0) {
		return false;
	}
	Node* secondNext = next->next;
	delete next;
	if (secondNext == 0) {
		next = 0;
	} else {
		next = secondNext;
		secondNext->prev = this;
	}
  return true;
}
