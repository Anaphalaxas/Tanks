#pragma once
#include <stdio.h>
namespace Flow
{
	enum _Flow
	{
		Init,
		PreRound,
		Round,
		EndRound
	};
}
class FlowManager
{
private:
	static FlowManager *instance;
	int round;
	int flow_state;
	bool preround_logic_done;
	bool postround_logic_done;
public:
	static FlowManager *get_instance();
	static void destroy();
	FlowManager();
	~FlowManager();
	int get_state();
	int get_round();
	void init_complete();
	void alert_players_dead();
	void end_round_complete();
	void pre_round_complete();
	void pre_round_logic_done();
	void post_round_logic_done();
	bool is_pre_round_logic_done();
	bool is_post_round_logic_done();
};
