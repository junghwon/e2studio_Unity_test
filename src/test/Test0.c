#include "../unity/unity_fixture.h"
#include "../source.h"
#include "../rangeControllerClass.h"


rangeController_t mocInit = {
	watt_300,
	1,
	&rangeControllerStart,
	&rangeControllerStop,
};



// テストグループを定義
TEST_GROUP(Test0);

// 各テストケースの前に実行する共通処理(初期化)
TEST_SETUP(Test0)
{
	mocInit.pStop (&mocInit);
}

// 各テストケースの後に実行する共通処理(後片付け)
TEST_TEAR_DOWN(Test0)
{
}

// テストケース
TEST(Test0, AlwaysFail)
{
    // 何もせず、テストを失敗させて、メッセージを出力する
    TEST_FAIL_MESSAGE("This test always fails.");
}

// honjoテストケース
TEST(Test0, addTest)
{
	TEST_ASSERT_EQUAL(9, add(1, 8));
}

TEST(Test0, subTest)
{
	TEST_ASSERT_EQUAL(7, subtract(8, 1));
}

TEST(Test0, rangeController_stop)
{
	TEST_ASSERT_EQUAL(0, mocInit.timer);
	TEST_ASSERT_EQUAL(watt_500, mocInit.watt);
}

// テストグループで、実行するテストケースを列挙する
TEST_GROUP_RUNNER(Test0)
{
//    RUN_TEST_CASE(Test0, AlwaysFail);
//    RUN_TEST_CASE(Test0, addTest);
//    RUN_TEST_CASE(Test0, subTest);
    RUN_TEST_CASE(Test0, rangeController_stop);
}
