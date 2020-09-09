#include "stdafx.h"
#include "TestScene.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

HRESULT TestScene::init()
{
	_inv = new Inventory;
	_inv->init();


	_store = new Store;


	_Bar = new HpStaminaBar;
	_Bar->init();

	_Mouse = IMAGEMANAGER->findImage("mouse");

	_CloseButton = IMAGEMANAGER->findImage("CloseButton");
	_CloseRc = RectMake(1400, 30, _CloseButton->getWidth(), _CloseButton->getHeight());

	_StoreOpen = false; //����������~

//-------------------------���̾�α� �����ϴ� �뵵�ΰ�--------------------
	_ChatWindow = IMAGEMANAGER->findImage("ChatBox");
	_TalkingXBox = IMAGEMANAGER->findImage("RightButton");
	_TalkingNpcImage = IMAGEMANAGER->findImage("����ī��");
	_TalkingNpcPortrait = IMAGEMANAGER->findImage("�ʻ�ȭ");

	_TalkingNpcImageRc = RectMake(300, 500, _TalkingNpcImage->getFrameWidth(), _TalkingNpcImage->getFrameHeight());
	_TalkingNpc = RectMakeCenter(_TalkingNpcImageRc.left + 25, _TalkingNpcImageRc.top + 25, 200, 200);

	_BlackWindow = IMAGEMANAGER->findImage("AlphaOnlyBlackWindow");

	_TestP = RectMake(WINSIZEX / 2, WINSIZEY / 2, 50, 100); //����

	_mouseIndex = 0;

	return S_OK;
}

void TestScene::release()
{
}

void TestScene::update()
{
	_inv->update();
	_mouseIndex = 0;
	/// <summary>
	_Inv->update();
	/// </summary>
	_store->update();
	_Bar->update();


	if (KEYMANAGER->isStayKeyDown(VK_UP) && !_StoreOpen && !_Talking)
	{
		_TestP.top -= 5;
		_TestP.bottom -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && !_StoreOpen && !_Talking)
	{
		_TestP.top += 5;
		_TestP.bottom += 5;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !_StoreOpen && !_Talking)
	{
		_TestP.left -= 5;
		_TestP.right -= 5;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && !_StoreOpen && !_Talking)
	{
		_TestP.left += 5;
		_TestP.right += 5;
	}



	if(KEYMANAGER->isOnceKeyDown(VK_F1))
	{ 
		_Bar->setPlayerHP(-5);
		_Bar->setPlayerStamina(-5);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_Bar->setPlayerHP(+5);
		_Bar->setPlayerStamina(+5);
	}


	RECT temp;
	if (IntersectRect(&temp, &_TestP, &_store->getStoreNpcOpen()) && !_StoreOpen)
	{
		if (PtInRect(&_store->getStoreNpcRect(), _ptMouse))
		{
			_mouseIndex = 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _StoreOpen = true;
		}
	}

	if (PtInRect(&_CloseRc, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _StoreOpen = false;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))
	{
		_StoreOpen = false;
		_Talking = false;
	}

	if (IntersectRect(&temp, &_TestP, &_TalkingNpc) && !_Talking)
	{
		if (PtInRect(&_TalkingNpcImageRc, _ptMouse))
		{
			_mouseIndex = 2;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _Talking = true;
		}
	}

///////////////////////����������̿�_���̾�α�_�⺻Ʋ?////////////////////////
	ifstream readFlie;
	readFlie.open("Dialogue/TEST.txt");

	if (readFlie.is_open())
	{
		while (!readFlie.eof())
		{
			string str;
			int findChar;

			getline(readFlie, str);
			findChar = str.find('@', 0);

			string outString(str.substr(findChar + 1, str.length()));

			_txtInTest.push_back(outString);
		}
	}
	readFlie.close();

	if (_Talking)
	{
		if (_stringNum < _txtInTest.front().length())
		{
			if (_txtInTest.front().at(_stringNum) < 0)
			{
				for (int i = 0; i < 2; i++)
				{
					_txtOutTest.push_back(_txtInTest.front().at(_stringNum++));
				}
			}
			else
			{
				_txtOutTest.push_back(_txtInTest.front().at(_stringNum++));
			}
		}
		else
		{
			_stringNum = _txtInTest.front().length();
		}
	}
	else
	{
		_stringNum = 0;
		_txtOutTest.clear();
	}
///////////////////////////////////////////////////////////////////////////

}

void TestScene::render()
{
	SetBkMode(getMemDC(), 1);
	SetTextColor(getMemDC(), BLACK);

	_store->render();
	Rectangle(getMemDC(), _TalkingNpc);
	Rectangle(getMemDC(), _TalkingNpcImageRc);

	Rectangle(getMemDC(), _TestP);
	_TalkingNpcImage->frameRender(getMemDC(), _TalkingNpcImageRc.left, _TalkingNpcImageRc.top, 0, 0);

	/// <summary>
	_inv->render();
	/// </summary>

	_Bar->staminaBarRender();
	_Bar->hpBarRender();

	if (_StoreOpen && !_Talking)
	{
		_BlackWindow->alphaRender(getMemDC(), 0, 0, 200);
		_store->OpenStoreRender();
		_CloseButton->render(getMemDC(), _CloseRc.left, _CloseRc.top);
	}
	
//---------------------���̾�α�_����-------yo---------------------------------

	HFONT TalkingOnlyFont, OldFont2;

	TalkingOnlyFont = CreateFont(50,0,0,0,300, false, false,false,  DEFAULT_CHARSET, OUT_STRING_PRECIS, 
					  CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Sandoll �̻�"));
	OldFont2 = (HFONT)SelectObject(getMemDC(), TalkingOnlyFont);

	if (_Talking && !_StoreOpen)
	{
		_TxtBoxRC = RectMake(427, 605, 500, 300);

		_ChatWindow->render(getMemDC(), 400, 580);
		_TalkingNpcPortrait->render(getMemDC(), 1010, 611);
		DrawText(getMemDC(), TEXT(_txtOutTest.c_str()), _stringNum, &_TxtBoxRC, DT_LEFT | DT_WORDBREAK | DT_VCENTER); //���������Ѱ�
		TextOut(getMemDC(), 1035, 820, "��ȭ�����", strlen("��ȭ�����"));
	}
	SelectObject(getMemDC(), OldFont2);
	DeleteObject(OldFont2);

	_Inv->render();
	//��ǥ�������~
	/*char mo[200];
	char mo2[200];
	sprintf_s(mo, "���콺�� X��ǥ:%d", _ptMouse.x);
	sprintf_s(mo2, "���콺�� Y��ǥ:%d", _ptMouse.y);
	TextOut(getMemDC(), 50, 90, mo, strlen(mo));
	TextOut(getMemDC(), 50, 120, mo2, strlen(mo2));*/

//------------------------------------------------------------------------------


	_Mouse->frameRender(getMemDC(), _ptMouse.x, _ptMouse.y, _mouseIndex, 0);
}