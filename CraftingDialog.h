#pragma once
#include "gameNode.h"
#include <string>


class CraftingDialog : public gameNode
{
private:
	image* _CrDiaWindow; //�̹���
	RECT _CrDiaRc; //���ڵ� ��ǥ��
	bool _SeeStrin; //BoInDa AnBoInDa

public:
	CraftingDialog() {};
	~CraftingDialog() {};

	virtual HRESULT init();
	virtual void release();
	virtual void TxtOutPut(string itemName);  //����������.

	bool getSeeStrin() { return _SeeStrin; }
	void setSeeStrin(bool set) { _SeeStrin = set; }
};