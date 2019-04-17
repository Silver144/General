#include "General.h"

PROCESSENTRY32 pe;
HANDLE hSnapshot;

General::General(QWidget *parent)
	: QMainWindow(parent)
{
	setupUI();

	timer = new QTimer(this);
	timer->start(100);
	connect(timer, SIGNAL(timeout()), this, SLOT(checkBox()));
}

void General::checkBox()
{
	if (tkz.isRunning())
	{
		this->setWindowTitle("th16");
		if (invbox->isChecked())
			tkz.invincible();
		else
			tkz.des();
		if (powerbox->isChecked()) 
			tkz.powerlock();
		else 
			tkz.powerres();
		if (bombbox->isChecked()) 
			tkz.bomblock();
		else 
			tkz.bombres();
		if (playerbox->isChecked())
			tkz.playerlock();
		else
			tkz.playerres();
		if (eneinvbox->isChecked()) 
			tkz.enemyinv();
		else
			tkz.enemysb();
		if (autobox->isChecked()) 
			tkz.autobomb();
		else
			tkz.noauto();
		if (timebox->isChecked()) 
			tkz.timelock();
		else
			tkz.timeres();
	}
	else if (gzz.isRunning())
	{
		this->setWindowTitle("th15");
		if (invbox->isChecked())
			gzz.invincible();
		else
			gzz.des();
		if (powerbox->isChecked())
			gzz.powerlock();
		else
			gzz.powerres();
		if (bombbox->isChecked())
			gzz.bomblock();
		else
			gzz.bombres();
		if (playerbox->isChecked())
			gzz.playerlock();
		else
			gzz.playerres();
		if (eneinvbox->isChecked())
			gzz.enemyinv();
		else
			gzz.enemysb();
		if (autobox->isChecked())
			gzz.autobomb();
		else
			gzz.noauto();
		if (timebox->isChecked())
			gzz.timelock();
		else
			gzz.timeres();
	}
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