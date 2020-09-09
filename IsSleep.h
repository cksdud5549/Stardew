#pragma once
#include "gameNode.h"
class IsSleep : public gameNode
{
private:
	image* _sleepSlect; //�����̹���
	image* _black; //�ᶧ�� ����ȭ��~

	RECT _isSleepYesRc;  //�߰ž� ����
	RECT _non;			//�����̴�

	int _alp; //���İ�

	bool _isSleep;  //���� ���ý� ���
	bool _isSelectOpen;


public:
	IsSleep() {};
	~IsSleep() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	bool getIsSelectOpen() { return _isSelectOpen; }
	bool getSleep() { return _isSleep; }
	virtual void setIsSelectOpen(bool open) { _isSelectOpen = open; }
};