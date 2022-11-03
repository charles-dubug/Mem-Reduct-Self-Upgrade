// Mem Reduct
// Copyright (c) 2011-2022 Henry++

#pragma once

#include "routine.h"

#include "resource.h"
#include "app.h"

DEFINE_GUID (GUID_TrayIcon, 0xae9053f0, 0x8d59, 0x4803, 0x9a, 0xbb, 0x74, 0xaf, 0xe6, 0x6b, 0x5f, 0xd2);

#define TITLE_WORKINGSET L"Working set (vista+)"
#define TITLE_SYSTEMWORKINGSET L"System working set"
#define TITLE_STANDBYLISTPRIORITY0 L"Standby list (without priority) (vista+)"
#define TITLE_STANDBYLIST L"Standby list* (vista+)"
#define TITLE_MODIFIEDLIST L"Modified page list* (vista+)"
#define TITLE_COMBINEMEMORYLISTS L"Combine memory lists (win10+)"

#define TIMER 1000
#define UID 1337
#define UID_FORCE 8044

#define LANG_MENU 7

#define TRAY_SUBMENU_1 4
#define TRAY_SUBMENU_2 5
#define TRAY_SUBMENU_3 6

#define DEFAULT_AUTOREDUCT_VAL 90
#define DEFAULT_AUTOREDUCTINTERVAL_VAL 30

#define DEFAULT_DANGER_LEVEL 90
#define DEFAULT_WARNING_LEVEL 60

// colors
#define TRAY_COLOR_BLACK RGB(0, 0, 0)
#define TRAY_COLOR_WHITE RGB(255, 255, 255)
#define TRAY_COLOR_TEXT RGB(255, 255, 255)
#define TRAY_COLOR_BG RGB(0, 128, 64)
#define TRAY_COLOR_WARNING RGB(255, 128, 64)
#define TRAY_COLOR_DANGER RGB(237, 28, 36)

// memory cleaning mask
#define REDUCT_WORKING_SET 0x01
#define REDUCT_SYSTEM_WORKING_SET 0x02
#define REDUCT_STANDBY_PRIORITY0_LIST 0x04
#define REDUCT_STANDBY_LIST 0x08
#define REDUCT_MODIFIED_LIST 0x10
#define REDUCT_COMBINE_MEMORY_LISTS 0x20

// memory cleaning values
#define REDUCT_MASK_ALL (REDUCT_WORKING_SET | REDUCT_SYSTEM_WORKING_SET | REDUCT_STANDBY_PRIORITY0_LIST | REDUCT_STANDBY_LIST | REDUCT_MODIFIED_LIST)
#define REDUCT_MASK_DEFAULT (REDUCT_WORKING_SET | REDUCT_SYSTEM_WORKING_SET | REDUCT_STANDBY_PRIORITY0_LIST)
#define REDUCT_MASK_FREEZES (REDUCT_STANDBY_LIST | REDUCT_MODIFIED_LIST)

typedef struct _STATIC_DATA
{
	HDC hdc;
	HDC hdc_mask;
	HBITMAP hbitmap;
	HBITMAP hbitmap_mask;
	HFONT hfont;
	RECT icon_size;
	ULONG ms_prev;
} STATIC_DATA, *PSTATIC_DATA;

typedef struct _MEMORY_OBJECT
{
	ULONG64 total_bytes;
	ULONG64 free_bytes;
	ULONG64 used_bytes;
	ULONG percent;
} MEMORY_OBJECT, *PMEMORY_OBJECT;

typedef struct _MEMORY_INFO
{
	MEMORY_OBJECT physical_memory;
	MEMORY_OBJECT virtual_memory;
	MEMORY_OBJECT system_cache;
} MEMORY_INFO, *PMEMORY_INFO;

typedef enum _CLEANUP_SOURCE_ENUM
{
	SOURCE_AUTO,
	SOURCE_MANUAL,
	SOURCE_TRAY,
	SOURCE_HOTKEY,
	SOURCE_CMDLINE
} CLEANUP_SOURCE_ENUM, *PCLEANUP_SOURCE_ENUM;
