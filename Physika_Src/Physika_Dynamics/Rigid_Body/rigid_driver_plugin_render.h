/*
 * @file rigid_driver_plugin_render.h 
 * @Render plugin of rigid body driver. This is a singleton class
 * @author Tianxiang Zhang
 * 
 * This file is part of Physika, a versatile physics simulation library.
 * Copyright (C) 2013 Physika Group.
 *
 * This Source Code Form is subject to the terms of the GNU General Public License v2.0. 
 * If a copy of the GPL was not distributed with this file, you can obtain one at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 *
 */

#ifndef PHYSIKA_DYNAMICS_RIGID_BODY_RIGID_DRIVER_PLUGIN_RENDER_H_
#define PHYSIKA_DYNAMICS_RIGID_BODY_RIGID_DRIVER_PLUGIN_RENDER_H_

#include<vector>

namespace Physika{

template <typename Scalar,int Dim> class RigidDriverPlugin;
class GlutWindow;
class RenderBase;

template <typename Scalar,int Dim>
class RigidDriverPluginRender: public RigidDriverPlugin<Scalar, Dim>
{
public:
	RigidDriverPluginRender();
	~RigidDriverPluginRender();

	//functions called in driver
	void onRun();
	void onAdvanceFrame();
	void onInitialize();
	void onAdvanceStep(Scalar dt);
	void onWrite();
	void onRead();

	void onAddRigidBody(RigidBody<Scalar, Dim>* rigid_body);
	void onCollisionDetection();

	//basic function
	void setDriver(DriverBase<Scalar>* driver);
	void setWindow(GlutWindow* window);

	//get
	unsigned int numRender() const;

	//control function of render
	void enableRenderSolidAll();
	void disableRenderSolidAll();
	void enableRenderVerticesAll();
	void disableRenderVerticesAll();
	void enableRenderWireframeAll();
	void disableRenderWireframeAll();
	void enableFlatShadingAll();
	void enableSmoothShadingAll();
	void enableTextureAll();
	void disableTextureAll();

	void enableRenderSolidAt(unsigned int index);
	void disableRenderSolidAt(unsigned int index);
	void enableRenderVerticesAt(unsigned int index);
	void disableRenderVerticesAt(unsigned int index);
	void enableRenderWireframeAt(unsigned int index);
	void disableRenderWireframeAt(unsigned int index);
	void enableFlatShadingAt(unsigned int index);
	void enableSmoothShadingAt(unsigned int index);
	void enableTextureAt(unsigned int index);
	void disableTextureAt(unsigned int index);

	void enableRenderContactFaceAll();

protected:
	GlutWindow* window_;
	std::vector<RenderBase*> render_queue_;
	bool is_render_contact_face_;

	//singleton
	static RigidDriverPluginRender<Scalar, Dim>* active_render_;//current active instance
	static void idle();//idle function which is set to window_. Called each frame by window and call simulation functions in driver
    static void display();//display function which is set to window_. Called each frame by window and call simulation functions in driver

	//singleton function
	void active();//active this instance
};


} //end of namespace Physika

#endif //PHYSIKA_DYNAMICS_RIGID_BODY_RIGID_DRIVER_PLUGIN_RENDER_H_