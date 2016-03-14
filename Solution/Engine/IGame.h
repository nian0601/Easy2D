#pragma once

namespace Easy2D
{
	class Engine;
	class IGame
	{
	public:
		virtual ~IGame(){};
		virtual void Init(Engine& aEngine) = 0;
		virtual void Update(float aDelta) = 0;
		virtual void Render() = 0;
	};
}