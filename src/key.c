/*
 * switch.c
 *
 *  Created on: 2021/05/19
 *      Author: kehnc
 */
#include "key.h"


// ハードウェアのインスタンスは使用するクラスで生成する
portIn_t portBack;
portIn_t portHome;
portIn_t portEnter;

keyCode_t key_CheckKeyCode (keyUser_t *this)
{
	this->keyCode = keyCode_non;

	// 優先度：Home > Back > Enter
	if (portHome.isActive) {
		this->keyCode = keyCode_home;
	} else if (portBack.isActive) {
		this->keyCode = keyCode_back;
	} else if (portEnter.isActive) {
		this->keyCode = keyCode_enter;
	} else {
		this->keyCode = keyCode_non;
	}

	return (this->keyCode);
}


void key_Constructor (keyUser_t *this)
{
	this->keyCode = keyCode_non;

	portIn_Constructor (&portBack);
	portIn_Constructor (&portHome);
	portIn_Constructor (&portEnter);
}
