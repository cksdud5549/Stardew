#include "stdafx.h"
#include "cameraManager.h"

cameraManager::cameraManager()
{
}

cameraManager::~cameraManager()
{
}

HRESULT cameraManager::init()
{
	return S_OK;
}

void cameraManager::release()
{
}

// �ʱ� ����, _L, _T�� ī�޶��� LEFT, TOP
void cameraManager::setConfig(float L, float T, float width, float height, float minL, float minT, float maxL, float maxT)
{
	_L = L;
	_T = T;
	_width = width;
	_height = height;
	_minL = minL;
	_minT = minT;
	_maxL = maxL;
	_maxT = maxT;

	_x = _L + (_width / 2);
	_y = _T + (_height / 2);
	_minX = _minL + (_width / 2);
	_minY = _minT + (_height / 2);
	_maxX = _maxL + (_width / 2);
	_maxY = _maxT + (_height / 2);
}

void cameraManager::setConfigCenter(float x, float y, float width, float height, float minX, float minY, float maxX, float maxY)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_minX = minX;
	_minY = minY;
	_maxX = maxX;
	_maxY = maxY;

	_L = _x - (width / 2);
	_T = _y - (height / 2);
	_minL = _minX - (width / 2);
	_minT = _minY - (height / 2);
	_maxL = _maxX - (width / 2);
	_maxT = _minY - (height / 2);
}

float cameraManager::getL()
{
	return _L;
}

float cameraManager::getT()
{
	return _T;
}

float cameraManager::getX()
{
	return _x;
}

float cameraManager::getY()
{
	return _y;
}

void cameraManager::setL(float newL)
{
	newL = min(_maxL, newL);
	newL = max(_minL, newL);
	_L = floor(newL);
	_x = _L + (_width / 2);
}

void cameraManager::setT(float newT)
{
	newT = min(_maxT, newT);
	newT = max(_minT, newT);
	_T = floor(newT);
	_y = _T + (_height / 2);
}

// ī�޶��� ������ X�� ����
void cameraManager::setX(float newX)
{
	newX = min(_maxX, newX);
	newX = max(_minX, newX);
	_x = floor(newX);
	_L = _x - (_width / 2);
}

// ī�޶��� ������ Y�� ����
void cameraManager::setY(float newY)
{
	newY = min(_maxY, newY);
	newY = max(_minY, newY);
	_y = floor(newY);
	_T = _y - (_height / 2);
}

// ī�޶��� �������� �̵���Ŵ
void cameraManager::movePivot(float offsetX, float offsetY)
{
	setL(_L + offsetX);
	setT(_T + offsetY);
	setX(_x + offsetX);
	setY(_y + offsetY);
}

// ī�޶��� �������� �������� �����ǥ X���� ����
float cameraManager::getRelativeX(float x)
{
	float newX = x - _L;
	return newX;
}

// ī�޶��� �������� �������� �����ǥ Y���� ����
float cameraManager::getRelativeY(float y)
{
	float newY = y - _T;
	return  newY;
}

// �簢�� �׸��� MYRECT ���
void cameraManager::rectangle(HDC hdc, TTYONE_UTIL::MYRECT mrec)
{
	RECT rect = { getRelativeX(mrec.left), getRelativeY(mrec.top), getRelativeX(mrec.right), getRelativeY(mrec.bottom) };
	Rectangle(hdc, rect);
}
void cameraManager::rectangle(HDC hdc, TTYONE_UTIL::MYRECT mrec, float destX, float destY)
{
	float newX = getRelativeX(destX);
	float newY = getRelativeY(destY);
	RECT rect = { getRelativeX(mrec.left), getRelativeY(mrec.top), getRelativeX(mrec.right), getRelativeY(mrec.bottom) };
	Rectangle(hdc, rect	,destX,destY);
}
// ���׶�� �׸��� MYRECT ���
void cameraManager::ellipse(HDC hdc, TTYONE_UTIL::MYRECT mrec)
{
	RECT rect = { getRelativeX(mrec.left), getRelativeY(mrec.top), getRelativeX(mrec.right), getRelativeY(mrec.bottom) };
	Ellipse(hdc, rect);
}

void cameraManager::render(HDC hdc, image* img)
{
	if (img) img->render(hdc, _x, _y);
}

void cameraManager::render(HDC hdc, image* img, float destX, float destY)
{
	float newX = getRelativeX(destX);
	float newY = getRelativeY(destY);
	if (img) img->render(hdc, newX, newY);
}

void cameraManager::render(HDC hdc, image* img, float destX, float destY, float sourX, float sourY, float sourWidth, float sourHeight)
{
	float newX = getRelativeX(destX);
	float newY = getRelativeY(destY);
	if (img) img->render(hdc, newX, newY, sourX, sourY, sourWidth, sourHeight);
}
void cameraManager::alpharender(HDC hdc, image* img, float destX, float destY, int alpha)
{
	float newX = getRelativeX(destX);
	float newY = getRelativeY(destY);
	if (img) img->alphaRender(hdc, newX, newY, alpha);
}
void cameraManager::frameRender(HDC hdc, image* img, float destX, float destY)
{
	float newX = getRelativeX(destX);
	float newY = getRelativeY(destY);
	if (img) img->frameRender(hdc, newX, newY);
}

void cameraManager::frameRender(HDC hdc, image* img, float destX, float destY, int frameX, int frameY)
{
	float newX = getRelativeX(destX);
	float newY = getRelativeY(destY);
	if (img) img->frameRender(hdc, newX, newY, frameX, frameY);
}

void cameraManager::AniRender(HDC hdc,image* img, float destX, float destY, animation* ani)
{
	float newX = getRelativeX(destX);
	float newY = getRelativeY(destY);
	if (img) img->render(hdc, newX, newY, ani->getFramePos().x, ani->getFramePos().y,(float) ani->getFrameWidth(), (float)ani->getFrameHeight());
}

void cameraManager::KeyAniRender(HDC hdc, image* img, string KeyName, float destX, float destY, animation* ani)
{
	float newX = getRelativeX(destX);
	float newY = getRelativeY(destY);
	if (img) img->aniRender(hdc, newX, newY, ani);
}

void cameraManager::KeyAnialphaRender(HDC hdc, image* img, float destX, float destY, animation* ani, int alpha)
{
	float newX = getRelativeX(destX);
	float newY = getRelativeY(destY);
	if (img) img->alphaAniRedRender(hdc, newX, newY, ani ,alpha);
}

void cameraManager::zoom(HDC hdc, float ratio)
{
	if (ratio == 1) return;

	float newWidth = (float)_width / ratio;
	float newHeight = (float)_height / ratio;

	float zoomL = WINSIZEX / 2 - (newWidth / 2);
	float zoomT = WINSIZEY / 2 - (newHeight / 2);

	StretchBlt(hdc, 0, 0, _width, _height,
		hdc, zoomL, zoomT, newWidth, newHeight,
		SRCCOPY);

	// �� ������ ���� Zoom ����
}


