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

	//------ヘッダークラス初期化-------
	Player girl;
	Player dog;
	Stage stage;
	System system;
	Enemy enemy;//敵のデータは配列に変更になるかもしれないです。
	//---------------------------------

	//--------------変数---------------
	bool character;//true:少女,false:犬
	//---------------------------------

	//------ループ前に必要な関数-------
	stage.StageGenerate();//ステージ作成
	//---------------------------------

	while (ProcessMessage() != -1) {
		int startTime = GetNowCount();//ループ開始時間

		girl.PlayerDraw();
		dog.PlayerDraw();

		//▽もしcharacterがtrueならgirl.PlayerMain(character)を呼び出す。(1/3・北川)
		//▽もしcharacterがfalseならdog.PlayerMain(character)を呼び出す。(1/3・北川)

		//▽もしキャラ入れ替えボタン(仮に"A"とする)が押されると、characterのboolを逆にする。bool値の反転は bool A = !A; でできる。(1/3・穐田)

		system.Loop(startTime,GetNowCount());//画面処理、時間計測処理

	}
	DxLib_End();
	return 0;
}