#include <iostream>
#include <Windwos.h>
#include <strings>

using namespace std;

DWORD pid; //process id

DWORD Plyaer = 0xB6F5F0;
DOWRD Money = 0XB7CE50;

int main() {
	HWND hWND = FindWindowA(0, ("GTA: SAN ANDREAS"));

	GetWindowsThreadProcessId(hWND, &pid);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, False, pid);

	float hp;
	ReadProcessMemory(pHandle, (LPVOID)Player, &Player, sizeof(Player), 0);
	ReadProcessMemory(pHandle, (LPVOID)(Player + 0x540), &hp, sizeof(hp), 0);

	cout << "Health : " << hp << endl;

}
