#pragma once
#include "gameNode.h"
#include "Environment.h"
#include "Dialog.h"
#include <vector>
#include <queue>

class Player;
class Crafting;
class ToolItemManager;
class ToolItem;
class Store;

struct tagInventory
{
	string keyname;
	RECT rc;
	image* image;
	int invenTabNum;
	int craftPageNum;
	int x, y, craftY;
	bool isInvenOpen;
};

struct tagQuickSlot
{
	image* image;
	int x, y, uY;
};
struct SaveLoad
{
	string name;
	int num;
};

class Inventory : public gameNode
{
private:
	typedef vector<RECT>			vInvenRC;	//�κ��丮�� ������ �� ��� ���� �ִ� (����)��Ʈ ����
	typedef vector<RECT>::iterator	viInvenRC;

	vInvenRC		_vInvenStaticRC;			//�κ��丮 ����� �׻� �� �ִ� ���� ��Ʈ
	vInvenRC		_vInvenDynamicRC;			//�κ��丮 ����� Ư�� �ǿ����� ������ ���� ��Ʈ
	vInvenRC		_vInvenIndexRC;				//�κ��丮 ĭ�� �ε��� ��Ʈ

	viInvenRC		_viInvenStaticRC;
	viInvenRC		_viInvenDynamicRC;
	viInvenRC		_viInvenIndexRC;

	//////////////////////////////////////////
	RECT _inventoryCloseRC;	// Static RC    //
	RECT _invenTabRC[5];	// Static RC    //
	//////////////////////////////////////////
	RECT _titleRC;			// Dynamic RC   //
	RECT _closeRC;			// Dynamic RC   //
	RECT _menuDownRC;		// Dynamic RC   //
	RECT _menuUpRC;			// Dynamic RC   //
	RECT _trashCanRC;		// Dynamic RC   //		
	RECT _sortRC;			// Dynamic RC   //	
	//////////////////////////////////////////
	RECT _indexRC[12];	    // Index RC     //
	//////////////////////////////////////////
	RECT _craftingRC[3];	// Crafting RC	//
	/// //////////////////////////////////////

	Player* _player;
	Store* _store;
	Crafting* _crafting;

	/////////////////////////<Inventory>////////////////////////////

	tagInventory _inventory;

	ToolItemManager* _toolItemManager;

	vector<ToolItem*> _toolList;	 // ����
	vector<ToolItem*> _toolInven;	// �� ������ �ִ°͵� 
	vector<SaveLoad> _toolLoad;		// _toolLoad
	vector<Crafting*> _itemCrafting;

	int _trashCanFrameX;			//�������� �̹��� ������
	int _frameCount;				//�̹��� ������ ī��Ʈ
	int _itemIndexNum;				//������ �ε��� ��ȣ �����

	int _sorted[12];
/////////////////////////</Inventory>///////////////////////////

	int _index;
	int _index1;
	int _index2;
/////////////////////////<QuickSlot>////////////////////////////

	tagQuickSlot _quickSlot;		//������
	tagQuickSlot _quickSlotSelect;	//�����Լ��� �簢��

/////////////////////////</QuickSlot>///////////////////////////

	bool _quickSlotUp;
	int _quickSlotSelectYUP;

	Dialog* _Dialog;
	RECT _dialogRc[12];

/////////////////////////</SAVE LOAD>///////////////////////////
	int size;

/////////////////////////<Get_Item>//////////////////////////
	struct tagGetItem   //ȹ��â
	{
		image* ItemWindow; //ȹ��â�̹���~
		image* Item;  //ȹ�� �̹���;
		RECT   ItemWindowRc; //ȹ���̹��� ��ǥ������ ��Ʈ~
		string ItemName;
		int Seetime; //���̴� �ð�
		bool isGet; //���̰� �ϴ°�
	};

	tagGetItem _tGetItem; //���� Ǫ�����~
	queue<tagGetItem> _qGetItem;
	bool _isGetItem; //ȹ���ߴ�?

public:
	Inventory() {};
	~Inventory() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void quickSlotMove();

	void Merge(vector<ToolItem*> &vIndex, int left, int mid, int right);
	void MergeSort(vector<ToolItem*> &vIndex, int left, int right);

	void Decrease();

	vector<RECT>	 GetVInvenIndexRC() { return _vInvenIndexRC; }
	vector<ToolItem*> GetInven() { return _toolInven; }
	ToolItem* GetInvenItem(int index) { return _toolInven[index]; }

	void PlayerLootItem(string itemName);
	void setPlayerBuyItme(ToolItem* buyItme);
	void setPlayerSellItem(int num);
	void SetStoreLink(Store* store) { _store = store; }
	void setPlayer(Player* pp) { _player = pp; }

	bool GetIsInvenOper() { return _inventory.isInvenOpen; }
	/////////////////////////<SAVE LOAD>///////////////////////////
	void Save();
	void SaveSize();
	void Load();
	void LoadSize();
	/////////////////////////</SAVE LOAD>//////////////////////////
};