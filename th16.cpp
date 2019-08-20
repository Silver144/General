#include <General.h>

void th16::invincible()
{
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z = 1;
	WriteProcessMemory(hSnapshot, (LPVOID)0x00443FE1, &z, 1, NULL);
}

void th16::des()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z = 4;
	WriteProcessMemory(hSnapshot, (LPVOID)0x00443FE1, &z, 1, NULL);
}

void th16::enemysb()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[2] = { 0x89, 0x07 };
	unsigned char y[2] = { 0x2B, 0xC1 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x0041A70D, z, 2, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x0041A716, y, 2, NULL);
}

void th16::enemyinv()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	
	unsigned char z[2] = { 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x0041A70D, z, 2, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x0041A716, z, 2, NULL);
}

void th16::autobomb()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[6] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x004427A8, z, 6, NULL);
}

void th16::noauto()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[6] = { 0x0F, 0x84, 0x72, 0x02, 0x0, 0x0 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x004427A8, z, 6, NULL);
}

void th16::timelock()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[2] = { 5, 141 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x0041D4EF, z, 2, NULL);
}

void th16::timeres()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[2] = { 157, 140 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x0041D4EF, z, 2, NULL);
}

void th16::playerres()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char dec = 0x48;
	WriteProcessMemory(hSnapshot, (LPVOID)0x00443D39, &dec, 1, NULL);
}

void th16::playerlock()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char nop = 0x90;
	WriteProcessMemory(hSnapshot, (LPVOID)0x00443D39, &nop, 1, NULL);
}

void th16::bombres()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[3] = { 0x83, 0xE8, 1 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x0040DB83, z, 3, NULL);
}

void th16::bomblock()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char z[3] = { 0x90, 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x0040DB83, z, 3, NULL);
}

void th16::powerres()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char inc = 0x47;
	unsigned char z[6] = { 0x89, 0x0D, 0xE4, 0x57, 0, 0x4A };
	WriteProcessMemory(hSnapshot, (LPVOID)0x004302B3, &inc, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x00442749, z, 6, NULL);
}

void th16::powerlock()
{
	
	hSnapshot = OpenProcess(PROCESS_ALL_ACCESS, false, (DWORD)pe.th32ProcessID);
	unsigned char inc = 0x90;
	unsigned char z[6] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
	WriteProcessMemory(hSnapshot, (LPVOID)0x004302B3, &inc, 1, NULL);
	WriteProcessMemory(hSnapshot, (LPVOID)0x00442749, z, 6, NULL);
}

bool th16::isRunning()
{
	LPCTSTR name = L"搶曽揤嬻圉丂乣 Hidden Star in Four Seasons. ver 1.00a";
	LPCTSTR namex = L"东方天空璋　～ Hidden Star in Four Seasons. ver 1.00a";
	LPCTSTR namey = L"東方天空璋丂乣 Hidden Star in Four Seasons. ver 1.00a";
	PROCESSENTRY32 tmppe;
	DWORD id = 0, TID1, PID1 = -1, TID2, PID2 = -1, PID3 = -1, TID3;
	HANDLE tmphSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	HWND hCurrentWindow1 = FindWindow(NULL, name);
	HWND hCurrentWindow2 = FindWindow(NULL, namex);
	HWND hCurrentWindow3 = FindWindow(NULL, namey);
	TID1 = GetWindowThreadProcessId(hCurrentWindow1, &PID1);
	TID2 = GetWindowThreadProcessId(hCurrentWindow2, &PID2);
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
			current_game = "tkz";
			return true;
		}
	} while (1);
}