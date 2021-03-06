// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "Engine.h"

#include "CoreUObject.h"
#include "ISIMVRPlugin.generated.h"

//Struct
USTRUCT(BlueprintType)
struct FSIMVRPacket
{
	GENERATED_USTRUCT_BODY()

	//Axis position controls
	float axis1;
	float axis2;
	float axis3;
	float axis4;

	//Axis speed/accel controls
	float speedAxis123;
	float accelAxis123;
	float speedAxis4;
	float accelAxis4;

	//Axis Processing
	float roll;
	float pitch;
	float yaw;
	float heave;
	float sway;
	float surge;

	float rotationMotionRatio;
	float gravityMotionRatio;

	int commandCount;
	int commandStride;
	char command[256];
};

typedef struct FSIMVRPacket simvrPacket;

/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules 
 * within this plugin.
 */
class ISIMVRPlugin : public IModuleInterface
{
public:
	static inline ISIMVRPlugin& Get(){
		return FModuleManager::LoadModuleChecked< ISIMVRPlugin >( "SIMVRPlugin" );
	}
	static inline bool IsAvailable() {
		return FModuleManager::Get().IsModuleLoaded( "SIMVRPlugin" );
	}

public:
	//Control
	virtual void Open(const char* serialId) = 0;
	virtual void Close() = 0;
	virtual void UpdateBackLog() = 0;
	virtual void UpdateSIMVR(simvrPacket* data) = 0;

	virtual void SetAxisProcesser(bool value) = 0;
	virtual void SetOrigin(bool value) = 0;
	virtual char* GetAppCode() = 0;
	virtual int GetState() = 0;
};
