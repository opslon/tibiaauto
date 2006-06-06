/*
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
*/



// PackSenderProxy.cpp: implementation of the CPackSenderProxy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PackSenderProxy.h"


//////////////////////////////////////////////////////////////////////

HMODULE CPackSenderProxy::dllModule=NULL;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPackSenderProxy::CPackSenderProxy()
{
	if (dllModule==NULL)
	{
		dllModule=LoadLibrary("mods\\tibiaauto_util.dll");
	}
}

CPackSenderProxy::~CPackSenderProxy()
{

}

void CPackSenderProxy::setPipeHandle(HANDLE hPipe)
{
	typedef void (*Proto_fun)(HANDLE hPipe);
	if (dllModule)
	{			
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"setPipeHandle");
		if (fun)
		{
			fun(hPipe);
		}
	} 	
}

void CPackSenderProxy::moveObjectBetweenContainers(int objectId, int sourceContNr, int sourcePos, int targetContNr, int targetPos, int qty)
{
	typedef void (*Proto_fun)(int objectId, int sourceContNr, int sourcePos, int targetContNr, int targetPos, int qty);
	if (dllModule)
	{			
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderMoveObjectBetweenContainers");
		if (fun)
		{
			fun(objectId,sourceContNr,sourcePos,targetContNr,targetPos,qty);
		}
	} 	
}

void CPackSenderProxy::useWithObjectFromContainerOnFloor(int sourceObjectId,int sourceContNr,int sourcePos,int targetObjectId,int targetX,int targetY,int targetZ)
{
	useWithObjectFromContainerOnFloor(sourceObjectId,sourceContNr,sourcePos,targetObjectId,targetX,targetY,targetZ,2);
}

void CPackSenderProxy::useWithObjectFromContainerOnFloor(int sourceObjectId,int sourceContNr,int sourcePos,int targetObjectId,int targetX,int targetY,int targetZ, int method)
{
	useWithObjectFromContainerOnFloor(sourceObjectId,sourceContNr,sourcePos,targetObjectId,targetX,targetY,targetZ,method,0);
}

void CPackSenderProxy::useWithObjectFromContainerOnFloor(int sourceObjectId,int sourceContNr,int sourcePos,int targetObjectId,int targetX,int targetY,int targetZ, int method, int extraInfo)
{
	typedef void (*Proto_fun)(int sourceObjectId,int sourceContNr,int sourcePos,int targetObjectId,int targetX,int targetY,int targetZ, int method, int extraInfo);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderUseWithObjectFromContainerOnFloor");
		if (fun)
		{
			fun(sourceObjectId,sourceContNr,sourcePos,targetObjectId,targetX,targetY,targetZ,method,extraInfo);
		}
	} 	
}

void CPackSenderProxy::moveObjectFromFloorToContainer(int objectId,int sourceX,int sourceY,int sourceZ,int targetContNr,int targetPos,int quantity)
{
	typedef void (*Proto_fun)(int objectId,int sourceX,int sourceY,int sourceZ,int targetContNr,int targetPos,int quantity);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderMoveObjectFromFloorToContainer");
		if (fun)
		{
			fun(objectId,sourceX,sourceY,sourceZ,targetContNr,targetPos,quantity);
		}
	} 
}

void CPackSenderProxy::moveObjectFromContainerToFloor(int objectId, int contNr, int pos, int x, int y, int z,int quantity)
{
	typedef void (*Proto_fun)(int objectId, int contNr, int pos, int x, int y, int z,int quantity);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderMoveObjectFromContainerToFloor");
		if (fun)
		{
			fun(objectId, contNr, pos, x, y, z,quantity);
		}
	} 

}
void CPackSenderProxy::castRuneAgainstCreature(int contNr, int itemPos, int runeObjectId, int creatureId, int method)
{
	typedef void (*Proto_fun)(int contNr, int itemPos, int runeObjectId, int creatureId, int method);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderCastRuneAgainstCreature");
		if (fun)
		{
			fun(contNr, itemPos, runeObjectId, creatureId, method);
		}
	} 

}
void CPackSenderProxy::castRuneAgainstCreature(int contNr, int itemPos, int runeObjectId, int creatureId)
{
	castRuneAgainstCreature(contNr,itemPos,runeObjectId,creatureId,2);
}
void CPackSenderProxy::castRuneAgainstHuman(int contNr, int itemPos, int runeObjectId, int targetX, int targetY, int targetZ, int method)
{
	typedef void (*Proto_fun)(int contNr, int itemPos, int runeObjectId, int targetX, int targetY, int targetZ, int method);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderCastRuneAgainstHuman");
		if (fun)
		{
			fun(contNr, itemPos, runeObjectId, targetX, targetY, targetZ, method);
		}
	} 

}
void CPackSenderProxy::castRuneAgainstHuman(int contNr, int itemPos, int runeObjectId, int targetX, int targetY, int targetZ)
{
	castRuneAgainstHuman(contNr,itemPos,runeObjectId,targetX,targetY,targetZ,2);
}
void CPackSenderProxy::sendTAMessage(char *msg)
{
	typedef void (*Proto_fun)(char *msg);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderSendTAMessage");
		if (fun)
		{
			fun(msg);
		}
	} 

}
void CPackSenderProxy::useItemOnFloor(int objectId, int x, int y, int z)
{
	typedef void (*Proto_fun)(int objectId, int x, int y, int z);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderUseItemOnFloor");
		if (fun)
		{
			fun(objectId, x, y, z);
		}
	} 

}
void CPackSenderProxy::useItemInContainer(int objectId, int contNr, int pos)
{
	typedef void (*Proto_fun)(int objectId, int contNr, int pos);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderUseItemInContainer");
		if (fun)
		{
			fun(objectId, contNr, pos);
		}
	} 

}
void CPackSenderProxy::openContainerFromFloor(int objectId,int x,int y,int z,int targetBag)
{
	typedef void (*Proto_fun)(int objectId,int x,int y,int z,int targetBag);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderOpenContainerFromFloor");
		if (fun)
		{
			fun(objectId,x,y,z,targetBag);
		}
	} 

}
void CPackSenderProxy::openContainerFromContainer(int objectId, int contNrFrom, int contPosFrom, int targetBag)
{
	typedef void (*Proto_fun)(int objectId, int contNrFrom, int contPosFrom, int targetBag);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderOpenContainerFromContainer");
		if (fun)
		{
			fun(objectId, contNrFrom, contPosFrom, targetBag);
		}
	} 

}

void CPackSenderProxy::sendAttackedCreatureToAutoAim(int attackedCreature)
{
	typedef void (*Proto_fun)(int attackedCreature);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderSendAttackedCreatureToAutoAim");
		if (fun)
		{
			fun(attackedCreature);
		}
	} 
}

void CPackSenderProxy::say(const char *buf)
{
	typedef void (*Proto_fun)(const char *buf);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderSay");
		if (fun)
		{
			fun(buf);
		}
	} 
}

void CPackSenderProxy::sayWhisper(const char *buf)
{
	typedef void (*Proto_fun)(const char *buf);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderSayWhisper");
		if (fun)
		{
			fun(buf);
		}
	} 
}
void CPackSenderProxy::sayYell(const char *buf)
{
	typedef void (*Proto_fun)(const char *buf);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderSayYell");
		if (fun)
		{
			fun(buf);
		}
	} 
}
void CPackSenderProxy::tell(char *msg, char *playerName)
{
	typedef void (*Proto_fun)(char *msg, char *playerName);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderTell");
		if (fun)
		{
			fun(msg,playerName);
		}
	} 
}

void CPackSenderProxy::sayOnChan(char *msg, int channelId)
{
	typedef void (*Proto_fun)(char *msg, int channelId);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderSayOnChan");
		if (fun)
		{
			fun(msg,channelId);
		}
	} 
}

void CPackSenderProxy::logout()
{
	typedef void (*Proto_fun)();
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderLogout");
		if (fun)
		{
			fun();
		}
	} 
}

void CPackSenderProxy::stepMulti(int *direction,int size)
{
	typedef void (*Proto_fun)(int *direction,int size);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderStepMulti");
		if (fun)
		{
			fun(direction,size);
		}
	} 
}


void CPackSenderProxy::closeContainer(int contNr)
{
	typedef void (*Proto_fun)(int contNr);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderCloseContainer");
		if (fun)
		{
			fun(contNr);
		}
	} 
}
void CPackSenderProxy::attackMode(int mode,int follow)
{
	typedef void (*Proto_fun)(int mode,int follow);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderAttackMode");
		if (fun)
		{
			fun(mode,follow);
		}
	} 
}
void CPackSenderProxy::attack(int tibiaCharId)
{
	typedef void (*Proto_fun)(int tibiaCharId);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderAttack");
		if (fun)
		{
			fun(tibiaCharId);
		}
	} 
}

void CPackSenderProxy::turnLeft()
{
	typedef void (*Proto_fun)();
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderTurnLeft");
		if (fun)
		{
			fun();
		}
	} 
}

void CPackSenderProxy::turnRight()
{
	typedef void (*Proto_fun)();
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderTurnRight");
		if (fun)
		{
			fun();
		}
	} 
}

void CPackSenderProxy::turnUp()
{
	typedef void (*Proto_fun)();
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderTurnUp");
		if (fun)
		{
			fun();
		}
	} 
}

void CPackSenderProxy::turnDown()
{
	typedef void (*Proto_fun)();
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderTurnDown");
		if (fun)
		{
			fun();
		}
	} 
}

void CPackSenderProxy::moveObjectFromFloorToFloor(int objectId, int srcX, int srcY, int srcZ, int destX, int destY, int destZ,int quantity)
{
	typedef void (*Proto_fun)(int objectId, int srcX, int srcY, int srcZ, int destX, int destY, int destZ,int quantity);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderMoveObjectFromFloorToFloor");
		if (fun)
		{
			fun(objectId, srcX, srcY, srcZ, destX, destY, destZ,quantity);
		}
	} 
}


void CPackSenderProxy::sendCreatureInfo(char *name, char *info1, char *info2)
{
	typedef void (*Proto_fun)(char *name, char *info1, char *info2);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderSendCreatureInfo");
		if (fun)
		{
			fun(name,info1,info2);
		}
	} 
}

void CPackSenderProxy::look(int x,int y, int z,int objectId)
{
	typedef void (*Proto_fun)(int x,int y, int z,int objectId);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderLook");
		if (fun)
		{
			fun(x,y,z,objectId);
		}
	} 
}

void CPackSenderProxy::ignoreLook(int end)
{
	typedef void (*Proto_fun)(int end);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderIgnoreLook");
		if (fun)
		{
			fun(end);
		}
	} 
}

void CPackSenderProxy::sendAutoAimConfig(int active, int onlyCreatures, int aimPlayersFromBattle)
{
	typedef void (*Proto_fun)(int active, int onlyCreatures, int aimPlayersFromBattle);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderSendAutoAimConfig");
		if (fun)
		{
			fun(active, onlyCreatures, aimPlayersFromBattle);
		}
	} 

}
void CPackSenderProxy::sendClearCreatureInfo()
{
	typedef void (*Proto_fun)();
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderSendClearCreatureInfo");
		if (fun)
		{
			fun();
		}
	} 

}

void CPackSenderProxy::enableCName(int enable)
{
	typedef void (*Proto_fun)(int enable);
	if (dllModule)
	{		
		Proto_fun fun=(Proto_fun)GetProcAddress(dllModule,"packSenderEnableCName");
		if (fun)
		{
			fun(enable);
		}
	} 
}