/*
This file is apart of ooge(object-oriented 2D game engine)

-------------------------------------------------------------------
Copyright (c) 2010 Benjamin Evenson

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
-------------------------------------------------------------------
*/

#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <Config.hpp>
#include <string>
#include <vector>
#include <Renderable.hpp>

namespace ooge
{
	class InputManager;
	class Camera;
	class Timer;
	class Object;
	class Cull;
	struct SceneDescription;

	class OOGE_API Scene
	{
	public:
		Scene(SceneDescription *sd);
		~Scene();

		void RenderOneFrame();
		void UpdateRenderable(Renderable *render);
		void DrawRenderable(Renderable *render);

		static bool RenderOrder(const Renderable *r1, const Renderable *r2);
		bool AddRenderable(Renderable *add);
		bool RemoveRenderable(Renderable *remove);
		bool RemoveRenderable(const std::string &name);
		Renderable *GetRenderable(const std::string &byName) const;

		Real GetDeltaTime() const;

		void RequestShutdown();
		void Shutdown();

		bool GetStatus() const;
		void SetDebugRender(bool render);

		void ClearRenderableList();
	protected:
		void _BeginFrame();
		void _EndFrame();
	private:
		void _InitWindow(UInt32 screenWidth, UInt32 screenHeight, bool fullscreen, const std::string &windowName);

		static Int32 _stdcall _OnExit();

		Real mDelta;
		Real mStartFrame;
		bool mActive;
		bool mAudioEnable;
		bool mDebugRender;

		Camera *mCamera;
		Timer *mTime;
		Cull *mCuller;
		InputManager *mInput;

		typedef std::vector<Renderable*>::iterator ItRenderableList;
		typedef std::vector<Renderable*>::const_iterator ConstItRenderableList;
		std::vector<Renderable*> mRenderableList;
	};
}

#endif //_SCENE_HPP_