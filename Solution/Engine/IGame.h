#pragma once

namespace Easy2D
{
	class Engine;
	class IGame
	{
	public:
		virtual void Init(Engine& aEngine){};
		virtual void Update(float aDelta){};
		virtual void Render(){};
	};
}