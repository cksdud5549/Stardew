#pragma once
#include "gameNode.h"
class MapMain;
class SpreadItem;
class ToolItemManager;
class Player;
//class DummyMap;//���Ⳣĥ ��

class ToolItem
{
protected:
	string _name="";		//�̸�
	string _tag="";		//�±� 
	int _dmage=0;			//������
	int _tileIndex[3] = { 0, }; //��ȣ�ۿ��� Ÿ���� �ε��� �����Ұ�
	bool _justSignal = false;//����Ÿ�ϻ�ȣ�ۿ��� üũ
	bool _slashSignal = false;//����Ÿ�ϻ�ȣ�ۿ� üũ
	FISHING _doing;//�����̾� ���� �������� üũ�ϱ�����
	TOOLS _enumName = TOOLS::NONE;		//���������� �̳Ѱ�
	int _number = 0;
	image* _imageI =nullptr;
	image* _imageC = nullptr;

	SpreadItem* _spreadItem;		//�������������

	Player* _player;

	Vector2 _playerCenter;
	PLAYER_DIRECTION _playerDir;

	MAPOBJECT	_mapObject = MAPOBJECT::NONE;	//����������Ʈ�ǼӼ�
	TERRAIN _mapTeeain = TERRAIN::NONE;			//����Ÿ���� �Ӽ�
	MapMain* _map = nullptr;//�����ٸ�

public:
	ToolItem() { ; }
	virtual ~ToolItem() { ; }

	//����
	virtual inline string GetName() { return _name; }
	virtual inline void SetName(string name) { _name = name; }

	//�±�
	virtual inline string GetTag() { return _tag; }
	virtual inline void SetTag(string tag) { _tag = tag; }

	
	//������
	virtual inline int GetDmage() { return _dmage; }
	virtual inline void SetDmage(int dmg) { _dmage = dmg; }

	//�����۰���
	virtual inline int GetNumber() { return _number;}
	virtual void SetNumber(int num) { _number += num; }

	//�������̹���
	virtual inline image* GetImageInven() { return _imageI; }
	virtual inline image* GetImageChar() { return _imageC; }

	virtual void SetSpreadItem(SpreadItem* spread) { _spreadItem = spread; }
	//virtual void SetSpreadInToolMemory(ToolItemManager* t) { _spreadItem->SetToolMemoryAddressLink(t); }

	virtual inline FISHING GetDoingFishing() { return _doing; }
	virtual inline void SetDoingFishing(FISHING tf) { _doing = tf; }

	void SetImageI(string image) { _imageI = IMAGEMANAGER->findImage(image + "(64x64)"); }
	void SetImageC(string image) { _imageI = IMAGEMANAGER->findImage(image); }

	//�÷��̾� ����,���� �������°�
	virtual inline void SetPlayerCenterNDir(Vector2 c, PLAYER_DIRECTION d) {
		_playerCenter = c;
		_playerDir = d;
	}

	//���������� �̳Ѱ��� 
	virtual inline TOOLS GetToolEnum() { return _enumName; }
	virtual inline void SetToolEnum(TOOLS toolEnum) { _enumName = toolEnum; }

	virtual inline int GetImpactTileIndexCenter() { return _tileIndex[0]; }
	virtual inline int GetImpactTileIndexLeft() { return _tileIndex[1]; }
	virtual inline int GetImpactTileIndexRight() { return _tileIndex[2]; }
	virtual inline void SetImpactTileIndex(int center){_tileIndex[0] = center;}
	virtual inline void SetImpactTileIndex(int center, int left, int right)
	{
		_tileIndex[0] = center;
		_tileIndex[1] = left;
		_tileIndex[2] = right;
	}
	//Ÿ�Ϻ��� ��ȣ�ִ°�
	virtual inline bool GetTileChangeSignalJust() { return _justSignal; }
	virtual inline bool GetTileChangeSignalSlash() { return _slashSignal; }

	//Ÿ�ϼӼ� �ְ�޴°�

	virtual inline void SetPlayerAddress(Player* pla) { _player = pla; }
	
	virtual inline MAPOBJECT GetMapObject() { return _mapObject; }
	virtual inline void SetMapObject(MAPOBJECT mapobj) { _mapObject = mapobj; }
	virtual void Init() {};
	virtual void Action() {};
	virtual void Update() {};
	virtual void ReAction() {}; // ������ �־��ּ��� ���� ���ø����ϴ�
	inline void SetNowMapMemoryAddressLink(MapMain* dmap) { _map = dmap; }
};

