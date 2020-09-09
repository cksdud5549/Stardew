#pragma once
#include "singletonBase.h"
#include <bitset>

#define KEYMAX 256

using namespace std;

class keyManager : public singletonBase<keyManager>
{
private:
	bitset<KEYMAX> _KeyPast;
	bitset<KEYMAX> _keyCurrent;

public:
	keyManager();
	~keyManager();

	HRESULT init();
	void update();

	void release();
	//Ű�� �� �� ������
	bool isOnceKeyDown(const int& key);
	//Ű�� �����ٰ� ����
	bool isOnceKeyUp(const int& key);
	//Ű�� ��� ������ ������
	bool isStayKeyDown(const int& key);
	//Ű�� ��۵Ǹ�(?) ĸ���� �����ض�
	bool isToggleKey(const int& key);

};

