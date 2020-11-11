#pragma once
#include "GameObject.h"

struct DialogElement
{
	wstring text;
	wstring name;
	Pokemon number;
	bool isLeft = false;
};

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
	static void EnqueueText(const wstring& _text, bool isLeft = false);
	static void EnqueueText(const wstring& _text, const wstring& name, Pokemon number, bool isLeft = false);
	static void EnqueueText(const DialogElement& elem);
	
	static void SetEndEvent(void(*Func)());
private:
	DialogElement element;
	wstring currText;
	int copyCount = 0;
	queue<DialogElement> textQ;

	float tick = 0.f;
	float delay = 0.1f;
	void (*End)() = nullptr;

};

