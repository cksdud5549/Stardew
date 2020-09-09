#pragma once
#include "gameNode.h"
#include <string>
#include <fstream>
#include <vector>
#include <queue>

class Dialog : public gameNode
{
private:
	int _stringNum; //strin.~.at()�� ���

	image* _infoHealBox;	//ȸ�������� �϶�
	image* _infoBox;		//������ �϶�

	vector<string> _vInfoTxtInPut;    //txt���ϸ��� ��´�(����)

	queue<string> _qInfoTxtInPut;	 //txt���ϸ��� ���(ť)

	string _infoTxtOutPut;		    //������ 1���ھ� �޾ƿͼ� �����ִ� ����
	RECT _TxtBoxRC;			   //���ڰ� �ѷ��� ��ǥ

	bool _stringClear;          //�������� �ǹ��̴�.

public:
	Dialog() {};
	~Dialog() {};

	void setDialogClear(bool set) { _stringClear = set; }

	virtual HRESULT init();
	virtual void release();
	virtual void update(string itemName);
	virtual void render();
};