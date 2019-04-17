#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QCheckBox>
#include <QTimer>
#include <Windows.h>
#include <psapi.h>
#include <tlhelp32.h>

class th16
{

public:
	void playerlock();
	void playerres();
	void bomblock();
	void bombres();
	void powerlock();
	void powerres();
	void autobomb();
	void noauto();
	void invincible();
	void des();
	void enemyinv();
	void enemysb();
	void timelock();
	void timeres();
	bool isRunning();
};

class th15
{

public:
	void playerlock();
	void playerres();
	void bomblock();
	void bombres();
	void powerlock();
	void powerres();
	void autobomb();
	void noauto();
	void invincible();
	void des();
	void enemyinv();
	void enemysb();
	void timelock();
	void timeres();
	bool isRunning();
};


class General : public QMainWindow
{
	Q_OBJECT

public:
	explicit General(QWidget *parent = Q_NULLPTR);

	th16 tkz;
	th15 gzz;
private:
	QTimer *timer;
	QCheckBox *playerbox;
	QCheckBox *bombbox;
	QCheckBox *invbox;
	QCheckBox *eneinvbox;
	QCheckBox *powerbox;
	QCheckBox *timebox;
	QCheckBox *autobox;

	void handleLoLK();
	void handleHSiFS();

	void setupUI();

private slots:
	void checkBox();
	
};

extern PROCESSENTRY32 pe;
extern HANDLE hSnapshot;