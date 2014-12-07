#include "StateManager.hpp"
#include "State.hpp"

using namespace ooge;

StateManager::StateManager()
: mCurrentState(0)
{
	mStates.clear();
}

StateManager::~StateManager()
{
	if(!mStates.empty())
		_Clear();
}

bool StateManager::AddState(State *state)
{
	ConstStateIt it = mStates.begin();
	for(; it != mStates.end(); ++it)
	{
		if((*it) == state)
			return false;
		if((*it)->GetName() == state->GetName())
			return false;
	}

	mStates.push_back(state);
	return true;
}

bool StateManager::RemoveState(State *state)
{
	StateIt it = mStates.begin();
	for(; it != mStates.end(); ++it)
	{
		if((*it) == state)
		{
			state->OnExit();
			delete state;
			mStates.erase(it);
			return true;
		}
	}
	return false;
}

bool StateManager::RemoveState(const std::string &name)
{
	StateIt it = mStates.begin();
	for(; it != mStates.end(); ++it)
	{
		if((*it)->GetName() == name)
		{
			(*it)->OnExit();
			delete (*it);
			mStates.erase(it);
			return true;
		}
	}
	return false;
}

void StateManager::SetCurrentState(State *state)
{
	ConstStateIt it = mStates.begin();
	for(; it != mStates.end(); ++it)
	{
		if((*it) == state)
		{
			mCurrentState = state;
			mCurrentState->OnEnter();
		}
	}
}

void StateManager::SetCurrentState(const std::string &name)
{
	ConstStateIt it = mStates.begin();
	for(; it != mStates.end(); ++it)
	{
		if((*it)->GetName() == name)
		{
			mCurrentState = (*it);
			mCurrentState->OnEnter();
		}
	}
}

void StateManager::UpdateCurrentState(float deltaT)
{
	if(mCurrentState)
		mCurrentState->Update(deltaT);
}

void StateManager::_Clear()
{
	StateIt it = mStates.begin();
	for(; it != mStates.end(); ++it)
		delete (*it);
	mStates.clear();
}

State *StateManager::GetCurrentState() const
{
	return mCurrentState;
}