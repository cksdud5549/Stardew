#include "stdafx.h"
#include "Homi.h"
#include "AllMap.h"
#include"SpreadItem.h"

void Homi::Init()
{
	_name = "Homi";
	_tag = "ToolItem";
	_imageI = IMAGEMANAGER->findImage("Homi(64x64)");
	_dmage = 1;
	_enumName = TOOLS::HOE;
}

void Homi::Action()
{
	_justSignal = true;
	_mapObject = MAPOBJECT::NONE;
	_mapTeeain = TERRAIN::NONE;
	//�� �μ���
	if (_map->GetTiles(_tileIndex[0]).object == MAPOBJECT::NONE &&
		_map->GetTiles(_tileIndex[0]).terrain == TERRAIN::DIRT)
	{
		_map->SetMapObject(_tileIndex[0], MAPOBJECT::HOETILE);
		_map->SetFrameX(_tileIndex[0], 0);
		_map->SetFrameY(_tileIndex[0], 0);
	}

	if (_map->GetTiles(_tileIndex[0]).object == MAPOBJECT::WEED)
	{
		_spreadItem->Init("Weed", _map, _spreadItem->IndexToVector(_map, _tileIndex[0]), 1);

		_map->SetMapObject(_tileIndex[0], MAPOBJECT::NONE);
		_map->SetColl(_tileIndex[0], false);
		EFFECTMANAGER->play("WeedDis", _map->GetTiles(_tileIndex[0]).rc.left + 32, _map->GetTiles(_tileIndex[0]).rc.top + 32);
	}

}

void Homi::Update()
{
	_spreadItem->Update();
}

void Homi::ReAction()
{
}
