// Copyright 2018 Minkyu Jo

#include "node.h"
#include "node_test.h"
#include "test.h"

class NodeConstructorTestSuite
{
private:
  static void SingleNodeTest() {
	//std::cout << "NodeConstructorTestSuite : SingleNodeTest start..." << std::endl;
    Node *node = new Node('A');
    EXPECT_EQ(node->GetData(), 'A');
    delete node;
  }

public:
  static void RunTest() {
    SingleNodeTest();
  }
};

class SomeOtherTestSuite
{
private:
	static void InsertPreviousNodeTest() {
		//std::cout << "SomeOtherTestSuite : InsertPreviousNodeTest start..." << std::endl;
		Node* node = new Node('A');
		Node* node1 = node->InsertPreviousNode('B');

		Node* prev = node->GetPreviousNode();
		EXPECT_EQ(prev->GetData(), 'B');
		delete node;
		delete node1;
	}
	static void InsertSecondPreviousNodeTest() {
		//std::cout << "SomeOtherTestSuite : InsertSecondPreviousNodeTest start..." << std::endl;
		Node* node = new Node('A');
		Node* node1 = node->InsertPreviousNode('B');
		Node* node2 = node->InsertPreviousNode('C');

		Node* prev = node->GetPreviousNode();
		EXPECT_EQ(prev->GetData(), 'C');
		delete node;
		delete node1;
		delete node2;
	}
	static void GetPreviousNodeTest() {
		//std::cout << "SomeOtherTestSuite : GetPreviousNodeTest start..." << std::endl;
		Node* node = new Node('A');
		node->InsertPreviousNode('B');
		Node* prev = node->GetPreviousNode();
		EXPECT_EQ(prev->GetData(), 'B');
		delete node;
		delete prev;
	}
	static void GetPreviousNodeForNullTest() {
		//std::cout << "SomeOtherTestSuite : GetPreviousNodeForNullTest start..." << std::endl;
		Node* node = new Node('A');
		EXPECT_TRUE(node->GetPreviousNode() == nullptr);
		delete node;
	}
	static void InsertNextNodeTest() {
		//std::cout << "SomeOtherTestSuite : InsertNextNodeTest start..." << std::endl;
		Node* node = new Node('A');
		Node* node1 = node->InsertNextNode('B');

		Node* next = node->GetNextNode();
		EXPECT_EQ(next->GetData(), 'B');
		delete node;
		delete node1;
	}
	static void InsertSecondNextNodeTest() {
		//std::cout << "SomeOtherTestSuite : InsertSecondNextNodeTest start..." << std::endl;
		Node* node = new Node('A');
		Node* node1 = node->InsertNextNode('B');
		Node* node2 = node->InsertNextNode('C');

		Node* next = node->GetNextNode();
		EXPECT_EQ(next->GetData(), 'C');
		delete node;
		delete node1;
		delete node2;
	}
	static void GetNextNodeTest() {
		//std::cout << "SomeOtherTestSuite : GetNextNodeTest start..." << std::endl;
		Node* node = new Node('A');
		node->InsertNextNode('B');
		Node* next = node->GetNextNode();
		EXPECT_EQ(next->GetData(), 'B');
		delete node;
		delete next;
	}
	static void GetNextNodeTestForNullTest() {
		//std::cout << "SomeOtherTestSuite : GetNextNodeTestForNullTest start..." << std::endl;
		Node* node = new Node('A');
		EXPECT_TRUE(node->GetNextNode() == nullptr);
		delete node;
	}
	static void ErasePreviousNodeTest() {
		//std::cout << "SomeOtherTestSuite : ErasePreviousNodeTest start..." << std::endl;
		Node* node = new Node('A');
		node->InsertPreviousNode('B');
		EXPECT_TRUE(node->ErasePreviousNode());
		delete node;
	}
	static void EraseSecondPreviousNodeTest() {
		//std::cout << "SomeOtherTestSuite : EraseSecondPreviousNodeTest start..." << std::endl;
		Node* node = new Node('A');
		Node* node1 = node->InsertPreviousNode('B');
		node->InsertPreviousNode('C');
		EXPECT_TRUE(node->ErasePreviousNode());
		delete node;
		delete node1;
	}
	static void ErasePreviousNodeForNullTest() {
		//std::cout << "SomeOtherTestSuite : ErasePreviousNodeForNullTest start..." << std::endl;
		Node* node = new Node('A');
		EXPECT_FALSE(node->ErasePreviousNode());
		delete node;
	}
	static void EraseNextNodeTest() {
		//std::cout << "SomeOtherTestSuite : EraseNextNodeTest start..." << std::endl;
		Node* node = new Node('A');
		node->InsertNextNode('B');
		EXPECT_TRUE(node->EraseNextNode());
		delete node;
	}
	static void EraseSecondNextNodeTest() {
		//std::cout << "SomeOtherTestSuite : EraseSecondNextNodeTest start..." << std::endl;
		Node* node = new Node('A');
		Node* node1 = node->InsertNextNode('B');
		node->InsertNextNode('C');
		EXPECT_TRUE(node->EraseNextNode());
		delete node;
		delete node1;
	}
	static void EraseNextNodeForNullTest() {
		//std::cout << "SomeOtherTestSuite : EraseNextNodeForNullTest start..." << std::endl;
		Node* node = new Node('A');
		EXPECT_FALSE(node->EraseNextNode());
		delete node;
	}
public:
  static void RunTest() {
	  InsertPreviousNodeTest();
	  InsertSecondPreviousNodeTest();
	  GetPreviousNodeTest();
	  GetPreviousNodeForNullTest();
	  InsertNextNodeTest();
	  InsertSecondNextNodeTest();
	  GetNextNodeTest();
	  GetNextNodeTestForNullTest();
	  ErasePreviousNodeTest();
	  EraseSecondPreviousNodeTest();
	  ErasePreviousNodeForNullTest();
	  EraseNextNodeTest();
	  EraseSecondNextNodeTest();
	  EraseNextNodeForNullTest();
  }
};

void NodeTest() {
  NodeConstructorTestSuite::RunTest();
  SomeOtherTestSuite::RunTest();
}

/*
int main() {
	
	NodeTest();
	while (true) {

	}
}
*/
