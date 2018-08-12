// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	myData = data;
	next = nullptr;
	prev = nullptr;
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
	if (oldPrev != nullptr) {
		prev->prev = oldPrev;
		oldPrev->next = prev;
	}
  return prev;
}

Node* Node::InsertNextNode(char data) {
	Node* oldNext = next;
	next = new Node(data);
	next->prev = this;
	if (oldNext != nullptr) {
		next->next = oldNext;
		oldNext->prev = next;
	}
  return next;
}

bool Node::ErasePreviousNode() {
	if (prev == nullptr) {
		return false;
	}
	Node* secondPrev = prev->prev;
	delete prev;
	if (secondPrev == nullptr) {
		prev = nullptr;
	} else {
		prev = secondPrev;
		secondPrev->next = this;
	}
  return true;
}

bool Node::EraseNextNode() {
	if (next == nullptr) {
		return false;
	}
	Node* secondNext = next->next;
	delete next;
	if (secondNext == nullptr) {
		next = nullptr;
	} else {
		next = secondNext;
		secondNext->prev = this;
	}
  return true;
}
