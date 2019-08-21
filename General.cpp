#include "General.h"
#include <QDebug>

PROCESSENTRY32 pe;
HANDLE hSnapshot;

#define mf std::make_pair<QString, std::function<void()>>

General::General(QWidget *parent)
	: QMainWindow(parent), playerbox(new QCheckBox("锁残机", this)), bombbox(new QCheckBox("锁Bomb", this)), powerbox(new QCheckBox("锁火力", this)),
	  timebox(new QCheckBox("锁时间", this)), invbox(new QCheckBox("无敌", this)), autobox(new QCheckBox("自动放B", this)), eneinvbox(new QCheckBox("敌人无敌", this))
{
	init();
	setupUI();
	connect(playerbox.get(), SIGNAL(stateChanged(int)), this, SLOT(handleplayer(int)));
	connect(bombbox.get(), SIGNAL(stateChanged(int)), this, SLOT(handlebomb(int)));
	connect(powerbox.get(), SIGNAL(stateChanged(int)), this, SLOT(handlepower(int)));
	connect(timebox.get(), SIGNAL(stateChanged(int)), this, SLOT(handletime(int)));
	connect(invbox.get(), SIGNAL(stateChanged(int)), this, SLOT(handleinv(int)));
	connect(autobox.get(), SIGNAL(stateChanged(int)), this, SLOT(handleauto(int)));
	connect(eneinvbox.get(), SIGNAL(stateChanged(int)), this, SLOT(handleenemy(int)));
}

void General::handleplayer(int state)
{
	for (auto &detect : game_exist)
		if (detect())
			break;
	if (state == Qt::Unchecked)
		playerres[current_game];
	else
		playerlock[current_game];
}

void General::handlebomb(int state)
{
	for (auto &detect : game_exist)
		if (detect())
			break;
	if (state == Qt::Unchecked)
		bombres[current_game];
	else
		bomblock[current_game];
}

void General::handletime(int state)
{
	for (auto &detect : game_exist)
		if (detect())
			break;
	if (state == Qt::Unchecked)
		timeres[current_game];
	else
		timelock[current_game];
}

void General::handlepower(int state)
{
	for (auto &detect : game_exist)
		if (detect())
			break;
	if (state == Qt::Unchecked)
		powerres[current_game];
	else
		powerlock[current_game];
}

void General::handleinv(int state)
{
	for (auto &detect : game_exist)
		if (detect())
			break;
	if (state == Qt::Unchecked)
		des[current_game];
	else
		invincible[current_game];
}

void General::handleauto(int state)
{
	for (auto &detect : game_exist)
		if (detect())
			break;
	if (state == Qt::Unchecked)
		noauto[current_game];
	else
		autobomb[current_game];
}

void General::handleenemy(int state)
{
	for (auto &detect : game_exist)
		if (detect())
			break;
	if (state == Qt::Unchecked)
		enemysb[current_game];
	else
		enemyinv[current_game];
}

void General::init()
{
	game_exist.push_back(th15::isRunning);
	game_exist.push_back(th16::isRunning);

	playerlock.insert(std::move(mf("tkz", th16::playerlock)));
	playerlock.insert(std::move(mf("gzz", th15::playerlock)));

	playerres.insert(std::move(mf("tkz", th16::playerres)));
	playerres.insert(std::move(mf("gzz", th15::playerres)));

	bomblock.insert(std::move(mf("tkz", th16::bomblock)));
	bomblock.insert(std::move(mf("gzz", th15::bomblock)));
	
	bombres.insert(std::move(mf("tkz", th16::bombres)));
	bombres.insert(std::move(mf("gzz", th15::bombres)));

	timelock.insert(std::move(mf("tkz", th16::timelock)));
	timelock.insert(std::move(mf("gzz", th15::timelock)));
	
	timeres.insert(std::move(mf("tkz", th16::timeres)));
	timeres.insert(std::move(mf("gzz", th15::timeres)));

	powerlock.insert(std::move(mf("tkz", th16::powerlock)));
	powerlock.insert(std::move(mf("gzz", th15::powerlock)));
	
	powerres.insert(std::move(mf("tkz", th16::powerres)));
	powerres.insert(std::move(mf("gzz", th15::powerres)));

	invincible.insert(std::move(mf("tkz", th16::invincible)));
	invincible.insert(std::move(mf("gzz", th15::invincible)));
	
	des.insert(std::move(mf("tkz", th16::des)));
	des.insert(std::move(mf("gzz", th15::des)));

	autobomb.insert(std::move(mf("tkz", th16::autobomb)));
	autobomb.insert(std::move(mf("gzz", th15::autobomb)));
	
	noauto.insert(std::move(mf("tkz", th16::noauto)));
	noauto.insert(std::move(mf("gzz", th15::noauto)));

	enemyinv.insert(std::move(mf("tkz", th16::enemyinv)));
	enemyinv.insert(std::move(mf("gzz", th15::enemyinv)));
	
	enemysb.insert(std::move(mf("tkz", th16::enemysb)));
	enemysb.insert(std::move(mf("gzz", th15::enemysb)));
}

void General::setupUI()
{
	setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
	
	int width = GetSystemMetrics(SM_CXFULLSCREEN);
	int height = GetSystemMetrics(SM_CYFULLSCREEN);
	setWindowTitle("无游戏");
	setWindowFlags(Qt::WindowCloseButtonHint);
	setFixedSize(200, 240);
	move((width - 205) / 2, (height - 140) / 2);

	playerbox->setGeometry(QRect(14, 14, 100, 23));
	bombbox->setGeometry(QRect(14, 44, 100, 23));
	powerbox->setGeometry(QRect(14, 74, 100, 23));
	timebox->setGeometry(QRect(14, 104, 120, 23));
	invbox->setGeometry(QRect(14, 134, 100, 23));
	autobox->setGeometry(QRect(14, 164, 100, 23));	
	eneinvbox->setGeometry(QRect(14, 194, 100, 23));
}
