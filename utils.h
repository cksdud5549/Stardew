#pragma once

#define PI 3.14159f
#define PI2 PI * 2

//������ ȸ�������� ������ ���ϰ� �ϱ� ���� ��ũ��
#define PI8 float(PI / 8.0f) //45
#define PI16 float(PI / 16.0f) // 22.5
#define PI32 float(PI / 32.0f) // 11.25
#define PI64 float(PI / 64.0f) // 5.625
#define PI128 float(PI / 128.0f) // 2.8125


#define FLOAT_EPSILON 0.001f	//�Ǽ��� ���� ���� ������ ��Ī�ϴ� �׸���� ���Ƿ�
#define FLOAT_EQUAL(f1, f2) (fabs(f1, f2) <= FLOAT_EPSILON)	//�� �Ǽ��� ������ �� ����
#define FLOAT_TO_INT(f1) static_cast<int>(f1 + FLOAT_EPSILON) //�Ǽ����� ����������

namespace TTYONE_UTIL
{
	float getDistance(float startX, float startY, float endX, float endY);

	float getAngle(float x1, float y1, float x2, float y2);
}
