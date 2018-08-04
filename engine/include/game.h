#pragma once
class Game
{
public:
	virtual void pre_loop_logic();
	virtual void round_logic();
	virtual void handle_input(int key);
	virtual void pre_round_logic();
	virtual void pre_round_post_logic();
	virtual void end_round_logic();
	virtual void post_loop_logic();
};