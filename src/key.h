/*
 * switch.h
 *
 *  Created on: 2021/05/18
 *      Author: kehnc
 */

#ifndef KEY_H_
#define KEY_H_

#include "portIn.h"

typedef enum {
	keyCode_non,
	keyCode_back,
	keyCode_home,
	keyCode_enter,
} keyCode_t;

typedef struct {
	keyCode_t keyCode;
} keyUser_t;

// 割込み処理を使う場合、インスタンスにアクセスできるようにextern宣言する
extern portIn_t portBack;
extern portIn_t portHome;
extern portIn_t portEnter;

keyCode_t key_CheckKeyCode (keyUser_t *this);
void key_Constructor (keyUser_t *this);

#endif /* KEY_H_ */
