#pragma once

class Input : public Singleton<Input>
{
	friend class Singleton<Input>;
private:
	static const int MaxKeys = 256;

	enum KeyState
	{
		None, Down, Up, Press
	};
private:
	Input() = default;
	~Input() = default;
public:
	void Update();

	bool IsKeyDown(int key) const { return mapState[key] == Down; }
	bool IsKeyUp(int key) const  { return mapState[key] == Up; }
	bool IsKeyPress(int key) const { return mapState[key] == Press; }

private:
	BYTE curState[MaxKeys] = {};
	BYTE preState[MaxKeys] = {};
	KeyState mapState[MaxKeys] = {};
};
