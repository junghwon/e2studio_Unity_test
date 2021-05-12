#include "../unity/unity_fixture.h"

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
TEST(Test0, AlwaysFail)
{
    // 何もせず、テストを失敗させて、メッセージを出力する
    TEST_FAIL_MESSAGE("This test always fails.");
}

// テストグループで、実行するテストケースを列挙する
TEST_GROUP_RUNNER(Test0)
{
    RUN_TEST_CASE(Test0, AlwaysFail);
}
