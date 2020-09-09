#include"stdafx.h"
#include "Pickax.h"
#include"AllMap.h"
#include"SpreadItem.h"
Pickax::Pickax()
{

}

void Pickax::Init()
{
	_name = "Pickax";
	_tag = "ToolItem";
	_imageI = IMAGEMANAGER->findImage("Pickax(64x64)");
	_dmage = 1;
	_enumName = TOOLS::PICK;
}

void Pickax::Action()
{
	_justSignal = true;
	_mapObject = MAPOBJECT::NONE;
	//�� �μ���
	if (_map->GetTiles(_tileIndex[0]).object == MAPOBJECT::ROCK )
	{
		_spreadItem->Init("Stone", _map, _spreadItem->IndexToVector(_map, _tileIndex[0]), 1);

		_map->SetMapObject(_tileIndex[0], MAPOBJECT::NONE);
		_map->SetColl(_tileIndex[0], false);
		
		_map->GetTiles(_tileIndex[0]).rc.left;
		EFFECTMANAGER->play("RockDis", _map->GetTiles(_tileIndex[0]).rc.left+32, _map->GetTiles(_tileIndex[0]).rc.top+32);
	}
	if (_map->GetTiles(_tileIndex[0]).object == MAPOBJECT::WEED)
	{
		_spreadItem->Init("Weed", _map, _spreadItem->IndexToVector(_map, _tileIndex[0]), 1);

		_map->SetMapObject(_tileIndex[0], MAPOBJECT::NONE);
		_map->SetColl(_tileIndex[0], false);
		EFFECTMANAGER->play("WeedDis", _map->GetTiles(_tileIndex[0]).rc.left + 32, _map->GetTiles(_tileIndex[0]).rc.top + 32);
	}
	//������ ���ٶ�
	if (_map->GetTiles(_tileIndex[0]).object == MAPOBJECT::HOETILE||
		_map->GetTiles(_tileIndex[0]).object == MAPOBJECT::HOETILE_WET)
	{
		_map->SetMapObject(_tileIndex[0], MAPOBJECT::NONE);
		_map->SetColl(_tileIndex[0], false);
		_map->SetWet(_tileIndex[0], false);
	}
}

void Pickax::Update()
{
	_spreadItem->Update();
}

void Pickax::ReAction()
{
}
