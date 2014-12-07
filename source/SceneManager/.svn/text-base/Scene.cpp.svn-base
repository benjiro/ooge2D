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

#include <Scene.hpp>
#include <InputManager.hpp>
#include <Camera.hpp>
#include <Timer.hpp>
#include <StringUtil.hpp>
#include <Object.hpp>
#include <Cull.hpp>
#include <ScreenCull.hpp>
#include <Loader.hpp>
#include <Common.hpp>
#include <PhysicsWorld.hpp>
#include <InputListener.hpp>
#include <SceneDescription.hpp>
#include <AudioDevice.hpp>

using namespace ooge;

Scene::Scene(SceneDescription *sd)
: mCamera(new Camera()), mDelta(0.6f), mStartFrame(0.0f), mInput(new InputManager()),
mTime(new Timer()), mActive(false), mCuller(sd->SceneCuller), mDebugRender(false)
{
	new Loader;
	if(sd->EnableAudio)
		new AudioDevice;

	mRenderableList.clear();
	_InitWindow(sd->ScreenWidth, sd->ScreenHeight, sd->EnableFullScreen, sd->WindowName);
}

Scene::~Scene()
{
	glfwTerminate();
	ClearRenderableList();
	if(mAudioEnable)
		delete AudioDevice::GetSingletonPtr();
	delete InputManager::GetSingletonPtr();
	delete Loader::GetSingletonPtr();
	delete Camera::GetSingletonPtr();
	delete mCuller;
	delete mTime;
}

void Scene::RequestShutdown()
{
	mActive = false;
}

bool Scene::GetStatus() const
{
	return mActive;
}

void Scene::RenderOneFrame()
{
	if(glGetError() == GL_INVALID_OPERATION)
		RequestShutdown();

	if(mActive)
	{
		_BeginFrame();

		mCamera->Update(mDelta);

		bool requestOrderUpdate = false;
		ConstItRenderableList it = mRenderableList.begin();
		for(; it != mRenderableList.end(); ++it)
		{
			if(mCuller->CheckRenderable((*it)))
			{
				if((*it)->GetDirty())
				{
					(*it)->SetDirty(false);
					UpdateRenderable((*it));
				}
				DrawRenderable((*it));

				if((*it)->GetNeedOrderUpdate())
				{
					(*it)->SetNeedOrderUpdate(false);
					requestOrderUpdate = true;
				}

				if(mDebugRender)
				{
					glColor4f(0,0,0,(*it)->GetAlpha());
					(*it)->GetRect().RenderRect();
				}
			}
		}

		mInput->UpdateListener();

		if(requestOrderUpdate)
			std::sort(mRenderableList.begin(), mRenderableList.end(), RenderOrder);

		_EndFrame();
	}
}

void Scene::UpdateRenderable(Renderable *render)
{
	render->Update(mDelta);
}

void Scene::DrawRenderable(Renderable *render)
{
	glPushMatrix();
	glLoadIdentity();

	if(render->GetBlendMode() == None)
		glDisable(GL_BLEND);
	else
	{
		glEnable(GL_BLEND);

		switch(render->GetBlendMode())
		{
		case Alpha:
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case Add:
			glBlendFunc(GL_SRC_ALPHA, GL_ONE);
			break;
		case Multiply:
			glBlendFunc(GL_DST_COLOR, GL_ZERO);
			break;
		}
	}

	//Set colour by scaling the number back down to 0 to 1
	glColor4f(render->GetColour().R / 255.0f, render->GetColour().G / 255.0f, 
		render->GetColour().B / 255.0f, render->GetColour().A / 255.0f);

	render->Render();

	glPopMatrix();
}

void Scene::_BeginFrame()
{
	mStartFrame = static_cast<Real>(mTime->GetMilliseconds());

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
}

void Scene::_EndFrame()
{
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glfwSwapBuffers();

	mDelta = mTime->GetMilliseconds() - mStartFrame;
}

bool Scene::AddRenderable(Renderable *add)
{
	//Check if valid pointer
	if(!add)
		return false;

	//Cast the renderable to Object
	ConstItRenderableList find = mRenderableList.begin();

	//Found a existing name add a sequence number to the end
	for(; find != mRenderableList.end(); ++find)
	{
		if((*find)->GetName() == add->GetName())
		{
			static UInt32 number = 0;		
			add->SetName(add->GetName() + StringUtil::ParseInt32ToString(number));
			mRenderableList.push_back(add);
			number++;
			return true;
		}
	}

	//No name set on object use default name Renderable plus sequence number
	if(add->GetName().empty())
	{
		static UInt32 number = 0;
		add->SetName("Renderable" + StringUtil::ParseInt32ToString(number));
		mRenderableList.push_back(add);
		number++;
		return true;
	}

	//Getting this far means that the object didn't exist in the list
	mRenderableList.push_back(add);

	std::sort(mRenderableList.begin(), mRenderableList.end(), RenderOrder);

	add->Update(mDelta);

	return true;
}

bool Scene::RenderOrder(const Renderable *r1, const Renderable *r2)
{
	return r1->GetOrder() > r2->GetOrder();
}

bool Scene::RemoveRenderable(Renderable *remove)
{
	if(!remove)
		return false;

	ItRenderableList it = mRenderableList.begin();
	for(; it != mRenderableList.end(); ++it)
	{
		if(remove == (*it))
		{
			delete (*it);
			mRenderableList.erase(it);
			return true;
		}
	}

	return false;
}

bool Scene::RemoveRenderable(const std::string &name)
{
	ItRenderableList it = mRenderableList.begin();
	for(; it != mRenderableList.end(); ++it)
	{
		if((*it)->GetName() == name)
		{
			delete (*it);
			mRenderableList.erase(it);
			return true;
		}
	}
	return false;
}

Renderable *Scene::GetRenderable(const std::string &byName) const
{
	ConstItRenderableList it = mRenderableList.begin();
	for(; it != mRenderableList.end(); ++it)
	{
		if((*it)->GetName() == byName)
			return (*it);
	}
	return NULL;
}

void Scene::ClearRenderableList()
{
	if(!mRenderableList.empty())
	{
		ItRenderableList it = mRenderableList.begin();
		for(; it != mRenderableList.end(); ++it)
		{
			delete (*it);
		}

		mRenderableList.clear();
	}
}

void Scene::_InitWindow(UInt32 screenWidth, UInt32 screenHeight, bool fullscreen, const std::string &windowName)
{
	std::cout << "OOGE Engine " << OOGE_VERSION << " " << OOGE_VERSION_NAME << std::endl;

	glfwInit();
	
	//read from winparams aa data
	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
	glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, 1);

	int mode;
	fullscreen ? mode = GLFW_FULLSCREEN : mode = GLFW_WINDOW;

	if(glfwOpenWindow(screenWidth, screenHeight,8,8,8,8,8,1,mode) != GL_TRUE)
			glfwTerminate();

	glfwSetWindowPos(100,100);

	glViewport(0,0, screenWidth, screenHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, screenWidth, screenHeight, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.375, 0.375, 0);
	
	glfwSetWindowTitle(windowName.c_str());
	glfwSwapInterval(1);
	glfwEnable(GLFW_KEY_REPEAT);
	//callbacks that will need a function poInt32or
	glfwSetWindowSizeCallback(Camera::ResizeCB);
	glfwSetKeyCallback(InputListener::KeyboardInputCB);
	glfwSetCharCallback(InputListener::CharacterInputCB);
	glfwSetMousePosCallback(InputListener::MousePositionCB);
	glfwSetMouseButtonCallback(InputListener::MouseButtonCB);
	glfwSetMouseWheelCallback(InputListener::MouseWheelCB);
	glfwSetWindowCloseCallback(Scene::_OnExit);

	glShadeModel(GL_FLAT);
	glPolygonMode(GL_FRONT, GL_FILL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glDepthFunc(GL_NEVER);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glAlphaFunc(GL_GREATER, 0.1f);
	glEnable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearStencil(0);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glewInit();

	mActive = true;
}

void Scene::Shutdown()
{
	_OnExit();
}

Int32 _stdcall Scene::_OnExit()
{
	return GL_TRUE;
}

Real Scene::GetDeltaTime() const
{
	return mDelta;
}

void Scene::SetDebugRender(bool render)
{
	mDebugRender = render;
}


