#include <General.h>

void th15::enemysb()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[] = { 0x2B, 0xC1, 0x89, 0x07 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x00424E06, z, sizeof(z), NULL);
}

void th15::enemyinv()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[] = { 0x90, 0x90, 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x00424E06, z, sizeof(z), NULL);
}

void th15::powerres()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char A[] = { 0x2B, 0x4D, 8 };
	unsigned char inc = 0x41;
	unsigned char z[] = { 0x89, 0x0D, 0x40, 0x74, 0x4E, 0 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x0044021E, &inc, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x0045830B, z, sizeof(z), NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x004582F9, A, sizeof(A), NULL);
}

void th15::powerlock()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char nop1 = 0x90;
	unsigned char A[] = { 0x90, 0x90, 0x90 };
	unsigned char z[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x0044021E, &nop1, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x0045830B, z, sizeof(z), NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x004582F9, A, sizeof(A), NULL);
}

void th15::des()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char four = 4;
	WriteProcessMemory(hSnapshot, (LPVOID)0x004566A5, &four, 1, NULL);
}

void th15::invincible()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char one = 1;
	WriteProcessMemory(hSnapshot, (LPVOID)0x004566A5, &one, 1, NULL);
}

void th15::noauto()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char bomb[] = { 0x0F, 0x84, 0x13, 0x01 };
	unsigned char zero[] = { 0x00, 0x00 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x00454CD0, bomb, 4, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x00454CD4, zero, 2, NULL);
}

void th15::autobomb()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x00454CD0, z, sizeof(z), NULL);
}

void th15::timeres()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[] = { 0xE8, 0x3F, 0, 0xFE, 0xFF };
	WriteProcessMemory(hSnapshot, (LPVOID)0x00428B5C, z, sizeof(z), NULL);
}

void th15::timelock()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[] = { 0x83, 0xC4, 4, 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x00428B5C, z, sizeof(z), NULL);
}

void th15::playerres()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char dec = 0x48, inc = 0x41;
	WriteProcessMemory(hSnapshot, (LPVOID)0x00456397, &dec, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x0044FAC0, &inc, 1, NULL);
}

void th15::playerlock()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char nop = 0x90;
	WriteProcessMemory(hSnapshot, (LPVOID)0x00456397, &nop, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x0044FAC0, &nop, 1, NULL);
}

void th15::bombres()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char A[] = { 0xC7, 0x05, 0x5C, 0x74, 0x4E, 0, 3, 0, 0, 0 };
	unsigned char B[] = { 0xC7, 5, 0x5C, 0x74, 0x4E, 0, 3, 0, 0, 0 };
	unsigned char inc = 0x40, dec = 0x48;
	WriteProcessMemory(hSnapshot, (LPVOID)0x0044FB85, &inc, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x00414963, &dec, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x00454D6F, B, sizeof(B), NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x00454D6F, A, sizeof(A), NULL);
}

void th15::bomblock()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char nop = 0x90;
	unsigned char A[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x0044FB85, &nop, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x00414963, &nop, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x00454D6F, A, sizeof(A), NULL);
}

bool th15::isRunning()
{
	LPCTSTR name = L"搶曽嵁庫揱丂乣 Legacy of Lunatic Kingdom. ver 1.00b";
	LPCTSTR name1 = L"东方绀珠传　～ Legacy of Lunatic Kingdom. ver 1.00b";
	LPCTSTR name3 = L"東方紺珠伝　～ Legacy of Lunatic Kingdom. ver 1.00b";
	PROCESSENTRY32 tmppe;
	DWORD id = 0, TID1, PID1, TID2, PID2, TID3, PID3;
	HANDLE tmphSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	HWND hCurrentWindow = FindWindow(NULL, name);
	HWND hCurrentWindow1 = FindWindow(NULL, name1);
	HWND hCurrentWindow3 = FindWindow(NULL, name3);
	TID1 = GetWindowThreadProcessId(hCurrentWindow, &PID1);
	TID2 = GetWindowThreadProcessId(hCurrentWindow1, &PID2);
	TID3 = GetWindowThreadProcessId(hCurrentWindow3, &PID3);
	tmppe.dwSize = sizeof(PROCESSENTRY32);
	if (!Process32First(tmphSnapshot, &tmppe)) return false;
	do
	{
		tmppe.dwSize = sizeof(PROCESSENTRY32);
		if (Process32Next(tmphSnapshot, &tmppe) == FALSE) return false;
		if ((tmppe.th32ProcessID == PID1) || (tmppe.th32ProcessID == PID2) || (tmppe.th32ProcessID == PID3))
		{
			pe = tmppe;
			hSnapshot = tmphSnapshot;
			return true;
		}
	} while (1);
}
