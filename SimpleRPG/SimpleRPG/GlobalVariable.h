// GlobalVariable.h

#pragma once
#include "Common.h"
#include "Player.h"
#include "Enemy.h"

namespace GlobalVariable {
	// �����ܼ�
	extern int InputOption; // �ϥΪ̿�J�ﶵ
	extern std::string InputString; // �ϥΪ̿�J�r��
	extern char InputChar; // �ϥΪ̿�J�r��
	extern Player player; // ���a�ܼ�
	extern Enemy enemy; // �ĤH�ܼ�
}