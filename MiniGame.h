#pragma once
#include "gameNode.h"

struct tagFish
{
	image* img;
	Vector2 pos;
	MYRECT rc;
	bool Setting;
};


class MiniGame : public gameNode

{
private:
	bool _nowFishing;				 //�׽�Ʈ��

	FISHING _fishingState;			 //���� ����
	
	bool _rareFish;					 //���������� �Ǻ�

	Vector2 _gauge;				 	 //�����󸶳���ư����� ������
	Vector2 _fishingUI;				 //������UIǥ������ǥ(left,top)��ǳ��
	Vector2 _minigame;				 //�̴ϰ���
	Vector2 _bar;					 //���� �� ��ǥ
	MYRECT _barRect;				 //���ù� ��Ʈ
	Vector2 _fishingHitBox;		 	 //�������Ʈ�ڽ���ǥ
	MYRECT _fishingHitRect;			 //����� ��Ʈ��Ʈ
	Vector2 _playerCenter;			 //�÷��̾� ���� ���� ����
	MYRECT _chageFrontBox;			 //���������� ��Ʈ �ո�
	MYRECT _chageBackBox;			 //���������� ��Ʈ �޸�
	Vector2 _fishfloat;				 //��������ǥ
	int _clickTime=0;				 //�Ŀ������� Ŭ���ð��޴º���
	int _power=0;					 //�� ������ŭ � ���ư�
	PLAYER_DIRECTION _dir;			 //�÷��̾� ���¹��� ����

	tagFish _Fish;	//����� �̹����� ��ǥ���� ����ü
	MYRECT _test;
	MYRECT	_playTest;

	image* _backimg;					 //���� ��ǳ��
	image* _minigameimg;				 //���� �̴ϰ���
	MYRECT _gaugeimg;					 //���� ������
	image* _barimg;						 //���� ��
	image* _hitimg;						 //���� ����
	image* _maximg;						 //�����ִ��Ŀ�����
	image* _fishimg;					 //�����
	image* _rareFishimg;				 //������

	int _hitcount;
	int _missCount;						 //�����ð� ī���� Ÿ�̸�
	int _maximgAlpha;					 //�ƽ� �̹��� ���İ�
	int _randomFish;					 //������ ����� ����Ȯ��
	int _fish;							 //��������� ����������
	int _fishingTime;					 //����ⳬ�̴µ� �ɸ��ð�
	int _fishTime;						 //�����Ȯ��
	bool up = false;							 //����⹫��

public:
	MiniGame() { _nowFishing = false; }
	virtual ~MiniGame() {};

	void Init(Vector2 center, PLAYER_DIRECTION dir);	//���ý������� �����ִ� ���� �ʱ�ȭ��
	void ChargeOne();									//����������� �������
	void ChargeTwo();									//��󰡴���
	void Wait();										//����ⳬ�϶����� ��ٸ�����
	void MiniGameOn();									//����2���� ����Ⱑ�������� Ŭ���ؼ� �̴ϰ��� ��������
	void Miss();										//����� ���µ� ����������
	void DoingFishing();								//�����ϴµ���
	void Success();										//���� ����������

	FISHING GetDoingFishing() { return _fishingState; }
	void SetDoingFishing(FISHING fish) { _fishingState = fish; }

	

	void Update();
	void Render();

	void SetNowFishing(bool i) { _nowFishing = i; }
	bool GetNowFishing() { return _nowFishing; }

};

