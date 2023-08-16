#include"GameOverScene.h"
#include"DxLib.h"
#include"SceneManager.h"


/*************************************

*変数定義

*************************************/

int GameOverImage;
int GameOverSE;
int GameOverFlag;


/**************************************

*プロトタイプ宣言

***************************************/


/**************************************

*ゲームオーバー画面：初期化処理

*引数：なし

*戻り値：エラー情報

***************************************/

int GameOverScene_Initialize(void)
{
	int ret = 0;

	//画面読み込み
	GameOverImage = LoadGraph("images/gameover.png");
	GameOverSE = LoadSoundMem("sounds/gameover_se.mp3");
	GameOverFlag = FALSE;

	//エラーチェック
	if (GameOverImage == D_ERROR)
	{
		ret = -1;
	}
	if (GameOverSE == -1)
	{
		ret = -1;
	}

	return ret;
}


/**************************************

*ゲームオーバー画面：更新処理

*引数：なし

*戻り値：なし

***************************************/
void GameOverScene_Update(void)
{
	//ゲームオーバー効果音再生チェック
	if (CheckSoundMem(GameOverSE) == 0)
	{
		if (GameOverFlag == TRUE)
		{
			Change_Scene(E_GAME_OVER);
		}
		else
		{
			PlaySoundMem(GameOverSE, DX_PLAYTYPE_BACK);
			GameOverFlag = TRUE;
		}
	}
}
/**************************************

*ゲームオーバー画面：描画処理

*引数：なし

*戻り値：なし

***************************************/
void GameOverScene_Draw(void)
{
	//ゲームオーバー画面表示
	DrawGraph(0, 0, GameOverImage, FALSE);
}