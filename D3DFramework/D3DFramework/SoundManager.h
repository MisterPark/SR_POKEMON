#pragma once

namespace PKH
{
	enum SoundChannel { BGM, PLAYER, MONSTER, EFFECT, MAXCHANNEL };

	class SoundManager
	{
	public:
		static SoundManager* GetInstance();
		static void Destroy();

	private:
		SoundManager();
		~SoundManager();

	public:
		static void Initialize();

		static void Release();
	public:
		static void PlaySound(TCHAR* pSoundKey, SoundChannel eID);
		static void PlayBGM(TCHAR* pSoundKey);
		static void StopSound(SoundChannel eID);
		static void StopAll();
		static void SetVolume(SoundChannel channel, float per);

	private:
		static void LoadSoundFile();

	private:
		// ���� ���ҽ� ������ ���� ��ü 
		map<TCHAR*, FMOD_SOUND*> soundMap;
		// FMOD_CHANNEL : ����ϰ� �ִ� ���带 ������ ��ü 
		FMOD_CHANNEL* channels[MAXCHANNEL];
		// ���� ,ä�� ��ü �� ��ġ�� �����ϴ� ��ü 
		FMOD_SYSTEM* pSystem;

	};


}
