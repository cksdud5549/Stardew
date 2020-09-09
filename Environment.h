#pragma once

struct tagClockHand
{
	POINT center;		//����
	POINT end;			//�ð�ħ ����
	int length;			//�ð�ħ ����
	float angle;		//�ð�ħ ����
	int count;			//�ð� ī��Ʈ
	int value;			//�ð� ��(���� �ð�ħ�� ��ġ)
};

class Environment : public singletonBase<Environment>
{
private:
	Environment() {};

	tagClockHand _clockHand;	//�ð�ħ struct

	int _alphaValue;			//���İ�

	int _monthCount;			//��
	int _dayOfWeek;				//����
	int _dayCount;				//��
	int _hour;					//�ð�
	int _minute;				//��

	float _timeRatio;			//�ð� �� ĭ �ۼ�Ʈ

	float _clockCalculate;		//�ð� ���

	float _elapsedTime;			//����� �ð�
	float _realTimeSecond;		//���ǽð�(��)

	bool _isInventoryOpen;		//�κ��丮�� ������
	bool _isDayIncrease;		//��¥�� �����ϸ�

	bool _isDayReset;

	bool _timeOut;

	float _delay;
	float _count;

	bool timeUpdate(const float count)
	{
		_count += count;
		if (_count >= _delay)
		{
			_count -= _delay;
			return true;
		}
		return false;
	}

public:
	~Environment() {};

	HRESULT init();
	void release();
	void update();
	void render(HDC _hdc);

	static Environment* GetInstance()
	{
		static Environment* _env;
		if (!_env)
		{
			_env = new Environment;
			return _env;
		}
		else return _env;
	}

	int GetCluckValue() { return _clockHand.value; }				//�ð� ��
	int GetDayCount() { return _dayCount; }							//��¥ ��
	int GetHour() { return _hour; }
	bool GetIsDayIncrease() { return _isDayIncrease; }				//��¥�� �����ϸ�
	bool GetIsInventoryOpen() { return _isInventoryOpen; }			//�κ��丮�� ������
	bool GetTimeOut() { return _timeOut; }
	void SetIsInventoryOpen(bool open) { _isInventoryOpen = open; }	//�κ��丮��
	void SetIsDayReset(bool reset) { _isDayReset = reset; }			//��¥ �ѱ��
	void SetHour(int hour) { _hour = hour; }
	void SetMinute(int minute) { _minute = minute; }
};

