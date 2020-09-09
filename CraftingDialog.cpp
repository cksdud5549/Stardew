#include "stdafx.h"
#include "CraftingDialog.h"

HRESULT CraftingDialog::init()
{
    _CrDiaWindow = IMAGEMANAGER->findImage("ItemInfoWindow");

    _CrDiaRc = RectMake(_ptMouse.x, _ptMouse.y, _CrDiaWindow->getWidth(), _CrDiaWindow->getHeight());
    _SeeStrin = false;

    return S_OK;
}

void CraftingDialog::release()
{
}

void CraftingDialog::TxtOutPut(string itemName)
{
    _CrDiaRc = RectMake(_ptMouse.x +25, _ptMouse.y+35, _CrDiaWindow->getWidth(), _CrDiaWindow->getHeight());
    if (_SeeStrin)
    {
        _CrDiaWindow->render(getMemDC(), _CrDiaRc.left, _CrDiaRc.top);
        if (itemName == "GrilledFish") //�������
        {
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+5, "���", strlen("���"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+25, "�Ϲݻ��� : 1EA   ���� : 1EA", strlen("�Ϲݻ��� : 1EA   ���� : 1EA"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+60, "������� (����)", strlen("������� (����)"));
            TextOut(getMemDC(), _CrDiaRc.left + 10, _CrDiaRc.top + 84, "���ڿ� ���� �������", strlen("���ڿ� ���� �������"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+108, "ü�� : 40 ȸ��", strlen("ü�� : 40 ȸ��"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+130, "��� : 50 ȸ��", strlen("��� : 50 ȸ��"));
        }
        if (itemName == "RawFish") //����ȸ
        {
            TextOut(getMemDC(), _CrDiaRc.left + 10, _CrDiaRc.top + 5,  "���", strlen("���"));
            TextOut(getMemDC(), _CrDiaRc.left + 10, _CrDiaRc.top + 25, "�Ϲݻ��� : 1EA", strlen("�Ϲݻ��� : 1EA"));
            TextOut(getMemDC(), _CrDiaRc.left + 10, _CrDiaRc.top + 60, "����ȸ (����)", strlen("����ȸ (����)"));
            TextOut(getMemDC(), _CrDiaRc.left + 10, _CrDiaRc.top + 84, "��� �� �� ����", strlen("��� �� �� ����"));
            TextOut(getMemDC(), _CrDiaRc.left + 10, _CrDiaRc.top + 108, "ü�� : 20 ȸ��", strlen("ü�� : 20 ȸ��"));
            TextOut(getMemDC(), _CrDiaRc.left + 10, _CrDiaRc.top + 130, "��� : 30 ȸ��", strlen("��� : 30 ȸ��"));
        }
        if (itemName == "Salad") //������
        {
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+5,  "���", strlen("���"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+25, "���� : 1EA    �Ľ��� : 1EA", strlen("���� : 1EA    �Ľ��� : 1EA"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+60, "������ (����)", strlen("������ (����)"));
            TextOut(getMemDC(), _CrDiaRc.left + 10, _CrDiaRc.top + 84, "�ǰ��� ��ä������", strlen("�ǰ��� ��ä������"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+108, "ü�� : 10 ȸ��", strlen("ü�� : 10 ȸ��"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+130, "��� : 70 ȸ��", strlen("��� : 70 ȸ��"));
        }

        if (itemName == "ScareCrow")
        {
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+5, "���", strlen("���"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+25, "���� : 3EA    Ǯ : 2EA", strlen("���� : 3EA    Ǯ : 2EA"));
            TextOut(getMemDC(), _CrDiaRc.left+10, _CrDiaRc.top+60, "����ƺ� (����)", strlen("����ƺ� (����)"));
            TextOut(getMemDC(), _CrDiaRc.left + 10, _CrDiaRc.top + 84, " ��Ͱ� �۹��� ��ġ�� ���ϰ� �����ݴϴ�.", strlen(" ��Ͱ� �۹��� ��ġ�� ���ϰ� �����ݴϴ�."));
        }
    }
    else _SeeStrin = false;
}