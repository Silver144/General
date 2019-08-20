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
	QCheckBox *playerbox;
	QCheckBox *bombbox;
	QCheckBox *invbox;
	QCheckBox *eneinvbox;
	QCheckBox *powerbox;
	QCheckBox *timebox;
	QCheckBox *autobox;
	std::vector<std::function<bool()>> game_exist;
	std::map<std::string, std::function<void()>> playerlock;
	std::map<std::string, std::function<void()>> playerres;
	std::map<std::string, std::function<void()>> bomblock;
	std::map<std::string, std::function<void()>> bombres;
	std::map<std::string, std::function<void()>> timelock;
	std::map<std::string, std::function<void()>> timeres;
	std::map<std::string, std::function<void()>> powerlock;
	std::map<std::string, std::function<void()>> powerres;
	std::map<std::string, std::function<void()>> autobomb;
	std::map<std::string, std::function<void()>> noauto;
	std::map<std::string, std::function<void()>> invincible;
	std::map<std::string, std::function<void()>> des;
	std::map<std::string, std::function<void()>> enemysb;
	std::map<std::string, std::function<void()>> enemyinv;
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

inline std::string current_game;