#include "framework.h"

void Input::Update()
{
    memcpy(preState, curState, sizeof(preState));

    GetKeyboardState(curState);

    // 0,1 -> Ű�����Է� X
	//128, 129->Ű�����Է� O

	for (int i = 0; i < MaxKeys; i++)
	{
		curState[i] = (curState[i] & 0x80) ? 1 : 0;
		if (curState[i] == 1 && preState[i] == 0)
		{
			mapState[i] = Down; // Ű�� ������ ��
		}
		else if (curState[i] == 0 && preState[i] == 1)
		{
			mapState[i] = Up; // Ű�� �������� ��
		}
		else if (curState[i] == 1 && preState[i] == 1)
		{
			mapState[i] = Press; // Ű�� ������ ���� ��
		}
		else
		{
			mapState[i] = None; // Ű�� ������ �ʾ��� ��
		}
	}
}
