// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	cursor = new Node('\0');
  return;
}

void TypingMachine::HomeKey() {
	Node* start = cursor;
	Node* prev = cursor->GetPreviousNode();
	while (start->GetPreviousNode() != nullptr) {
		start = start->GetPreviousNode();
	}
	if (prev != nullptr) {
		cursor = start->InsertPreviousNode(cursor->GetData());
		prev->EraseNextNode();
	}
  return;
}

void TypingMachine::EndKey() {
	Node* end = cursor;
	Node* next = cursor->GetNextNode();
	while (end->GetNextNode() != nullptr) {
		end = end->GetNextNode();
	}
	if (next != nullptr) {
		cursor = end->InsertNextNode(cursor->GetData());
		next->ErasePreviousNode();
	}
  return;
}

void TypingMachine::LeftKey() {
	Node* prev = cursor->GetPreviousNode();
	if (prev == nullptr) {
		return;
	}
	char data = prev->GetData();
	cursor->InsertNextNode(data);
	cursor->ErasePreviousNode();
  return;
}

void TypingMachine::RightKey() {
	Node* next = cursor->GetNextNode();
	if (next == nullptr) {
		return;
	}
	char data = next->GetData();
	cursor->InsertPreviousNode(data);
	cursor->EraseNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {
	if (!IsMaxLength()) {
		return false;
	}
	if (32 <= key && key <= 126) {
		cursor->InsertPreviousNode(key);
		return true;
	} else {
		return false;
	}
}

bool TypingMachine::EraseKey() {
	return cursor->ErasePreviousNode();
}

bool TypingMachine::IsMaxLength() {
	Node* start = cursor->GetPreviousNode();
	int leftLength = 0;
	while (start != nullptr) {
		leftLength++;
		start = start->GetPreviousNode();
	}

	Node* end = cursor->GetNextNode();
	int rightLength = 0;
	while (end != nullptr) {
		rightLength++;
		end = end->GetNextNode();
	}

	if ((leftLength + rightLength) < 100) {
		return true;
	}
	else {
		return false;
	}
}

std::string TypingMachine::Print(char separator) {
	Node* left = cursor->GetPreviousNode();
	string leftStr = "";
	while (left != nullptr) {
		leftStr = left->GetData() + leftStr;
		left = left->GetPreviousNode();
	}

	Node* right = cursor->GetNextNode();
	string rightStr = "";
	while (right != nullptr) {
		rightStr = rightStr + right->GetData();
		right = right->GetNextNode();
	}
	if (separator == '\0') {
		return leftStr + rightStr;
	}
	else {
		return leftStr + separator + rightStr;
	}
}

