#include "stdafx.h"
#include "WaterSpray.h"
#include "AllMap.h"
#include"SpreadItem.h"

void WaterSpray::Init()
{
	_name = "WaterSpray";
	_tag = "ToolItem";
	_imageI = IMAGEMANAGER->findImage("WaterSpray(56x56)");
	_dmage = 0;
	_enumName = TOOLS::WATERING_CAN;
}

void WaterSpray::Action()
{
	_justSignal = true;
	_mapObject = MAPOBJECT::NONE;
	_mapTeeain = TERRAIN::NONE;
	//�� �μ���
	if (_map->GetTiles(_tileIndex[0]).object == MAPOBJECT::HOETILE)
	{
		_map->SetWet(_tileIndex[0],true);
		EFFECTMANAGER->play("Water", _map->GetTiles(_tileIndex[0]).rc.left + 32, _map->GetTiles(_tileIndex[0]).rc.top + 32);
	}

}

void WaterSpray::ReAction()
{
}
