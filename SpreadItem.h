#pragma once
//#include"ToolItemManager.h"
#include"gameNode.h"

class MapMain;

struct tagSpread
{
	SpreadState state = SpreadState::NONE;		//�ѷ����� ��Ȳ
	MapMain* nowMap;							//�����
	Vector2 pos;								//���� �������� ��ǥ
	Vector2 lastPos;							//������ ��ǥ
	string name;								//�ѷ��� �������� �̸�
	image* img;									//�ѷ����������� �̹���
	MYRECT col;									//�浹��
	float speed;								//�������̻ѷ����ӵ�
	bool move;									//�������� �����̰��ִ���
	bool render;								//�����Ǿ��ϴ���
	bool isActive;								//����ִ���
	bool up = false;
	bool left = false;
};

class SpreadItem : public gameNode
{

private:
	//vector<ToolItem*> itemList;			//������������ ��� ����ִ� ����
	//ToolItemManager* _toolItemManager;	//������������ ����ִ�Ŭ����
	tagSpread _spread;					//�ѷ���������
	vector<tagSpread> _spreadItemList;	//�ѷ��������۵��� ������� ����

public:
	SpreadItem();
	virtual ~SpreadItem() {};
	
	//�׷����������� �� �̴��Լ� ��þ�����Ʈ�Ǵ°��������� ���˴ϴ�
	virtual void Init( string name ,MapMain* map, int index , int num); //�ѷ����������� �������� �־�Ӵϴ�
	virtual void Init( string name ,MapMain* map, Vector2 index , int num); //�ѷ����������� �������� �־�Ӵϴ�
	
	
	virtual void Update();


	virtual vector<tagSpread> GetSpreadItemList() { return _spreadItemList; }
	void SetIsActive(bool isActive,int idx) { _spreadItemList[idx].isActive = isActive; }
	void SpreadUpdate(tagSpread &spread);




	int VectorToIndex(tagSpread s,Vector2 v);
	Vector2 IndexToVector(MapMain* map, int i);

	//inline void SetToolMemoryAddressLink(ToolItemManager* t) { _toolItemManager = t; }//��������������������ģ���Դϴ� �����Ҵ� �ӵ���������� �������°ɷθ����
};

