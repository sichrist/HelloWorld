#include "testheader.h"

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
	EXPECT_EQ(x,num.getNum());
}