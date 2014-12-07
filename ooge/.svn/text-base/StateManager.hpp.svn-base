#ifndef _STATE_MANAGER_HPP_
#define _STATE_MANAGER_HPP_

#include <vector>
#include <string>

namespace ooge
{
	//forward declare
	class State;

	class StateManager
	{
	public:
		StateManager();
		~StateManager();

		bool AddState(State *state);
		bool RemoveState(State *state);
		bool RemoveState(const std::string &name);
		
		void SetCurrentState(State *state);
		void SetCurrentState(const std::string &name);
		
		State *GetCurrentState() const;

		void UpdateCurrentState(float deltaT);
	protected:
		void _Clear();
	private:
		typedef std::vector<State *>::const_iterator ConstStateIt;
		typedef std::vector<State *>::iterator StateIt;
		std::vector<State *> mStates;
		State *mCurrentState;
	};
}

#endif //_STATE_MANAGER_HPP_