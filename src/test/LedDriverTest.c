#ifdef UNIT_TEST

#include "../unity/unity_fixture.h"
#include "../LedDriver.h"


// テストグループを定義
TEST_GROUP(LedDriver);

static uint16_t virtualLeds;


// 各テストケースの前に実行する共通処理(初期化)
TEST_SETUP(LedDriver)
{
	LedDriver_Create (&virtualLeds);
}

// 各テストケースの後に実行する共通処理(後片付け)
TEST_TEAR_DOWN(LedDriver)
{
}

// テストケース
TEST(LedDriver, LedsOffAfterCreate)
{
	virtualLeds = 0xffff;
	LedDriver_Create (&virtualLeds);
	TEST_ASSERT_EQUAL_HEX16 (0, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
	LedDriver_TurnOn (1);
	TEST_ASSERT_EQUAL_HEX16 (1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
	LedDriver_TurnOn (1);
	LedDriver_TurnOff (1);
	TEST_ASSERT_EQUAL_HEX16 (0, virtualLeds);
}

// テストグループで、実行するテストケースを列挙する
TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(LedDriver, TurnOnLedOne);
    RUN_TEST_CASE(LedDriver, TurnOffLedOne);
}

#endif // UNIT_TEST
