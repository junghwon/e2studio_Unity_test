#include "../unity/unity_fixture.h"
#include "../source.h"


// テストグループを定義
TEST_GROUP(Test0);

// 各テストケースの前に実行する共通処理(初期化)
TEST_SETUP(Test0)
{
}

// 各テストケースの後に実行する共通処理(後片付け)
TEST_TEAR_DOWN(Test0)
{
}

// テストケース
TEST(Test0, addTest)
{
	TEST_ASSERT_EQUAL(10, add(9, 1));
}

TEST(Test0, subTest)
{
	TEST_ASSERT_EQUAL(7, subtract(8, 1));
}

// テストグループで、実行するテストケースを列挙する
TEST_GROUP_RUNNER(Test0)
{
    RUN_TEST_CASE(Test0, addTest);
    RUN_TEST_CASE(Test0, subTest);
}
