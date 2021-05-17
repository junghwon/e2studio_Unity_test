/***********************************************************************
*
*  FILE        : Unity_test.c
*  DATE        : 2021-05-12
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"
#include "unity/unity_fixture.h"

void main(void);

void main(void)
{
#ifdef UNIT_TEST
    // コマンドラインオプション "-v" を指定。
    // -v   詳細(verbose)モード。各テストの実行前にテスト名を出力する。
    int argc = 2;
    const char *argv[] = {"program name", "-v"};
    extern void RunAllTests(void);
    UnityMain(argc, argv, RunAllTests);
#endif // UNIT_TEST



    while(1);
}
