#pragma once
#include "gameNode.h"
#include "Vector2.h"
#include "ToolItemManager.h"
#include "Inventory.h"


class HpStaminaBar;
class State;
class MapMain;
class HpStaminaBar;

enum class PLAYER_SOUND_TILES
{
	GRASS,
	ROCK,
	SOIL,
	END
};

class Player : public gameNode
{
private:
	struct NecessaryInfo
	{
		string name;
		image* img;
		image* shadowImg;
		animation* anim;
		Vector2 position;
		MYRECT collision;
		MYRECT shadowCollision;
		PLAYER_DIRECTION direction;
		TOOLS equipment;
		int maxHP;
		int maxStamina;
		int HP;
		int stamina;
		int money;
		float velocity;
		string exMapName; // (��)�ǿ찡 �����ϴ�
		FISHING doing; //�����̾� ���� �������� üũ�ϱ�����
	};

private:


	/// <summary>
	ToolItemManager* _tool;
	/// </summary>
	string _mapName;
	MapMain* _Map;
	NecessaryInfo _info;
	PLAYER_ACTION _action;
	shared_ptr<State> _state;
	ToolItem* _getItem;
	ToolItem* _haveItem;			//���� ���� �κ��ε���
	HpStaminaBar* _gauge;
	Inventory* _inven;
	Vector2 _mousePt;
	PLAYER_SOUND_TILES _playerSound;

	int _playerOnTileIndex;
	int _tileIndex[3];
	int _actTileIndex[3];
	int _playerTileX, _playerTileY;
	bool _isKeyDown;
	bool _isOpenStore;
public:
	Player() {}
	~Player() {}

	HRESULT init();
	void update();
	void render();
	void release();

	NecessaryInfo GetInfo() { return _info; }
	shared_ptr<State> GetState() { return _state; }
	PLAYER_ACTION GetAction() { return _action; }
	PLAYER_DIRECTION GetDirection() { return _info.direction; }
	TOOLS GetEquip() { return _info.equipment; }
	ToolItem* GetHaveItem() { return _haveItem; }
	ToolItemManager* GetTM() { return _tool; }
	MapMain* GetMap() { return _Map; }
	int* GetTileIndex() { return _actTileIndex; }
	int* GetMoveTileIndex() { return _tileIndex; }
	int GetMaxHp() { return _info.maxHP; }
	int GetHp() { return _info.HP; }
	int GetmaxStamina() { return _info.maxStamina; }
	int GetStamina() { return _info.stamina; }
	int GetMoney() { return _info.money; }
	MYRECT GetPlayercollision() { return _info.collision; }
	Inventory* GetPlayerInver() { return _inven; }
	int GetPlayerOnTileIndex() { return _playerOnTileIndex; }
	PLAYER_SOUND_TILES GetSoundWalk() { return _playerSound; }
	FISHING GetDoingFishing() { return _info.doing; }//�����̾� ���� �������� üũ�ϱ�����
	MYRECT GetAttackRect();

	void SetDoingFishing(FISHING tf) { _info.doing = tf; }//�����̾� ���� �������� üũ�ϱ�����
	void SetName(string Name) { _info.name = Name; }
	void SetImg(string imgName) { _info.img = IMAGEMANAGER->findImage(imgName); }
	void SetAnim(string stringName) { _info.anim = KEYANIMANAGER->findAnimation(stringName); }
	void SetEquip(TOOLS tool) { _info.equipment; }
	void SetPosition(Vector2 Pos) { _info.position = Pos; }
	void SetDirection(PLAYER_DIRECTION Direction) { _info.direction = Direction; }
	void SetDecreaseHp(int Hp) { _info.HP -= Hp; }
	void SetIncreaseHp(int Hp) { _info.HP += Hp; }
	void SetHp(int Hp) { _info.HP = Hp; }
	void SetDecreaseStamina(int Stamina) { _info.stamina -= Stamina; }
	void SetIncreaseStamina(int Stamina) { _info.stamina += Stamina; }
	void SetStamina(int Stamina) { _info.stamina = Stamina; }
	void SetDecreaseMoney(int Money) { _info.money -= Money; }
	void SetIncreaseMoney(int Money) { _info.money += Money; }
	void SetMoney(int Money) { _info.money = Money; }
	void SetDecreaseVelocity(float Velocity) { _info.velocity -= Velocity; }
	void SetIncreaseVelocity(float Velocity) { _info.velocity += Velocity; }
	void SetVelocity(float Velocity) { _info.velocity = Velocity; }
	void SetItem(ToolItem* Velocity) { _haveItem = Velocity; }
	void SetShadowImg(string imgName) { _info.shadowImg = IMAGEMANAGER->findImage(imgName); }
	void SetOpenStore(bool open) { _isOpenStore = open; }
	/// <summary>
	string GetMapName() { return _info.exMapName; }
	void SetMapName(string name) { _info.exMapName = name; }
	/// </summary>
	/// <returns></returns>


	//void SetMapMemoryAddressLink()

public:

	string GetStateName();
	
	void ChangeState(shared_ptr<State> state);
	void ChangeEquipment(TOOLS equip) { _info.equipment = equip; }
	void Move();
	void CheckTiles();
	void SetMapMemoryAddressLink(MapMain* map) { _Map = map; }

	void SavePlayerInfo(string fileName);
	void LoadPlayerInfo(string fileName);

};

