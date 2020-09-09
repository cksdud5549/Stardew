#pragma once
#include "gameNode.h"
#include "Inventory.h"
#include "Store.h"
#include "HpStaminaBar.h"
#include <string>
#include <fstream>	//��������� �Ҷ� �ʿ�
#include <vector>
#include <queue>

class TestScene : public gameNode
{
private:
	image* _Mouse; //���콺 �̹��� ->������ �ѹ����� �̹��� �����ֽð� ������ ��ǥ�� _ptmouseX, _ptmouseY  ���ֻ���
	Inventory* _inv;
	Store* _store;
	HpStaminaBar* _Bar;

	image* _CloseButton;     //�ݱ��ư
	image* _BlackWindow;     //���ĸ��ϰ�
	RECT _CloseRc;			 //�ݱ��ư�浹ó����

	bool _StoreOpen;  //����

	
//-------------------------���̾�α�_����--------------------------------

	image* _ChatWindow;      	 //��ȭâ �̹���
	image* _TalkingNpcImage;     //��ȭ����NPC ��Ʈ�̹���
	image* _TalkingNpcPortrait;  //��ȭ����NPC �ʻ�ȭ
	image* _TalkingXBox;		 //��ȭâ �����ϴܿ� �ִ°� ���ٸ� ȿ������

	/// <summary>
	Inventory* _Inv;
	/// </summary>

	RECT _TalkingNpcImageRc; //��ȭ��NPC �̹�����
	RECT _TalkingNpc;	     //��ȭ��NPC ��ȭ���ɿ���

	vector<string> _txtInTest;    //txt���ϸ��� ��´�
	string _txtOutTest;		 //������ 1���ھ� �޾ƿͼ� �����ִ� ����
	RECT _TxtBoxRC;	     //���ڰ� �ѷ��� ��ġ

	bool _Talking;			 //��ȭ�� �ϴ����ΰ�
	int _stringNum;			 //strin.~.at()���� ���~


	RECT _TestP;	  //�׽�Ʈ�����
	int _mouseIndex;  //���콺 �̹��� ������

public:
	TestScene();
	~TestScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};