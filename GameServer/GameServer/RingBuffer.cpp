#include "stdafx.h"
#include "RingBuffer.h"


RingBuffer::RingBuffer()
{
	Initial(DEFALT_SIZE);
}

RingBuffer::RingBuffer(int iBufferSize)
{
	Initial(iBufferSize);
}

RingBuffer::~RingBuffer()
{
	if (buffer != nullptr)
	{
		delete buffer;
	}
}

void RingBuffer::Initial(int iBufferSize)
{
	buffer = new char[iBufferSize];
	memset(buffer, 0, iBufferSize);
	size = iBufferSize;
	front = rear = 0;
}

bool RingBuffer::isEmpty()
{
	return (front == rear);
}

bool RingBuffer::Resize(int resize)
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

int RingBuffer::GetBufferSize(void)
{
	return size;
}

int RingBuffer::GetUseSize(void)
{
	if (front > rear)
	{
		return (size - (front - rear));

	}
	return (rear - front);
}

int RingBuffer::GetFreeSize(void)
{
	int re = 0;
	re = (size - 1) - GetUseSize();
	return re;
}

int RingBuffer::GetDeqSize(void) // 디큐사이즈
{
	int re = size - front;
	int use = GetUseSize();

	if (use > re)
	{
		return re;
	}
	else
	{
		return use;
	}
}

int RingBuffer::GetEnqSize(void) // 인큐사이즈
{
	int re = size - rear;
	int free = GetFreeSize();

	if (free > re)
	{
		return re;
	}
	else
	{
		return free;
	}
}

int RingBuffer::Enqueue(char* chpData, int iSize)
{
	int len = iSize;
	int free = GetFreeSize();
	//if (free < iSize)
	//{
	//	Resize(size+iSize + 1);
	//	free = GetFreeSize();

	//}
	int part = GetEnqSize();
	char* pData = chpData;
	char* ptr = GetRearBufferPtr();

	if (iSize == 0) { return 0; }
	if (free < iSize) { len = free; }

	if (len > part)
	{
		for (int i = 0; i < part; i++)
		{
			*ptr = *pData;
			ptr++;
			pData++;
		}
		ptr = buffer;
		part = len - part;
		for (int i = 0; i < part; i++)
		{
			*ptr = *pData;
			ptr++;
			pData++;
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			*ptr = *pData;
			ptr++;
			pData++;
		}
	}

	MoveRear(len);

	return len;
}

int RingBuffer::Dequeue(char* chpDest, int iSize)
{
	int len = iSize;
	int use = GetUseSize();
	int part = GetDeqSize();
	char* pDest = chpDest;
	char* ptr = GetFrontBufferPtr();

	if (iSize == 0) { return 0; }
	if (use < iSize) { len = use; }

	if (len > part)
	{
		for (int i = 0; i < part; i++)
		{
			*pDest = *ptr;
			ptr++;
			pDest++;
		}
		ptr = buffer;
		part = len - part;
		for (int i = 0; i < part; i++)
		{
			*pDest = *ptr;
			ptr++;
			pDest++;
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			*pDest = *ptr;
			ptr++;
			pDest++;
		}
	}

	MoveFront(len);

	return len;
}

int RingBuffer::Peek(char* chpDest, int iSize)
{
	int len = iSize;
	int use = GetUseSize();
	int part = GetDeqSize();
	char* pDest = chpDest;
	char* ptr = GetFrontBufferPtr();

	if (iSize == 0) { return 0; }
	if (use < iSize) { len = use; }

	if (len > part)
	{
		for (int i = 0; i < part; i++)
		{
			*pDest = *ptr;
			ptr++;
			pDest++;
		}
		ptr = buffer;
		part = len - part;
		for (int i = 0; i < part; i++)
		{
			*pDest = *ptr;
			ptr++;
			pDest++;
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			*pDest = *ptr;
			ptr++;
			pDest++;
		}
	}

	return len;
}

void RingBuffer::MoveRear(int iSize)
{
	int re = rear + iSize;

	rear = re % size;
}

int RingBuffer::MoveFront(int iSize)
{
	int re = front + iSize;
	front = re % size;
	return front;
}

void RingBuffer::ClearBuffer(void)
{
	front = rear = 0;
}

char* RingBuffer::GetFrontBufferPtr(void)
{
	return &buffer[front];
}

char* RingBuffer::GetRearBufferPtr(void)
{
	return &buffer[rear];
}
