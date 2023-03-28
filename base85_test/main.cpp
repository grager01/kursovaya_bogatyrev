#include <UnitTest++/UnitTest++.h>
#include <../base85/base85.cpp>

SUITE(ConstructFirst)
{
	TEST(EmptyString) {
		CHECK_THROW(Base85 obj("", ""), base85_error);
	}
}

SUITE(ConstructSecond)
{
	TEST(EmptyString) {
		CHECK_THROW(Base85 obj("", ""), base85_error);
	}
}


int main(int argc, char **argv) {
	return UnitTest::RunAllTests();
}
