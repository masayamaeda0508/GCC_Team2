#include "DxLib.h"
#include "Player.h"
#include "Stage.h"
#include "System.h"
#include "Enemy.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);

	//------�w�b�_�[�N���X������-------
	Player girl;
	Player dog;
	Stage stage;
	System system;
	Enemy enemy;//�G�̃f�[�^�͔z��ɕύX�ɂȂ邩������Ȃ��ł��B
	//---------------------------------

	//--------------�ϐ�---------------
	bool character;//true:����,false:��
	//---------------------------------

	//------���[�v�O�ɕK�v�Ȋ֐�-------
	stage.StageGenerate();//�X�e�[�W�쐬
	//---------------------------------

	while (ProcessMessage() != -1) {
		int startTime = GetNowCount();//���[�v�J�n����

		girl.PlayerDraw();
		dog.PlayerDraw();

		//������character��true�Ȃ�girl.PlayerMain(character)���Ăяo���B(1/3�E�k��)
		//������character��false�Ȃ�dog.PlayerMain(character)���Ăяo���B(1/3�E�k��)

		//�������L��������ւ��{�^��(����"A"�Ƃ���)���������ƁAcharacter��bool���t�ɂ���Bbool�l�̔��]�� bool A = !A; �łł���B(1/3�E���c)

		system.Loop(startTime,GetNowCount());//��ʏ����A���Ԍv������

	}
	DxLib_End();
	return 0;
}