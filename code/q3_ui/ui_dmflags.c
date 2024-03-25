/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/
//
/*
=======================================================================

GAME OPTIONS MENU

=======================================================================
*/


#include "ui_local.h"


#define ART_FRAMEL				"menu/" MENU_ART_DIR "/frame2_l"
#define ART_FRAMER				"menu/" MENU_ART_DIR "/frame1_r"
#define ART_BACK0				"menu/" MENU_ART_DIR "/back_0"
#define ART_BACK1				"menu/" MENU_ART_DIR "/back_1"

#define ID_BACK					127
#define ID_FALLING				128
#define ID_FOV					129
#define ID_FOOTSTEPS				130
#define ID_SWITCH				131
#define ID_STRAFE				132
#define ID_INVISIBILITY				133
#define ID_VOTING				134
#define ID_SELFDAMAGE				135


typedef struct {
	menuframework_s		menu;

	menutext_s			banner;
	menubitmap_s		framel;
	menubitmap_s		framer;

	menuradiobutton_s	fallingDamage;
	menuradiobutton_s	fixedFOV;
	menuradiobutton_s	footsteps;
	menuradiobutton_s	instantWeaponChange;
	menuradiobutton_s	strafeJumping;
	menuradiobutton_s	totalInvisibility;
	menuradiobutton_s	lightVoting;
	menuradiobutton_s	weaponsSelfDamage;

	menubitmap_s		back;
} dmflagsOptions_t;

static dmflagsOptions_t dmflagsOptions_s;

static void DMflagsOptions_SetMenuItems( void ) {
}

static void DMflagsOptions_Event( void* ptr, int notification ) {
	if( notification != QM_ACTIVATED ) {
		return;
	}

	switch( ((menucommon_s*)ptr)->id ) {
	case ID_BACK:
		UI_PopMenu();
		break;
	}
}

static void DMflagsOptions_MenuInit( void ) {
	//int				y;

	memset( &dmflagsOptions_s, 0 ,sizeof(dmflagsOptions_t) );

	UI_DMflagsOptionsMenu_Cache();

	dmflagsOptions_s.menu.wrapAround = qtrue;
	dmflagsOptions_s.menu.fullscreen = qtrue;

	dmflagsOptions_s.banner.generic.type	= MTYPE_BTEXT;
	dmflagsOptions_s.banner.generic.x		= 320;
	dmflagsOptions_s.banner.generic.y		= 16;
	dmflagsOptions_s.banner.string			= "DMFLAGS";
	dmflagsOptions_s.banner.color			= color_white;
	dmflagsOptions_s.banner.style			= UI_CENTER;

	dmflagsOptions_s.framel.generic.type	= MTYPE_BITMAP;
	dmflagsOptions_s.framel.generic.name	= ART_FRAMEL;
	dmflagsOptions_s.framel.generic.flags	= QMF_INACTIVE;
	dmflagsOptions_s.framel.generic.x		= 0;
	dmflagsOptions_s.framel.generic.y		= 78;
	dmflagsOptions_s.framel.width			= 256;
	dmflagsOptions_s.framel.height			= 329;

	dmflagsOptions_s.framer.generic.type	= MTYPE_BITMAP;
	dmflagsOptions_s.framer.generic.name	= ART_FRAMER;
	dmflagsOptions_s.framer.generic.flags	= QMF_INACTIVE;
	dmflagsOptions_s.framer.generic.x		= 376;
	dmflagsOptions_s.framer.generic.y		= 76;
	dmflagsOptions_s.framer.width			= 256;
	dmflagsOptions_s.framer.height			= 334;

	dmflagsOptions_s.back.generic.type		= MTYPE_BITMAP;
	dmflagsOptions_s.back.generic.name		= ART_BACK0;
	dmflagsOptions_s.back.generic.flags		= QMF_LEFT_JUSTIFY|QMF_PULSEIFFOCUS;
	dmflagsOptions_s.back.generic.callback	= DMflagsOptions_Event;
	dmflagsOptions_s.back.generic.id		= ID_BACK;
	dmflagsOptions_s.back.generic.x			= 0;
	dmflagsOptions_s.back.generic.y			= 480-64;
	dmflagsOptions_s.back.width				= 128;
	dmflagsOptions_s.back.height			= 64;
	dmflagsOptions_s.back.focuspic			= ART_BACK1;

	Menu_AddItem( &dmflagsOptions_s.menu, &dmflagsOptions_s.banner );
	Menu_AddItem( &dmflagsOptions_s.menu, &dmflagsOptions_s.framel );
	Menu_AddItem( &dmflagsOptions_s.menu, &dmflagsOptions_s.framer );

	Menu_AddItem( &dmflagsOptions_s.menu, &dmflagsOptions_s.back );

	DMflagsOptions_SetMenuItems();
}


/*
===============
UI_DMflagsOptionsMenu_Cache
===============
*/
void UI_DMflagsOptionsMenu_Cache( void ) {

	trap_R_RegisterShaderNoMip( ART_FRAMEL );
	trap_R_RegisterShaderNoMip( ART_FRAMER );
	trap_R_RegisterShaderNoMip( ART_BACK0 );
	trap_R_RegisterShaderNoMip( ART_BACK1 );
}


/*
===============
UI_DMflagsOptionsMenu
===============
*/
void UI_DMflagsOptionsMenu( void ) {
	DMflagsOptions_MenuInit();
	UI_PushMenu( &dmflagsOptions_s.menu );
}
