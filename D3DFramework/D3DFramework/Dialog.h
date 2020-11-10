#pragma once
#include "GameObject.h"

class Dialog : public GameObject
{
private:
	Dialog();
	virtual ~Dialog();

public:
	static Dialog* GetInstance();
	static void Destroy();

	virtual void Initialize() override;
	virtual void Release() override;

	static void Show();
	static void Hide();

	virtual void Update() override;
	virtual void Render() override;

	// 대화 내용 대기열에 삽입
	static void EnqueueText(const wstring& _text);
	

private:
	wstring readyText;
	wstring currText;
	int copyCount = 0;
	queue<wstring> textQ;

	float tick = 0.f;
	float delay = 0.1f;

};

