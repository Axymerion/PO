#pragma once

enum FrameType {ECHO = 0x00, TEXT, RECV_FILE, SEND_FILE, FILE_DATA, END_OF_FILE, INVALID_COMMAND};

struct Frame
{
	char type;
	unsigned short len;
	char data[1024];
};