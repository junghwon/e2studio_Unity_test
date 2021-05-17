#ifdef UNIT_TEST

#include "../unity/unity_fixture.h"
#include "../rangeCookModelClass.h"


// テストグループを定義
TEST_GROUP(TestRangeCookModel);

static rangeCookModel_t mocRangeCookModel = {
	state_standby,
	0,
	&cookManager,
	&cookStart,
	&getCookTimer,
};

// 各テストケースの前に実行する共通処理(初期化)
TEST_SETUP(TestRangeCookModel)
{
	mocRangeCookModel.state = state_standby;
	mocRangeCookModel.cookTimer = 0;
}

// 各テストケースの後に実行する共通処理(後片付け)
TEST_TEAR_DOWN(TestRangeCookModel)
{
}

// テストケース
TEST(TestRangeCookModel, cookStart)
{
	mocRangeCookModel.cookTimer = 10;

	cookStart (&mocRangeCookModel, watt_500, mocRangeCookModel.cookTimer);
	TEST_ASSERT_EQUAL (state_cook, mocRangeCookModel.state);
	TEST_ASSERT_EQUAL (10, mocRangeCookModel.cookTimer);
}

TEST(TestRangeCookModel, stateCook1)
{
	mocRangeCookModel.cookTimer = 1;
	stateCook (&mocRangeCookModel, watt_500, mocRangeCookModel.cookTimer);
	TEST_ASSERT_NOT_EQUAL (state_end, mocRangeCookModel.state);
}

TEST(TestRangeCookModel, stateCook2)
{
	stateCook (&mocRangeCookModel, watt_500, mocRangeCookModel.cookTimer);
	TEST_ASSERT_EQUAL (state_end, mocRangeCookModel.state);
}

// テストグループで、実行するテストケースを列挙する
TEST_GROUP_RUNNER(TestRangeCookModel)
{
    RUN_TEST_CASE(TestRangeCookModel, stateCook1);
    RUN_TEST_CASE(TestRangeCookModel, stateCook2);
    RUN_TEST_CASE(TestRangeCookModel, cookStart);
}

#endif // UNIT_TEST
