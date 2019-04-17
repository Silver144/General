#include "General.h"

PROCESSENTRY32 pe;
HANDLE hSnapshot;

bool flag[20][10][2];

General::General(QWidget *parent)
	: QMainWindow(parent)
{
	setupUI();

	memset(flag, 0, sizeof(flag));
	timer = new QTimer(this);
	timer->start(100);
	connect(timer, SIGNAL(timeout()), this, SLOT(checkBox()));
}

void General::handleLoLK()
{
	this->setWindowTitle("th15");
	if (invbox->isChecked())
	{
		if (!flag[15][0][0])
		{
			gzz.invincible();
			flag[15][0][0] = true;
			flag[15][0][1] = false;
		}
	}
	else
	{
		if (!flag[15][0][1])
		{
			gzz.des();
			flag[15][0][0] = false;
			flag[15][0][1] = true;
		}
	}
	if (powerbox->isChecked())
	{
		if (!flag[15][1][0])
		{
			gzz.powerlock();
			flag[15][1][0] = true;
			flag[15][1][1] = false;
		}
	}
	else
	{
		if (!flag[15][1][1])
		{
			gzz.powerres();
			flag[15][1][0] = false;
			flag[15][1][1] = true;
		}
	}
	if (bombbox->isChecked())
	{
		if (!flag[15][2][0])
		{
			gzz.bomblock();
			flag[15][2][0] = true;
			flag[15][2][1] = false;
		}
	}
	else
	{
		if (!flag[15][2][1])
		{
			gzz.bombres();
			flag[15][2][0] = false;
			flag[15][2][1] = true;
		}
	}
	if (playerbox->isChecked())
	{
		if (!flag[15][3][0])
		{
			gzz.playerlock();
			flag[15][3][0] = true;
			flag[15][3][1] = false;
		}
	}
	else
	{
		if (!flag[15][3][1])
		{
			gzz.playerres();
			flag[15][3][0] = false;
			flag[15][3][1] = true;
		}
	}
	if (eneinvbox->isChecked())
	{
		if (!flag[15][4][0])
		{
			gzz.enemyinv();
			flag[15][4][0] = true;
			flag[15][4][1] = false;
		}
	}
	else
	{
		if (!flag[15][4][1])
		{
			gzz.enemysb();
			flag[15][4][0] = false;
			flag[15][4][1] = true;
		}
	}
	if (autobox->isChecked())
	{
		if (!flag[15][5][0])
		{
			gzz.autobomb();
			flag[15][5][0] = true;
			flag[15][5][1] = false;
		}
	}
	else
	{
		if (!flag[15][5][1])
		{
			gzz.noauto();
			flag[15][5][0] = false;
			flag[15][5][1] = true;
		}
	}
	if (timebox->isChecked())
	{
		if (!flag[15][6][0])
		{
			gzz.timelock();
			flag[15][6][0] = true;
			flag[15][6][1] = false;
		}
	}
	else
	{
		if (!flag[15][6][1])
		{
			gzz.timeres();
			flag[15][6][0] = false;
			flag[15][6][1] = true;
		}
	}
}

void General::handleHSiFS()
{
	this->setWindowTitle("th16");
	if (invbox->isChecked())
	{
		if (!flag[16][0][0])
		{
			tkz.invincible();
			flag[16][0][0] = true;
			flag[16][0][1] = false;
		}
	}
	else
	{
		if (!flag[16][0][1])
		{
			tkz.des();
			flag[16][0][0] = false;
			flag[16][0][1] = true;
		}
	}
	if (powerbox->isChecked())
	{
		if (!flag[16][1][0])
		{
			tkz.powerlock();
			flag[16][1][0] = true;
			flag[16][1][1] = false;
		}
	}
	else
	{
		if (!flag[16][1][1])
		{
			tkz.powerres();
			flag[16][1][0] = false;
			flag[16][1][1] = true;
		}
	}
	if (bombbox->isChecked())
	{
		if (!flag[16][2][0])
		{
			tkz.bomblock();
			flag[16][2][0] = true;
			flag[16][2][1] = false;
		}
	}
	else
	{
		if (!flag[16][2][1])
		{
			tkz.bombres();
			flag[16][2][0] = false;
			flag[16][2][1] = true;
		}
	}
	if (playerbox->isChecked())
	{
		if (!flag[16][3][0])
		{
			tkz.playerlock();
			flag[16][3][0] = true;
			flag[16][3][1] = false;
		}
	}
	else
	{
		if (!flag[16][3][1])
		{
			tkz.playerres();
			flag[16][3][0] = false;
			flag[16][3][1] = true;
		}
	}
	if (eneinvbox->isChecked())
	{
		if (!flag[16][4][0])
		{
			tkz.enemyinv();
			flag[16][4][0] = true;
			flag[16][4][1] = false;
		}
	}
	else
	{
		if (!flag[16][4][1])
		{
			tkz.enemysb();
			flag[16][4][0] = false;
			flag[16][4][1] = true;
		}
	}
	if (autobox->isChecked())
	{
		if (!flag[16][5][0])
		{
			tkz.autobomb();
			flag[16][5][0] = true;
			flag[16][5][1] = false;
		}
	}
	else
	{
		if (!flag[16][5][1])
		{
			tkz.noauto();
			flag[16][5][0] = false;
			flag[16][5][1] = true;
		}
	}
	if (timebox->isChecked())
	{
		if (!flag[16][6][0])
		{
			tkz.timelock();
			flag[16][6][0] = true;
			flag[16][6][1] = false;
		}
	}
	else
	{
		if (!flag[16][6][1])
		{
			tkz.timeres();
			flag[16][6][0] = false;
			flag[16][6][1] = true;
		}
	}
}

void General::checkBox()
{
	if (tkz.isRunning())
		handleHSiFS();
	else if (gzz.isRunning())
		handleLoLK();
}

void General::setupUI()
{
	setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
	
	int width = GetSystemMetrics(SM_CXFULLSCREEN);
	int height = GetSystemMetrics(SM_CYFULLSCREEN);
	this->setWindowTitle("无游戏");
	this->setWindowFlags(Qt::WindowCloseButtonHint);
	this->setFixedSize(200, 240);
	this->move((width - 205) / 2, (height - 140) / 2);

	playerbox = new QCheckBox("锁残机", this);
	playerbox->setGeometry(QRect(14, 14, 100, 23));
	
	bombbox = new QCheckBox("锁Bomb", this);
	bombbox->setGeometry(QRect(14, 44, 100, 23));
	
	powerbox = new QCheckBox("锁火力", this);
	powerbox->setGeometry(QRect(14, 74, 100, 23));
	
	timebox = new QCheckBox("锁时间", this);
	timebox->setGeometry(QRect(14, 104, 120, 23));
	
	invbox = new QCheckBox("无敌", this);
	invbox->setGeometry(QRect(14, 134, 100, 23));
	
	autobox = new QCheckBox("自动放B", this);
	autobox->setGeometry(QRect(14, 164, 100, 23));
	
	eneinvbox = new QCheckBox("敌人无敌", this);
	eneinvbox->setGeometry(QRect(14, 194, 100, 23));
}