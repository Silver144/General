#include <General.h>

void th17::autobomb()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[6] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x004427A8, z, 6, NULL);
}

void th17::noauto()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[6] = { 0x0F, 0x84, 0x72, 0x02, 0x0, 0x0 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x004427A8, z, 6, NULL);
}

void th17::invincible()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z = 1;
	WriteProcessMemory(hSnapshot, (LPVOID)0x00443FE1, &z, 1, NULL);
}

void th17::des()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z = 4;
	WriteProcessMemory(hSnapshot, (LPVOID)0x00443FE1, &z, 1, NULL);
}
