#include "../unity/unity_fixture.h"
#include "../source.h"
#include "../rangeCookModelClass.h"


static rangeCookModel_t mocRangeCookModel = {
	state_standby,
	0,
	&cookManager,
	&cookStart,
	&getCookTimer,
};

// テストグループを定義
TEST_GROUP(TestRangeCookModel);

// 各テストケースの前に実行する共通処理(初期化)
TEST_SETUP(TestRangeCookModel)
{
}

// 各テストケースの後に実行する共通処理(後片付け)
TEST_TEAR_DOWN(TestRangeCookModel)
{
}

// テストケース
TEST(TestRangeCookModel, stateStart)
{
	mocRangeCookModel.state = state_standby;
	mocRangeCookModel.cookTimer = 0;

	cookStart (&mocRangeCookModel, watt_500, 10);

	TEST_ASSERT_EQUAL (state_cook, mocRangeCookModel.state);
	TEST_ASSERT_EQUAL (10, mocRangeCookModel.cookTimer);

	TEST_ASSERT_NOT_EQUAL (state_standby, mocRangeCookModel.state);
	TEST_ASSERT_NOT_EQUAL (state_end, mocRangeCookModel.state);
	TEST_ASSERT_NOT_EQUAL (0, mocRangeCookModel.cookTimer);

}

TEST(TestRangeCookModel, stateCook)
{
	mocRangeCookModel.cookTimer = 1;
	stateCook (&mocRangeCookModel, watt_500, 0);
	TEST_ASSERT_NOT_EQUAL (state_end, mocRangeCookModel.state);

	mocRangeCookModel.cookTimer = 0;
	stateCook (&mocRangeCookModel, watt_500, 0);
	TEST_ASSERT_EQUAL (state_end, mocRangeCookModel.state);
}

// テストグループで、実行するテストケースを列挙する
TEST_GROUP_RUNNER(TestRangeCookModel)
{
    RUN_TEST_CASE(TestRangeCookModel, stateCook);
    RUN_TEST_CASE(TestRangeCookModel, stateStart);
}
