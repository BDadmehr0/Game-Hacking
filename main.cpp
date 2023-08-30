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

	static bool godmode;

	while (true) {
		
		if(GetAsynKeyState(0x74) != 0) { // 0x74 = F5 key check push
			godmode = !godmode;
			cout << "GodMode: " << godmode << endl;
			Beep(500, 500)
			Sleep(10) // anti game crash
		}

		if(godmode) {
			float newhp = 100;

			WriteProccessMemory(pHandle, (LPVOID)(Player + 0x540), &newhp, sizeof(newhp), 0);
		}
	}
}
