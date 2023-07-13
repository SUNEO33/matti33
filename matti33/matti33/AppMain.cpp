/********************************************

*プログラミング実習

*マッチ３ゲームの製作

*********************************************/

#include "DxLib.h"

#include "FreamContorol.h"

#include "InputControl.h"

#include "SceneManager.h"


/********************************************

*マクロ定義

*********************************************/

#define SCREEN_HEIGHT    (480)          //スクリーンサイズ（高さ）
#define SCREEN_WIDTH     (640)          //スクリーンサイズ（幅）
#define SCREEN_COLORBIT  (32)           //スクリーンカラービット
#define FONT_SIZE        (20)           //文字サイズ


/*********************************************

*グローバル変数宣言

**********************************************/




/**********************************************

*プロトタイプ宣言

************************************************/




/************************************************

*プログラムの開始

*************************************************/

int WINAPI WinMain(_In_HINSTANCE hinstance, _In_opt_HINSTANCE hPrevInstance,
	_In_LPSTR lpCmdLine, _In_int nShowCmd)

{


	//ウィンドウタイトル設定
	SetMainWindowText("Match 3 Puzzle");
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);
	//画面サイズの最大サイズ,カラービット数を設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);


	//Dxライブラリ初期化処理
	//エラーが発生したら、終了する
	if (DxLib_Init() == D_ERROR)
	{

		return D_ERROR;

	}


	//各機能の初期化処理
	FreamControl_Initialize();         //フレームレートの制御機能

	Input_Initialize();                //入力制御機能




}