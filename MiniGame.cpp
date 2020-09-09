#include "stdafx.h"
#include "MiniGame.h"


void MiniGame::Update()
{
	cout << "���ÿ����� ����" << (int)_fishingState << endl;

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON) && _fishingState == FISHING::FIRST)
	{
		_fishingState = FISHING::CHARGE;
	}


	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && _fishingState == FISHING::CHARGE)
	{
		_power = _clickTime;
		_fishingState = FISHING::SHOT;
	}

	switch (_fishingState)
	{
	case FISHING::FIRST://0
		break;
	case FISHING::CHARGE://1
		_chageFrontBox.right++;
		_clickTime++;
		if (_chageFrontBox.right >= _chageBackBox.right - 1)_chageFrontBox.right = _chageBackBox.right - 1;

		break;
	case FISHING::SHOT://2
		ChargeTwo();				//1.� �Ŀ���ŭ ���󰡴� �Լ�
		break;
	case FISHING::WAIT://3
		Wait();						//2.����ⳬ�϶� ���� ��ٸ��� �Լ�
		break;
	case FISHING::MINiGAMEON://4
		MiniGameOn();				//3.���� �̴ϰ��� ����(UI��ǥ����)
		break;
	case FISHING::DOINGMINIGAME://5
		DoingFishing();				//4.���� ���� �������϶� �۵�
		break;
	case FISHING::MISS://6
		Miss();						//����� ��������
		break;
	case FISHING::SUCCESS://7
		Success();					//������������
		break;
	case FISHING::NONE://8
		//_fishingState = FISHING::FIRST;
		break;
	default:
		break;
	}

}

void MiniGame::Render()
{
	//_test.set(_fishfloat.x, _fishfloat.y, _fishfloat.x + 30, _fishfloat.y - 30);


	switch (_fishingState)
	{
	case FISHING::FIRST:
		break;
	case FISHING::CHARGE:
		CAMERAMANAGER->rectangle(getMemDC(), _chageBackBox);

		//CAMERAMANAGER->rectangle(getMemDC(), _chageFrontBox);

		//_chageBackBox.render(getMemDC());
		//_chageFrontBox.render(getMemDC());

		break;
	case FISHING::SHOT:
		if (_power > 90)
		{
			CAMERAMANAGER->alpharender(getMemDC(), _maximg, _playerCenter.x, _playerCenter.y, _maximgAlpha);
			//_maximg->alphaRender(getMemDC(), _playerCenter.x, _playerCenter.y, _maximgAlpha);
		}
		//CAMERAMANAGER->rectangle(getMemDC(), _test);
		CAMERAMANAGER->render(getMemDC(), IMAGEMANAGER->findImage("FishingWWWW"), _fishfloat.x, _fishfloat.y);
		break;
	case FISHING::WAIT:
		if (_fish == _randomFish && _fishTime == _fishingTime && _hitcount < 50)
		{
			CAMERAMANAGER->render(getMemDC(), _hitimg, _fishfloat.x, _fishfloat.y + 50);
			//_hitimg->render(getMemDC(), _fishfloat.x, _fishfloat.y+50);
		}
		//CAMERAMANAGER->rectangle(getMemDC(), _test);
		CAMERAMANAGER->render(getMemDC(), IMAGEMANAGER->findImage("FishingWWWW"), _fishfloat.x, _fishfloat.y);
		break;
	case FISHING::MINiGAMEON:
		CAMERAMANAGER->render(getMemDC(), _hitimg, _playerCenter.x, _playerCenter.y);
		CAMERAMANAGER->render(getMemDC(), _backimg, _fishingUI.x, _fishingUI.y);
		CAMERAMANAGER->render(getMemDC(), _minigameimg, _minigame.x, _minigame.y);
		CAMERAMANAGER->render(getMemDC(), _barimg, _bar.x, _bar.y);
		if (_rareFish)CAMERAMANAGER->render(getMemDC(), _rareFishimg, _fishingHitBox.x, _fishingHitBox.y);
		else CAMERAMANAGER->render(getMemDC(), _fishimg, _fishingHitBox.x, _fishingHitBox.y);
		CAMERAMANAGER->rectangle(getMemDC(), _gaugeimg);
		//CAMERAMANAGER->rectangle(getMemDC(), _test);
		CAMERAMANAGER->render(getMemDC(), IMAGEMANAGER->findImage("FishingWWWW"), _fishfloat.x, _fishfloat.y);


		//_hitimg->render(getMemDC(), _playerCenter.x , _playerCenter.y );

		//_backimg->render(getMemDC(),_fishingUI.x, _fishingUI.y);
		//_minigameimg->render(getMemDC(),_minigame.x, _minigame.y);
		//_barimg->render(getMemDC(), _bar.x, _bar.y);

		//if (_rareFish)_rareFishimg->render(getMemDC(), _fishingHitBox.x, _fishingHitBox.y); 
		//else _fishimg->render(getMemDC(), _fishingHitBox.x, _fishingHitBox.y);

		//_gaugeimg.render(getMemDC());

		break;
	case FISHING::DOINGMINIGAME:

		CAMERAMANAGER->render(getMemDC(), _backimg, _fishingUI.x, _fishingUI.y);
		CAMERAMANAGER->render(getMemDC(), _minigameimg, _minigame.x, _minigame.y);
		CAMERAMANAGER->render(getMemDC(), _barimg, _bar.x, _bar.y);
		if (_rareFish)CAMERAMANAGER->render(getMemDC(), _rareFishimg, _fishingHitBox.x, _fishingHitBox.y);
		else CAMERAMANAGER->render(getMemDC(), _fishimg, _fishingHitBox.x, _fishingHitBox.y);
		//CAMERAMANAGER->rectangle(getMemDC(), _gaugeimg);
		//CAMERAMANAGER->rectangle(getMemDC(), _test);
		CAMERAMANAGER->render(getMemDC(), IMAGEMANAGER->findImage("FishingWWWW"), _fishfloat.x, _fishfloat.y);
		//_backimg->render(getMemDC(), _fishingUI.x, _fishingUI.y);
		//_minigameimg->render(getMemDC(), _minigame.x, _minigame.y);
		//_barimg->render(getMemDC(), _bar.x, _bar.y);

		//if (_rareFish)_rareFishimg->render(getMemDC(), _fishingHitBox.x, _fishingHitBox.y);
		//else _fishimg->render(getMemDC(), _fishingHitBox.x, _fishingHitBox.y);

		//_gaugeimg.render(getMemDC());

		break;
	case FISHING::MISS:
		break;
	case FISHING::SUCCESS:
		CAMERAMANAGER->render(getMemDC(), _Fish.img, _Fish.pos.x, _Fish.pos.y);
		break;
	case FISHING::NONE:
		break;
	default:
		break;
	}
	if (_fishingState == FISHING::CHARGE)
	{
		HBRUSH hbrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), hbrush);
		HPEN hPen = CreatePen(PS_SOLID, 0, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(getMemDC(), hPen);
		CAMERAMANAGER->rectangle(getMemDC(), _chageFrontBox);
		SelectObject(getMemDC(), oldBrush);
		DeleteObject(hbrush);
		SelectObject(getMemDC(), oldPen);
		DeleteObject(hPen);
	}
	if (_fishingState == FISHING::DOINGMINIGAME)
	{
		HBRUSH hbrush = CreateSolidBrush(RGB(50, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), hbrush);
		HPEN hPen = CreatePen(PS_SOLID, 0, RGB(50, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(getMemDC(), hPen);
		CAMERAMANAGER->rectangle(getMemDC(), _gaugeimg);
		SelectObject(getMemDC(), oldBrush);
		DeleteObject(hbrush);
		SelectObject(getMemDC(), oldPen);
		DeleteObject(hPen);
	}
}

void MiniGame::Init(Vector2 center, PLAYER_DIRECTION dir)
{
	_fishingState = FISHING::FIRST;
	_Fish.img = IMAGEMANAGER->findImage("NormalFish");
	_Fish.pos.x = -500;
	_Fish.pos.y = -500;
	_Fish.rc.set(_Fish.pos.x - 1, _Fish.pos.y - 1, _Fish.pos.x + 1, _Fish.pos.y + 1);
	_Fish.Setting = false;
	_missCount = 0;					//���� ī��Ʈ

	_gauge.x = 0;					//���� ����� �󸶳���ư����� ������
	_gauge.y = 0;

	_hitcount = 0;

	_fishingUI.x = 0;				//�������� UI
	_fishingUI.y = 0;

	_minigame.x = 0;				//���� �̴ϰ��� ǥ��� ��ǥ
	_minigame.y = 0;

	_fishingHitBox.x = 0;			//������� ��Ʈ�ڽ� �̹���ǥ��� ��ǥ
	_fishingHitBox.y = 0;

	_dir = dir;	//�÷��̾��� ���Ⱚ���� �̿����� UI�ߴ� ��ġ�� �޶���

	_clickTime = 0;					//�Ŀ� ���� �ð��� ����ϴ� ����

	_power = 0;						//�Ŀ���ġ Ÿ�ӿ� ����ؼ� � ���ư��� ����

	_bar.x = 0;						//���ù� ��ǥ �ʱ�ȭ
	_bar.y = 0;

	_playerCenter.x = center.x;			//�÷��̾� ���Ͱ� �޾ƿ��� ����
	_playerCenter.y = center.y;			//�÷��̾� ���Ͱ� �޾ƿ��� ����
	cout << _playerCenter.x << endl;
	cout << _playerCenter.y << endl;
	cout << "TLQKF" << endl;
	_fishfloat.x = _playerCenter.x;	//���� � ǥ��� ��ǥ
	_fishfloat.y = _playerCenter.y - 100;

	_chageBackBox.set(_fishfloat.x - 50, _fishfloat.y - 50,
		_fishfloat.x + 50, _fishfloat.y - 80);
	_chageFrontBox.set(_chageBackBox.left + 1, _chageBackBox.top - 1,
		_chageBackBox.left + 1, _chageBackBox.bottom + 1);
	//���� �����ʱ�ȭ ������ ���������� ��Ʈ ����
	_maximgAlpha = 255;

	_backimg = IMAGEMANAGER->findImage("FishingBack");			//���� ��ǳ��
	_minigameimg = IMAGEMANAGER->findImage("FishingMiniGame");	//���� �̴ϰ���
	_gaugeimg.set(-500, -500, -500, -500);						//���� ������
	_fishingHitRect.set(-500, -500, -500, -500);				//����� ��Ʈ�ڽ�
	_barRect.set(-500, -500, -500, -500);						//���ù� ��Ʈ
	_barimg = IMAGEMANAGER->findImage("FishingBar");			//���� ��
	_hitimg = IMAGEMANAGER->findImage("FishingStart");			//���� ����
	_maximg = IMAGEMANAGER->findImage("FishingPower");			//�����ִ��Ŀ�����
	_fishimg = IMAGEMANAGER->findImage("FishingFish");			//�����
	_rareFishimg = IMAGEMANAGER->findImage("FishingRareFish");	//������
	_fish = 0;
	_fishTime = 0;

	_nowFishing = true;	//�׽�Ʈ��
}

void MiniGame::ChargeOne()
{
	if (_fishingState == FISHING::CHARGE)
	{
		_chageFrontBox.right++;
		_clickTime++;
		if (_chageFrontBox.right >= _chageBackBox.right - 1)_chageFrontBox.right = _chageBackBox.right - 1;

	}
}

void MiniGame::ChargeTwo()
{

	if (_power > 90)
	{
		_maximgAlpha -= 1;
	}

	if (_power > 100)
	{
		_power = 100;
	}

	if (_dir == PLAYER_DIRECTION::DOWN)
	{
		_fishfloat.y += 6;

		_power -= 2;
	}

	if (_dir == PLAYER_DIRECTION::LEFT)
	{
		_fishfloat.x -= 3;
		_fishfloat.y += 2;

		_power -= 2;
	}

	if (_dir == PLAYER_DIRECTION::RIGHT)
	{
		_fishfloat.x += 3;
		_fishfloat.y += 2;

		_power -= 2;
	}

	if (_dir == PLAYER_DIRECTION::UP)
	{
		_fishfloat.y -= 3;

		_power -= 2;
	}
	if (_power <= 0)
	{
		_randomFish = RND->getInt(11);//���� �Ϲ� Ȯ��
		_fishingTime = RND->getFromIntTo(0, 150);//���������Ÿ��Ȯ��
		_fishingState = FISHING::WAIT;
	}

}

void MiniGame::Wait()
{

	if (_fish == _randomFish && _fishTime == _fishingTime)
	{
		_missCount++;
		_hitcount++;
		if (_fish > 3)
		{
			_rareFish = false;
		}

		else if (_fish <= 3)
		{
			_rareFish = true;
		}

		if (_hitcount < 50 && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_hitcount = 0;
			_fishingState = FISHING::MINiGAMEON;
		}
		else if (_hitcount >= 50 && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_hitcount = 0;
			_fishingState = FISHING::NONE;
		}

	}
	else if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))_fishingState = FISHING::NONE;
	if (_fish < _randomFish)_fish++;
	if (_fishTime < _fishingTime)_fishTime++;

}


void MiniGame::MiniGameOn()
{

	if (_dir == PLAYER_DIRECTION::LEFT)
	{
		_fishingUI.x = _playerCenter.x + 300;
		_fishingUI.y = _playerCenter.y - 400;
		if (_fishingUI.y <= 0)_fishingUI.y = 0;
		_minigame.x = _fishingUI.x + 12;
		_minigame.y = _fishingUI.y;

		_gauge.x = _fishingUI.x + 122;
		_gauge.y = _fishingUI.y + 587;
		_gaugeimg.set(_gauge.x, _gauge.y - 400, _gauge.x + 15, _gauge.y);

		_bar.x = _fishingUI.x + 67;
		_bar.y = _fishingUI.y + 425;
		_barRect.set(_bar.x, _bar.y, _bar.x + 34, _bar.y - 96);

		_fishingHitBox.x = _fishingUI.x + 70;
		_fishingHitBox.y = _fishingUI.y + 300;
		_fishingHitRect.set(_fishingHitBox.x, _fishingHitBox.y,
			_fishingHitBox.x + 28, _fishingHitBox.y - 28);

	}
	else
	{
		_fishingUI.x = _playerCenter.x - 300;
		_fishingUI.y = _playerCenter.y - 400;
		if (_fishingUI.y <= 0)_fishingUI.y = 0;
		_minigame.x = _fishingUI.x + 12;
		_minigame.y = _fishingUI.y;

		_gauge.x = _fishingUI.x + 122;
		_gauge.y = _fishingUI.y + 587;
		_gaugeimg.set(_gauge.x, _gauge.y - 400, _gauge.x + 15, _gauge.y);

		_bar.x = _fishingUI.x + 67;
		_bar.y = _fishingUI.y + 425;
		_barRect.set(_bar.x, _bar.y, _bar.x + 34, _bar.y - 96);

		_fishingHitBox.x = _fishingUI.x + 70;
		_fishingHitBox.y = _fishingUI.y + 300;
		_fishingHitRect.set(_fishingHitBox.x, _fishingHitBox.y,
			_fishingHitBox.x + 28, _fishingHitBox.y - 28);


	}
	_fishingState = FISHING::DOINGMINIGAME;


}


void MiniGame::DoingFishing()
{

	//�浹������ ��Ʈ������Ʈ=============================================
	_gaugeimg.set(_gauge.x, _gaugeimg.top, _gauge.x + 15, _gauge.y);//�󸶳���ư�����
	_fishingHitRect.set(_fishingHitBox.x, _fishingHitBox.y,//������ǰݷ�Ʈ
		_fishingHitBox.x + 28, _fishingHitBox.y + 28);
	_barRect.set(_bar.x, _bar.y, _bar.x + 34, _bar.y + 96);//�÷��̾��� ����� ��ȹ��Ʈ

	//===================================================================

	//����� ������ ������Ʈ================================================
	if (_rareFish)			//������ ������
	{

		if (isCollision(_barRect, _fishingHitRect))
		{
			if (up)_fishingHitBox.y -= 4;

			else _fishingHitBox.y += 4;
		}
		if (up)
		{
			if (_fishingHitBox.y < _fishingUI.y + 20)
			{
				_fishingHitBox.y = _fishingUI.y + 20;
				up = false;
			}
			_fishingHitBox.y--;
		}
		else if (!up)
		{
			if (_fishingHitBox.y > _fishingUI.y + 530)
			{
				_fishingHitBox.y = _fishingUI.y + 530;
				up = true;
			}
			_fishingHitBox.y++;
		}
	}

	if (!_rareFish)			//�Ϲݹ���������
	{

		if (up)
		{
			if (_fishingHitBox.y < _fishingUI.y + 20)
			{
				_fishingHitBox.y = _fishingUI.y + 20;
				up = false;
			}
			_fishingHitBox.y -= 5;
		}
		if (!up)
		{
			if (_fishingHitBox.y > _fishingUI.y + 530)
			{
				_fishingHitBox.y = _fishingUI.y + 530;
				up = true;
			}
			_fishingHitBox.y += 5;
		}
	}
	//===============================================================

	//�÷��̾� ���� ��Ʈ�ѷ�=============================
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		if (_bar.y < _fishingUI.y + 15)
		{
			_bar.y = _fishingUI.y + 15;
		}
		_bar.y -= 5;
	}
	else
	{
		if (_bar.y > _fishingUI.y + 480)
		{
			_bar.y = _fishingUI.y + 480;
		}
		_bar.y += 6;
	}
	//=================================================

	//��ȹ������ ��� ������Ʈ=============================
	if (isCollision(_barRect, _fishingHitRect))
	{
		_gaugeimg.top -= 3;
	}
	else
	{
		_gaugeimg.top += 3;
	}

	if (_gaugeimg.top < _fishingUI.y + 15)_fishingState = FISHING::SUCCESS;
	if (_gaugeimg.top > _gaugeimg.bottom)_fishingState = FISHING::NONE;
	//===================================================


}

void MiniGame::Miss()
{
	_fishingState = FISHING::NONE;
}



void MiniGame::Success()
{
	if (_rareFish)_Fish.img = IMAGEMANAGER->findImage("RareFish(64x64)");
	else if (!_rareFish)_Fish.img = IMAGEMANAGER->findImage("NormalFish(64x64)");

	if (!_Fish.Setting)
	{
		_Fish.pos.x = _fishfloat.x;
		_Fish.pos.y = _fishfloat.y;
		_Fish.Setting = true;
	}

	//switch (_dir)
	//{
	//case PLAYER_DIRECTION::UP:
	//	if (_Fish.pos.y < _playerCenter.y)_Fish.pos.y += 2;
	//	break;
	//case PLAYER_DIRECTION::DOWN:
	//	if (_Fish.pos.y > _playerCenter.y)_Fish.pos.y -= 2;
	//	break;
	//case PLAYER_DIRECTION::RIGHT:
	//	if (_Fish.pos.x > _playerCenter.x)_Fish.pos.x += 2;
	//	if (_Fish.pos.y > _playerCenter.y)_Fish.pos.y += 2;
	//	break;
	//case PLAYER_DIRECTION::LEFT:
	//	if (_Fish.pos.x < _playerCenter.x)_Fish.pos.x -= 2;
	//	if (_Fish.pos.y > _playerCenter.y)_Fish.pos.y += 2;
	//	break;
	//default:
	//	break;
	//}
	_playTest.set(_playerCenter.x - 20, _playerCenter.y - 100, _playerCenter.x + 20, _playerCenter.y + 20);
	_Fish.rc.set(_Fish.pos.x - 5, _Fish.pos.y - 5, _Fish.pos.x + 5, _Fish.pos.y + 5);
	if (_dir == PLAYER_DIRECTION::UP && !isCollision(_playTest, _Fish.rc))
	{
		_Fish.pos.y += 3;
	}
	else if (_dir == PLAYER_DIRECTION::DOWN && !isCollision(_playTest, _Fish.rc))
	{
		_Fish.pos.y -= 3;
	}
	else if (_dir == PLAYER_DIRECTION::RIGHT && !isCollision(_playTest, _Fish.rc))
	{
		if (_Fish.rc.bottom < _playTest.top)_Fish.pos.y += 5;
		_Fish.pos.x -= 3;
		_Fish.pos.y -= 3;
	}
	else if (_dir == PLAYER_DIRECTION::LEFT && !isCollision(_playTest, _Fish.rc))
	{
		if (_Fish.rc.bottom < _playTest.top)_Fish.pos.y += 5;
		_Fish.pos.x += 3;
		_Fish.pos.y -= 3;
	}
	
	//if ( _Fish.rc.bottom < _playTest.top)
	//{
	//	_Fish.pos.y += 5;
	//}
	//if ( _Fish.rc.top > _playTest.bottom)
	//{
	//	_Fish.pos.y -= 3;
	//}
	//if (_Fish.rc.left > _playTest.right)
	//{
	//	_Fish.pos.x -= 3;
	//	//_Fish.pos.y -= 3;
	//}
	//if (_Fish.rc.left < _playTest.left)
	//{
	//	_Fish.pos.x += 3;
	//	//_Fish.pos.y -= 3;
	//}

	if (isCollision(_playTest, _Fish.rc))
	{
		_fishingState = FISHING::NONE;
	}
	_Fish.rc.set(_Fish.pos.x - 5, _Fish.pos.y - 5, _Fish.pos.x + 5, _Fish.pos.y + 5);

}
