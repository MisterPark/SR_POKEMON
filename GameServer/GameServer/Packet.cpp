#include "stdafx.h"
#include "Packet.h"
#include <iostream>


Packet::Packet()
{
	Initial();
}

Packet::Packet(int iBufferSize)
{
	Initial(iBufferSize);
}

Packet::Packet(const Packet& clSrcPacket)
{
	Initial(clSrcPacket.size);
	memcpy_s(buffer, clSrcPacket.size, clSrcPacket.buffer, clSrcPacket.size);
	write = clSrcPacket.write;
	read = clSrcPacket.read;
}


Packet::~Packet()
{
	if (buffer != nullptr) { delete buffer; }
}

void Packet::Initial(int iBufferSize)
{
	buffer = new char[iBufferSize];
	memset(buffer, 0, iBufferSize);
	size = iBufferSize;
	read = write = 0;
}

void Packet::Release(void)
{
	delete buffer;
	buffer = nullptr;
}

bool Packet::Resize(unsigned int resize)
{
	char* rebuf = new char[resize];
	if (rebuf == NULL) { return false; }
	for (unsigned int i = 0; i < resize; i++)
	{
		if (i < size)
		{
			rebuf[i] = buffer[i];
		}
		else
		{
			rebuf[i] = '\0';
		}
	}
	size = resize;

	char* target = buffer;
	delete target;
	buffer = rebuf;

	return true;
}

void Packet::Clear(void)
{
	read = write = 0;
}

int Packet::GetBufferSize(void)
{
	return size;
}

int Packet::GetPacketSize(void)
{
	return (write - read);
}

char* Packet::GetBufferPtr(void)
{
	return buffer;
}

char* Packet::GetReadPtr(void)
{
	return &buffer[read];
}

char* Packet::GetWritePtr(void)
{
	return &buffer[write];
}

int Packet::GetReadPos(void)
{
	return read;
}

int Packet::GetWritePos(void)
{
	return write;
}

int Packet::MoveWritePos(int iSize)
{
	if (iSize <= 0) { return 0; }
	if (write + iSize > size)
	{
		int resize = write + iSize;
		resize = resize / 50;
		resize = (resize + 1) * 50;
		Resize(resize);
	}
	return (write += iSize);
}

int Packet::MoveReadPos(int iSize)
{
	if (iSize <= 0) { return 0; }
	if (read + iSize > size)
	{
		int resize = write + iSize;
		resize = resize / 50;
		resize = (resize + 1) * 50;
		Resize(resize);
	}
	return (read += iSize);
}

Packet & Packet::operator=(const Packet & pack)
{
	if (buffer != nullptr)
	{
		delete buffer;
		buffer = nullptr;
	}
	Packet p = pack;
	int len = p.size;
	Initial(len);
	memcpy_s(buffer, len, p.buffer, len);
	read = p.read;
	write = p.write;

	return *this;
}

Packet& Packet::operator<<(bool value)
{
	if (write + sizeof(bool) < size)
	{
		bool* dest = (bool*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(bool));
	}
	return *this;
}

Packet& Packet::operator<<(char value)
{
	if (write + sizeof(char) < size)
	{
		char* dest = (char*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(char));
	}
	return *this;
}

Packet& Packet::operator<<(short value)
{
	if (write + sizeof(short) < size)
	{
		short* dest = (short*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(short));
	}
	return *this;
}

Packet& Packet::operator<<(int value)
{
	if (write + sizeof(int) < size)
	{
		int* dest = (int*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(int));
	}
	return *this;
}

Packet& Packet::operator<<(long value)
{
	if (write + sizeof(long) < size)
	{
		long* dest = (long*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(long));
	}
	return *this;
}

Packet& Packet::operator<<(float value)
{
	if (write + sizeof(float) < size)
	{
		float* dest = (float*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(float));
	}
	return *this;
}

Packet& Packet::operator<<(double value)
{
	if (write + sizeof(double) < size)
	{
		double* dest = (double*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(double));
	}
	return *this;
}

Packet& Packet::operator<<(__int64 value)
{
	if (write + sizeof(__int64) < size)
	{
		__int64* dest = (__int64*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(__int64));
	}
	return *this;
}

Packet& Packet::operator<<(unsigned char value)
{
	if (write + sizeof(unsigned char) < size)
	{
		unsigned char* dest = (unsigned char*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(unsigned char));
	}
	return *this;
}

Packet& Packet::operator<<(unsigned short value)
{
	if (write + sizeof(unsigned short) < size)
	{
		unsigned short* dest = (unsigned short*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(unsigned short));
	}
	return *this;
}

Packet& Packet::operator<<(unsigned int value)
{
	if (write + sizeof(unsigned int) < size)
	{
		unsigned int* dest = (unsigned int*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(unsigned int));
	}
	return *this;
}

Packet& Packet::operator<<(unsigned long value)
{
	if (write + sizeof(unsigned long) < size)
	{
		unsigned long* dest = (unsigned long*)& buffer[write];
		*dest = value;
		MoveWritePos(sizeof(unsigned long));
	}
	return *this;
}

Packet& Packet::operator>>(bool& value)
{
	if (read + sizeof(bool) < size)
	{
		bool* src = (bool*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(bool));
	}
	return *this;
}

Packet& Packet::operator>>(char& value)
{
	if (read + sizeof(char) < size)
	{
		char* src = (char*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(char));
	}
	return *this;
}

Packet& Packet::operator>>(short& value)
{
	if (read + sizeof(short) < size)
	{
		short* src = (short*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(short));
	}
	return *this;
}

Packet& Packet::operator>>(int& value)
{
	if (read + sizeof(int) < size)
	{
		int* src = (int*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(int));
	}
	return *this;
}

Packet& Packet::operator>>(long& value)
{
	if (read + sizeof(long) < size)
	{
		long* src = (long*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(long));
	}
	return *this;
}

Packet& Packet::operator>>(float& value)
{
	if (read + sizeof(float) < size)
	{
		float* src = (float*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(float));
	}
	return *this;
}

Packet& Packet::operator>>(double& value)
{
	if (read + sizeof(double) < size)
	{
		double* src = (double*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(double));
	}
	return *this;
}

Packet& Packet::operator>>(__int64& value)
{
	if (read + sizeof(__int64) < size)
	{
		__int64* src = (__int64*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(__int64));
	}
	return *this;
}

Packet& Packet::operator>>(unsigned char& value)
{
	if (read + sizeof(unsigned char) < size)
	{
		unsigned char* src = (unsigned char*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(unsigned char));
	}
	return *this;
}

Packet& Packet::operator>>(unsigned short& value)
{
	if (read + sizeof(unsigned short) < size)
	{
		unsigned short* src = (unsigned short*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(unsigned short));
	}
	return *this;
}

Packet& Packet::operator>>(unsigned int& value)
{
	if (read + sizeof(unsigned int) < size)
	{
		unsigned int* src = (unsigned int*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(unsigned int));
	}
	return *this;
}

Packet& Packet::operator>>(unsigned long& value)
{
	if (read + sizeof(unsigned long) < size)
	{
		unsigned long* src = (unsigned long*)& buffer[read];
		value = *src;
		MoveReadPos(sizeof(unsigned long));
	}
	return *this;
}

int Packet::Enqueue(char* chpSrc, int iSize)
{
	int re = iSize;
	int free = size - write;
	if (iSize <= 0 || free == 0) { return 0; }

	if (free < iSize)
	{
		Resize(iSize);
		//re = free;
	}

	char* dest = GetWritePtr();
	char* src = chpSrc;

	for (int i = 0; i < re; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}

	MoveWritePos(re);

	return re;
}

int Packet::Dequeue(char* chpDest, int iSize)
{
	int re = iSize;
	int packSize = GetPacketSize();
	if (iSize <= 0 || packSize == 0) { return 0; }

	if (packSize < iSize)
	{
		re = packSize;
	}

	char* dest = chpDest;
	char* src = GetReadPtr();

	for (int i = 0; i < re; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}

	MoveReadPos(re);

	return re;
}
