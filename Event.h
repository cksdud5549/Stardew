#pragma once
class Event
{
public:
	//�̺�Ʈ�� �����Ҷ� ������ �Լ�
	virtual void EventStart(float centerX, float centerY) = 0;
	//�̺�Ʈ ������Ʈ
	virtual bool EventUpdate() = 0;

};

class StopCamera : public Event
{

public:

	void EventStart(float centerX, float centerY)override;
	bool EventUpdate()override;
};