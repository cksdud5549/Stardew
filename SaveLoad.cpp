#include "stdafx.h"
#include "SaveLoad.h"

SaveLoad::SaveLoad()
{
}

SaveLoad::~SaveLoad()
{
}

void SaveLoad::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) Save();
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) Load();
}

void SaveLoad::Save()
{
	HANDLE file;
	DWORD write;

	char str[128] = "������ �����̴� xx���� �ƴմϴ�";

	file = CreateFile("�����̰������̱�������.txt", GENERIC_WRITE,
		FALSE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);

	CloseHandle(file);
}

void SaveLoad::Load()
{
	HANDLE file;
	DWORD read;

	char str[128];

	file = CreateFile("backupPlayer.txt", GENERIC_READ,
		FALSE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	CloseHandle(file);
}
