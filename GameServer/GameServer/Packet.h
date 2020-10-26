#pragma once

#pragma pack(push,1)
typedef struct st_NETWORK_PACKET_HEADER
{
	BYTE	byCode;			// 패킷코드 0x89 고정.
	BYTE	bySize;			// 패킷 사이즈.
	BYTE	byType;			// 패킷타입.
	BYTE	byTemp;			// 사용안함.
}PACKET_HEADER;

typedef BYTE ENDCODE;
#pragma pack(pop)

class Packet
{
public:
	enum en_Packet
	{
		eBUFFER_DEFAULT = 10000
	};
	Packet();
	Packet(int iBufferSize);
	Packet(const Packet& clSrcPacket);
	virtual ~Packet();

protected:
	void Initial(int iBufferSize = eBUFFER_DEFAULT);
	void Release(void);
	bool Resize(unsigned int resize);

public:
	void Clear(void);
	int GetBufferSize(void);
	int GetPacketSize(void);
	char* GetBufferPtr(void);
	char* GetReadPtr(void);
	char* GetWritePtr(void);
	int GetReadPos(void);
	int GetWritePos(void);
	int MoveWritePos(int iSize);
	int MoveReadPos(int iSize);

	Packet& operator = (const Packet& pack);

	Packet& operator << (bool value);
	Packet& operator << (char value);
	Packet& operator << (short	value);
	Packet& operator << (int value);
	Packet& operator << (long value);
	Packet& operator << (float	value);
	Packet& operator << (double value);
	Packet& operator << (__int64 value);
	Packet& operator << (unsigned char value);
	Packet& operator << (unsigned short value);
	Packet& operator << (unsigned int value);
	Packet& operator << (unsigned long value);

	Packet& operator >> (bool& value);
	Packet& operator >> (char& value);
	Packet& operator >> (short& value);
	Packet& operator >> (int& value);
	Packet& operator >> (long& value);
	Packet& operator >> (float& value);
	Packet& operator >> (double& value);
	Packet& operator >> (__int64& value);
	Packet& operator >> (unsigned char& value);
	Packet& operator >> (unsigned short& value);
	Packet& operator >> (unsigned int& value);
	Packet& operator >> (unsigned long& value);

	int Enqueue(char* chpSrc, int iSize);
	int Dequeue(char* chpDest, int iSize);

protected:
	char* buffer = nullptr;
	unsigned int read = 0;
	unsigned int write = 0;
	unsigned int size = 0;
};

