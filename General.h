#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QCheckBox>
#include <QTimer>
#include <functional>
#include <Windows.h>
#include <psapi.h>
#include <tlhelp32.h>

namespace th17
{
	void autobomb();
	void noauto();
	void invincible();
	void des();
}

namespace th16
{
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
}

namespace th15
{
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

private:
	std::unique_ptr<QCheckBox> playerbox;
	std::unique_ptr<QCheckBox> bombbox;
	std::unique_ptr<QCheckBox> invbox;
	std::unique_ptr<QCheckBox> eneinvbox;
	std::unique_ptr<QCheckBox> powerbox;
	std::unique_ptr<QCheckBox> timebox;
	std::unique_ptr<QCheckBox> autobox;
	std::vector<std::function<bool()>> game_exist;
	std::map<QString, std::function<void()>> playerlock;
	std::map<QString, std::function<void()>> playerres;
	std::map<QString, std::function<void()>> bomblock;
	std::map<QString, std::function<void()>> bombres;
	std::map<QString, std::function<void()>> timelock;
	std::map<QString, std::function<void()>> timeres;
	std::map<QString, std::function<void()>> powerlock;
	std::map<QString, std::function<void()>> powerres;
	std::map<QString, std::function<void()>> autobomb;
	std::map<QString, std::function<void()>> noauto;
	std::map<QString, std::function<void()>> invincible;
	std::map<QString, std::function<void()>> des;
	std::map<QString, std::function<void()>> enemysb;
	std::map<QString, std::function<void()>> enemyinv;
	void init();
	void setupUI();

private slots:
	void handleplayer(int state);
	void handlebomb(int state);
	void handletime(int state);
	void handleinv(int state);
	void handleenemy(int state);
	void handleauto(int state);
	void handlepower(int state);
};

extern PROCESSENTRY32 pe;
extern HANDLE hSnapshot;

inline QString current_game;
