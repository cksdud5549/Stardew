#pragma once

#define MAGENTA RGB(255,0,255)
#define CYAN RGB(0,255,255)
#define YELLOW RGB(255,255,0)
#define BLACK RGB(0,0,0)
#define WHITE RGB(255,255,255)

//////////////////////////////
#define RadToDeg (float)180/PI        // ���� -> ��׸�
#define DegToRad (float)PI/180		  // ��׸� -> ����

//////////////////////////////
#define IMAGECOOR 376, 126

#define TILESIZE 64	//Ÿ�� ������
#define ClIPPINGY 15
#define ClIPPINGX 26 

/////////////////////////////
#define LOADINGMAX 500	
////////////////////////////
#define INVENIMAGECOOR 376, 126			//�κ��丮 �̹��� ��ġ ��
#define ALPHAVALUEMAX 230				//��ο����� �� �ִ� ���İ�
#define REALTIMEMAX 860				//���� �� �ִ� �ð�, [���� �ΰ��� �ð��� 860]
#define REALTIMEHALF REALTIMEMAX / 2	//���� �� �ִ� �ð��� �� ��/�� ����
#define ALPHADELAY REALTIMEMAX / 10		//���ķ��� �����̰�
#define CLOCKMOVEDANGLE 0.029f			//�ð� ���� ��ȭ �ӵ�
#define CLOCKTIMEMAX 109.f				//�ð� �ִ� ��
#define CLOCKTIMEHALF CLOCKTIMEMAX / 2	//�ð� ���� ��
//////////////////////////////