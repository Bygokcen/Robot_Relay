#include"icb_gui.h"
#include <Windows.h>
#include <stdio.h>


// RELAY NUMARALARI

/// <summary>
/// 
/// 8. numarali role pilleri aktif hale getirir.
/// 
/// 7. numarali role sol motoru ileri yonde çalistirir.
/// 
/// 6. numarali role sol motoru geri yonde calistirir.
/// 
/// 5. numarali role sag motoru ileri yonde calistirir.
/// 
/// 4. numarali role sag motoru geri yonde calistirir.
/// 
/// </summary>
// Tekerlek renkleri için global değişkenler
int solOnTekerRenk = 0;    // 0: sarı, 1: Yeşil 2: kirmisi
int solArkaTekerRenk = 0;  
int sagOnTekerRenk = 0;    
int sagArkaTekerRenk = 0;  

static ICBYTES m;
int FRM1, MLE, FRM2, SLE1;

// Global değişkenler
int hareketSuresi = 1000; // milisaniye cinsinden
bool kameraAcik = false;  // Kamera durumunu takip eden bayrak




void ArabaCiz();
void ICGUI_Create()
{
	ICG_MWPosition(0, 0);
	ICG_MWTitle("ROBOT KONTROL");
	
	ICG_MWSize(1350, 720);
	
	
}

DWORD WINAPI RightForwardThread(LPVOID lpParam)
{
	ICDEVICE relay;
	CreateDCTtechRelay(relay, 0);
	CommandRelay(relay, 1, "8");
	CommandRelay(relay, 1, "5");
	sagOnTekerRenk = 1;
	sagArkaTekerRenk = 1;
	
	ArabaCiz();
	Sleep(hareketSuresi);
	CommandRelay(relay, 0, "8");
	CommandRelay(relay, 0, "5");
	sagOnTekerRenk = 0;
	sagArkaTekerRenk = 0;
	
	CloseDevice(relay);
	ArabaCiz();
	return 0;
}

void RightForward()
{
	CreateThread(NULL, 0, RightForwardThread, NULL, 0, NULL);
}

DWORD WINAPI RightBackThread(LPVOID lpParam)
{
	ICDEVICE relay;
	CreateDCTtechRelay(relay, 0);
	CommandRelay(relay, 1, "8");
	CommandRelay(relay, 1, "4");
	sagOnTekerRenk = 2;
	sagArkaTekerRenk = 2;
	
	ArabaCiz();
	Sleep(hareketSuresi);
	CommandRelay(relay, 0, "8");
	CommandRelay(relay, 0, "4");
	sagOnTekerRenk = 0;
	sagArkaTekerRenk = 0;
	
	CloseDevice(relay);
	ArabaCiz();
	return 0;
}

void RightBack()
{
	CreateThread(NULL, 0, RightBackThread, NULL, 0, NULL);
}

DWORD WINAPI LeftForwardThread(LPVOID lpParam)
{
	ICDEVICE relay;
	CreateDCTtechRelay(relay, 0);
	CommandRelay(relay, 1, "8");
	CommandRelay(relay, 1, "7");
	solOnTekerRenk = 1;
	solArkaTekerRenk = 1;

	ArabaCiz();
	Sleep(hareketSuresi);
	CommandRelay(relay, 0, "8");
	CommandRelay(relay, 0, "7");
	solOnTekerRenk = 0;
	solArkaTekerRenk = 0;
	
	CloseDevice(relay);
	ArabaCiz();
	return 0;
}

void LeftForward()
{
	CreateThread(NULL, 0, LeftForwardThread, NULL, 0, NULL);
}

DWORD WINAPI LeftBackThread(LPVOID lpParam)
{
	ICDEVICE relay;
	CreateDCTtechRelay(relay, 0);
	CommandRelay(relay, 1, "8");
	CommandRelay(relay, 1, "6");
	solOnTekerRenk = 2;
	solArkaTekerRenk = 2;
	ArabaCiz();
	Sleep(hareketSuresi);
	CommandRelay(relay, 0, "8");
	CommandRelay(relay, 0, "6");
	solOnTekerRenk = 0;
	solArkaTekerRenk = 0;
	CloseDevice(relay);
	ArabaCiz();
	return 0;
}

void LeftBack()
{
	CreateThread(NULL, 0, LeftBackThread, NULL, 0, NULL);
}

DWORD WINAPI FullForwardThread(LPVOID lpParam)
{
	ICDEVICE relay;
	CreateDCTtechRelay(relay, 0);
	CommandRelay(relay, 1, "8");
	CommandRelay(relay, 1, "7");
	CommandRelay(relay, 1, "5");
	solOnTekerRenk = 1;
	solArkaTekerRenk = 1;
	sagOnTekerRenk = 1;
	sagArkaTekerRenk = 1;
	ArabaCiz();
	Sleep(hareketSuresi);
	CommandRelay(relay, 0, "8");
	CommandRelay(relay, 0, "7");
	CommandRelay(relay, 0, "5");
	solOnTekerRenk = 0;
	solArkaTekerRenk = 0;
	sagOnTekerRenk = 0;
	sagArkaTekerRenk = 0;
	CloseDevice(relay);
	ArabaCiz();
	return 0;
}

void FullForward()
{
	CreateThread(NULL, 0, FullForwardThread, NULL, 0, NULL);
}

DWORD WINAPI FullBackThread(LPVOID lpParam)
{
	ICDEVICE relay;
	CreateDCTtechRelay(relay, 0);
	CommandRelay(relay, 1, "8");
	CommandRelay(relay, 1, "6");
	CommandRelay(relay, 1, "4");
	solOnTekerRenk = 2;
	solArkaTekerRenk = 2;
	sagOnTekerRenk = 2;
	sagArkaTekerRenk = 2;
	ArabaCiz();
	Sleep(hareketSuresi);
	CommandRelay(relay, 0, "8");
	CommandRelay(relay, 0, "6");
	CommandRelay(relay, 0, "4");
	solOnTekerRenk = 0;
	solArkaTekerRenk = 0;
	sagOnTekerRenk = 0;
	sagArkaTekerRenk = 0;
	CloseDevice(relay);
	ArabaCiz();
	return 0;
}

void FullBack()
{
	CreateThread(NULL, 0, FullBackThread, NULL, 0, NULL);
}

DWORD WINAPI TurnRightThread(LPVOID lpParam)
{
	ICDEVICE relay;
	CreateDCTtechRelay(relay, 0);
	CommandRelay(relay, 1, "8");
	CommandRelay(relay, 1, "7");
	CommandRelay(relay, 1, "4");
	solOnTekerRenk = 1;
	solArkaTekerRenk = 1;
	sagOnTekerRenk = 2;
	sagArkaTekerRenk = 2;
	ArabaCiz();
	Sleep(hareketSuresi);
	CommandRelay(relay, 0, "8");
	CommandRelay(relay, 0, "7");
	CommandRelay(relay, 0, "4");
	solOnTekerRenk = 0;
	solArkaTekerRenk = 0;
	sagOnTekerRenk = 0;
	sagArkaTekerRenk = 0;
	CloseDevice(relay);
	ArabaCiz();
	return 0;
}

void TurnRight()
{
	CreateThread(NULL, 0, TurnRightThread, NULL, 0, NULL);
}

DWORD WINAPI TurnLeftThread(LPVOID lpParam)
{
	ICDEVICE relay;
	CreateDCTtechRelay(relay, 0);
	CommandRelay(relay, 1, "8");
	CommandRelay(relay, 1, "5");
	CommandRelay(relay, 1, "6");
	solOnTekerRenk = 2;
	solArkaTekerRenk = 2;
	sagOnTekerRenk = 1;
	sagArkaTekerRenk = 1;
	ArabaCiz();
	Sleep(hareketSuresi);
	CommandRelay(relay, 0, "8");
	CommandRelay(relay, 0, "5");
	CommandRelay(relay, 0, "6");
	solOnTekerRenk = 0;
	solArkaTekerRenk = 0;
	sagOnTekerRenk = 0;
	sagArkaTekerRenk = 0;
	CloseDevice(relay);
	ArabaCiz();
	return 0;
}

void TurnLeft()
{
	CreateThread(NULL, 0, TurnLeftThread, NULL, 0, NULL);
}

DWORD WINAPI WorkThread(LPVOID lpParam)
{
	// İlk hareket
	FullForward();
	
	Sleep(5000);
	FullBack();
	
	Sleep(5000);
	TurnRight();
	
	Sleep(5000);
	TurnLeft();
	
	return 0;
}

void Work()
{
	CreateThread(NULL, 0, WorkThread, NULL, 0, NULL);
}

void Kameralar()
{
	ICBYTES kamera_listesi;
	
	ICG_printf(MLE, "%d\n", GetVideoSourceList(kamera_listesi));
	Print(MLE, kamera_listesi);
}

DWORD WINAPI GosterThread(LPVOID lpParam) {
	ICDEVICE cam;
	ICBYTES frame;
	CreateImage(frame, 340, 480, ICB_UINT);

	if (CreateMFCam(cam, 1) < 0) {
		ICG_printf(MLE, "Kamera açılamadı!\n");
		return 1;
	}

	kameraAcik = true;
	ICG_printf(MLE, "Kamera acildi\n");

	while (kameraAcik) {
		if (CaptureImage(cam, frame) != 0) {
			DisplayImage(FRM2, frame);
		}
		Sleep(30);
	}

	CloseDevice(cam);
	ICG_printf(MLE, "Kamera kapatildi\n");
	return 0;
}

void Goster() {
	if (!kameraAcik) {
		CreateThread(NULL, 0, GosterThread, NULL, 0, NULL);
	}
	else {
		kameraAcik = false;
	}
}

// TrackBar değerini hareket süresine çeviren fonksiyon
int TrackBarToMs(int pos) {
	// pos: 0-100 arası değer
	// çıktı: 100ms-5000ms arası değer
	return 100 + (pos * 49); // 100ms + (0-4900ms)
}

// TrackBar pozisyonunu hesaplayan fonksiyon
int MsToTrackBarPos(int ms) {
	return (ms - 100) / 49;
}

void TrackBarCallback(int pos) {
	hareketSuresi = TrackBarToMs(pos);
	if (SLE1) {
		ICG_SetWindowText(SLE1, "");
		ICG_printf(SLE1, "%d", hareketSuresi);
	}
}

void ICGUI_main()
{	
	CreateImage(m, 600, 400,ICB_UINT);
	
	FRM1 = ICG_FramePanel(0, 0, 500, 500);
	MLE = ICG_MLEdit(615, 560, 180, 50, "", SCROLLBAR_V);
	FRM2 = ICG_FrameDeep(615, 0, 500, 415);
	
	char baslangicDeger[32];
	sprintf_s(baslangicDeger, sizeof(baslangicDeger), "%d", hareketSuresi);
	SLE1 = ICG_SLEditBorder(615, 498, 180, 25, baslangicDeger);
	
	ICG_Button(95, 425, 150, 25, "FullForward", FullForward);
	ICG_Button(20, 450, 150, 25, "LEFT FORWARD", LeftForward);
	ICG_Button(170, 450, 150, 25, "RIGHT FORWARD", RightForward);
	ICG_Button(20, 475, 150, 25, "LEFT BACK", LeftBack);
	ICG_Button(170, 475, 150, 25, "RIGHT BACK", RightBack);
	ICG_Button(95, 500, 150, 25, "FullBack", FullBack);
	ICG_Button(20, 525, 150, 25, "TURN RIGHT", TurnRight);
	ICG_Button(170, 525, 150, 25, "TURN LEFT", TurnLeft);
	ICG_Button(95, 550, 150, 25, "WORK WORK WORK", Work);
	ICG_Button(615, 525, 150, 25, "Kameralar", Kameralar);	
	ICG_Button(770, 525, 150, 25, "GOSTER", Goster);
	
	// TrackBar'ı güncelleme
	ICG_TrackBarH(795, 488, 180, 25, TrackBarCallback);
	
	
	int baslangicPos = MsToTrackBarPos(1000);
	TrackBarCallback(baslangicPos);
	
	ArabaCiz();
}

void ArabaCiz() {
    m = 0;
    Impress12x20(m, 5, 5, "GREEN = FORWARD", 0x00ff00);
    Impress12x20(m, 225, 5, "RED = BACK", 0xff0000);
    Impress12x20(m, 400, 5, "YELLOW = STOP", 0xffff00);
    // Ana gövde (gri)
    FillRoundRect(m, 200, 50, 200, 300, 35, RGB(180, 180, 180));
    
    // Sol ön teker
    if (solOnTekerRenk == 0) {
        FillRoundRect(m, 150, 70, 50, 80, 20, 0xffff00);
    }
    else if (solOnTekerRenk == 1) {
        FillRoundRect(m, 150, 70, 50, 80, 20, 0x00ff00);
        Impress12x20(m, 160, 80, "^^", 0x000000);
        Impress12x20(m, 160, 115, "^^", 0x000000);
    }
    else {
        FillRoundRect(m, 150, 70, 50, 80, 20, 0xff0000);
        Impress12x20(m, 160, 80, "vv", 0x000000);
        Impress12x20(m, 160, 120, "vv", 0x000000);
    }
        
    // Sol arka teker
    if (solArkaTekerRenk == 0)
        FillRoundRect(m, 150, 250, 50, 80, 20, 0xffff00);
    else if (solArkaTekerRenk == 1) {
        FillRoundRect(m, 150, 250, 50, 80, 20, 0x00ff00);
        Impress12x20(m, 160, 260, "^^", 0x000000);
        Impress12x20(m, 160, 300, "^^", 0x000000);
    }
    else {
        FillRoundRect(m, 150, 250, 50, 80, 20, 0xff0000);
        Impress12x20(m, 160, 260, "vv", 0x000000);
        Impress12x20(m, 160, 300, "vv", 0x000000);
    }

    // Sağ ön teker
    if (sagOnTekerRenk == 0)
        FillRoundRect(m, 400, 70, 50, 80, 20, 0xffff00);
    else if (sagOnTekerRenk == 1) {
        FillRoundRect(m, 400, 70, 50, 80, 20, 0x00ff00);
        Impress12x20(m, 410, 80, "^^", 0x000000);
        Impress12x20(m, 410, 120, "^^", 0x000000);
    }
    else {
        FillRoundRect(m, 400, 70, 50, 80, 20, 0xff0000);
        Impress12x20(m, 410, 80, "vv", 0x000000);
        Impress12x20(m, 410, 120, "vv", 0x000000);
    }

    // Sağ arka teker
    if (sagArkaTekerRenk == 0)
        FillRoundRect(m, 400, 250, 50, 80, 20, 0xffff00);
    else if (sagArkaTekerRenk == 1) {
        FillRoundRect(m, 400, 250, 50, 80, 20, 0x00ff00);
        Impress12x20(m, 410, 260, "^^", 0x000000);
        Impress12x20(m, 410, 300, "^^", 0x000000);
    }
    else {
        FillRoundRect(m, 400, 250, 50, 80, 20, 0xff0000);
        Impress12x20(m, 410, 260, "vv", 0x000000);
        Impress12x20(m, 410, 300, "vv", 0x000000);
    }

    DisplayImage(FRM1, m);
}