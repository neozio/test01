// Copyright 2018 Minkyu Jo

#include "typing_machine.h"
#include "typing_machine_test.h"
#include "test.h"

class TmConstructorTestSuite
{
private:
  static void BarSeparatorTest() {
	  //std::cout << "TmConstructorTestSuite : BarSeparatorTest start..." << std::endl;
      TypingMachine tm;
      EXPECT_EQ(tm.Print('|'), std::string("|"));
  }
  static void NullSeparatorTest() {
	  //std::cout << "TmConstructorTestSuite : NullSeparatorTest start..." << std::endl;
	  TypingMachine tm;
	  EXPECT_EQ(tm.Print('\0'), std::string(""));
  }

public:
  static void RunTest() {
    BarSeparatorTest();
	NullSeparatorTest();
    // add more..
  }
};

class TmSomeOtherTestSuite
{
private:
	static void PrintLog(std::string text) {
		//std::cout << "TmSomeOtherTestSuite : " + text + " start..." << std::endl;
	}
	static void TypeKeyTest() {
		PrintLog("TypeKeyTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey(' ');
		tm.TypeKey((char)126);
		EXPECT_EQ(tm.Print('|'), std::string("a ~|"));
	}
	static void Type31KeyTest() {
		PrintLog("Type31KeyTest");
		TypingMachine tm;
		tm.TypeKey(31);
		EXPECT_EQ(tm.Print('|'), std::string("|"));
	}
	static void Type200KeyTest() {
		PrintLog("Type200KeyTest");
		TypingMachine tm;
		tm.TypeKey((char)200);
		EXPECT_EQ(tm.Print('|'), std::string("|"));
	}
	static void Type100CountKeyTest() {
		PrintLog("Type100CountKeyTest");
		TypingMachine tm;
		int keyA = 65; // A ascii code
		int key;
		for (int i = 0; i < 100; i++) {
			key = keyA + i % 10;
			tm.TypeKey(key);
		};
		std::string expected = "ABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJ|";
		EXPECT_EQ(tm.Print('|'), expected);
	}
	static void Type101CountKeyTest() {
		PrintLog("Type101CountKeyTest");
		TypingMachine tm;
		int keyA = 65; // A ascii code
		int key;
		for (int i = 0; i < 101; i++) {
			key = keyA + i % 10;
			tm.TypeKey(key);
		};
		std::string expected = "ABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJ|";
		EXPECT_EQ(tm.Print('|'), expected);
	}
	static void EraseKeyTest() {
		PrintLog("EraseKeyTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.EraseKey();
		EXPECT_EQ(tm.Print('|'), std::string("|"));
	}
	static void Erase100thKeyTest() {
		PrintLog("Erase100thKeyTest");
		TypingMachine tm;
		int keyA = 65; // A ascii code
		int key;
		for (int i = 0; i < 100; i++) {
			key = keyA + i % 10;
			tm.TypeKey(key);
		};
		tm.EraseKey();
		std::string expected = "ABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHI|";
		EXPECT_EQ(tm.Print('|'), expected);
	}
	static void EraseMiddleKeyTest() {
		PrintLog("EraseMiddleKeyTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey(' ');
		tm.TypeKey((char)126);
		tm.LeftKey();
		tm.EraseKey();
		EXPECT_EQ(tm.Print('|'), std::string("a|~"));
	}
	static void EraseNullKeyTest() {
		PrintLog("EraseNullKeyTest");
		TypingMachine tm;
		tm.EraseKey();
		EXPECT_EQ(tm.Print('|'), std::string("|"));
	}
	static void HomeKeyTest() {
		PrintLog("HomeKeyTest");
		TypingMachine tm;
		int keyA = 65; // A ascii code
		int key;
		for (int i = 0; i < 100; i++) {
			key = keyA + i % 10;
			tm.TypeKey(key);
		};
		tm.HomeKey();
		std::string expected = "|ABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJ";
		EXPECT_EQ(tm.Print('|'), expected);
	}
	static void HomeKeyFromHomeTest() {
		PrintLog("HomeKeyFromHomeTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey(' ');
		tm.TypeKey((char)126);
		tm.HomeKey();
		tm.HomeKey();
		EXPECT_EQ(tm.Print('|'), std::string("|a ~"));
	}
	static void HomeKeyFromMiddleTest() {
		PrintLog("HomeKeyFromMiddleTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey(' ');
		tm.TypeKey((char)126);
		tm.LeftKey();
		tm.HomeKey();
		EXPECT_EQ(tm.Print('|'), std::string("|a ~"));
	}
	static void HomeKeyAtOnlyCursorTest() {
		PrintLog("HomeKeyAtOnlyCursorTest");
		TypingMachine tm;
		tm.HomeKey();
		EXPECT_EQ(tm.Print('|'), std::string("|"));
	}
	static void EndKeyTest() {
		PrintLog("EndKeyTest");
		TypingMachine tm;
		int keyA = 65; // A ascii code
		int key;
		for (int i = 0; i < 100; i++) {
			key = keyA + i % 10;
			tm.TypeKey(key);
		};
		tm.HomeKey();
		tm.EndKey();
		std::string expected = "ABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJABCDEFGHIJ|";
		EXPECT_EQ(tm.Print('|'), expected);
	}
	static void EndKeyFromEndTest() {
		PrintLog("EndKeyFromEndTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey(' ');
		tm.TypeKey((char)126);
		tm.EndKey();
		tm.EndKey();
		EXPECT_EQ(tm.Print('|'), std::string("a ~|"));
	}
	static void EndKeyFromMiddleTest() {
		PrintLog("EndKeyFromMiddleTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey(' ');
		tm.TypeKey((char)126);
		tm.LeftKey();
		tm.EndKey();
		EXPECT_EQ(tm.Print('|'), std::string("a ~|"));
	}
	static void EndKeyAtOnlyCursorTest() {
		PrintLog("EndKeyAtOnlyCursorTest");
		TypingMachine tm;
		tm.EndKey();
		EXPECT_EQ(tm.Print('|'), std::string("|"));
	}
	static void LeftKeyTest() {
		PrintLog("LeftKeyTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.LeftKey();
		EXPECT_EQ(tm.Print('|'), std::string("|a"));
	}
	static void LeftKeyFromMiddleTest() {
		PrintLog("LeftKeyFromMiddleTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey(' ');
		tm.TypeKey((char)126);
		tm.LeftKey();
		tm.LeftKey();
		EXPECT_EQ(tm.Print('|'), std::string("a| ~"));
	}
	static void LeftKeyFromHomeTest() {
		PrintLog("LeftKeyFromHomeTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey((char)126);
		tm.LeftKey();
		tm.LeftKey();
		tm.LeftKey();
		EXPECT_EQ(tm.Print('|'), std::string("|a~"));
	}
	static void LeftKeyAtOnlyCursorTest() {
		PrintLog("LeftKeyAtOnlyCursorTest");
		TypingMachine tm;
		tm.LeftKey();
		EXPECT_EQ(tm.Print('|'), std::string("|"));
	}
	static void RightKeyTest() {
		PrintLog("RightKeyTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey(' ');
		tm.TypeKey((char)126);
		tm.LeftKey();
		tm.LeftKey();
		tm.RightKey();
		EXPECT_EQ(tm.Print('|'), std::string("a |~"));
	}
	static void RightKeyFromHomeTest() {
		PrintLog("RightKeyFromHomeTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey(' ');
		tm.TypeKey((char)126);
		tm.HomeKey();
		tm.RightKey();
		EXPECT_EQ(tm.Print('|'), std::string("a| ~"));
	}
	static void RightKeyFromEndTest() {
		PrintLog("RightKeyFromEndTest");
		TypingMachine tm;
		tm.TypeKey('a');
		tm.TypeKey((char)126);
		tm.EndKey();
		tm.RightKey();;
		EXPECT_EQ(tm.Print('|'), std::string("a~|"));
	}
	static void RightKeyAtOnlyCursorTest() {
		PrintLog("RightKeyAtOnlyCursorTest");
		TypingMachine tm;
		tm.RightKey();;
		EXPECT_EQ(tm.Print('|'), std::string("|"));
	}
	
public:
  static void RunTest() {
	  TypeKeyTest();
	  Type31KeyTest();
	  Type200KeyTest();
	  Type100CountKeyTest();
	  Type101CountKeyTest();
	  EraseKeyTest();
	  Erase100thKeyTest();
	  EraseMiddleKeyTest();
	  EraseNullKeyTest();
	  HomeKeyTest();
	  HomeKeyFromHomeTest();
	  HomeKeyFromMiddleTest();
	  HomeKeyAtOnlyCursorTest();
	  EndKeyTest();
	  EndKeyFromEndTest();
	  EndKeyFromMiddleTest();
	  EndKeyAtOnlyCursorTest();
	  LeftKeyTest();
	  LeftKeyFromMiddleTest();
	  LeftKeyFromHomeTest();
	  LeftKeyAtOnlyCursorTest();
	  RightKeyTest();
	  RightKeyFromHomeTest();
	  RightKeyFromEndTest();
	  RightKeyAtOnlyCursorTest();
  }
};

void TypingMachineTest() {
  TmConstructorTestSuite::RunTest();
  TmSomeOtherTestSuite::RunTest();
}

/*
int main() {

	TypingMachineTest();
	while (true) {

	}
}
*/
