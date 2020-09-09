#pragma once
#include "gameNode.h"
#include <string>
#include <vector>
//������ �ι��丮�� �����Ѵ�~

class Player;
class ToolItemManager;
class ToolItem;
class Inventory;

class Store : public gameNode
{
private:
	ToolItemManager* _ItemManager;
	Inventory* _inven;
	Player* _player;

	vector<ToolItem*> _itemInfo;
	vector<ToolItem*> _saleItem;

	string _saleKoName[7]; //������ �ѱ�����
	int _saleMoney[7];     //��

	image* _StoreWindow;	  //����â
	image* _StorePortrait;	  //���������ʻ�ȭ
	image* _StoreItem[4];	  //���� ������
	image* _StoreInfo;		  //�����Ұ���â
	image* _StoreNPC;		  //����npc��Ʈ

	image* _CloseButton;     //�ݱ��ư
	image* _BlackWindow;

	image* _StoreUpArrow;	  //������������ ���ǰ��� ����ȭ��ǥ
	image* _StoreDownArrow;   //������������ ���ǰ��� �Ʒ���ȭ��ǥ

	image* _noMoney;		//������
	int _noMoneyAlpha;		//������ �̹��� Alpha

	vector<RECT> _Item;	     //�������ڵ�(4��)
	RECT _CloseRc;			 //�ݱ��ư
	RECT _StoreNpcRect;		 //npc�̹����������
	RECT _StoreNpcOpen;		 //�̿��� �������� ����� Ȱ��ȭ��ų������(����)

	RECT _StoreUpArrowRc;	 //������������ ���ǰ��� ����ȭ��ǥ �浹ó����
	RECT _StoreDownArrowRc;	 //������������ ���ǰ��� �Ʒ���ȭ��ǥ �浹ó����

	int _StoreItmeFrameY;	//������ǰ���ý�����
	int _StoreItmeFrameY2;
	int _StoreItmeFrameY3;
	int _StoreItmeFrameY4;

	int _bupp;
	int _StoreSearchMin;	//������ǰ Ž������

	bool _storeOpen;		//���� ������!

	RECT _SellRect[12];

public:
	Store();
	~Store();

	virtual HRESULT init(int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void OpenStoreRender();

	RECT getStoreNpcRect() { return _StoreNpcRect; }  //�������� ������ �Ǵ³���
	RECT getStoreNpcOpen() { return _StoreNpcOpen; }  //�����ִ� ��������~
	vector<ToolItem*> getStoreSaleItem() { return _saleItem; }
	bool getStoreOpen() { return _storeOpen; }

	void setStoreOpen(bool isOpen) { _storeOpen = isOpen; }

	void setLinkToolItemManager(ToolItemManager* TIM) { _ItemManager = TIM; }
	void setLinkInventory(Inventory* Inven) { _inven = Inven; }
	void setLinkPlayer(Player* player) { _player = player; }
};