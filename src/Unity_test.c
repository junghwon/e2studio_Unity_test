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

typedef union {
	uint8_t byte;
	struct {
		uint8_t bit0 : 1;
		uint8_t bit1 : 1;
		uint8_t bit2 : 1;
		uint8_t bit3 : 1;
		uint8_t bit4 : 1;
		uint8_t bit5 : 1;
		uint8_t bit6 : 1;
		uint8_t bit7 : 1;
	}bit;
} port_t;


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




    R_Config_PORT_Create();

    PORTB.PODR.BYTE = 0;

    port_t portData;
    portData.bit.bit5 = 1;

    volatile uint8_t *port;
    port = &(PORTB.PODR.BYTE);

    while(1) {
    	*port = portData.byte;
    }
}
