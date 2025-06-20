#include "framework.h"

void Input::Update()
{
    memcpy(preState, curState, sizeof(preState));

    GetKeyboardState(curState);

    // 0,1 -> 키보드입력 X
	//128, 129->키보드입력 O

	for (int i = 0; i < MaxKeys; i++)
	{
		curState[i] = (curState[i] & 0x80) ? 1 : 0;
		if (curState[i] == 1 && preState[i] == 0)
		{
			mapState[i] = Down; // 키가 눌렸을 때
		}
		else if (curState[i] == 0 && preState[i] == 1)
		{
			mapState[i] = Up; // 키가 떼어졌을 때
		}
		else if (curState[i] == 1 && preState[i] == 1)
		{
			mapState[i] = Press; // 키가 눌려져 있을 때
		}
		else
		{
			mapState[i] = None; // 키가 눌리지 않았을 때
		}
	}
}
