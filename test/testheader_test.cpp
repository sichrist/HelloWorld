#include "testheader.h"
#include "gtest/gtest.h"

class TestHeaderTest : public::testing::Test {
protected:
	virtual void SetUp() {

	}

	virtual void TearDown() {

	}

};

TEST_F(TestHeaderTest,getNum){
	const int x = 4;
	Num num = Num(x);
	Num num1 = Num();
	EXPECT_EQ(x,num.getNum());
	EXPECT_EQ(0,num1.getNum());
}

	