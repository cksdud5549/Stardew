#pragma once
#include "singletonBase.h"
#include "image.h"
#include "animation.h"
class cameraManager : public singletonBase<cameraManager>
{
private:
	float _L, _T; // ī�޶� LEFT, TOP ���� ��ǥ�̸� �̸� �������� �׷���
	float _x, _y; // ī�޶� ���� ��ǥ
	float _width, _height; // ī�޶� �ʺ�, ���� ��

	float _minL, _maxL; // Left ��ǥ�� ������ ����
	float _minT, _maxT; // Top ��ǥ�� ������ ����
	float _minX, _maxX; // x ��ǥ�� ������ ����
	float _minY, _maxY; // y ��ǥ�� ������ ����

	float _speed;
public:
	cameraManager();
	~cameraManager();

	HRESULT init();
	void release();

	void setConfig(float left, float top, float width, float height, float minL, float minT, float maxL, float maxT);
	void setConfigCenter(float x, float y, float width, float height, float minX, float minY, float maxX, float maxY);
	float getL();
	float getT();
	float getX();
	float getY();
	void setL(float newL);
	void setT(float newT);
	void setX(float newX);
	void setY(float newY);
	void movePivot(float offsetX, float offsetY);

	float getRelativeX(float x);
	float getRelativeY(float y);

	void rectangle(HDC hdc, TTYONE_UTIL::MYRECT rect);
	void rectangle(HDC hdc, TTYONE_UTIL::MYRECT mrec, float destX, float destY);
	void ellipse(HDC hdc, TTYONE_UTIL::MYRECT rect);

	void render(HDC hdc, image* img);
	void render(HDC hdc, image* img, float destX, float destY);
	void render(HDC hdc, image* img, float destX, float destY, float sourX, float sourY, float sourWidth, float sourHeight);
	void alpharender(HDC hdc, image* img, float destX, float destY, int alpha);
	void loopRender(HDC hdc, image* img, float destX, float destY);

	void frameRender(HDC hdc, image* img, float destX, float destY);
	void frameRender(HDC hdc, image* img, float destX, float destY, int frameX, int frameY);
	void AniRender(HDC hdc, image* img, float destX, float destY, animation* ani);
	void KeyAniRender(HDC hdc, image* img, string KeyName, float destX, float destY, animation* ani);
	void KeyAnialphaRender(HDC hdc, image* img, float destX, float destY, animation* ani,int alpha);
	float getSpeed() { return _speed; }
	void setSpeed(float s) { _speed = s; }

	void zoom(HDC hdc, float ratio);
};

