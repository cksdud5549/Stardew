#pragma once
#include "gameNode.h"

class Player;

class HpStaminaBar : public gameNode
{
private:
	struct tagBar
	{
		image* topImg;		 //�Ӹ� ����
		image* midImg;		 //���� ����
		image* bottomImg;	 //�ݴ� ����
		image* frontBarImg;  //ü�¹� ���׹̳� �̹���
		image* BottomBarImg; //ü�¹� ���׹̳� �̹���
		RECT frontBarRc;     //ü�¹� ���׹̳� �� ��Ʈ
		RECT bottomBarRc;    //ü�¹� ���׹̳� �� ��Ʈ
		RECT midRc;			 //���� ���� ��ǥ�� ��Ʈ
		int x;				 //ü�¹� ���׹̳��� �ʱ� ��ǥ������ x��
		int y;				 //ü�¹� ���׹̳��� �ʱ� ��ǥ������ y��
		int hit;
	};

	Player* _pl;

	tagBar _StaminaBar;
	tagBar _HpBar;

public:
	HpStaminaBar() {};
	~HpStaminaBar() {};

	HRESULT init();
	void release();
	void update();
	void staminaBarRender();
	void hpBarRender();

	tagBar GetStaminaBar() { return _StaminaBar; }
	tagBar GetHpBar() { return _HpBar; }



	void setPlayerLink(Player* pp) { _pl = pp; }
	void setPlayerHP(int hp) { _HpBar.hit -= hp; }
	void setPlayerStamina(int stamina) { _StaminaBar.hit -= stamina; }
};