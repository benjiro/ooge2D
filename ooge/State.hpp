#ifndef _STATE_HPP_
#define _STATE_HPP_

#include <string>

namespace ooge
{
	class State
	{
	public:
		State(const std::string &name)
		: mName(name) {};
		virtual ~State() {};
		
		const std::string &GetName()
		{
			return mName;
		}
		
		virtual void Update(float deltaT) = 0;
		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;
	private:
		std::string mName;
	};
}

#endif //_STATE_HPP_