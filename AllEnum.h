#pragma once

/// MapTool

enum class INOUT
{
	INDOOR,
	OUTDOOR
};
/// /////////////// ��ǥ �̳�
enum class POS
{
	COLLISION,
	PARM_TO_HOME,	//������ ��ǥ
	PARM_TO_CAVE,	//�������� ��ǥ
	HOME_TO_PARM,	//������ ����
	CAVE_TO_PARM,	//�������� ����
	BED,			//ħ��
	NPC,			//NPC
	ENEMY,			//��
	NONE
};

enum class CRTSELECT
{
	TERRAINDRAW,
	TERRAINDRAW_INDOOR,
	TERRAINDRAW_CAVE,
	WALLDRAW,
	WALLDRAW_CAVE,
	HOETILEDRAW,
	OBJECTDRAW,
	BUILDINGDRAW,
	ENEMYDRAW,
	ERASER,
	COLLISION,
	SAVE,
	LOAD,
	NONE
};
enum class TERRAIN
{
	DIRT,	
	GRASS,
	WATER,
	WOODEN,
	CAVE,
	NONE
};
enum class MAPOBJECT
{
	TREE1,
	TREE2,
	TREE3,			//����
	HOETILE,		//��綥
	HOETILE_WET,	//��綥������
	WEED,			//Ǯ
	ROCK,			//��
	BRANCH,			//��������
	WALL,			//��
	BUILDING,		//�ǹ�
	BED,
	//ENEMY,			//���ʹ�
	NONE
};
//--------------------------------------------------------------
// Player
enum class PLAYER_STATE
{
	IDLE,
	MOVE,
	EXHAUST,
	ACTING,
	END
};

enum class PLAYER_DIRECTION
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	UP_RIGHT,
	UP_LEFT,
	DOWN_RIGHT,
	DOWN_LEFT,
	END
};

enum class TOOLS
{
	PICK,
	HOE,
	SICKLE,
	AXE,
	FISHINGROD,
	SWORD,
	ITEM,
	WATERING_CAN,
	ACTIVEITEM,
	EATITEM,
	RESOURCEITEM,
	CRAFTITEM,
	NONE,
	END
};

enum class PLAYER_ACTION
{
	PLOWING,
	EATING,		//ó�Ա� (�Ҹ�ǰ : ���ķ�) Ÿ�ϰ˻� X
	MINING,		//������ (���� : ���) ��ȣ �ۿ��� Ÿ�� ���� && ������Ʈ; Ÿ�� �˻����� 1ĭ; 1. ���� : �����ȶ�; 2. ������Ʈ : ��, ����, �۹� ������, Ǯ;
	GATHERING,	//ä��	(ALL)	��ȣ�ۿ��� ������Ʈ : �۹�; ����; ���� : ���� ���� 1ĭ
	FELLING,	//����	(���� : ����) ��ȣ�ۿ��� ������Ʈ : ����, ����, �۹� ������, Ǯ; ���� : ���� ���� 1ĭ
	PLANTING,	//�ɱ�	(�Ҹ�ǰ : ���� || ���� || �ֹ��) �ͷ��� ��ȣ�ۿ�;  ��ȣ�ۿ��� �ͷ��� ���� && �۹� ������ : �����ȶ�; ���� : ����ٴ�, �ֹ�� : ���������� �ͷ���
	FISHING,	//������	(���� : ���˴�)
	SWING,		//�ֵθ��� (���� : ��, ��) ������Ʈ ��ȣ�ۿ�; ��ȣ�ۿ��� ������Ʈ : ����, �ܵ�; ���� : �ֵθ��� ���� 3ĭ;
	END
};

enum class FISHING
{
	FIRST,			//0.���� �ʱ�ȭ
	CHARGE,			//1.���� �������
	SHOT,			//2.�������
	WAIT,			//3.����ⳬ�ϋ����� ��ٸ���
	MINiGAMEON,		//4.����� ����������
	DOINGMINIGAME,	//5.���� ���ӵ���
	MISS,			//6.����� ��������
	SUCCESS,		//7.����� ��µ� ����������
	NONE			//8.Ȥ�� �� �ƹ����µ� �ƴҶ�
};

enum class Spread
{
	SPREAD,				//��Ѹ���
	HARVEST,			//��Ȯ�Ҷ�
	FISHING,			//�����Ҷ�
	THROW,				//�÷��̾ �۹�����	
	NONE
};
enum class SpreadState
{
	BEFORE_SPREAD,	//�Ѹ�������
	DOING_SPREAD,	//�Ѹ�����
	AFTER_SPREAD,	//�Ѹ�����
	NONE
};

enum class ATTRIBUTE
{
	NONE,
	START,
	WALL,
	PLAYER,
	ENEMY,
	NPC,
	END
};